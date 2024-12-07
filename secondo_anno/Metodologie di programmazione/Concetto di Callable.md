Quando si scrive codice generico solitamente si hanno delle *policy* che riguardano, ad esempio quali vincoli devono avere determinati elementi, quali tipi di parametro accetta una funzione etc.

Un esempio e' l'algoritmo `std::adjacent_find` che ricerca all'interno di una sequenza la prima occorrenza di due elementi adiacenti ed equivalenti, abbiamo le seguenti dichiarazioni in overloading
```cpp
template<typename FwdIter>
FwdIter adjacent_find(FwdIter first, FwdIter last);

template<typename FwdIter, typename BPred pred>
FwdIter adjacent_find(FwdIter first, FwdIter last, BPred pred);
```
Nella prima versione il confronto dovra' avvenire necessariamente tramite un qualche overloading di`operator==`, quindi il tipo `FwdIter` dovra' definire tale operatore.

Nella seconda versione abbiamo un terzo parametro che ci dice che possiamo passare *qualsiasi cosa che si comporti come un predicato binario di confronto*.
Si capisce bene che questa versione e' decisamente piu' generica.

>Il concetto di **callable** e' l'insieme di tutti i tipi di dato che consentono ai propri "valori" di essere utilizzati come nomi di funzione in una chiamata.

Possiamo distinguerne 3 tipi:
1. **puntatori a funzione**
2. **oggetti funzione**
3. **lambda functions**

## 1) Puntatori a funzione
>Un **puntatore a funzione** intuitivamente e' una variabile che memorizza l'indirizzo di una funzione. Questo consente di chiamare la funzione attraverso il puntatore consentendo un comportamento flessibile e dinamico.

Facciamo subito un esempio
```cpp
#include <vector>


std::vector<int>::iterator v;

template<typename InIter, typename T>
InIter find_if(InIter first, InIter last, UnaryPred pred);

bool pari(int i);

auto iter = std::find_if(v.begin(), v.end(), pari);

```
il parametro `UnaryPred` viene legato al tipo concreto dell'espressione `pari` che (causa il **type decay**) e risulta essere `bool (*)(int)` cioe' un **puntatore ad una funzione** che prende un argomento intero per valore e restituisce un booleano.

## 2) Gli "Oggetti Funzione"
>Sfruttando il cosiddetto *duck typing*, specializziamo `BPred` con *"qualcosa che si comporta come un predicato binario di confronto"*, in particolare utilizziamo degli **oggetti che si comportano come funzioni**.

Esempio
```cpp
struct Pari {
	bool operator()(int i) const {
		return i % 2 ==0;
	}
};

int foo() {
	Pari pari;
	if (pari(12345)){
		...
	}
}

```

Le classi dalle quali istanzio il mio *oggetto funzione* sono sostanzialmente classi che hanno solo un metodo che definisce l'operatore `operator()`, che trasforma gli oggetti di quella classe in funzioni, e quindi in oggetti **callable**.

**NOTA**
>Spesso l'operatore e' marcato `const` perche' gli oggetti funzione sono quasi sempre **stateless**, cioe' non hanno dati membro e quindi non sono modificati dalle invocazioni dei loro `operator()`.

#### Perche' gli oggetti funzione?
>A primo impatto ci si potrebbe chiedere quale sia il senso di utilizzare gli oggetti di funzione, la risposta sta nel fatto che sono piu' *efficienti* perche' consentono al compilatore di eseguire delle ottimizzazioni.

Esempio:
Consideriamo un programma che lavora su un `std::vector<int>` e istanzia piu' volte la funzione generica `std::find_if` per effettuare ricerche nel vector usando predicati unari diversi. Consideriamo i seguenti predicati:
```cpp
bool pari(int i);
bool dispari(int i);
bool positivo(int i);
bool negativo(int i);
bool maggiore_di_mille(int i);
bool numero_primo(int i);
```
Questi predicati hanno tutti tipo "bool(int)" di conseguenza quando si istanzia l'algoritmo `std::find_if` sul vettore usando i sei predicati, si ottiene ogni volta la stessa identica istanza del template.

Se usiamo i seguenti alias di tipo
```cpp
using Iter = std::vector<int>::iterator;
using Ptr = bool (*)(int);
```
La specifica istanza ottenuta sara' la seguente
```cpp
Iter std::find_if<Iter, Ptr>(Iter first, Iter last, Ptr pred);
```

Il codice generato e' unico e deve gestire correttamente tutte le 6 possibili invocazioni, di conseguenza la chiamata e' implementata come chiamata di funzione.

Supponiamo ora che i predicati siano stati implementati come *oggetti funzione*, in questo caso quando si istanzia l'algoritmo `std::find_if`, siccome i tipi degli oggetti funzione sono distinti si otterranno 6 diverse istanze del template di funzione
```cpp
Iter std::find_if<Iter, Pari>(Iter first, Iter last, Pari pred);
Iter std::find_if<Iter, Dispari>(Iter first, Iter last, Dispari pred);
Iter std::find_if<Iter, Positivo>(Iter first, Iter last, Positivo pred);
...
```
Quando genera il codice per una delle istanze, il compilatore vede l'invocazione di solo uno dei sei metodi `operator()` quindi puo' ottimizzare il codice per quella specifica invocazione (ad esempio tramite un'espansione in linea). Quindi nonostante il codice eseguibile sia piu' grande e' piu' efficiente.

## 3) Lambda functions
>Talvolta si vuole utilizzare definire una funzione che verra' utilizzata solo in uno specifico punto del programma; di per se' sarebbe inutile averla esterna e poi richiamarla, noi vorremo che questa esistesse solo nel punto necessario. Qui ci vengono in aiuto le **lambda functions**. Una funzione lambda e' una funzione "anonima" nel senso che non ha nome e non puo' essere richiamata.

### Under the hood
>Quello che fa il compilatore (di nascosto) quando trova una funzione lambda e':

1. Creare una classe *anonima* con un nome arbitrario e con gli argomenti della *capture list* come dati membro
2. Definire un metodo `operator()` avente come parametri quelli della funzione lambda
3. Istanziare un oggetto della classe appena creata e richiamarlo come un *oggetto funzione*

La sintassi e' la seguente
```cpp
[](const long& i){ return i % 2 ==0;}

// oppure
[](const long& i) -> bool {return i % 2 == 0;}

```
- `[]` -> rappresenta la **capture list** cioe' una lista di variabili locali accessibili alla funzione nel punto in cui viene chiamata
- `(const long& i)` -> lista dei parametri
- `{return i % 2 == 0;}` -> corpo della funzione
- `->bool` -> e' una parte opzionale chiamata **trailing type** che specifica il tipo di ritorno della funzione (solitamente non lo si mette, anche perche' il compilatore e' in grado di dedurre il tipo di ritorno dall'espressione `return`)

#### Capture list
>Nella *capture list* andiamo a specificare delle variabili esterne che vogliamo utilizzare all'interno della nostra funzione.

Facciamo un esempio
```cpp
[x, y](int z) -> int { return x + y - z;}
```
Il chiamante sa che questa funzione prende in input **un intero** e restituisce un intero, mentre in realta' la funzione utilizza anche dei valori presi da uno scope piu' esterno.

E' possibile passare variabili nella capture list nei seguenti modi:
- `[&soglia]` -> passaggio per riferimento
- `[=soglia]` -> passaggio per valore
- `[=, &soglia]` -> tutti i parametri sono passati per valore, tranne `soglia` che e' passato per riferimento
- `[&, =soglia]` -> analogo a sopra ma opposto

**NOTA**
>Solitamente il metodo `operator()` e' qualificato `const` quindi se si vuole accedere alle variabili catturate in scrittura bisogna aggiungere la keyword `mutable`.

```cpp
void foo(const std::vector<long>& v) {
	long num_chiamate = 0;
	auto iter = std::find_if(v.begin(), v.end(), 
							[&num_chiamate](const long& i) mutable {
								++num_chiamate;
								return i % 2 ==0;
								});
	std::cout << "funzione lambda invocata" << num_chiamate << " volte \n";
}
```

**NOTA 2**
>Nel caso vengano effettuate catture per riferimento, occorre prestare attenzione a NON usare la funzione lambda dopo che il tempo di vita della variabile catturata e' terminato.

E' possibile dare un nome all'oggetto *anonimo* che rappresenta la lambda, anche se non se ne conosce il tipo, sfruttando `auto`.
```cpp
auto corta = [max_size](const std::string& s) {
	return s.size() <= max_size;
};
```


#### Links
[[Programmazione generica]]
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]



