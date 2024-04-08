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


#### Links