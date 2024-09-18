>Per eseguire le istruzioni la CPU esegue diversi passi in modo ciclico, questo viene chiamato cliclo Fetch, Decode, Execute

Per poter capire il ciclo FDE e' necessario conoscere i componenti della CPU, si possono trovare qui: [[Struttura della CPU]].

### 1. Fetch
>La fase di *Fetch* e' un'operazione che prevede di prendere l'istruzione successiva che deve essere eseguita dal processore.

1. Per prima cosa abbiamo il **PC** che punta alla prossima istruzione da eseguire
2. Tramite il **BUS interno** passiamo il contenuto del **PC** al **MAR** che andra' in memoria RAM a recuperare l'indirizzo dell'istruzione puntata
3. Una volta trovata l'istruzione il **MDR** (o DTR) prende il contenuto della cella di memoria e tramite il **BUS interno** lo manda nell'**IR** che poi sara' pronto per la prossima fase

### 2. Decode
>La fase di *Decode* e' l'operazione successiva a quella di fetch nel quale l'istruzione presa viene decodificata

1. Una volta che l'**IR** contiene l'istruzione la **CU** la decodifica
2. Dopo aver decodificato l'istruzione viene fatto il cosidetto **fetch degli operandi** nel quale la CPU va a caricare i dati necessari (istruzione e dati) all'interno dei registri
3. Successivamente carica questi nella **ALU**

### 3. Execute
>La parte di *Execute* e' la parte finale, nella quale appunto la CPU esegue l'istruzione

1. Una volta che sono stati caricati tutti gli operandi all'interno della **ALU** questa esegue l'operazione
2. Al termine dell'operazione il valore del **PC** viene incrementato per puntare all'istruzione successiva

#### Links
[[Stack e gestione delle chiamate di funzione]]