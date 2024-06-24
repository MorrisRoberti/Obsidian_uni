$\Theta\left(n\right)$
$O\left(n\log n\right)$
$\Omega\left(n\log n\right)$ 
---
### Algoritmo
L'**heap sort** e' un algoritmo di ordinamento che sfrutta la struttura dello [[Heap]] per ordinare gli elementi. E' un algoritmo **in place** basato **su confronti**. Sfrutta la proprieta' di [[Heap#Max Heap]].

### Principio di base
La proprieta' degli **Heap** (che sia *max heap* o *min heap*) ci consente di stabilire una gerarchia degli elementi basata sul piu' grande, che sfrutta la struttura ad albero per definirne l'ordine.

In buona sostanza una volta che abbiamo gli elementi nel nostro heap chiamiamo iterativamente la **max_heapify** sugli elementi dell'albero, in modo da far salire, di volta in volta, l'elemento piu' grande.

### Pseudocodice
Sfrutta le funzioni:
- **build_max_heap(A)** -> che preso un array di numeri casuale costruisce l'heap
- **max_heapify(A, i)** -> vedi [[Heap#Max_heapify]]

*build_max_heap*
```
void build_max_heap(A) {
	heap_size[A] = length[A]
	for i = length[A] down to 1
		max_heapify(A, i)
}
```
- 2 -> dice quanto deve essere grande l'heap creato
- 3-4 -> posiziona gli elementi dell'array in modo che questi mantengano la proprieta' di [[Heap#Max Heap]]

*heap_sort*
```
void heap_sort(A) {
	build_max_heap(A)
	for i = length[A] down to 2 
		scambia A[1] <--> A[i]
		heap_size[A] = heap_size[A]-1
		max_heapify(A, 1)
}
```
- 2 -> costruisce l'heap con l'array passato in input
- 3-5 -> itera sull'array al contrario e di volta in volta scambia l'ultimo elemento e il primo e diminuisce la dimensione dell'heap
- 6 -> lancia *max_heapify* su ogni elemento per mantenere ordinati i sottoalberi
#### Links
