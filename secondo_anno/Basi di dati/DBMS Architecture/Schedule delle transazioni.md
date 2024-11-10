>Uno **schedule** di transazioni $S$ e' una sequenza di azioni (*read*, *write*, *commit* and *abort*) prese da un insieme di transazioni. L'ordine di azioni in $S$ e' lo stesso dell'ordine nelle singole transazioni. Uno *schedule* rappresenta un'esecuzione cronologica di transazioni.

Esempio:
Date le seguenti transazioni su $A$, $B$ e $C$ che sono oggetti del database, definiamo le seguenti transazioni:
- $T_1$ -> read$_1$($A$), write$_1$($B$), read$_1$($C$), write$_1$($C$)
- $T_2$ -> read$_2$($B$), write$_2$($B$)

Un possibile *schedule* $S$ puo' essere il seguente
- $S$ ->  read$_1$($A$), write$_1$($A$), read$_1$($B$), write$_1$($B$), read$_1$($C$), write$_1$($C$)

Gli *schedule* permettono di descrivere esecuzioni alternate di transazioni concorrenti:
- **complete schedule** -> include *commit* o *abort* per ogni transazione coinvolta
- **serial schedule** -> per ogni transazione ogni operazione e' eseguita in modo consecutivo

## Serializable Schedule
>Un **Serializable Schedule** e' uno schedule il cui effetto su un database consistente e' garantito essere *identico* a quello di un *complete serial schedule*.

![[Pasted image 20241110204905.png]]

![[Pasted image 20241110204948.png]]

![[Pasted image 20241110205000.png]]

## Anomalie dell'interleaved execution
>Una **interleaved execution** di due transazioni consistenti e *commited* possono lasciare il database in uno stato di inconsistenza.

Possiamo definire 3 tipi di conflitti:
- **Write-Read Conflict** -> (anche chiamato *dirty read*) $T_2$ legge un oggetto scritto da $T_1$ ma quest'ultimo non ha ancora fatto commit
- **Read-Write Conflict** -> (anche chiamato *unrepeatable reads*) $T_2$ scrive  un oggetto letto da $T_1$ ma questo non ha ancora fatto commit
- **Write-Write Conflict** -> (anche chiamato *lost update*) $T_2$ scrive un oggetto scritto da $T_1$ ma questo non ha ancora fatto commit

$S_4$ nell'esempio sopra presenta un *write-read conflict*.

### Write-Read Conflict
>Date le seguenti transazioni $T_1$ e $T_2$ e lo schedule $S$:
>$T_1: \space A:= A+100, \space B:= B-100$
>$T_2: A:=A*1.06, \space B:= B*1.06$

![[Pasted image 20241110215131.png]]

$T_1$ scrive un valore in $A$ che potrebbe rendere il database inconsistente e tale valore e' poi letto da $T_2$.

**Problema**
>$A$ e' scritto da $T_1$ e letto da $T_2$ prima che $T_1$ faccia commit.


### Read-Write Conflict
>Date le seguenti transazioni $T_1$ e $T_2$ e lo schedule $S$:
>$T_1 : A:= A + 1$
>$T_2 : A:= A - 1$

![[Pasted image 20241110215452.png]]

Se $T_1$ ripete la lettura di $A$, otterra' un valore diverso.

**Problema**
>$A$ e' scritto da $T_2$ prima che $T_1$ faccia commit.


### Write-Write Conflict
>Date le seguenti transazioni $T_1$ e $T_2$ e lo schedule $S$:
>$T_1: A:=1000, \space B:=1000$
>$T_2: A:=2000, \space B:=2000$

![[Pasted image 20241110215711.png]]

I valori di $A$ e $B$ sono uguali alla fine di ognuna delle due transazioni.

**Problema**
>$A$ e $B$ hanno valori differenti alla fine dello schedule.

## Anomalie fantasma (phantom anomalies)
>Questo problema si verifica quando una transazione legge un oggetto in due punti diversi e si accorge che l'oggetto non e' piu' lo stesso.

![[Pasted image 20241110221256.png]]

## Transazioni Aborted
>In linea di principio ogni transazione *aborted* deve essere annullata, tuttavia questo e' impossibile in alcuni casi.

![[Pasted image 20241110221800.png]]

**Problema**
>$T_2$ legge il valore di $A$ che non dovrebbe aver letto, a causa di un *write-read conflict*.

**Soluzione non soddisfacente**
Anche $T_2$ dovrebbe fare *abort* ma questo violerebbe la **D**URABILITY della proprieta' [[Transazioni#ACID||ACID]], poiche' il suo risultato e' stato gia' salvato.

## Transaction Parameters
>Per fare in modo che vengano rispettate le clausole della proprieta' ACID il DBMS implementa i cosidetti **transaction parameter**.

**ACCESS MODE**
Imposta i permessi relativi al cambiamento delle tabelle nella transazione:
- **READ ONLY** -> permette di accedere alle tabelle in *sola lettura*
- **READ WRITE** -> permette di accedere alle tabelle in *lettura e scrittura*

**STATEMENT MODE**
Specifica l'azione da eseguire non appena la transazione termina.

**ISOLATION LEVEL**
Specifica come gestire le transazioni che modificano il database (questo torna utile nella gestione della concorrenza), classificando da *low* a *high*:
- **READ UNCOMMITED** -> la transazione richiede dei *lock* per l'oggetto che vado a scrivere ma nessun lock per la lettura; la transazione potrebbe non essere pronta per fare il commit di cambiamenti fatti da altre transazioni
- **READ COMMITTED** -> la transazione richiede dei *lock* per scrivere e dei **lock condivisi** per leggere; garantisce che ogni dato letto e' stato *committed* nel momento in cui viene letto
- **REPEATABLE READS** -> la transazione richiede *lock* per leggere e scrivere un qualsiasi oggetto del database e li rilascia solo quando viene eseguito il *commit*; i lock a livello di tabella non sono autorizzati a leggerli
- **SERIALIZABLE**-> come la precedente ma *includendo i lock a livello di tabella nella lettura*

![[Pasted image 20241110223518.png]]


## Concorrenza & Interleaving
>L'interleaving e' necessario e desiderabile per migliorare le performance, tuttavia non tutti i possibili schedule sono adatti. Alcune azioni devono subire *rollback* quando le transazioni sono *aborted*.

La domanda e', quali controlli devono essere fatti per evitare conflitti?

### Concurrency control approaches
Ci sono approcci diversi:
- RESTRICTIVE -> cerca uno schedule serializzabile che evita conflitti attraverso protocolli di *data locking*
- OPTIMISTIC -> esegue tutte le transazioni in modo concorrente controllando i conflitti prima di fare commit
- TIMESTAMPING -> assegna timestamp alle transazioni che hanno letto o scritto oggetti e confronta tali valori per determinare l'ordine delle operazioni nello scheduling

[[Concurrency Control Approaches]]
#### Links
[[DBMS Architecture]]
[[Transazioni]]
[[Concurrency Control Approaches]]
