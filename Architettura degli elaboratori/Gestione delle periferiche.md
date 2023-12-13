>Quello che si vuole fare e' far interagire il nostro elaboratore con un dispositivo esterno, che sia una tastiera, un CD o una chiavetta USB, per fare cio' esistono 3 metodi principali: **Protocollo di Handshaking**, **Interrupt driven I/O**, **DMA I/O**.

## Funzionamento di base
Per fare in modo che la CPU comunichi con dei dispositivi esterni e' necessario avere delle **interfacce** che possano gestire lo scambio di dati tra  le due parti, solitamente queste interfacce sono i **driver**.

Ogni dispositivo ha i suoi driver, che vengono installati sulla macchina (tipicamente al primo collegamento ma possono anche essere scaricati e installati manualmente), cioe' l'interfaccia usata dalla CPU per interagire effettivamente con il dispositivo. 

>Per dispositivi di uso comune quali mouse, tastiere, monitor etc. sono gia' presenti dei driver all'interno del SO.

La CPU comunica con l'interfaccia che e' esposta su una determinata **porta** della macchina, nella quale e' collegato il dispositivo.

### Protocollo di Handshaking
>Il protocollo di handshaking e' un protocollo che serve per la comunicazione tra la CPU e i device di I/O. Consiste nel mettere la CPU in attesa mentre il dispositivo elabora i dati da mandargli.

#### Funzionamento
1. Il dispositivo e' occupato ad elaborare i dati, quindi manda un messaggio **BUSY=1** alla CPU in *attesa* per comunicare che non e' pronto a mandare i dati
2. Una volta che il dispositivo ha finito di preparare i dati manda un messaggio di **BUSY=0** alla CPU ad indicare che i dati sono pronti
3. Quindi la CPU si riattiva e manda un nuovo dato sulla porta, insieme ad un messaggio **DATA_READY=1** e si rimette in *attesa*
4. A questo punto il dispositivo ritorna ad essere **BUSY** nel frattempo che il dato viene copiato e viene settato **DATA_READY=0**
5. Questo ciclo si ripete fintanto che la comunicazione non termina

#### Busy Waiting
>Il problema dell'handshaking e' il collo di bottiglia, cioe' la differenza di velocita' tra la CPU e i dispositivi. Per questa differenza la CPU impieghera' gran parte del tempo ad aspettare che il dispositivo sia pronto, questo rallentamento e' chiamato: **Busy Waiting**.

### Interrupt driven I/O
>L'interrupt driven e' un metodo per gestire i dispositivi che rimuove il **Busy Waiting** che si ha nel protocollo di Handshaking. Utilizza appunto gli interrupt come meccanismo alla base.

#### Funzionamento
1. La CPU esegue le sue operazioni normalmente, senza aspettare il dispositivo (no busy waiting)
2. Il dispositivo manda un *segnale di interrupt* con **BUSY=0** alla CPU per indicare che e' pronto
3. La CPU interrompe quello che sta facendo e gestisce l'interrupt
4. Alla fine della gestione manda setta **DATA_READY=1** e termina la gestione tornando a fare cio' che stava facendo prima dell'interrupt
5. Nel frattempo il dispositivo avra' **BUSY=1** fino a quando non finisce di elaborare il dato, quando ha finito rimette **BUSY=0** e il ciclo riparte

==Con questo metodo evitiamo che la CPU rimanga in attesa e facciamo aspettare il dispositivo==

#### Gestione della chiamata
>A questo punto il rallentamento dell'interrupt driven I/O e' la **gestione della chiamata** che nei trasferimenti di dati molto grandi e' inefficiente
### DMA (Direct Memory Address)
>La tecnica **DMA** prevede di utilizzare un **DMA Controller** che, tramite i bus gestisce il flusso di dati tra il dispositivo I/O e la memoria. Quando il dispositivo I/O avvia una richiesta, il DMA Controller la inoltra alla CPU, che definisce quanti dati vuole leggere, da che dispositivo e in che parte di memoria andarli a scrivere

==Con questo meccanismo la comunicazione viene standardizzata quindi e' possibile usare la stessa interfaccia per piu' dispositivi==

In piu' i dispositivi non comunicano piu' con la CPU ma direttamente con il DMA Controller che gestisce lo scambio di dati.
r
#### Links

