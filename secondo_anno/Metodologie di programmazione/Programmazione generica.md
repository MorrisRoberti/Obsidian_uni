[[secondo_anno/Metodologie di programmazione/I Template|I Template]] vengono usati in C++ per realizzare il **polimorfismo statico**.
Si parla di polimorfismo in quanto scriviamo una sola versione del codice che viene utilizzata per generare diverse varianti e quindi puo' assumere diverse forme concrete. Si parla in particolare di polimorfismo **statico** perche' la scelta delle istanza da generare avviene staticamente, in fase di compilazione.

>La **programmazione generica** e' una metodologia di programmazione fortemente basata sul polimorfismo statico (cioe' sui template); tuttavia sarebbe sbagliato pensare che la programmazione generica sia esclusivamente basata su questi.
>I maggiori benefici della programmazione generica si hanno quando *un certo numero di template vengono progettati in maniera coordinata, allo scopo di fornire interfacce comuni e facilmente estendibili*.

Per capire meglio vediamo come si intrecciano alcune parti della *standard library*.

## I contenitori
>Un **contenitore** e' una classe che ha come scopo quello di *contenere una collezione di oggetti*; i contenitori sono tipicamente realizzati tramite template di classe che si differenziano a seconda dell'organizzazione della collezione di oggetti e delle operazioni fondamentali supportate.

### Contenitori sequenziali
>I contenitori **sequenziali** forniscono accesso ad una sequenza di elementi organizzati in base alla loro posizione. L'ordinamento degli oggetti nella sequenza e' stabilito dalle operazioni di inserimento e rimozione degli elementi.

Vediamo alcuni contenitori sequenziali
- `std::vector<T>` -> sequenza di elementi di tipo`T` di dimensione variabile memorizzati **in modo contiguo**;
	- l'accesso agli elementi e' fornito in tempo **costante**
	- inserimenti e rimozioni sono *ragionevolmente efficienti* se effettuati **in fondo alla sequenza**; altrimenti e' necessario effettuare un numero *lineare* di spostamenti di elementi per creare lo spazio per l'inserimento
- `std::deque<T>` -> contrazione di *double-ended queue* e' una coda a doppia entrata;
	- l'accesso agli elementi e' fornito in tempo **costante**
	- inserimenti e rimozioni sono **efficienti** sia all'inizio che alla fine della sequenza
- `std::list<T>` -> sequenza di `T` di dimensione variabile a tempo di esecuzione, memorizzati in modo non contiguo in una struttura a lista doppiamente concatenata;
	- per accedere ad un elemento bisogna *raggiungerlo* nella lista
	- inserimenti e rimozioni sono fatti in tempo **costante** nella posizione corrente perche' non occorre spostare elementi
- `std::forward_list<T>` -> come una `list` ma la concatenazione tra nodi e' singola, quindi e' consentito solo lo scorrimento in avanti

**IMPORTANTE**
>Per "memorizzazione contigua" si intende che i valori nel contenitore sono contenuti in celle di memoria *contigue* quindi successive.

Oltre a quelli elencati sopra vi sono i cosiddetti "pseudo-contenitori" o "quasi-contenitori":
- `std::array<T, N>` -> sequenza di `T` di dimensione `N` fissata a tempo di compilazione, dove `T` e' un `typename` mentre `N` e' un parametro valore; intuitivamente e' come un array del linguaggio ma e' immune alle problematiche di type decay e consente di conoscere facilmente il numero di elementi
- `std:::string` -> puo' essere visto come una sequenza di caratteri ed e' alias per l'istanza `std::basic_string<char>` del template `std::basic_string`; possiamo istanziare il template con caratteri di altro tipo, per cui esistono gli alias `std::wstring`, `std::u16string` e `std::u32string` per le stringhe di `w_char_t`, `char16` e `char32`
- `std::bitset<N>` -> una sequenza di esattamente `N` bit (dove `N` e' un parametro di valore e non un `typename`)

#### Operazioni su contenitori sequenziali
I contenitori sequenziali forniscono le sequenti operazioni:
- costruttori
- operatori per interrogare (gestire) la dimensione
- operatori per consentire l'accesso agli elementi
- operatori per inserire e rimuovere elementi
- operatori di confronto (tra contenitori)
- alcuni operatori specifici

## Algoritmi generici: dai "tipi" ai "concetti"
>Si puo' notare, nelle reference delle classi descritte che queste non contengono metodi per algoritmi di comune rilevanza, ad esempio la classe `std::vector<T>` non contiene metodi per ordinare la sequenza o per verificare se un elemento sia presente o meno al suo interno.

Questo perche' tali algoritmi sono *generalizzabili* a tutti i contenitori e quindi si vuole che siano il piu' possibile indipendenti dal tipo di dato. In altre parole si vuole che questi algoritmi non lavorino su tipi di dato ma su **concetti** astratti e quindi a tutti i tipi che forniscono le garanzie che caratterizzano un concetto.

#### Sequenze
>Un modo di rappresentare una **sequenza** e' quello di utilizzare una coppia di **iteratori** convenzionalmente chiamati *first* e *last* che rappresentano l'inizio della sequenza e la posizione immediatamente successiva all'ultimo elemento di questa
>$$[first, last)$$

#### iteratori
>Un iteratore NON e' un tipo di dato ma una **concetto astratto**. Un esempio classico di iteratore e' il tipo puntatore ad un elemento in un array.

```cpp
int* cerca(int* first, int* last, int elem) {
	for ( ; first != last; ++first)
		if (*first == elem)
			return first;
	return last;
}

int main() {
	int ai[200] = {1, 2, 3, 4, ... };
	int* first = ai;
	int* last = ai + 2; // cerco solo nei primi 3
	int* ptr = cerca(first, last, 2);
	if (ptr == last)
		std::cerr << "Non trovato";
	else
		std::cerr << "Trovato";
}
```

L'algoritmo di ricerca sopra funziona *solo per i puntatori a interi*. Proviamo a fare il *lifting* di questa funzione

```cpp
template <typename T>
T* cerca(T* first, T* last, T elem) {
	for ( ; first != last; ++first)
		if (*first == elem)
			return first;
	return last;
}
```

Questa soluzione e' piu' generica della prima ma comunque limitante perche' presuppone l'utilizzo di puntatori, quando in realta' esistono strutture diverse che possono essere utilizzate in modo analogo. Sostituiamo `T*` con un ulteriore parametro che fornira' il concetto di iteratore

```cpp
template <typename Iter, typename T>
Iter cerca(Iter first, Iter last, T elem) {
	for ( ; first != last; ++first)
		if (*first == elem)
			return first;
	return last;
}
```

##### Requisiti per gli Iter di cui sopra
1. `Iter` deve supportare la copia (passato e restituito per valore)
2. `Iter` deve supportare il confronto binario (`first != last`), per capire se la sequenza e' terminata o meno
3. `Iter` deve supportare il pre-incremento `++first`, per avanzare di una posizione nella sequenza
4. `Iter` deve consentire la dereferenziazione `*first` per poter leggere il valore "puntato"
5. Il tipo dei valori puntati da `Iter` deve essere confrontabile con il tipo `T` 

Qualunque tipo di dato concreto che rispetta questi requisiti puo' essere utilizzato per istanziare l'algoritmo.

>Si dice che i template applicano delle regole di tipo *strutturale* in contrapposizione alle regole *nominali*: non importa l'identita' del tipo, importa la sua struttura.

Gli algoritmi generici seguono il principio chiamato **Duck Typing**:
		*"If it walks like a duck and it quacks like a duck, then it must be a duck"*

### Contenitori associativi
>I **contenitori associativi** sono contenitori che organizzano gli elementi al loro interno in modo da facilitarne la ricerca in base al valore di una *chiave*.

Abbiamo i seguenti contenitori:
- `std::set<Key, Cmp>`
- `std::multiset<Key, Cmp>`
- `std::map<Key, Mapped, Cmp>`
- `std::multimap<Key, Mapped, Cmp>`
- `std::unordered_set<Key, Hash, Equal>`
- `std::unordered_multiset<Key, Hash, Equal>`
- `std::unordered_map<Key, Mapped, Hash, Equal>`
- `std::unordered_map<Key, Mapped, Hash, Equal>`

Queste 8 tipologie di contenitori si ottengono combinando tutti i modi possibili le seguenti proprieta':
1. La *presenza/assenza* negli elementi di ulteriori informazioni, oltre alla chiave usata per effettuare le associazioni: se il tipo elemento e' formato solo dalla chiave `Key` allora abbiamo contenitori detti **insiemi**; altrimenti abbiamo contenitori detti **mappe** che associano valori di tipo `Key`a valori del tipo `Mapped`; nel caso degli insiemi, il tipo degli elementi contenuti e' `const Key` mentre nel caso delle mappe il tipo degli elementi e' la coppia `std::pair<const Key, Mapped>`
2. La possibilita' o meno di memorizzare nel contenitore piu' elementi con lo stesso valore per la chiave: nel caso sia possibile memorizzare piu' elementi con lo stesso valore per la chiave abbiamo le versioni *multi* dei contenitori
3. Il fatto che l'organizzazione interna del contenitore sia ottenuta mediante una criterio di ordinamento delle chiavi (il tipo `Cmp`) oppure attraverso una opportuna funzione di hashing (il tipo `Hash`): nel primo caso abbiamo la possibilita' di scorrere gli elementi del contenitore in base al criterio di ordinamento; l'implementazione interna deve garantire che la ricerca di un valore con una determinata chiave possa essere effettuata eseguendo un numero di confronti $O(n\log{n})$ (l'implementazione e' tipicamente basata su qualche forma di albero di ricerca bilanciato).

	Nel secondo caso si ottengono contenitori "unordered": questi organizzano gli elementi in una *hash table* per cui quando si scorrono non presentano un criterio di ordinamento naturale. L'implementazione interna garantisce che la ricerca di un valore con una determinata chiave abbia nel caso medio un costo costante: per fare questo, la funzione di hashing calcola una posizione "presunta" nella tabella hash e poi, usando la funzione di confronto per uguaglianza si controlla se vi sono stati clash.

#### Gli adattatori (per contenitori della STL)
>Oltre ai contenitori, nella libreria sono forniti gli **adattatori**. Questi forniscono ad un contenitore esistente un'interfaccia specifica per usarlo "come se" fosse un determinato tipo di dato.

Esempi di adattatori sono `std::stack<T, C>` e `std::queue<T, C>` che forniscono le classiche strutture dati di pila e coda. Al loro interno usano un altro contenitore standard (rappresentato dal tipo `C`); la scelta di default e' `std::deque<T>` sia per le pile che per le code.

Esiste anche l'adattatore `std::priority_queue<T, C, Cmp>` per le code con priorita' (la classica struttura dati Heap) nelle quali la priorita' tra gli elementi e' stabilita dal criterio di confronto `Cmp`.
In questo caso, il contenitore `C` usato per default e' uno `std::vector<T>`

**ATTENZIONE**
>Gli adattatori **NON** implementano il concetto di sequenza; in particolare **NON** forniscono i tipi iteratore e i corrispondenti metodi `begin()` e `end()`.


#### Links
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]
[[Concetto di Iteratore]]
[[Concetto di Callable]]
[[Gli Iterator traits]]