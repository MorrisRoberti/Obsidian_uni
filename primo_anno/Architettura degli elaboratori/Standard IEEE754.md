>Lo standard IEEE754 e' uno standard utilizzato per codificare i numeri decimali in virgola mobile nel loro equivalente binario.

### Come funziona

>La regola generale e' che ogni numero binario che vogliamo rappresentare in notazione IEEE754 segue la formula: $$\left(1,M\right)\cdot2^{e}$$

**N.B.**
1 nella formula sopra indica che bisognera' avere un 1 come parte intera e la M come parte decimale

I numeri decimali a precisione singola (float) sono composti da 32 bit, in generale per convertire il numero si suddivide come segue:
1. Il **segno** della mantissa: 0 positivo, 1 negativo. (occupa il bit piu' a sinistra)
2. **L'esponente** (e) ci dice il range di numeri positivi e negativi che possiamo rappresentare con quei bit. (nel caso della precisione singola occupa 8 bit)
3. La **Mantissa** (M) rappresenta la parte decimale del numero. (occupa gli ultimi 23 bit)

### Da decimale a binario
I passaggi sono i seguenti:
1. Si converte il numero in binario (virgola fissa)
2. Si sposta la virgola di *e* posti a sx fino ad ottenere un numero di questo tipo $$\left(1,M\right)\cdot2^{e}$$ 
3. Si calcola l'esponente e si guarda il numero di bit che gli sono riservati (n), e si applica la seguente formula:$$k=\frac{2^{n}}{2}-1$$ dove *k* indica quanti numeri possiamo rappresentare, nel caso degli 8 bit si avra' *k*=127.
4. Una volta calcolato *k* si fa *k*+*e*, il numero che si ottiene dovra' essere portato in binario e diventera' il nostro esponente

Esempio
```
n = 8 bit -> 8 bit precisione singola
k = (2^n / 2) - 1 = 127 -> calcolo il k che mi dice quanti numeri posso rappresentare 

1. (13,25) = 1101,01 -> converto il numero in binario (virgola fissa)
2. 1,10101 * 2^3 -> mi sono mosso di 3 posizioni verso sinistra
3. 3 + k = 3 + 127 = 130 -> trovato l'esponente in decimale
4. 130 = 10000010 -> lo converto in binario

0 10000010 10101000000000000000000
|    |                      |
|  esponente (8 bit)    mantissa (23 bit)
segno ( 1bit)
```

### Da binario a decimale
Prendiamo come esempio il numero sopra
```
0 10000010 10101000000000000000000
```
per trasformare in decimale basta applicare la seguente formula:
$$\left(-1\right)^{s}\cdot\left(1,M\right)\cdot2^{e-k}$$
- *s* -> segno
- *M* -> mantissa
- *e* -> esponente
- *k* -> quanti numeri posso rappresentare (127 per precisione singola)

quindi applicando la formula abbiamo
```
1. (-1)^0 = 1 -> elevo il numero al segno
2. 1,1010100 -> prendo il risultato dell'operazione sopra a ci attacco la mantissa
3. 2^(130-127) = 3-> converto l'esponente in decimale e prendo il k 
4. prendo il numero 1,1010100 e gli faccio faccio fare 3 salti verso dx
5. 1101,01 -> converto in decimale e il gioco e' fatto
```


#### Links
[[Numeri binari negativi]]