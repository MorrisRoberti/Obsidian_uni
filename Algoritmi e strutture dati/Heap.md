>Un **heap binario** e' una struttura ad *albero binario quasi completo*.

Un *albero binario quasi completo* e' un albero binario in cui tutti i livelli sono pieni tranne l'ultimo che puo' non esserlo del tutto. La cosa fondamentale e' che l'ultimo livello venga riempito da sinistra verso destra, quindi le eventuali foglie mancanti saranno nella parte destra.

#### Max Heap
>La proprieta' fondamentale di questi alberi e' la proprieta' di **max heap**, cioe':
>$$\forall nodo\ne root \Rightarrow A\left\lbrack parent\left\lbrack nodo\right\rbrack\right\rbrack\ge A\left\lbrack nodo\right\rbrack$$
>In buona sostanza significa che per ogni nodo che non sia la radice il suo valore dovra' essere minore o uguale al valore del nodo padre

### Implementazione
>Un **heap binario** puo' essere implementato utilizzando, oltre ai componenti standard per implementare gli alberi, altre funzioni quali: *length*, *heap_size* e *parent*.

Descriviamo le nuove funzioni:
- **length[A]** -> ritorna la dimensione massima dell'array contenente l'heap 
- **heap_size[A]** -> ritorna il numero degli elementi dell'heap
- **parent[i]** -> ritorna la posizione (cella dell'array) del *parent* del nodo *i*

**ATTENZIONE** 
Gli elementi vengono inseriti nell'array rappresentante l'albero in modo contiguo (per il discorso di prima dell'albero quasi completo).

### Operazioni
#### Max_heapify
>L'operazione di **max heapify** consiste nel sistemare i valori nell'albero per fare in modo che la proprieta' di *max heap* sia rispettata.

Idealmente -> confronta i valori con i loro figli *left* e *right* e se trova che sia minore di uno di questi lo scambia; fa questo ricorsivamente fino ad avere un heap che rispetti la proprieta' desiderata.
```
void max_heapify(A, i) {
	l = left[i]
	r = right[i]
	
	if ( l <= heap_size[A] && A[l] > A[i] ) 
		massimo = l
	 else
		massimo = i
		
	if ( r <= heap_size[A] && A[r] > A[massimo] ) 
		massimo = r
	
	
	if ( massimo != i ) {
		scambia A[i] <--> A[massimo]
		max_heapify(A, massimo)
	}
}
```
- 2-3 -> mette gli indici degli elementi sinistro e destro di *i* (che inizialmente sara' la radice) nelle variabili
- 5-8 -> fa un controllo per vedere se l'elemento sinistro e' fuori dall'albero, se non lo e' confronta l'elemento alla radice con l'elemento sinistro e mette il piu grande in *massimo* (qui *l'else* e' presente mentre sotto no perche' *massimo* ha bisogno di un valore per confrontarlo dopo)
- 10-11 -> fa la stessa cosa di sopra ma confronta direttamente con il valore in *massimo*
- 14-16 -> se *massimo* e *i* (la radice del sottoalbero) sono uguali vuol dire che e' ordinato, altrimenti li scambia e richiama se stessa sul sottoalbero in cui e' presente *massimo*

*Ricorrenza*: $T\left(n\right)=T\left(\frac23n\right)+\Theta\left(1\right)$
**Complessita'**: $O\left(\log n\right)$

#### Heap_sort
>L'**heap sort** e' un tipo di ordinamento che sfrutta la struttura dello heap per ordinare gli elementi.

Sfrutta le funzioni:
- **build_max_heap(A)** -> che preso un array di numeri casuale costruisce l'heap
- **max_heapify(A, i)** -> vedi [[#Max_heapify]]

*build_max_heap*
```
void build_max_heap(A) {
	heap_size[A] = length[A]
	for i = length[A] down to 1
		max_heapify(A, i)
}
```
- 2 -> dice quanto deve essere grande l'heap creato
- 3-4 -> posiziona gli elementi dell'array in modo che questi mantengano la proprieta' di [[#Max Heap]]

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
**Complessita'**: $O\left(n\log n\right)$

#### Links