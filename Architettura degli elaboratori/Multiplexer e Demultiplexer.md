### Multiplexer (MUX)
>Un multiplexer (indicato con MUX) e' un circuito combinatorio che presi $2^{n}$ input restituisce 1 solo output. L'output dipende dagli input e dai bit di selezione. Per  $2^{n}$ input ci sono $n$ bit di selezione

![[Pasted image 20231202113157.png]] 
La tavola della verita' e' come segue:
```
S0  S1  Y
 0   0  I0
 0   1  I1
 1   0  I2
 1   1  I3
```

#### Vantaggi 
1. **Salvataggio dello spazio** -> canalizzano molti segnali in un canale solo, il che diminuisce lo spreco di spazio nei circuiti.
2. **Risparmio economico** -> con un multiplexer si risparmia perche' permette di implementare, da solo, una logica che altrimenti avrebbe richiesto piu porte
3. **Risparmio di tempo** -> dovendo collegare meno parti si ha un circuito meno intricato e quindi piu efficiente
#### Svantaggi 
1. **Numero limitato di ingressi** -> chiaramente un multiplexer ha ingressi limitati
2. **Complessita' di controllo** -> al crescere degli input, crescono anche i bit di selezione e quindi per circuiti di grandezza elevata il flusso di controllo puo complicarsi
3. **Utilizzo di corrente** -> purtroppo i multiplexer consumano piu corrente delle porte normali

### Demultiplexer (DEMUX)
>Un demultiplexer (indicato con DMUX) e' un circuito combinatorio (duale di MUX) che preso 1 input restituisce $2^{n}$ output. Come per il multiplexer la scelta dell'output dipende dai bit di selezione. Per $2^{n}$ output ci sono $n$ bit di selezione

![[Pasted image 20231202114751.png]]
La tabella della verita' e' definita come segue: 
```
S0  S1  O
0   0   O0
0   1   O1
1   0   O2
1   1   O3
```

#### Links
[[Half Adder e Full Adder]]