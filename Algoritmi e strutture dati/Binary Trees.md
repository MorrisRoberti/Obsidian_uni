>Un **albero binario** e' un albero in cui un nodo ha un numero di figli compreso tra 0 e 2 (inclusi).

Per visitare i nodi sx e dx della *root* **x** si usano le "funzioni" ricorsive: **left[x]** e **right[x]**.
Le funzioni *left* e *right* indicano rispettivamente il nodo sinistro e destro del nodo specificato tra le parentesi.
### Visita di un albero binario
>E' possibile visitare gli alberi binari in due modi: **in ampiezza** e **in profondita'**.

Per visitare gli alberi binari in profondita' ci sono 3 modi:
- *in-order* -> *left[x]* | *x* | *right[x]*
- *pre-order* -> *x* | *left[x]* | *right[x]* 
- *post-order* -> *left[x]* | *right[x]* | *x*


 *in-order*
```
void in_order(x) {
	if (x != NIL) {
		in_order(left[x])
		print(x)
		in_order(right[x])
	}
}
```

*pre-order*
```
void pre_order(x) {
	if (x != NIL) {
		print(x)
		pre_order(left[x])
		pre_order(right[x])
	}
}
```

*post-order*
```
void post_order(x) {
	if (x != NIL) {
		post_order(left[x])
		post_order(right[x])
		print(x)
	}
}
```

### Implementazione Alberi binari
>Gli alberi binari si possono implementare in due modi in base al linguaggio e al paradigma che utilizziamo: tramite **oggetti** o tramite **array**.

Tramite *oggetti* avremmo qualcosa del genere
```cpp
class Node {
private:
	Node* left; // puntatore al nodo sinistro
	Node* right; // puntatore al nodo destro
	int value; // valore contenuto nel nodo
};
```

Tramite array avremmo una struttura del tipo
```
left = [1, 3, NIL, NIL, NIL]
right = [2, 4, NIL, NIL, NIL]
root = 0
```

#### Links
[[Heap]]
[[Binary Search Trees]]