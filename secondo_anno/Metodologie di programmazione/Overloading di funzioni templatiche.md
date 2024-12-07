>Template di funzione dotati dello stesso nome e visibili nello stesso scope sono ordinati rispetto ad una relazione di **specificita'**. Il concetto di specificita' e' quello che regola l'ordinamento parziale che sta alla base della risoluzione dell'overloading con template di funzione.

Supponiamo di avere una funzione che conta il numero di istanze di un determinato template di funzione`istanze(X)` dove `X` e' un template di funzione.
Ora supponiamo di avere un altro template `Y` per cui vale che `istanze(X)` $\subset$ `istanze(Y)`, in questo caso si dice che `X` e' piu' **specifico** di `Y`.

## Risoluzione dell'overloading
>Nella risoluzione dell'overloading le istanze di template piu' specifici sono preferite a quelle di template meno specifici.

Per decidere se un'istanza di template di funzione entra fa parte delle funzioni candidate occorre verificare *se e' possibile effettuare una deduzione di parametri del template*.
Durante il processo di deduzione e' possibile applicare **SOLO CORRISPONDENZE ESATTE**.

Se il processo di deduzione ha successo allora l'istanza del template oltre ad essere candidata e' anche utilizzabile.

Quando si cerca la migliore utilizzabile bisogna considerare queste due regole:
- **si preferiscono i template piu' specifici** -> eliminare le istanze ottenute da template meno specifici
- **preferenza per le funzioni non templatiche** -> Se anche dopo aver effettuato questa operazione rimane un'ambiguita' si *eliminano dalle utilizzabili TUTTE le istanze di template* e si risolve l'overloading solo con le funzioni non templatiche

Esempi
```cpp
template<typename T, typename U> void foo(T t1, U u2);
template<typename T, typename U> void foo(T t1, U* u2);
template<typename T> void foo(T t1, T t2);
```
I template 2 e 3 sono piu' specifici del template 1, ogni loro istanza e' anche istanza del template 1, quindi questo viene scartato dalle utilizzabili. I template 2 e 3 *non sono confrontabili tra loro*, quindi abbiamo un'ambiguita'.

```cpp
template<typename T, typename U> void foo(T t1, U u2);
template<typename T, typename U> void foo(T t1, U* u2);
template<typename T> void foo(T t1, T t2);

// chiamata
foo(42, 42);
```
2 e 4 non sono utilizzabili. La migliore funzione `void foo<int>(int, int)` si ottiene istanziando il template 3, che viene preferito al template 1 per specificita'

Se avessimo una chiamata
```cpp
foo(&i, &i); // con i intero
```
Sono utilizzabili tutte e la 1 e' scartata per specificita'.
Ci sarebbe ambiguita' tra l'istanza 2 `void foo<int*, int>(int*, int*)` istanza 3 `void foo<int*>(int*, int*)` e funzione 4.
In questo caso la *migliore* e' la funzione 4 (preferenza alla non templatica).

#### Links
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]
[[Overloading - definizione e risoluzione]]
