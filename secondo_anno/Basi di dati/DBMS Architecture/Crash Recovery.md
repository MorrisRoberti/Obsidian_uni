>Il **logging & recovery manager** di un DBMS deve assicurare: **Atomicita'** e **Persistenza**.

**Atomicita'** -> le operazioni eseguite da *non-committing transactions* vengono annullate (rollback)
**Persistenza** -> le operazioni eseguite da *committing transactions* devono sopravvivere ai crash di sistema 

## Algoritmo di recovery ARIES
>**ARIES** o *Advanced Recovery and Integrated Extraction System* e' un algoritmo di recovery che e' eseguito dal recovery manager quando il sistema va in crash.

**ARIES** e' utilizzato in DB2, SQL Server e altri DBMS.
Elenchiamo le tre fasi:
- **Fase di analisi** -> identifica le **dirty pages** (cioe' le pagine di memoria cambiate ma non ancora scritte) del buffer pool e le **transazioni attive** al momento del crash
- **Fase di redo** -> partendo da un dato **checkpoint** nel log file, ripete tutte le operazioni e porta il database allo stato in cui era al momento del crash
- **Fase di undo** -> **annulla le operazioni** di transazioni che erano attive al momento del crash ma che non erano state *committed*, nell'ordine opposto

#### Principi di ARIES
- **Write-Ahead Logging** -> ogni cambiamento fatto ad un oggetto del database deve essere prima registrato nel log file, poi questo deve essere scritto sul disco e la pagina corrispondente deve essere aggiornata
- **Repeating History During Redo** -> quando si riavvia dopo un crash il sistema e' riportato allo stato in cui era prima del crash; le operazioni delle transazioni ancora attive al momento del crash sono cancellate
- **Logging Changes During Undo** -> i cambiamenti apportati al database mentre vengono annullate le transazioni sono loggati per assicurare l'azione causante non venga ripetuta nell'eventualita' di riavvii o crash ricorrenti

## Log File
>Il **log file** tiene traccia di tute le azioni eseguite dal DBMS. Fisicamente e' organizzato in record che vengono memorizzati in memoria persistente che si presume sopravviva a crash o altri tipi di collasso. 

>I **log record** sono ordinati in sequenza con un unico id che e' il **Log Sequence Number** (*LSN*). L'*LSN* e' strettamente crescente e permette di trovare e di accedere a record.

La parte piu' recente del log file, la cosidetta **log tail** e' tenuta nei log buffer e periodicamente salvata nella memoria persistente. Il log file e i dati vengono scirti sul disco con gli stessi meccanismi.

Abbiamo alcune strutture per il logging:
- La **Dirty Page Table** tiene un registro di tutti gli id di pagine che sono state modificate ma non scritte e del primo *LSN* che ha causato lo "sporcamento" della pagina
- La **Transaction Table** tiene un registro di tutti gli id delle transazioni che sono attualmente in esecuzione e l'*LSN* dell'ultimo log entry

### Com'e' strutturato un log record?
La struttura convenzionale di un *log file record* e' la seguente:
$<LSN,\space Transaction ID,\space Page ID, \space Redo, \space Undo,\space Previous LSN>$

- $Transaction ID$ e $Page ID$ identificano rispettivamente **la transazione** e **la pagina**
- $Redo$ e $Undo$ contengono informazioni riguardo **i cambiamenti** che il log record salva e **come annullarli**
- $PreviousLSN$ e' una **reference al log record precedente** che e' stato creato **per la stessa transazione**; permette di fare **rollback** velocemente su una transazione abortita

### Creazione di un log record
Un record e' scritto nel log file per ognuno di questi eventi:
- **Page update** -> un record deve essere scritto nella memoria persistente prima di cambiare effettivamente i dati nella pagina; mantiene sia il vecchio che il nuovo valore della pagina per rendere possibili le operazioni di *undo* e *redo*
- **Commit** -> un record che traccia se la transazione e' completata con successo e se il log tail e' scritto nella memoria persistente
- **Abort** -> un record traccia una transazione abortita e l'undo della transazione inizia
- **End** -> dopo un'operazione di abort/commit alcune operazioni di finalizzazione sono necessarie, alla fine di queste un end record viene scritto
- **Undoing Operation** -> durante il recupero o mentre si fa l'undo, uno speciale tipo di record e' scritto, il **Log Compensation Record** (*CLR*); un CLR record non e' mai invertito e controlla se un'operazione ha gia' subito un undo

### Checkpoint
>Un **checkpoint** e' uno snapshot dello stato del database. I checkpoint riducono il tempo di recovery. Invece di dover navigare l'intero log file basta andare all'indietro finche' non troviamo un checkpoint.

ARIES crea checkpoint in 3 passi:
- Un **begin-checkpoint** record e' scritto nel log file
- Un **end-checkpoint** record, contenente sia la *Dirty Page Table* che la *Transaction Table* e' scritto nel log file
- Dopo che un *end-checkpoint* record e' scritto nella memoria persistente, un **Master Record** contenente L'LSN del *begin-checkpoint* record viene scritto in una locazione nota nella memoria persistente

Questo tipo di checkpoint e' chiamato **fuzzy checkpoint** ed e' economico in termini di performance. Non interrompe le normali operazioni del DBMS e non richiede la scrittura di pagine nel buffer pool.

#### Links
[[DBMS Architecture]]
[[Transazioni]]
[[Schedule delle transazioni]]
