>La ROM (Read Only Memory) e' un tipo di memoria persistente che contiene informazioni essenziali per il funzionamento di un computer come: informazioni essenzialli per l'input/output (BIOS), il processo di avvio, i meccanismi di lettura e scrittura su periferiche e altre funzioni base.

Esistono 4 tipi fondamentali di ROM

### Mask ROM
>Le mask ROM sono dei circuiti che fanno passare la corrente in base ai fusibili sul chip

Una volta che una mask ROM e' stata creata non si puo' piu' riprogrammare.

### PROM
>Le PROM o *Programmable* ROM, sono dei circuiiti che, a differenza delle mask ROM sono prodotte con tutti i fusibili, quindi il programmatore puo programmare il loro comportamento bruciando o meno determinati fusibili.

**c'e' il rischio che possano essere cancellate se soggette a scariche di elettricita' statica**

### EPROM
>Le EPROM o *Erasable* PROM, sono circuiti che non solo possono essere programmati ma, tramite una piastra di quarzo e dei raggi UV, cancellate e riprogrammate in modo diverso

**C'e' il rischio che se vengono esposte a luce solare possano essere cancellate**

### EEPROM
>*Electrically* EPROM, come le EPROM possono essere cancellate e riprogrammate ma senza l'utilizzo di attrezzature speciali. Possono essere programmate elettricamente

**Questo tipo di ROM come le altre EPROM non puo' essere riprogrammato all'infinito ma ha un numero massimo di riprogrammazioni dovute anche all'usura dei materiali**

## Com'e' fatta?
>Una ROM e' composta da due parti: **Il decoder** e **la matrice**.

La definizione di decoder si puo' trovare qui [[Encoder e Decoder]], per quanto riguarda la matrice e' fatta come segue:
![[Pasted image 20231202233919.png]]
Il flusso generale e' definito nell'immagine sotto:
![[Pasted image 20231202234523.png]]

#### Interessante
- A differenza della memoria RAM, la ROM non e' volatile, questo significa che una volta tolta la corrente i dati rimarranno comunque memorizzati
- L'accesso in ROM e' piu lento di quello in RAM quindi molte volte i dati della ROM vengono copiati in RAM, in modo da essere accessibili + velocemente. Verranno cancellati dalla RAM al momento dello spegnimento (ma non dalla ROM)


#### Links