>Per fare in modo che vengano rispettate le clausole della proprieta' ACID il DBMS implementa i cosiddetti **transaction parameter**.

### ACCESS MODE
>Imposta i permessi relativi al cambiamento delle tabelle nella transazione:
- **READ ONLY** -> permette di accedere alle tabelle in *sola lettura*
- **READ WRITE** -> permette di accedere alle tabelle in *lettura e scrittura*

### STATEMENT MODE
>Specifica l'azione da eseguire non appena la transazione termina.

### ISOLATION LEVEL
Specifica come gestire le transazioni che modificano il database (questo torna utile nella gestione della concorrenza), classificando da *low* a *high*:

**READ UNCOMMITTED** 
>La transazione richiede dei *lock* per l'oggetto che vado a scrivere ma nessun lock per la lettura; quindi una transazione puo' leggere dati che sono stati modificati da altre transazioni non ancora *committed* -> adatta a situazioni in cui **l'efficienza e' critica**, e ci si puo' assumere il rischio di inconsistenza.


**READ COMMITTED**
>La transazione richiede dei *lock* per scrivere e dei **lock condivisi** per leggere; garantisce che ogni dato letto e' stato *committed* nel momento in cui viene letto.


**REPEATABLE READS** 
>La transazione richiede *lock* per leggere e scrivere un qualsiasi oggetto del database e li rilascia solo quando viene eseguito il *commit*; i lock a livello di tabella non sono autorizzati a leggerli.


**SERIALIZABLE**
>Come la precedente ma *includendo i lock a livello di tabella nella lettura*.

![[Pasted image 20241110223518.png]]

#### Links
[[Transazioni]]
[[Schedule delle transazioni]]