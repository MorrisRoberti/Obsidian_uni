$\Theta\left(n\log n\right)$
$O\left(n\log n\right)$
$\Omega\left(n\log n\right)$ 
---
### Algoritmo
>L'**heapsort** e' un algoritmo di ordinamento che sfrutta la struttura dello [[Heap]] per ordinare gli elementi. E' un algoritmo **in place** basato **su confronti**. Sfrutta la proprieta' di [[Heap#Max Heap]].

### Principio di base
La proprieta' degli **Heap** (che sia *max heap* o *min heap*) ci consente di stabilire una gerarchia degli elementi basata sul piu' grande, che sfrutta la struttura ad albero per definirne l'ordine.

Siccome sappiamo, per come e' definito max heap che il primo elemento e' sempre il piu' grande, possiamo scambiarlo con l'ultimo. Una volta fatto cio' possiamo decrementare l'heap_size perche' l'elemento piu' grande e' stato tirato fuori dall'heap ed e' nella sua posizione corretta.

Dopo aver scambiato l'elemento in posizione *1* con quello in posizione *i* non sappiamo se l'array rimane un heap, quindi per correttezza lanciamo max_heapify sulla "nuova radice".
Alla fine di questo procedimento avremo l'array ordinato.
### Pseudocodice
Sfrutta le funzioni:
- **build_max_heap(A)** -> vedi [[Heap#Build_max_heap]]
- **max_heapify(A, i)** -> vedi [[Heap#Max_heapify]]

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
- 2 -> costruisce l'heap con l'array passato in input (*complessita'* $O\left(n\right)$)
- 3-5 -> itera sull'array al contrario e di volta in volta scambia l'ultimo elemento e il primo (poiche' sappiamo che per come abbiamo definito il max heap il primo elemento e' sempre quello piu' grande) e diminuisce la dimensione dell'heap
- 6 -> lancia *max_heapify* su ogni elemento per mantenere ordinati i sottoalberi
#### Links
