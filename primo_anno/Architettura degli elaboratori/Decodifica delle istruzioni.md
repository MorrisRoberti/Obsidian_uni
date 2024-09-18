## ISA
>L'ISA (*Instruction Set Architecture*) e' il livello dell'architettura che definisce la codifica delle istruzioni (assembly) in linguaggio macchina (binario).

Quello che si vuole e' decodificare l'istruzione **assembly** in **linguaggio macchina** per far in modo che l'elaboratore possa eseguirla.

Esempio, ISA di un processore ARM:
![[arm-fundamentals-3-728-2152017444.jpg]]
## Decodifica

>La fase di decodifica delle istruzioni (**decode** nel ciclo FDE) si occupa di, ricevere l'istruzione e decodificarla, in modo da identificare gli eventuali comandi e operandi (solitamente registri).

In base all'architettura su cui siamo, la decodifica delle istruzioni cambia
### Logica cablata
>Inizialmente la decodifica delle istruzioni avvenne tramite la **logica cablata**, cioe' un decoder che riceve in input l'istruzione dall'IR e la decodifica mandandola alla ROM per restituire il comando corrispondente.

==La **logica cablata** e' un meccanismo complesso, rigido e difficilmente scalabile.== 

**CON IL PASSARE DEL TEMPO LA LOGICA CABLATA E' RITORNATA IN AUGE GRAZIE A DEI MECCANISMI DI VELOCIZZAZIONE** 
Vedi [[Pipeline]]

### Microprogrammazione
>La microprogrammazione e' un modo di risolvere i problemi di scalabilita' e rigidita' della logica cablata.

Vedi [[Microprogrammazione]]

### Istruzioni RISC
>Il formato delle istruzioni per le architetture RISC era minimale e di dimensione standard, per cui era facilmente decodificabile
![[Mips32_addi.svg.png]]
### Istruzioni CISC
>Il formato delle istruzioni nelle architetture CISC e' di lunghezza variabile e tendenzialmente maggiore di quello delle architetture RISC.

Tale complessita' aggiunta al numero di istruzioni elevato (istruzioni che poi non venivano effettivamente utilizzate) ha fatto si che a lungo andare i CISC venissero superati dalle architetture RISC


#### Links
[[Microprogrammazione]]