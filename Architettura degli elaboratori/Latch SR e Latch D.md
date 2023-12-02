>Un latch e' un circuito sequenziale la cui uscita al tempo corrente dipende dall'ingresso attuale e dall'uscita al tempo t-1

Possiamo distinguere due tipi di latch: SR e D.

### Latch SR
>Un latch Set-Reset (SR) e' un circuito sequenziale che ha due ingressi R e S e due uscite Q e !Q

Il latch SR (creato tramite NOR) e' strutturato nel seguente modo:
![[RS-with-NAND-gates-4.png]]
La sua tabella di verita' e' la seguente:
```
S  R  Q
0  0  stato precedente
0  1  0
1  0  1
1  1  0(invalido)
```

Spieghiamo i casi: 
1. E' lo stato di memorizzazione del latch SR, perche' mantiene l'output precedente (si puo provare ad assumere Q=1 o Q=0 e la cosa risulta evidente)
2. Questo e' lo stato di *Reset* nel quale l'output viene rimesso a 0
3. Dualmente a quello sopra lo stato di *Set* e' lo stato nel quale l'output viene messo a 1
4. L'ultimo e' uno stato che non avviene, perche' non si puo' avere un circuito contemporaneamente a *Set* e *Reset*

### Latch D
>Un latch D e' sostanzialmente un circuito sequenziale (tipo latch) l'ingresso e' uno solo e viene regolato da un bit di abilitazione chiamato *Enable*

![[d_ltch.png]]
Abbiamo due ingressi:
- D -> Ingressi
- Enable  -> rappresenta l'abilitazione degli ingressi

In sostanza il circuito a sx attiva gli ingressi al secondo alternativamente in base al valore di *Enable*.
Essendo che D entra una volta normale e una volta negato all'interno del circuito si avranno solo situazioni di *Set* e *Reset*

La tabella di verita' e' fatta come segue:
```
Enable  D  Q(n)    Q(n+1)
  1     0   x      RESET
  1     1   x       SET
  0     x   Q(n)    No change
```


### Vantaggi
1. **Semplicita'** -> I latch sono circuiti facili da implementare tramite le porte logiche
2. **Basso consumo** -> Consumano meno elettricita' di altri circuiti come i flip flop
3. **Basso costo**
4. **Velocita'** 

### Svantaggi
1. **No clock** -> non hanno un clock che sincronizza le operazioni quindi in alcuni contesti il loro comportamento potrebbe essere sconosciuto
2. **Non predicibili** -> alcune volte i latch potrebbero ritrovarsi in uno stato del tipo R=1, S=1 in cui la loro uscita e' impredicibile

#### Links
