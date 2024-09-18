Le conversioni di base servono (come dice il nome stesso) a trasformare un dato numero in base x nell'equivalente in base y.
## Regole

### Da base x a base 10
>Per trasformare un qualsiasi numero in base x nell'equivalente numero in base 10 e' necessario utilizzare il metodo posizionale

ad esempio:
$$123_{x}=?_{10}$$
si trasforma dando un peso al numero in base x partendo da dx e si fa la somma dei prodotti del numero moltiplicato per la base elevata al peso
$$1^22^13_{}^0=1\cdot x^2+2\cdot x^1+3\cdot x^0$$
La somma di questi sara' il numero convertito in base 10.

### Da base 10 a base x
>Per trasformare un numero in base 10 nell'equivalente in una qualche base x si deve utilizzare il metodo della divisione.

### Da base 2 a base 8/16
>Si prendono i bit a gruppi da x dove x e' il piu piccolo multiplo di 2 t.c. x>base (quindi 3 per la base 8 e 4 per la base 16), il risultato e' la concatenazione di questi.

### Da base 8/16 a base 2
>L'operazione di conversione da base 8 o 16 a base due e' la speculare di quella sopra. Si prendono le singole cifre del numero e si traducono in binario, poi si combinano.

### Da base 8 a base 16 (e viceversa)
>Semplicemente non esiste un modo diretto, quindi la cosa migliore da fare e' trasformare il numero in base 2 e poi nella base che si desidera.

### Nota speciale: conversione in virgola fissa
#### Da base 10 a base 2
>Si converte la parte intera come nella conversione normale, poi si moltiplica la parte decimale ricorsivamente per 2 fino a che il risultato non e' 0

esempio:
```
21,25

1. 21 = 10101
2. 0,25 * 2 = 0,5 -> prendo la parte intera 0
3. 0,5 * 2 = 1,0 -> prendo la parte intera 1
4. 0,0 * 2 = 0,0 -> da qui in poi saranno tutti 0
```

#### Da base 2 a base 10
> E' analoga a  quella intera tranne per il fatto che i numeri decimali avranno indice negativo decrescente man mano che si va verso dx

#### Links