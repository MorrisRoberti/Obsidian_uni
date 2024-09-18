>E' una specifica che serve per classificare le CPU in base alla loro capacita di parallelizzazione dell'esecuzione.

### Estendiamo le capacita' della CPU tradizionale
Vogliamo estendere in due strade: 
- La capacita' di elaborare **istruzioni** in parallelo
- La capacita' di elaborare **dati** in parallelo

![[Pasted image 20231220184257.png]]
### SISD 
>*Single Instruction Single Data*, quindi singoli processori che eseguono un'istruzione alla volta su un singolo stream di dati, sono quindi le macchine di Von Neumann

![[Pasted image 20231220184457.png]]
La velocita' delle architetture SISD e' limitata dalla velocita' di trasmissione dei dati.

### SIMD
>*Single Instruction Multiple Data*, una singola istruzione viene eseguita su piu'  *Data Streams*, le architetture di questo tipo vengono utilizzate in ambito scientifico, soprattutto per i calcoli su vettori e matrici.

![[Pasted image 20231220190116.png]]
==Richiede hardware dedicato== 

### MISD
>*Multiple Instruction Single Data*, utilizzano la stessa istruzione su piu' *Data Streams*. Al momento non sono utili piu' di tanto.

Esempio:$$Z=\sin\left(x\right)+\cos\left(x\right)+\tan\left(x\right)$$
Utilizzo lo stesso dato $x$ in piu' istruzioni diverse

![[Pasted image 20231220190825.png]]

==Non e' molto utilizzato attualmente poiche' e' difficile trovare applicazioni che si prestino bene ad essere decomposte in set di istruzioni separate==

### MIMD
>*Multiple Instructions Multiple Data*, utilizzano piu' istruzioni su diversi *Data Stream*, ricadono in questa classificazione le cosiddette architetture **multicore** nelle quali ogni core esegue un'istruzione diversa in parallelo, su dati diversi

![[Pasted image 20231220193821.png]]

Ci sono due modelli distinti di questo tipo di architettura
#### Modello a memoria condivisa
>Tutti i processori sono connessi ad una memoria globale via software o hardware.

#### Modello a memoria distribuita
>Ogni processore possiede la sua memoria specifica, per passare i dati tra i vari processori questi vengono mandati come messaggi.

Esempio sono i **Cluster**, cioe' processori connessi tra di loro tramite una rete locale, la manifestazione piu' recente del cluster computing e' il **cloud computing**.

#### Links
[[GPU e GPGPU]]