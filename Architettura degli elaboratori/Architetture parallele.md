### Potenza di calcolo
>Dagli anni 80 fino ai 2000 la potenza dei processori e' cresciuta esponenzialmente fino a che non si sono raggiunti limiti fisici, da li la strategia e' diventata avere piu' di un processore: **Multiprocessori** e **Cluster**

Si vuole raggiungere una maggiore velocita' facendo in modo che l'elaborazione venga divisa in piu' punti di elaborazione, nelle architetture multiprocessore questi sono detti **core**.

### Multiprocessori (multicore)
>Un'architettura **Multiprocessore** (o Multicore) e' un sistema nel quale sono presenti appunto piu' processori che consentono di eseguire **programmi paralleli**.

Le architetture multiprocessore attualmente sono implementate come **Multicore** poiche' all'interno dello stesso socket (collegamento del processore con la motherboard), sono presenti piu' core.
#### Attenzione
>E' importante notare che se si vuole sfruttare l'incremento di prestazioni del multi-threading il programma deve essere scritto in modo parallelo e non sequenziale. 

Se si esegue un programma sequenziale in modo parallelo non solo non si ha *speed-up* ma anzi, il tempo di esecuzione diventera' **molto piu' lungo**.

A livello di struttura abbiamo una cosa di questo tipo
![[Pasted image 20231213222025.png]]
Nell'immagine si vedono due cose: 
- i core di ogni processore sono nello stesso involucro (socket), questo consente una maggiore velocita'
- i due processori condividono lo stesso bus, quindi l'incremento di velocita' non potra' essere doppio, per dei limiti fisici

#### Hyper-Threading
>L'**Hyper-Threading** e' una tecnica che consiste nell'eseguire piu' istruzioni con un solo core, sfruttando dei **thread** virtuali (logici) per "simulare" la parallelizzazione.


#### Utilizzi comuni per le architetture multicore
- Database -> C'e' il bisogno di eseguire molti task contemporaneamente
- Analitycs -> Gestione dei big data
- Cloud -> Nei Cloud l'utilizzo di processori multicore e' fondamentale per la scalabilita'
- Visualizzazione -> Applicazioni grafiche, rendering di dati etc.
#### Links 
[[Tassonomia di Flynn]]
[GPU e GPGPU]