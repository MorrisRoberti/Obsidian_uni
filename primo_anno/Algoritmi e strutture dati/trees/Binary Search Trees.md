>Un **albero di ricerca binaria** (*BST*) e' un albero binario che contiene il seguente vincolo:
>$$value\left\lbrack left\right\rbrack\le value\left\lbrack x\right\rbrack\le value\left\lbrack right\right\rbrack$$

Piu' nello specifico: 
> *Sia x un nodo in un BST. Se y e' un nodo nel sottoalbero sinistro di x, allora y.key <= x.key. Se y e' un nodo nel sottoalbero destro di x, allora y.key >= x.key*

L'immagine sotto illustra l'esempio di come, non e' possibile avere 2 nel sottoalbero destro di 3, poiche' tutti i valori di tale sotto albero devono essere >= 3

![[bst-vs-not-bst-2006374884.png]]

### Operazioni
>Le operazioni sui **binary search trees** sono eseguite generalmente in un tempo proporzionale all'altezza dell'albero, quindi in media $\Theta\left(\log n\right)$

Possiamo definire le seguenti operazioni:
- Attraversamenti -> valgono gli algoritmi [[Binary Trees#Visita di un albero binario]]
-  `tree_minimum(x)` -> trova l'elemento minimo dell'albero a partire dal nodo `x`
- `tree_maximum(x)` -> come sopra ma per l'elemento massimo
- `search(x, v)` -> cerca e restituisce (se presente) il primo nodo con valore `v`
- `successore(x)` -> dato un nodo `x` restituisce il nodo con il valore immediatamente successivo
- `insert(T, z)` -> inserisce il nodo `z` nell'albero `T
- `transplant(T, u, v)` -> metodo che sposta il sottoalbero di radice `u` con il sottoalbero nel nodo `v`
- `delete(T, z)` -> elimina un nodo da un BST


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
**Complessita'**: $O\left(n\right)$ nel caso peggiore
#### successore
Premessa:
>Il successore di un nodo *x* sara' sicuramente: nella posizione piu' a sinistra del sottoalbero destro (a partire da *x*) oppure sara' il suo parent
```
successore(x) {
	if right[x] != NIL
		return min(right[x])

	y = parent[x]
	
	while y != NIL && x == right[y] 
		x = y
		y = parent[y]
	
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
	
	while x != NIL 
		y = x
		if ( value[z] < value[x] )
			x = left[x]
		else
			x = right[x]
	
	
	parent[z] = y

	if y == NIL 
		root[T] = z
	else
		if value[z] < value[y]
			left[y] = z
		else
			right[y] = z
}
```
- 5-10 -> confronta iterativamente il valore del nuovo nodo *z* per trovare la posizione adatta che mantenga la proprieta' dei BST
- 13 -> una volta trovata la posizione, per ricordarla salvo il valore di *y* nel puntatore *parent* di *z*
- 15-16 -> se *y* e' NIL allora vuol dire che l'albero e' vuoto quindi metto *z* come *root*
- 18-21 -> confronto il valore di *z* con quello del suo *parent* per vedere se dovra' essere messo a dx o a sx, mantenendo la proprieta' dei BST

#### tree_minimum
```
tree_minimum(x) {
	while x.left != NIL
		x = x.left
	return x
}
```
- 2-4 -> percorre l'albero scendendo sempre a sinistra finche' `x` punta a `NIL`.
Dalla proprieta' dei BST siamo sicuri che il nodo piu' a sinistra e' il minore dell'albero

#### tree_maximum
```
tree_maximum(x) {
	while x.right != NIL
		x = x.right
	return x
}
```
Come sopra ma scende a destra per trovare il massimo

#### transplant
```
transplant(T, u, v) {
	if parent[u] == NIL
		root[T] = v
	else if u == left[parent[u]]
		left[parent[u]] = v
	else 
		right[parent[u]] = v
	
	if v != NIL
		parent[v] = parent[u]
}
```
- 2-3 -> caso in cui l'albero contiene solo il nodo `u`
- 4-5 -> se `u` e' il figlio sinistro del suo *parent* allora lo sostituisco con `v`
- 6-7 -> come sopra ma nel caso in cui `u` sia figlio destro 
- 9-10 -> controllo se `v != NIL`, in caso positivo vuol dire che `v` e' un nodo e dunque posso settare il suo *parent* a quello di `u`
#### delete
Per la delete abbiamo 3 casi di cui due semplici:
- `z` e' la radice -> prendiamo `parent[z]` e al posto di `z` mettiamo `NIL`
- `z` ha un solo figlio -> mettiamo il figlio al posto di `z`
- `z` ha due figli -> dobbiamo utilizzare la funzione ausiliaria`transplant` e fare qualche passaggio in piu'
```
delete(T, z) {
	if left[z] == NIL
		transplant(T, z, right[z])
	else if right[z] == NIL
		transplant(T, z, left[z])
	else
		y = tree_minimum(right[z])
		if parent[y] != z
			transplant(T, y, right[y])
			right[y] = right[z]
			parent[right[y]] = y
		transplant(T, z, y)
		left[y] = left[z]
		parent[left[y]] = y
}
```
- 2-5 -> se uno dei due figli di `z` non esiste prendo l'altro e lo sostituisco a `z` stesso
- 7 -> prendo il minimo del sottoalbero destro di `z` e lo salvo in `y`, quest'ultimo non avra' sottoalbero sinistro, poiche' e' minimo dunque per la proprieta' di BST avrebbe un nodo sinistro minore, ma cio' non e' possibile
- 8-11 -> se `y` non e' figlio di `z` allora scambio `y` con il suo nodo destro, poi assegno al figlio destro di `y`, il figlio destro di `z` e metto `y` come figlio destro del padre di `z`
- 12-14 -> sostituisco `y` a `z`

>In buona sostanza: il figlio destro di `y` va nella posizione di `y` e `y` va nella posizione di `z`, in questo modo rimuoviamo il nodo `z` mantenendo inalterata la proprieta' dei BST

![[Pasted image 20240625112718.png]]
#### Links