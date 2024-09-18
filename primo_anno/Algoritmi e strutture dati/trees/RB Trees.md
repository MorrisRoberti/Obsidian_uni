>Un **RB Tree** (*albero rosso nero*) e' un *BST* **approssimativamente bilanciato**, e utilizza un bit aggiuntivo per il colore che mantiene l'albero bilanciato.

**RB** e' l'acronimo di *Red-Black*, poiche' convenzionalmente i colori dei nodi sono rosso e nero.

L'altezza massima di un RB Tree con *n* nodi interni e' $2\log\left(n+1\right)$. Una conseguenza immediata di questo fatto e' che le operazioni sugli insiemi dinamici SEARCH, MAXIMUM, MINIMUM, SUCCESSOR e PREDECESSOR possono essere implementate in $O\left(\log n\right)$.

### Proprieta'
Le seguenti proprieta' sono fondamentali, in quanto garantiscono che l'albero rimanga approssimativamente bilanciato.
- Ogni nodo e' *rosso* o *nero*
- La radice e' nera
- Ogni foglia (NIL) e' nera -> (per rappresentare NIL viene utilizzato un nodo nero aggiuntivo)
- Se un nodo e' rosso, allora entrambi i suoi figli sono neri
- Per ogni nodo, tutti i cammini semplici che vanno da un nodo alle sue foglie discendenti contengono lo stesso numero di nodi neri

### Altezza nera di un nodo
>Definiamo **altezza nera** di un nodo x, indicata da *bh(x)* il numero di nodi neri lungo un cammino semplice che inizia dal nodo x (ma non lo include) e finisce a una foglia


### Rotazioni
>Le operazioni di inserimento e di eliminazione degli RB tree richiedono una subroutine che permette di ruotare a destra (RIGHT-ROTATE) o a sinistra (LEFT-ROTATE) i sottoalberi con radice nel nodo desiderato.

Quando effettuiamo una rotazione a destra di un nodo x supponiamo che il suo figlio sinistro non sia *NIL*, viceversa quando effettuiamo una rotazione a sinistra supponiamo che il figli destro non sia *NIL*.

![[Pasted image 20240723230558.png]]
#### left_rotate
```
left_rotate(T, x) {
	y = x.right
	x.right = y.left

	if y.left != T.nil
		y.left.p = x
	y.p = x.p
	if x.p == T.nil
		T.root = y
	else if x == x.p.left
		x.p.left = y
	else 
		x.p.right = y

	y.left = x
	x.p = y
}
```
- 2-3 -> fa puntare da `y` il figlio destro di `x` e nel figlio destro di `x` mette il figlio sinistro di `y`
- 5-6 -> se il nodo appena posto come figlio destro di `x` non e' il nodo NIL allora assegno il suo parent a `x`
- 7-9 -> riassegno il parent di `y`
- 10-13 -> riassegno `y` come figlio destro o sinistro del vecchio parent di `x`
- 15-16 -> metto  `x` come figlio sinistro di `y`e `y` come padre di `x`

>**right_rotate** e' analogo
### Inserimento
>Inserire un elemento in un RB Tree e' trivialmente come inserire un elemento in un qualsiasi BST, tuttavia dopo aver trovato il posto giusto e' necessario ricolorare l'albero per ribilanciarlo

#### rb_insert
```
rb_insert(T, z) {
	y = T.nil
	x = T.root

	while x != T.nil
		y = x
		if z.key < x.key
			x = x.left
		else x = x.right
	z.p = y
	if y == T.nil
		T.root = z
	else if z.key < y.key
		y.left = 
	else
		y.right = z
	
	z.left = T.nil
	z.right = T.nil
	z.color = RED
	rb_insert_fixup(T, z)
}
```
- 2-16 -> in buona sostanza e' [[Binary Search Trees#insert]]
- 18-22 -> imposta il nodo appena inserito e chiama **rb_insert_fixup** su questo, per ricolorare l'albero in modo che si mantenga il bilanciamento
#### rb_insert_fixup
Non spieghero' le varie fasi della seguente funzione, si dia per buona
```
rb_insert_fixup(T, z) {
while z.p.color == RED
	if z.p == z.p.p.left
		y = z.p.p.right
		if y.color == RED
			z.p.color = BLACK
			y.color = BLACK
			z.p.p.color = RED
			z = z.p.p
		else if z == z.p.right
			z = z.p
			left_rotate(T, z)
		z.p.color = BLACK
		z.p.p.color = RED
		right_rotate(T, z.p.p)
	else (come la clausola then ma con right e left scambiati)
T.root.color = BLACK	
}
```


### Eliminazione
>Per l'eliminazione, sfruttiamo il ragionamento analogo a quella dei BST quindi ci serviamo di una subroutine **rb_transplant** e di una subroutine per ricolorare l'albero, **rb_delete_fixup**

#### rb_delete
```
rb_delete(T, z) {
y = z
y-original-color = y.color
if z.left == T.nil
	x = z.right
	rb_transplant(T, z, z.right)
else if z.right == T.nil
	x = z.left
	rb_transplant(T, z, z.left)
else 
	y = tree_miniumum(z.right)
	y-original-color = y.color
	x = y.right
	
	if y.p == z
		x.p = y
	else rb_transplant(T, y, y.right)
		y.right = z.right
		y.right.p = y
	rb_transplant(T, z, y)
	y.left = z.left
	y.left.p = y
	y.color = z.color
if y-original-color == BLACK
	rb_delete_fixup(T, x)
}
```

#### rb_transplant
```
rb_transplant(T, u, v) {
if u.p == T.nil
	T.root = v
else if u == u.p.left
	u.p.left = v
else u.p.right = v
v.p = u.p
}
```

>Il codice della subroutine **rb_delete** non lo riportero' qui ne lo spieghero' in quanto lungo e complesso, si sappia soltanto che serve a ricolorare l'albero una volta eliminato l'elemento


#### Links