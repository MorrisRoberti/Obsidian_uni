>Se sommiamo due numeri binari **in complemento a2** con lo stesso segno ed otteniamo un numero con segno diverso, siamo in presenza di un **overflow**

Di base **overflow** significa "sforare", quindi il significato dovrebbe essere abbastanza intuitivo: tramite un'operazione aritmetica tra numeri binari su *k* bit abbiamo sforato (verso l'alto o verso il basso) il range di numeri rappresentabili con *k* bit e quindi ci si ritrova all'estremo opposto.

esempio:
Su *n* bit abbiamo  un range di valori che va da $-2^{n-1}$ a $2^{n-1}-1$  quindi per *n = 4* possiamo rappresentare tutti i numeri da -8 a 7 

```
0001 + ---> 1
0111 = ---> 7
------
1111 -----> -8
```

Per vedere velocemente se c'e' stato un overflow basta confrontare i MSD degli operandi con quello del risultato, **se sono diversi siamo in presenza di un overflow**
Nel caso di sopra
```
|0|001 +
|0|111 =
--------
|1|111
```
Si puo' facilmente notare che sono diversi e quindi c'e' un overflow.


#### Links
