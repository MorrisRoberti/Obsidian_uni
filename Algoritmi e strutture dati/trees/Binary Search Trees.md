>Un **albero di ricerca binaria** (*BST*) e' un albero binario che contiene il seguente vincolo:
>$$value\left\lbrack left\right\rbrack\le value\left\lbrack x\right\rbrack\le value\left\lbrack right\right\rbrack$$

**ATTENZIONE** 
Possono non essere degli [[Heap]]

### Operazioni
Possiamo definire le seguenti operazioni:
- *search(x, v)* -> cerca e restituisce (se presente) il primo nodo con valore *v*
- *successore(x)* -> dato un nodo *x* restituisce il nodo con il valore immediatamente successivo
- *insert(T, z)* -> inserisce il nodo *z* nell'albero *T*

#### search
```
search(x, v) {
	if ( x == NIL || value[x] == v) 
		return x
	if ( value[x] > v ) 
		search(left[x], v)
	if ( value[x] < v )
		search(right[x], v)
}
```
- 2-3 -> caso base: il nodo con quel valore non e' presente oppure viene trovato
- 4-7 -> confronta il valore nel nodo attuale con quelli a dx e sx, e sfruttando la proprieta' dei BST si muove nel sottoalbero di dx quando il numero cercato e' maggiore di quello attuale e nel sottoalbero di sx quando e' minore
**Complessita'**: $O\left(n\right)$
#### successore
Premessa:
>Il successore di un nodo *x* sara' sicuramente: nella posizione piu' a sinistra del sottoalbero destro (a partire da *x*) oppure sara' il suo parent
```
successore(x) {
	if ( right[x] != NIL )
		return min(right[x])
	y = parent[x]
	while ( y != NIL && x == right[y] ) {
		x = y
		y = parent[y]
	}
	return y
}
```
- 2-3 -> prendo il valore piu' piccolo nel sottoalbero destro
- 5-8 -> siamo nel caso in cui il successore e' nel parent: tramite un ciclo si sale sempre verso l'alto per trovare il primo numero diverso che sara' sicuramente maggiore

#### insert
```
insert(T, z) {
	y = NIL
	x = root[T]
	
	while ( x != NIL ) {
		y = x
		if ( value[z] < value[x] )
			x = left[x]
		else
			x = right[x]
	}
	
	parent[z] = y

	if ( y == NIL ) 
		root[T] = z
	else
		if ( value [z] < value[y] )
			left[y] = z
		else
			right[y] = z
}
```
- 5-10 -> confronta iterativamente il valore del nuovo nodo *z* per trovare la posizione adatta che mantenga la proprieta' dei BST
- 13 -> una volta trovata la posizione, per ricordarla salvo il valore di *y* nel puntatore *parent* di *z*
- 15-16 -> se *y* e' NIL allora vuol dire che l'albero e' vuoto quindi metto *z* come *root*
- 18-21 -> confronto il valore di *z* con quello del suo *parent* per vedere se dovra' essere messo a dx o a sx, mantenendo la proprieta' dei BST

#### Links