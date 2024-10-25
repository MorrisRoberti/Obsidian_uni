>Con il termine **risorse** si intende genericamente entita' disponibili in quantita' limitata e la cui mancanza potrebbe compromettere o limitare la funzionalita' del programma. Per questo motivo, il software deve necessariamente interagire con le risorse in modo corretto, evitando che alcune di esse vadano *perse* o compromesse.

L'interazione software con le risorse deve avvenire secondo uno schema predefinito:
1. **Acquisizione** della risorsa
2. **Utilizzo** della risorsa
3. **Rilascio** della risorsa

In particolare:
- La risorsa deve essere acquisita prima di essere usata (o rilasciata)
- Al termine del suo utilizzo la risorsa deve essere rilasciata
- Non e' lecito usare una risorsa dopo averla lasciata

Esempi di risorse:
- La **memoria ad allocazione dinamica** -> viene acquisita tramite l'uso dell'espressione *new* (magari effettuato indirettamente), utilizzata per leggere e scrivere valori (mediante *dereferenziazione del puntatore*) e infine rilasciata mediante l'uso della *delete* (magari effettuato indirettamenete); il mancato rilascio genera **memory leak** e potrebbe portare all'esaurimento della memoria disponibile; *l'accesso al dangling pointer* e' un esempio di uso dopo il rilascio
- i (descrittori dei) file del **file system** -> vengono acquisiti con l'operazione di apertura del file, utilizzati per leggere e/o scrivere sul file e infine rilasciati con l'operazione di chiusura
- i **lock** per l'accesso (condiviso o esclusivo) a risorse condivise -> l'acquisizione dei *lock* e' necessaria per una corretta gestione della condivisione delle risorse (da parte di piu' processi o thread); il mancato rilascio di un lock puo' causare *deadlock* cioe' un'interruzione totale del software o *starvation* cioe' la morte di una parte del programma per l'assenza di risorse
- Le **connessioni di rete** a server etc.

#### Links
[[Exception Safety]]