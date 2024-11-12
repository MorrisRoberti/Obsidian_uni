>**L'architettura di un DBMS** e' divisa in 3 componenti principali: *query processor*, *resource manager* e *transaction manager*.

## Query Processor
>Il **Query Processor** e' il componente che si occupa di tradurre, interpretare ed eseguire le query dell'utente. E' il componente che **pesa di piu' sulle performance**.

Si divide in
- **Query Compiler** che traduce la query in un formato piu' schematico tramite i seguenti passi:
	- *parsing* -> prende la stringa iniziale e, dopo aver verificato la correttezza *sintattica* costruisce una struttura ad albero (parsing tree) con le varie parti della query
	- *preprocessing* -> controlla la *semantica* della query e trasforma le operazioni del parsing tree in operazioni di *algebra relazionale*
	- *optimization* -> trasforma la query originale in una sequenza di operazioni piu' efficiente (ottimisticamente la migliore)
- **Execution Engine** -> esegue la query finale interagendo con gli altri componenti del DBMS

## Resource Manager
>Solitamente i dati risiedono in memoria secondaria per garantirne la persistenza. Il **Resource Manager**  e' il componente che conosce la posizione e il modo di reperire i dati in memoria.

Si divide in
- **Index/File/Record Manager** -> e' la parte che conosce lo *schema* del database e le strutture che garantiscono accesso efficiente ai dati
- **Buffer Manager** -> e' la parte che si occupa di dividere la memoria principale in buffer in cui trasferire blocchi di memoria
- **Storage Manager** -> tiene traccia delle locazioni dei file sul disco e ottiene blocchi contenenti il file richiesto dal *buffer manager*

## Transaction Manager
>Solitamente, in un DBMS si vogliono gestire le [[Transazioni]], in modo tale da avere dei blocchi autocontenuti di query che vengono eseguite insieme. Tuttavia gestire le transazioni puo' essere complicato, percio' i DBMS si servono di un componente detto **Transaction Manager**.

Il *transaction manager* ha due compiti principali
#### Logging e Recovery
>Per assicurare la durabilita' e la stabilita' dei dati durante una transazione, il *transaction manager* implementa dei meccanismi che appunto garantiscano la consistenza dei dati in casi di crash o di collasso del sistema.

##### Log Manager
>Il **log manager** si occupa di scrivere separatamente sul disco ogni cambiamento che avviene nel database. Inizialmente scrive il log nei buffer e successivamente comunica con il *buffer manager* per essere sicuri che questi vengano poi scritti sul disco.

##### Recovery Manager
>Il **recovery manager** entra in azione quando si verifica effettivamente un crash, andando ad esaminare i cambiamenti del log e facendo tornare il database ad uno stato consistente.

#### Concurrency Control
>Le transazioni, nonostante appaiano separate avvengono in contemporanea, per tale motivo e' necessario gestirne la concorrenza. A questo scopo viene in aiuto il **Concurrency Manager** che assicura che le singole transazioni vengano eseguite in modo tale da far sembrare che queste siano state eseguite una dietro l'altra.

Un tipico gestore di concorrenza mantiene *bloccate* alcune porzioni del database per impedire che due transazioni diverse accedano agli stessi dati in modi disastrosi. Il manager (o meglio lo *scheduler*) blocca (*lock*) alcune parti del database in modo che non siano accessibili alle query.
##### Deadlock & Deadlock Resolution
>Le transazioni concorrono alle risorse attraverso i *lock* che lo scheduler fornisce, tuttavia, talvolta possono verificarsi situazioni spiacevoli in cui ogni transazione per procedere ha bisogno di accedere a qualcosa che ha un'altra transazione, questo genera situazioni di **Deadlock**.

>Per avere una buona **Deadlock Resolution** il *Transaction Manager* ha la responsabilita' di intervenire e cancellare una o piu' transazioni per far in modo che le altre possano procedere, tale cancellazione e' chiamata **rollback** o **abort**.

#### Links
[[Transazioni]]
[[Implementazione del JOIN]]
[[Concurrency Control Approaches]]
[[Schedule delle transazioni]]
[[Transaction Parameters]]
[[Crash Recovery]]