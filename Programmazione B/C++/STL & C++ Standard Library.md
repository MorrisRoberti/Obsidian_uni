>La **STL** (*Standard Template Library*) e' la libreria di C++ contenente strutture dati e algoritmi generici (template), mentre la **C++ Standard Library** e' una collezione di classi e funzioni che fanno parte del core di C++.

Sono due librerie distinte che per motivi storici non sono mai state unificate.
### STL
La STL contiene:
- Containers
- Iterators
- Algoritmi
- Funtori
#### Containers
Sono collezioni di elementi di tipo ``T``, differiscono principalmente per criterio di aggregazione e modalita' di selezione degli elementi.
Abbiamo due tipi di containers: **sequenziali** e **associativi**.

##### Containers sequenziali
- *vector< T >* -> vettori
- *list< T >* -> lista doppiamente concatenata
- *stack< T >* -> pila
- *queue< T >* -> coda

##### Containers associativi
- *set< T >* -> insieme
- *multiset< T >* -> insieme con elementi ripetuti
- *map< T1, T2 >* -> insieme di elementi chiave-valore (*dizionario*)

#### Algoritmi
La STL mette a disposizione diverse funzioni globali che realizzano operazioni di uso comune: 
- *sort* -> ordina una sequenza di valori di un container
- *merge* -> fonde due sequenze ordinate di valori di container
- *reverse* -> inverte l'ordine degli elementi di un container
- *swap* -> scambia i valori di due oggetti di tipo qualsiasi

#### Un altro modo per iterare
>Per **alcune** strutture dati della STL e' possibile usare il costrutto **foreach**
```cpp
for (string s: v1) {
	cout << s;
}
```

Non funziona per tutte le strutture, ad esempio sugli array non funziona. Funziona solo su quelle strutture che implementano il pattern dell'iterator
#### Cose da sapere
Quando abbiamo una classe della STL in un'altra classe il distruttore di default della classe in questione andra' a chiamare i distruttori di "tutti i campi"
- La regola dei 3 vale quando sono direttamente io ad usare memoria dinamica, nel momento in cui uso attributi che appartengono a classi della STL non avro' bisogno di ridefinire distruttori, costruttori di copia e operator= perche' la classe andra' a richiamare quelli definiti nelle classi STL
- L'iteratore for per le collection ritorna una copia dei valori, quindi nel caso di Map con vector l'update si rompe, per far in modo di aggiornare dobbiamo passare per riferimento
```cpp
for (Pair<K, V>& p : pairs) {
	...
}
```
- si puo' usare **auto** per lasciar inferire al compilatore il tipo dell'oggetto sul quale sto iterando
```cpp
for (auto k: m.keys()) {
	...
}
```

#### Links
[[La classe vector<T>]]