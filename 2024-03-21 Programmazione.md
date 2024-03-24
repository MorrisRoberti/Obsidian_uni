### STL & C++ Standard Library

- Containers:
```
# container sequenziali
	-vector<T> 
	- list<T>
	- stack<T>

# container associativi
	- set<T>
	- multiset<T> -> set con elementi ripetuti
	- map<T1,T2>
```
- Per le strutture dati della STL e' possibile usare il foreach:
```cpp
for (string s: v1) {
	cout << s;
}
```
**non si puo' fare per ogni struttura dati, es. sugli array non funziona. Funziona solo sulle strutture che implementano il pattern dell'iterator**
- Nel caso dei ``vector<T>`` possiamo utilizzare il metodo ``reserve(int n)`` (quindi modifica ``capacity``) per aumentare la grandezza del vettore di una certa dimensione, poiche' la riallocazione totale e' dispendiosa
- Quando abbiamo una classe della STL in un'altra classe il distruttore di default della classe in questione andra' a chiamare i distruttori di "tutti i campi"
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