>Nella libreria standard viene utilizzato il concetto di **iteratore** che prende spunto dal puntatore e fornisce un modo *generico* per rappresentare le varie tipologie di sequenze.

Possiamo classificare gli iteratori in 5 categorie:
- iteratori **di input**
- iteratori **forward**
- iteratori **bidirezionali**
- iteratori **random access**
- iteratori **di output**

## Iteratori di input
>Consentono di effettuare le seguenti operazioni

- `++iter` -> avanzamento prefisso
- `iter++` -> avanzamento postfisso (NON USARLO)
- `*iter` -> accesso *in sola lettura* dell'elemento corrente
- `iter->m` -> equivalente a `(*iter).m` dove si assume che l'elemento sia di tipo classe e che `m` sia membro della classe
- `iter1 == iter2` -> confronto per uguaglianza tra iteratori: viene utilizzato per capire se siamo arrivati alla fine della sequenza
- `iter1 != iter2` -> confronto per disuguaglianza

Un esempio di iteratore di input lo troviamo negli iteratori definiti sugli stream di input `std::istream`.

```cpp
#include <iterator>
#include <iostream>

int main() {

	std::istream_iterator<double> i(std::cin); // inizio della pseudo sequenza
	std::istream_iterator<double> iend; // fine della pseudo sequenza

	// scorro la sequenza e stampo i double letti su std::cout 
	for ( ; i != iend; ++i)
		std::cout << *i << std::endl;

}
```

Nel caso degli `istream` l'iteratore che parte dall'inizio si istanzia passando uno stream di input.

**ATTENZIONE**
>Quando si lavora con gli iteratori di input bisogna tenere conto del fatto che eventuali altri iteratori definiti sulla sequenza possano venire invalidati.

```cpp
std::istream_iterator<double> i(std::cin);
auto j = i;

// ora j e i puntano entrambi all'elemento corrente
std::cout << *i; // stampo l'elemento corrente
std::cout << *j; // stampo l'elemento corrente

++i; // avanzo con i: questa operazione INVALIDA j
std::cout << *j; // ERRORE: UNDEFINED BEHAVIOR

```

In linguaggio informale diciamo che gli iteratori di input sono *one shot*, cioe' l'operazione di avanzamento "consuma" l'input precedentemente letto.

## Iteratori forward
>Gli iteratori **forward** consentono di effettuare tutte le operazioni supportate dagli *iteratori di input*. inoltre l'operazione di avanzamento NON INVALIDA eventuali altri iteratori che puntano ad elementi precedenti nella sequenza.

Se il tipo e' modificabile, un iteratore forward puo' essere utilizzato anche per scrivere.

```cpp
#include <forward_list>
#include <iostream>

int main() {
	std::forward_list<int> lista = {1, 2, 3, 4, 5};

	// modifica gli elementi della lista
	for(auto i = lista.begin(); i != lista.end(); ++i)
		*i += 10;

	// stampa i valori 11, 12, 13, 14, 15
	for(auto i = lista.begin(); i != lista.end(); ++i)
		std::cout << *i << std::endl;
}
```

## Iteratori bidirezionali
>Consentono di effettuare tutte le operazioni supportate dagli *iteratori forward*. Inoltre consentono anche di **spostarsi all'indietro** nella sequenza.

Oltre agli operatori degli iteratori forward hanno gli operatori di decremento
- `--iter`
- `iter--`

Esempi di iteratori bidirezionali
```cpp
#include <list>
#include <iostream>

int main() {
	std::list<int> lista = {1, 2, 3, 4, 5};

	// Modifico gli elememti della lista
	for (auto i = lista.begin(); i != lista.end(); ++i)
		*i += 10;

	// Stampo i valori all'indietro
	for (auto i = lista.end(); i != lista.begin(); ){
		--i;
		std::cout << *i << std::endl;
	}

	// Posso ottenere (piu' facilmente) lo stesso risultato utilizzando gli iteratori all'indietro
	for (auto i = crbegin(); i != lista.crend(); ++i)
		std::cout << *i << std::endl;
}
```

## Iteratori random access
>Gli iteratori **random access** consentono di effettuare tutte le operazioni definite dagli *iteratori bidirezionali*.

Sono inoltre supportate le seguenti operazioni
- `iter += n` -> sposta `iter` di `n` posizioni (in avanti se positivo, all'indietro se negativo)
- `iter -= n` -> analogo ma nella direzione opposta
- `iter + n` -> calcola un iteratore spostato di `n` posizioni
- `n + iter` -> equivalente a `iter + n`
- `iter - n` -> analogo ma nella direzione opposta
- `iter[n]` -> equivalente a `*(iter + n)`
- `iter1 - iter2` -> calcola la "distanza" tra i due iteratori, ovvero il numero di elementi che dividono le due posizioni
- `iter1 < iter2` -> restituisce true se `iter1` occorre prima di `iter2`
- `iter1 > iter2`
- `iter1 <= iter2`
- `iter1 >= iter2`

Un esempio di iteratori random access sono i puntatori degli array buit in

```cpp
#include <vector>
#include <iostream>

int main() {
	std::vector<int> vect = {1, 2, 3, 4, 5, 6};

	// Modifica solo gli elementi di indice pari
	for (auto i = vect.begin(); i != vect.end(); i += 2)
		*i += 10;

	// Stampa i valori 11, 2, 13, 4, 15, 6
	for (auto i = vect.cbegin(); i != vect.cend(); ++i)
		std::cout << *i << std::endl;
}
```

## Iteratori di output
>Gli iteratori di **output** sono iteratori che permettono solamente di scrivere gli elementi di una sequenza: l'operazione di scrittura deve essere fatta una volta sola, dopodiche' e' necessario incrementare l'iteratore (per prepararsi a scrivere l'elemento successivo).

Le uniche operazioni consentite sono quindi:
- `++iter` 
- `iter++`
- `*iter` -> accesso *in sola scrittura* all'elemento corrente

**NOTA** 
>Non viene data la possibilita' di confrontare gli iteratori di output tra loro in quanto non e' necessario farlo: un iteratore di output assume che vi sia sempre spazio nella sequenza per fare le sue scritture; e' compito di chi lo usa fornire tali garanzie.

Quindi banalmente iterare in questo modo `for (auto i = seq.begin(); i != seq.end(); ++i)` non e' consentito

Esempio di iteratore output su `std::ostream`.

```cpp
#include <iterator>
#include <iostream>

int main() {
	std::ostream_iterator<double> out(std::cout, "\n");
	// Nota: non esiste una posizione finale
	// Nota: il secondo argomento serve da separatore, se non viene fornito si assume la stringa vuota ""

	double pi = 3.1415;
	for (int i = 0; i != 10; ++i)
		*out = (pi * i); // scrittura di un double usando out
		++out; // spostarsi in avanti dopo ogni scrittura

}
```

**IMPORTANTE**
>Si noti che, quando il tipo degli oggetti della sequenza e' accessibile in scrittura, gli iteratori *forward*, *bidirezionali* e *random access* soddisfano i requisiti degli iteratori *di output* e quindi possono essere usati ovunque ci sia bisogno di un iteratore di output.


>Nelle interfacce dei contenitori standard, possiamo notare alcuni nomi ricorrenti, che sono **canonici** nella libreria standard.

Talvolta si ritiene necessario dover utilizzare *nomi canonici* anche quando si scrivono algoritmi generici che sfruttano il concetto di iteratore, per questo un iteratore implementato come classe dovrebbe fornire i seguenti type alias:
- `value_type` -> tipo ottenuto "dereferenziando" l'iteratore
- `reference` -> tipo *riferimento* (al `value_type`)
- `pointer` -> tipo *puntatore* (al `value_type`)
- `difference_type` -> tipo intero con segno (per le "distanze" tra iteratori)
- `iterator_category` -> un tipo **tag** che indica a quale categoria appartiene l'iteratore

## Osservazioni
#### 1) const_reference e const_pointer
>Non sono forniti i `const_reference` e `const_pointer` perche' e' l'iteratore che decide se il `value_type` e' o meno in sola lettura; per esempio, se da un vettore `vi` di tipo `const std::vector<int>&` estraggo un iteratore utilizzando il metodo `begin()` otterro' un `std::vector<int>::const_iterator` il cui alias reference e' `const int&` e il cui alias pointer e' `const int*`.

#### 2) iterator_category
>La `iterator_category` e' un **tag type** (ovvero un tipo che puo' assumere un solo valore, il cui unico significato e' dato dall'identita' del tipo stesso).

I tipi *tag* per le categorie di iteratori, nella libreria standard sono definiti in questo modo
- `struct output_iterator_tag { };`
- `struct input_iterator_tag { };`
- `strutct forward_iterator_tag : public input_iterator_tag { };`
- `struct bidirectional_acess_iterator_tag : public forward_iterator_tag { };`
- `struct random_access_iterator_tag : public bidirectional_iterator_tag { };`

Le relazioni di ereditarieta' valgono, quindi tali **tag types** possono essere utilizzate per codificare versioni alternative di un algoritmo generico scelte in base alla categoria dell'iteratore (come esempi concreti, vedere le funzioni generiche `std::advance` e `std::distance`)

#### Links
[[Gli Iterator traits]]
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]
[[Programmazione generica]]