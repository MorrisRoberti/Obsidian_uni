### Half Adder
>Un Half adder e' un circuito che prende in input 2 bit e restituisce in output la loro somma e il resto dell'operazione

La tabella di verita' e' fatta nel modo seguente:
```
A  B  SUM  CARRY
0  0   0     0 
0  1   1     0 
1  0   1     0
1  1   0     1
```

L'implementazione tramite porte logiche e' semplice: 
- SUM -> A e B che entrano in una XOR
- CARRY -> A e B che entrano in una AND

### Full Adder
>Un Full Adder e' un circuito che prende in input 3 valori (bit) e restituisce in output la somma e il resto dell'operazione

![[1-77.png]]

La tavola della verita' e' definita come segue:
```
A  B  C-IN  SUM  C-OUT
0  0   0     0     0 
0  0   1     1     0
0  1   0     1     0
0  1   1     0     1
1  0   0     1     0
1  0   1     0     1
1  1   0     0     1    
1  1   1     1     1
```

Il funzionamento e' analogo all'half adder solo che questa volta abbiamo un terzo bit che rappresenta il resto dell'operazione precedente, per capire meglio scomponiamo il full adder come sotto
![[4-34.png]]
Cosi' implementato si capisce che il primo half adder esegue una somma e il risultato viene dato come input al secondo half adder insieme all'addendo C-IN, il quale esegue la somma tra il risultato precedente (S) e C-IN. Per il riporto si esegue un'ulteriore somma tra i riporti dei due half adder, in questo modo riusciamo ad eseguire le somme bit-a-bit tra numeri con piu bit.

Facciamo un esempio:
```
Usiamo il seguente algoritmo in pseudocodice
	SUM1 = A + B
	C1 = CARRY

	SUM2 = C-IN + SUM1
	C2 = CARRY2

	C-OUT = C1 + C2 (qui il + e' un OR diversamente da quelli sopra)
dove CARRY1 e CARRY2 sono i resti delle operazioni di somma

Elenchiamo le righe della tavola di verita' sopra
1 -> SUM1 = 0 + 0, CARRY1 = 0, SUM2 = 0 + 0, CARRY2 = 0, C-OUT = 0 + 0
2 -> SUM1 = 0 + 0, CARRY1 = 0, SUM2 = 1 + 0, CARRY2 = 0, C-OUT = 0 + 0
3 -> SUM1 = 0 + 1, CARRY1 = 0, SUM2 = 0 + 1, CARRY2 = 0, C-OUT = 0 + 0
4 -> SUM1 = 0 + 1, CARRY1 = 0, SUM2 = 1 + 1, CARRY2 = 1, C-OUT = 0 + 1
5 -> SUM1 = 1 + 0, CARRY1 = 0, SUM2 = 0 + 1, CARRY2 = 0, C-OUT = 0 + 0
6 -> SUM1 = 1 + 0, CARRY1 = 0, SUM2 = 1 + 1, CARRY2 = 1, C-OUT = 1 + 1
7 -> SUM1 = 1 + 1, CARRY1 = 1, SUM2 = 0 + 0, CARRY2 = 0, C-OUT = 1 + 0
8 -> SUM1 = 1 + 1, CARRY1 = 1, SUM2 = 1 + 0, CARRY2 = 0, C-OUT = 1 + 0
```


#### Links