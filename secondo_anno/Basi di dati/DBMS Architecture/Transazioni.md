>Una **transazione** e' un insieme di operazioni atomiche che vengono effettuate sul db in modo consistente. Possono essere confermate (*commit*) o rifiutate (*rollback*).
### Sintassi MySQL
Le transazioni hanno varie keyword:
- `START TRANSACTION;` -> Indica che da quel punto in poi le query scritte saranno le operazioni (*atomiche*) di quella transazione
- `COMMIT;` -> Le query dall'inizio della transazione a questa keyword sono state eseguite e si accettano le modifiche
- `ROLLBACK;` -> Come `COMMIT` ma le modifiche vengono rifiutate

```mysql
START TRANSACTION;
SELECT * FROM table;

ALTER TABLE table DROP COLUMN col1;
COMMIT;
```

Supponiamo di avere due tipi di operazioni che possono essere svolte in una transazione:
- **read(X)** -> legge un oggetto del DB chiamato $X$
- **write(X)**-> scrive un valore nell'oggetto del DB chiamato $X$

### Problemi delle transazioni
>In generale le transazioni presentano due tipi di problemi: *esecuzione concorrente* e *crash recovery*.

Le motivazioni dietro tali problemi sono semplici:
- *concurrency* -> si vuole l'esecuzione concorrente delle transazioni perche' gli accessi al disco sono lenti e creano bottleneck con la CPU, quindi vogliamo eseguire piu' transazioni in concorrenza per tenere la CPU sempre occupata -> **il problema** e' che l'utente non deve percepire tale concorrenza
- *crash recovery* -> possono verificarsi eventi imprevisti che fanno terminare le transazioni in modo in aspettato -> **il problema** si verifica in quanto il DBMS deve assicurare che le altre transazioni non siano intaccate e che lo stato di consistenza del database rimanga inalterato

## ACID 
>Per assicurare la corretta esecuzione concorrente e il crash recovery, ogni transazione deve aderire alla convenzione **ACID**.

- **A**TOMICITY -> una transazione e' un'unita' atomica le cui operazioni vengono tutte eseguite o non ne viene eseguita nessuna. Non ci puo' essere una transazione parzialmente completata
- **C**ONSISTENCY -> tutte le transazioni devono mantenere il database consistente, cioe' devono rispettare i suoi vincoli
- **I**SOLATION -> ogni transazione deve sembrare di essere eseguita come se nessun'altra transazione sta venendo eseguita allo stesso tempo
- **D**URABILITY -> una volta che la transazione ha apportato modifiche al database ed e' stata *committed*, tali cambiamenti non devono mai essere persi a causa di crash successivi

#### Consistency & Isolation
>La **consistenza** deve essere assicurata dall'utente che definisce la transazione. L'**isolazione** in relazione ad altre transazioni viene garantita assicurando che il risultato dello scheduling e' lo stesso dell'esecuzione sequenziale delle transazioni.

**ATTENZIONE**
Il DBMS non garantisce che le transazioni vengano eseguite in un ordine preciso.

Durante l'esecuzione di una transazione e' possibile che il database arrivi a situazioni di inconsistenza, questo non e' un fatto allarmante in quanto e' importante che, il database sia consistente quando *la transazione termina*.
#### Atomicity & Durability
Le transazioni possono essere abortite nei seguenti casi:
1. **Anomalia interna** -> causata dall'esecuzione, in questo caso il DBMS stoppa la transazione
2. **Condizioni di eccezione** -> individuata dalla transazione che quindi si auto-sospende
3. **Crash di sistema** -> per esempio uno spegnimento anomalo a seguito di un black-out oppure un crash dovuto da un errore del software o dalla rete

>Una transazione *aborted* puo' lasciare il database in uno stato di inconsistenza, il DBMS garantisce **atomicita'** attraverso un *log file di tutte le operazioni* che sono state effettuate; se un problema di quelli sopra si verifica, il DBMS controlla il log file ed effettua un *rollback* all'ultimo stato consistente precedente all'*abort*. I log file garantiscono anche **durabilita'**.


#### Links
[[Database & DBMS]]
[[Schedule delle transazioni]]