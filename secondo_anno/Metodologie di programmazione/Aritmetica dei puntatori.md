>L'**aritmetica dei puntatori** e' un insieme di operatori che consente di eseguire operazioni matematiche sui puntatori, facilitando la navigazione attraverso strutture dati come gli *array*.

### Muoversi negli array con i puntatori
Se `ptr` e' un puntatore del tipo corretto che indirizza un elemento all'interno di un array, allora valgono le seguenti espressioni:
- `ptr + n` -> muoviti in avanti di `n` posizioni
- `n + ptr` -> come sopra
- `ptr - n` -> muoviti all'indietro di `n` posizioni
Tali operazioni sono legittime solo nel caso in cui il puntatore risultante punti comunque ad un elemento dell'array, cioe' non si vada oltre il limite iniziale o finale, altrimenti puntera' ad un'area di memoria che *non appartiene all'array*.

Dati due puntatori `ptr1` e `ptr2` del tipo corretto che indirizzano elementi dello stesso array, l'espressione `ptr1 - ptr2` indica la distanza tra i due puntatori, ovvero il numero di elementi che li separa (la distanza potrebbe essere negativa).

L'aritmetica dei puntatori e' utile per la definizione di un importante idioma di programmazione relativo all'iterazione su array
```cpp
// iterazione basata su indice
for (int i = 0; i != 100; ++i) {
	// fai qualcosa con a[i]
}

// iterazione basata su puntatore
for (int *p = a; p != a + 100; ++p){
	// fai qualcosa con *p
}

```
La seconda forma si presta bene a generalizzazioni che non richiedono di conoscere il punto di inizio dell'array e la sua dimensione.

Se sono sicuro che `p1` e `p2` sono puntatori validi all'interno dell'array e sono anche sicuro che `p1` *non* viene dopo `p2` allora posso iterare su tutti gli elementi compresi tra l'elemento puntato da `p1` (compreso) e l'elemento puntato da `p2` (escluso) nel modo seguente
```cpp
for ( ; p1 != p2; ++p1) {
	// fai qualcosa con *p1
}
```
Convenzionalmente per la coppia `p1` e `p2` si usano i nomi **first** e **last**, con l'accortezza di ricordarsi che **last** si riferisce alla posizione **successiva** all'ultimo elemento che si vuole processare.

**IMPORTANTE**
>Questo idioma e' stato esteso nel C++ al caso degli [[Concetto di Iteratore|iteratori]] sulle sequenze generiche e sui contenitori della libreria standard.

#### Links
[[Array e puntatori]]
[[Concetto di Iteratore]]
[[Programmazione generica]]