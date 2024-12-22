>Quando si usa l'espressione di tipo array di `T`, viene applicato il *type decay* e si ottiene il puntatore al primo elemento dell'array. Questa conversione (trasformazione di lvalue) e' necessaria per evitare l'uso di copie costose quando un array viene passato come argomento ad una funzione: si passa il puntatore per valore.

Il legame tra array e puntatori e' molto forte, si vede subito dal fatto che la sintassi dell'indicizzazione di un array non e' altro che una sorta di shortcut per un uso semplificato dell'aritmetica dei puntatori.
```cpp
int a[100];
int b = 5;

a[b];

// le due espressioni sono del tutto equivalenti

*(a + b);

```
Nella seconda espressione, infatti, l'array `a` decade al puntatore al suo primo elemento, poi si somma `b` al puntatore (che indica di muoversi in avanti nell'array di 5 posizioni) e infine si dereferenzia il puntatore in modo da avere il valore effettivo.

**NOTA**
```cpp
int a[100];
int b = 5;

a[b]; // accesso al sesto elemento di a

*(a + b); // accesso al sesto elemento di a con a decaduto a puntatore

*(b + a); // la somma e' commutativa quindi l'espressione e' equivalente a quella sopra

b[a]; // quindi abbiamo che a[b] = b[a] il che e' strano

```

#### Links
[[Aritmetica dei puntatori]]