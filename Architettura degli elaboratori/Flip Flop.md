>I flip flop sono dei circuiti sequenziali (latch) regolati da un **clock** cioe' un segnale che li rende temporizzati. Un flip flop e' un circuito **sincrono**

### Flip Flop SR
>Un flip flop SR si presenta come un latch D, tranne per il fatto che al posto di D ci sono S e R e al posto dell'enable c'e' il **clock**. Il dato in uscita viene cambiato solo quando il clock e' nello stato attivo

![[Pasted image 20231202204741.png]]
La tabella di verita' e' definita come segue
```
S  R  Q  !Q
0  0  0   1  --> memorizza
0  1  0   1  --> reset
1  0  1   0  --> set
1  1  INDEFINITO
```

### Flip Flop JK
>Il flip flop JK e' un circuito che implementa una soluzione al caso S=R=1 dei flip flop SR

![[Pasted image 20231202205328.png]]

Il flip flop JK funziona esattamente come il flip flop SR nella maggior parte dei casi, l'unica differenza e' nel caso J=K=1:

>Nel caso J=K=1 si ha che gli input al circuito piu a destra avranno **necessariamente** come valori 0 e 1, poiche' nonostante i valori del clock, di J e di K, quelli di Q e !Q saranno sempre opposti

Tavola di verita'
```
J  K  Q  !Q
0  0  0   0
0  1  0   0  
1  0  0   1
1  1  0   1
0  0  1   1
0  1  1   0
1  0  1   1
1  1  1   0
```

### Flip Flop D
>Nei flip flop D l'output puo essere cambiato solo dopo lo stadio di salita del clock, se gli input cambiano in altri momenti tale cambiamento non riguardera' l'output

![[Pasted image 20231202211216.png]]

### Flip Flop Edge Triggerd
>E' un flip flop nel quale, ad ogni cambio di stadio del clock viene attivato. La differenza con il flip flop D sta nel fatto che questo circuito si attiva anche durante stadio di discesa del clock

![[Pasted image 20231206114934.png]]

==Vengono utilizzati per fare i buffer== 

#### Links 
[[Latch SR e Latch D]]
[[SRAM e DRAM]]
