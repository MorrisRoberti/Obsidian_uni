>Un **sequential file index** e' un indice che viene creato per ottimizzare l'accesso ai dati in un file sequenziale. In pratica e' una struttura che ci aiuta a trovare rapidamente un record all'interno di un file sequenziale.

![[Pasted image 20241216224554.png]]
Ogni *chiave di ricerca* nell'*Index File* ha un puntatore al record del *Sequential File* e la chiave di ricerca e' la *primary key* della relazione.

## Classificazione degli indici
- Un **primary** index su un insieme di attributi e' un indice che include la primary key, e i dati indicizzati sono ordinati sugli stessi attributi. Altrimenti e' **secondary**
- Un **dense** index ha almeno una *search key* per ogni chiave del data file. Altrimenti l'indice e' **sparse**
- Un indice e' **clustered** se l'ordine dei record riflette (e' lo stesso o e' simile) l'ordine delle label. Altrimenti l'indice e' **unclustered**

esempi
**DENSE & CLUSTERED**
![[Pasted image 20241216224950.png]]

**SPARSE & CLUSTERED**
![[Pasted image 20241216225013.png]]
>Lo spazio richiesto per un *indice sparso* e' inferiore a quello richiesto da un *indice denso*.

**SECONDARY, DENSE & UNCLUSTERED**
![[Pasted image 20241216225055.png]]
>Gli *indici unclustered* sono meno efficienti: ci sono 3 record con valore 20 sono immagazzinati in blocchi diversi.

## Indexing di piu' livelli
>E' possibile indicizzare degli indici, in modo da ridurre il numero di blocchi utilizzati per immagazzinare gli offset dei record.

![[Nuovo progetto 1.png]]

#### Links
[[Indexes]]