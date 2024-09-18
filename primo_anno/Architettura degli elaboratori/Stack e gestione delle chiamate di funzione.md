>Lo **stack** e' un'area di memoria **inaccessibile al programmatore** dedicata all'esecuzione di un programma e viene gestita **in automatico**.

E' una struttura di tipo **LIFO** (*Last In First Out*) con 2 operazioni:
- push -> inserisci un valore **in cima** allo stack
- pop -> rimuovi il valore **dalla cima** dello stack

### Chiamate di funzione
>Lo stack viene principalmente utilizzato dal processore per gestire le chiamate di funzione nel flusso di esecuzione di un programma.

Le chiamate di funzione sono effettivamente salti ad un blocco di istruzioni che si puo' trovare in una posizione completamente diversa della memoria (rispetto a quella dell'istruzione corrente). Quindi per accedere a tale area ed evitare di perdere la locazione del chiamante si utilizza **lo stack**.

Le chiamate di funzione a basso livello sono eseguite in questo modo:
- Quando la CPU vede un'istruzione "**CALL**" fa **push** della posizione attuale dell'istruzione e poi passa a gestire il codice nel blocco della funzione. 
- Alla fine del blocco della funzione sara' presente un'istruzione "**RET**" che fara' **pop** dello stack e restituira' il controllo al chiamante
- Una volta restituito il controllo, la CPU riprende il ciclo di esecuzione e passa all'istruzione successiva 

	Questo meccanismo consente al processore di gestire anche le chiamate annidate, fino a che lo stack non e' pieno

#### Meccanismo ad alto livello
>Ad alto livello quello che succede e' che, nel momento in cui chiamiamo una funzione, tutte le variabili che dichiariamo in modo **statico** vengono distrutte nel momento della return

#### Heap
>Se vogliamo fare in modo di preservare tali variabili anche dopo la fine della chiamata di funzione e' allocarle dinamicamente (in linguaggi simil-C si usa la parola *new*). In questo modo le variabili non verranno messe nello stack e distrutte alla fine dell'esecuzione ma verranno allocate in una parte della memoria accessibile al programmatore chiamata **Heap**.

#### Links
[[Gestione degli interrput]]
