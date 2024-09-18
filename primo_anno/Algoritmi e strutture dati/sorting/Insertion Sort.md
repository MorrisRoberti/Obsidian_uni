$\Theta\left(n^2\right)$
$O\left(n^2\right)$
$\Omega\left(n\right)$
--- 
### Algoritmo
L'**Insertion Sort** e' implementato tramite cicli basato su **confronti**.
E' **pessimo** (anche se c'e' di peggio).
### Principio di base
Il principio e' il seguente:
- prende l'elemento successivo dell'array
- lo confronta con tutti quelli precedenti
- se un elemento e' minore di quello preso li scambia, altri altrimenti aggiunge quello in coda

![[Insertion_sort.gif]]

### Pseudocodice
```
Insertion_sort(A, n) {
for j = 2 to n
	key = A[j]
	i = j - 1
	while i > 0 and A[i] > key
		swap(A[i + 1], A[i])
		i = i - 1
	A[i + 1] = key
}
```
- 2 -> itera su tutto l'array a partire dalla posizione 2 perche' se passiamo un array di 1 elemento sara' sicuramente ordinato
- 3 -> assegna di volta in volta l'elemento da confrontare a *key*
- 5-7 -> controlla che gli elementi prima di key siano maggiori, se lo sono li scambia di volta in volta
- 8 -> nell'ultima posizione prima di *key* ci inserisce *key* che in quel momento sara' il piu grande dell'array ordinato
#### Links