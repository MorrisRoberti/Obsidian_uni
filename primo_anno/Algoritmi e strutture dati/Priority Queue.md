>Una **coda di priorita'** e' una struttura che serve a mantenere e gestire un insieme di elementi ciascuno con la propria priorita'. Solitamente viene implementata tramite [[Heap]].

### Tipologie
Possiamo implementare due tipi di **code di priorita'** basate rispettivamente su *max heap* e *min heap*:
- max_priority_queue
- min_priority_queue

>Una **max priority queue** viene utilizzata, ad esempio nella gestione dei processi.
### Operazioni
Dato un insieme di elementi *S* possiamo definire le seguenti operazioni:
- *insert(S, x)* -> inserisce *x* in S, ovvero $S=S\cup\left\lbrace x\right\rbrace$
- *maximum(S)* -> restituisce l'elemento con priorita' massima
- *extract_max(S)* -> elimina e restituisce l'elemento con la priorita' massima
- *increase_key(S, x, k)* -> aumenta il valore della priorita' di *x* ad un nuovo valore *k* (con *k* sempre >= x.key)

#### Links
[[Heap]]