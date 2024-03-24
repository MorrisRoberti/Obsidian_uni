$\Theta\left(n + k\right)$
$O\left(n + k\right)$
$\Omega\left(n_+ k\right)$ 
--- 
### Algoritmo
Il **Counting Sort** e' implementato in modo **iterativo** e **NON E' basato su confronti**.
E' un algoritmo di ordinamento **NON in place**.
**Counting Sort** suppone che ciascun elemento dell'array da ordinare sia compreso in un range da *0* a *k* (questa cosa e' fondamentale).

Una proprieta' importante di **Counting Sort** e' la **stabilita'**: i numeri con lo stesso valore si presentano nell'array di output nello stesso ordine in cui si trovano in quello di input.

### Principio di base
- Crea un nuovo array *C* di dimensione *k*
- Per ogni elemento *A[i]* dell'array originale mette in *C[A[i]]* il numero delle sue occorrenze 
- Scorre *C* ed esegue delle somme parziali (mette nella posizione 2 la somma degli elementi in 1 e in 2, nella posizione 3 la somma degli elementi in posizione 2 e 3 etc.)
- A questo punto *C[i]* conterra' il numero di elementi <= di *i*
- Scorre l'array *A* e per ogni elemento *A[i]*, inserisce questo valore nella posizione *C[A[i]]* dell'array *B* e decrementa tale valore in modo da essere pronto per l'iterazione successiva
(E' piu' facile a farsi che a dirsi)
![[Pasted image 20240324125720.png]]
- A -> inputArray
- B -> outputArray
- C -> countArray

### Pseudocodice
```
Counting_sort(A, B, k) {
// dichiaro C[0...k]
for i = 0 to k
	C[i] = 0
for j = 0 to A.length
	C[A[j]] = C[A[j]] + 1
for i = 1 to k
	C[i] = C[i] + C[i - 1]
for j = A.length downto 1
	B[C[A[j]]] = A[j]
	C[A[j]] = C[A[j]] - 1
}
```
- 2-4 -> dichiara l'array *C* e inizializza tutti i valori a 0
- 5-6 -> scorre *A* e mette in *C* il numero di volte che un elemento appare, nella posizione con valore uguale all'elemento stesso
- 7-8 -> scorre *C* ed esegue delle somme parziali
- 9-11 -> infine inserisce nell'array *B* gli elementi in modo ordinato

#### Links