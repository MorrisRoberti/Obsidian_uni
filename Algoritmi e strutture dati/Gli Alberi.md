>Un **albero** e' una struttura dati di forma arborescente composta da 2 elementi fondamentali: *radice* e *figli*.

In un albero possiamo determinare alcuni componenti in base a ruoli specifici:
- *root* -> nodo che non ha *parent*
- *parent* -> nodo che ha uno o piu *children*
- *child* (*children* al plurale) -> qualsiasi nodo che abbia rapporto con un nodo *parent*
- *leaf* (*leaves* al plurale) -> nodi senza *children* (sarebbero i nodi finali dell'albero)

Sull'albero possiamo denotare dei concetti che saranno fondamentali in futuro:
- **profondita'** -> e' la distanza che ho tra un nodo e la *root*
- **branch** -> e' il percorso dal nodo x alla *root* definito dalla *profondita'*
- **livello** -> insieme dei nodi ad una data *profondita'*
- **altezza** -> *profondita'* massima dell'albero

### Sottoalberi
>Un **sottoalbero** e' semplicemente un albero ricavato a partire da una *root* che e' un semplice nodo di un altro albero

Come sotto vengono usati 2 e 3 per definire i sottoalberi sinistro e destro (che saranno utili poi)
![[Pasted image 20240403123719.png]]


#### Links
[[Alberi Binari]]