>Ci sono due tipi di architettura predominanti quando si parla di CPU e queste differiscono per la complessita' delle istruzioni e sono **RISC** e **CISC**.

### RISC
>Le architetture RISC (*Reduced Instruction Set Architecture*) sono caratterizzate da poche istruzioni semplici, le quali vengono poi combinate per eseguire anche i compiti piu' complessi

#### Vantaggi
1. Le istruzioni sono piu' semplici quindi **la codifica e' piu veloce**
2. **Le istruzioni vengono eseguite piu velocemente**, poiche' sono minimali
3. Consumano **meno corrente**

#### Svantaggi
1. Per eseguire **compiti piu' complessi** si devono usare **piu' istruzioni**
2. Hanno bisogno di **piu memoria** per immagazzinare le singole istruzioni durante task complessi
3. Sono **piu' costosi**

### CISC
>Le architetture CISC (*Complex Instruction Set Architecture*) sono caratterizzate da un set di istruzioni complesse molto grande, per far in modo di eseguire un compito con una singola istruzione (es. ci sono processori in cui e' possibile copiare una lista in un'altra con una singola istruzione)

#### Vantaggi
1. **Codice piu snello**, poiche' con una sola istruzione e' possibile fare task complessi
2. **Gestione della memoria piu' efficiente**

#### Svantaggi
1. **Esecuzione piu' lenta**, poiche' le istruzioni sono complesse e quindi il processore ha bisogno di piu' tempo per la decodifica
2. Consumano **piu' corrente**


### Big-Endian e Little-Endian
>Le architetture CISC e RISC rappresentano i dati in modo differente. I due modi sono *Little-Endian* e *Big-Endian*.

Le architetture **RISC** immagazzinano i byte da sinistra a destra, **il byte piu' pesante si trova a sinistra** e tale organizzazione e' chiamate ==**Big-Endian (BE)**==.

Le architetture **CISC** immagazzinano i byte da destra a sinistra , **il byte piu' pesante si trova a destra** e tale organizzazione e' chiamate ==**Little-Endian (LE)**==.

![[Decimal-number_--1-.png]]

==ATTENZIONE==
L'ordine dei bit e' lo stesso, quello che cambia e' l'ordinamento dei **byte**.

Sono entrambe largamente utilizzate:
- BE -> Protocolli di networking
- LE -> PC

Nei linguaggi ad alto livello la questione LE o BE non ha piu un peso cosi' importante, dato che si lavora in un dominio piu' astratto, quindi il compilatore/interprete sottostante si occupera' di gestire l'eventuale conversione.

#### Links
[[Pipeline]]
[[Microprogrammazione]]
[[Decodifica delle istruzioni]]
