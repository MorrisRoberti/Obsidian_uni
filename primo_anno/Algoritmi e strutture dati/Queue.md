>Una **coda** e' una struttura dati di tipo *FIFO(First In First Out)*, cioe' il primo elemento ad uscire e' il primo che e' entrato. Es. persone in fila alle poste, il primo ad arrivare e' il primo ad essere servito e quindi andarsene.

### Operazioni
- `enqueue(k)` -> inserisce l'elemento `k` in coda
- `dequeue()` -> rimuove e restituisce l'elemento in testa alla coda

Solitamente le code hanno due attributi:
- `queue.head()` indica l'elemento in testa 
- `queue.tail()` indica l'elemento in coda
![[photo_2024-06-24_16-52-29.jpg]]

**ATTENZIONE**
Come si vede nell'immagine sopra, le code sono implementate tramite array circolari, cioe' e' possibile avere `tail` < `head` (immagine c)

#### Links