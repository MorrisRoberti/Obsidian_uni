Ci sono approcci diversi:
- **RESTRICTIVE** -> cerca uno schedule serializzabile che evita conflitti attraverso protocolli di *data locking*
- **OPTIMISTIC** -> esegue tutte le transazioni in modo concorrente controllando i conflitti prima di fare commit
- **TIMESTAMPING** -> assegna timestamp alle transazioni che hanno letto o scritto oggetti e confronta tali valori per determinare l'ordine delle operazioni nello scheduling

## Restrictive
>Il DBMS deve assicurare **l'assenza di conflitti** e **il rollback di transazioni abortite**.

### Strict Two-Phase Locking (strict 2PL)
>Se una transazione vuole leggere o scrivere un oggetto deve  **richiederne l'accesso esclusivo**. Dopo il rilascio di un lock una transazione non puo' richiederne di nuovi. La transazione rilascia tutti i suoi accessi esclusivi quando fa *commit*.

La *Strict 2PL garantisce serializzabilita'* in particolare:
- se le transazioni accedono a diversi oggetti possono essere tranquillamente *interleaved*
- altrimenti se due transazioni vogliono accedere allo stesso oggetto e almeno una transazione vuole modificarlo, devono essere eseguite in serie

**IMPORTANTE**
>Il **lock manager** tiene traccia, per ogni oggetto del database degli accessi esclusivi ad una *lock table*.

#### Deadlock Prevention
>Un *locking-based concurrency control* puo' causare **deadlocks** che devono essere evitati o risolti dal DBMS che di solito assegna una **priorita' ad ogni transazione** in base al tempo di inizio.

Se $T_i$ richiede un lock di proprieta' di $T_j$, il lock manager potrebbe implementare una di queste due *policy*:
- **Wait-Die** -> se $T_i$ e' la transazione piu' vecchia, allora aspetta; altrimenti $T_i$ viene disattivata e riattivata successivamente con un delay casuale ma con lo stesso timestamp
- **Wound-Wait** -> se $T_i$ e' la transazione piu' vecchia, $T_j$ e' disattivata e riattivata successivamente con un delay casuale ma con lo stesso timestamp, altrimenti $T_i$ aspetta

#### Deadlock Detection & Resolution
>Se i *deadlock* non sono frequenti, allora un DBMS puo' lasciarli avvenire e risolverli quando si verificano invece di adottare una *policy* per prevenirli.

Il DBMS puo' adottare uno dei due approcci piu' comuni:
- Il lock manager mantiene una struttura chiamata **waits-for-graph** che usa per identificare dei **deadlock cycles**, il grafo e' periodicamente analizzato e i deadlock cycles sono risolti abortendo alcune transazioni
- Se una transazione aspetta per un periodo di tempo superiore di un dato **timeout** allora il lock manager da per scontato che la transazione sia in *deadlock* e quindi viene abortita

## Optimistic
>In un approccio **ottimistico** si prevede che non ci siano conflitti tra le transazioni, o comunque che siano molto rari.

### Validation Approach
>Un approccio ottimistico e' quello della **validazione** in cui le transazioni sono autorizzate ad accedere ai dati senza lock e, al momento giusto, controlla che le transazioni si siano comportate in modo seriale.

Le transazioni sono eseguite in 3 fasi:
- **Read** -> la transazione e' eseguita leggendo i dati dal DBMS e scrivendo in un'area privata
- **Validation** -> prima del commit, il DBMS controlla che non ci siano stati conflitti; se ci sono stati, fa l'abort della transazione e la riavvia automaticamente
- **Write** -> se la validazione va a buon fine, i dati scritti nell'area privata sono copiati nel DBMS

## Timestamping
>Il **timestamping** e' un altro approccio ottimistico che assegna ad ogni transazione il timestamp $TS$ del suo inizio.

Per ogni operazione $a_i$ eseguita da $T_i$:
- Se l'operazione $a_i$ va in conflitto con l'operazione $a_j$ eseguita da $T_j$ e $TS_i \lt TS_j$ allora $a_i$ deve essere eseguito prima di $a_j$
- Se un'operazione eseguita da $T$ viola tale ordine la transazione $T$ viene abortita e riavviata con un $TS$ piu' grande

#### Links
[[DBMS Architecture]]
[[Transazioni]]
[[Schedule delle transazioni]]