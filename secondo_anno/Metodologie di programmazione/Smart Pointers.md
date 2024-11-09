>Uno **smart pointer** e' un puntatore "intelligente", cioe' un tipo di puntatore che gestisce in modo automatico il rilascio delle risorse deallocandole quando viene distrutto. Solitamente si usano in contrapposizione ai *raw pointers*, cioe' quelli forniti dal linguaggio, per garantire l'[[Exception Safety]].

Le tre classi *templatiche* degli smart pointers sono definite nell'header `<memory>`.

**ATTENZIONE**
>Gli *smart pointer* si riferiscono alla memoria dinamica, quindi contengono puntatori a memoria allocata dinamicamente sotto il controllo del programmatore, non si possono usare per la memoria che viene allocata staticamente o automaticamente.

Distinguiamo 3 tipi di smart pointer:
- **std::unique_ptr** -> puntatori *unici*
- **std::shared_ptr** -> puntatori *condivisi*
- **std::weak_ptr** -> puntatori *deboli*

## std::unique_ptr
>Uno **unique_ptr** ad un tipo *T* e' un puntatore smart ad un oggetto di tipo *T* allocato dinamicamente, in particolare questo implementa il concetto di **owning**, ovvero il puntatore si considera *l'unico proprietario della risorsa*.

Esempio:
```cpp
#include <memory>

void foo() {
	std::unique_ptr<int> pi (new int(42));
	std::unique_ptr<double> pd (new double(3.1415));
	*pd *= *pd; // si dereferenzia come un raw pointer
	// altro codice
} // qui termina il ciclo di vita di pi e pd e viene rilasciata la memoria
```

**IMPORTANTE**
>Una caratteristiche degli unique_ptr e' quella di **NON essere copiabili** ma di essere solo *spostabili*. La copia e' impedita perche' chiaramente si andrebbe a violare il requisito di unicita' di gestione della risorsa.

Esempio:
```cpp
void foo(std::unique_ptr<int> pi);

void bar() {
	std::unique_ptr<int> pj(new int(42));
	// foo(pj); // errore di compilazione: copia non ammessa
	foo(std::move(pj)); // ok: spostamento ammesso
	// dopo lo spostamento, pj non gestisce piu' nessuna risorsa
}
```

La classe fornisce metodi per interagire con puntatori *raw*, in particolare:
- *reset()* -> il puntatore prende in gestione una nuova risorsa diventandone il proprietario, rilasciando la risorsa che aveva prima (se ce l'aveva)
- *get()* -> fornisce il puntatore raw alla risorsa gestita, che pero' *rimane sotto responsabilita' dell'unique_ptr*
- *release()* -> restituisce il puntatore raw e ne cede anche la responsabilita' di corretta gestione

```cpp
std::unique_ptr<int> pi; // pi non gestisce ancora risorse
int* raw_pi = new int(42);
pi.reset(raw_pi); // NON devo invocare la delete su raw_pi
int* raw_pj = pi.get(); // NON devo invocare la delete su raw_pj
int* raw_pk = pi.release(); // devo invocare la delete su raw_pk
```

## std::shared_ptr
>Uno **shared_ptr** ad un tipo *T* e' uno smart pointer ad un oggetto di tipo *T* allocato dinamicamente. Lo shared_ptr implementa il concetto di puntatore per il quale la responsabilita' di corretta gestione della risorsa e' condivisa.

Quando uno *shared_ptr* viene copiato l'origine e la copia puntano allo stesso oggetto allocato nell'heap, condividendo quindi anche la responsabilita' della gestione di quella risorsa.
A livello implementativo, la copia causa l'incremento di un contatore del *reference counter* cioe' del numero di riferimenti alla risorsa. Quando uno shared_ptr viene distrutto il reference counter associato alla risorsa viene decrementato e, se si accorge di essere rimasto l'unico shared_ptr che punta a quella risorsa allora fa la deallocazione.

```cpp
#inlcude <memory> 

void foo() {
	std::shared_ptr<int> pi;
	{
		std::shared_ptr<int> pj(new int(42)); // ref counter = 1
		pi = pj; // condivisione risorsa, ref counter = 2
		++(*pi); // uso risorsa condivisa: nuovo valore 43
		++(*pj); // uso risorsa condivisa: nuovo valore 44
	} // distruzione pj, ref counter = 1
	++(*pi); // uso risorsa condivisa: nuovo valore 45
} // distruzione pj, ref counter = 0, rilascio risorsa
```

Come detto gli shared_ptr sono **copiabili** e **spostabili**.
La classe fornisce i metodi *reset* e *get* con la semantica intuitiva (non release).

#### I template di funzione std::make_shared e std::make_unique
>Uno *shared_ptr* deve interagire con due componenti: *la risorsa* e il *blocco di controllo* della risorsa cioe' una porzione di memoria nella quale viene salvato anche il reference counter. Per motivi di efficienza sarebbe bene che queste due componenti fossero allocate insieme con una singola operazione: tale e' la garanzia offerta dalla **std::make_shared**.

```cpp
void bar() {
	auto pi = std::make_shared<int>(42);
	auto pj = std::make_shared<double>(3.1415);
}
```

Oltre ad essere piu' efficiente, l'uso di std::make_shared consente di evitare alcuni errori subdoli che potrebbero compromettere la corretta gestione delle risorse in presenza di comportamenti eccezionali
```cpp
void bar(std::shared_ptr<int> pi, std::shared_ptr<int> pj);

void foo() {
	// codice NON exception safe
	bar(std::shared_ptr<int> (new int(42)), std::shared_ptr<int> (new int(42)));

	// codice excepion safe
	bar(std::make_shared<int> (42), std::make_shared<int>(42));
}
```

Siccome l'ordine di esecuzione delle sottoespressioni non e' specificato, nella prima chiamata della funzione bar una implementazione potrebbe decidere di valutare per prime le due espressioni *new*  passate come argomenti ai costruttori degli shared_ptr e solo dopo invocare i costruttori.
Se la prima allocazione tramite *new* andasse a buon fine ma la seconda invece fallisse con un'eccezione, si otterrebbe un memory leak, in quanto il distruttore  dello shared_ptr NON viene invocato e quindi la prima risorsa viene persa.
Il problema non si presenta nella seconda chiamata a bar, perche' le allocazioni sono effettuate implicitamente nella *make_shared*.

**ATTENZIONE**
>Tale esempio non causa problemi nel caso di implementazioni conformi allo standard C++17.

A partire da C++14 e' stata resa disponibile anche la **std::make_unique**.

L'uso di smart pointers e di queste funzioni fanno si che l'utilizzo di operazioni *new* e *delete* vengano limitate se non proprio eliminate. Nelle linee guida piu' recenti del linguaggio, l'uso *naked* di new e delete e' considerato cattivo stile di programmazione.

## std::weak_ptr
>Un problema che si potrebbe presentare quando si usano gli shared_ptr e' dato dalla possibilita' di creare *dipendenze circolari*, cioe' abbiamo piu' puntatori che si puntano a vicenda. In questo caso le risorse comprese in un ciclo mantengono sempre un reference couter positivo anche se non sono piu' raggiungibili dal programma e questo genera memory leak. L'uso di weak_ptr e' pensato per risolvere tali problemi

>Uno **weak_ptr** e' un puntatore ad una risorsa condivisa che pero' non partecipa attivamente alla gestione della risorsa stessa: la risorsa viene quindi rilasciata quando si distrugge l'ultimo shared_ptr, anche se esistono dei *weak_ptr* che la indirizzano.

Questo significa che un *weak_ptr* non puo' accedere direttamente alla risorsa: prima di farlo deve accertarsi che la risorsa sia ancora disponibile. 
Il modo migliore per farlo e' tramite la funzione **lock()**, che *produce uno shared_ptr* a partire dal *weak_ptr* -> se la risorsa non e' piu' disponibile restituisce *nullptr*.

```cpp
void maybe_print(std::weak_ptr<int> wp) {
	if(auto sp2 = wp.lock())
		std::cout << *sp2;
	else
		std::cout << "non piu' disponibile";
}

void foo() {
	std::weak_ptr<int> wp;
	{
		auto sp = std::make_shared<int>(42);
		wp = sp; // wp non incrementa il reference counter della risorsa
		*sp = 55;
		maybe_prin(wp); // stampa 
	} // sp viene distrutto, insieme alla risorsa
	maybe_print(wp); // stampa "non piu' disponibile"
}
```

#### Links
[[Exception Safety]]
