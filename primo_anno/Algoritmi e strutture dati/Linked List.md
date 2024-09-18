>Una **lista concatenata** e' una sequenza di elementi (solitamente nodi) che, oltre ai dati contengono *un puntatore* all'elemento successivo.

Le liste concatenate possono essere di due tipi:
- **Simply Linked List** -> ogni nodo punta solo al nodo successivo
- **Doubly Linked List** -> ogni nodo punta al nodo precedente e al successivo
![[photo_2024-06-24_17-10-09.jpg]]
- **Circular List** -> e' una *doubly linked list* ma il primo nodo e' collegato all'ultimo e viceversa
![[photo_2024-06-24_17-12-25.jpg]]
### Operazioni
Sia le liste semplici che doppiamente concatenate possiedono le seguenti operazioni:
- `search(k)` -> scorre la lista e cerca l'elemento `k`
- `insert(k)` -> inserisce l'elemento `k` nella lista (in testa o in coda in base all'implementazione)
- `delete(k)` -> rimuove l'elemento `k` dalla lista

>Le operazioni sovracitate possono avere complessita' diversa a seconda del tipo di lista e di come vengono implementate: ad esempio `insert` in una *simply linked list* avra' tempo $O\left(n\right)$ o $O\left(1\right)$ in base a se decidiamo di inserire in testa o in coda.

Solitamente nelle **simply linked list** se non ci sono particolari requisiti conviene inserire ed eliminare sempre in testa, per mantenere il tempo costante.

#### Links