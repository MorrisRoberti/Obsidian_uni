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
