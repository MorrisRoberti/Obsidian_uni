In breve: 
- **Encoder** => gli encoder convertono $2^{n}$ linee di input in un codice con *n* bit;
- **Decoder** => i decoder convertono *n* bit in input in $2^{n}$ bit di output;

### Encoder
>Un **encoder** converte $2^{n}$ informazioni in input in *n* linee di output. Negli encoder e' attiva una sola linea di input per volta.

![[Pasted image 20231128232722.png]]
Le linee di input sono formate in questo modo: 
```
INPUT
D0 -> 1 0 0 0 0 0 0 0
D1 -> 0 1 0 0 0 0 0 0
D2 -> 0 0 1 0 0 0 0 0
D3 -> 0 0 0 1 0 0 0 0
D4 -> 0 0 0 0 1 0 0 0
D5 -> 0 0 0 0 0 1 0 0
D6 -> 0 0 0 0 0 0 1 0
D7 -> 0 0 0 0 0 0 0 1

OUTPUT
X  -> 0 0 0 0 1 1 1 1 
Y  -> 0 0 1 1 0 0 1 1
Z  -> 0 1 0 1 0 1 0 1
```
Questo significa che i possibili output saranno calcolati nel seguente modo
```
X = D4 + D5 + D6 + D7
Y = D2 + D3 + D6 + D7
Z = D1 + D3 + D5 + D7
```
Per cui **e' possibile realizzare un encoder tramite sole porte OR** codificando le uscite e gli ingressi come sopra.

**ATTENZIONE**: Puo' essere attivo un solo input per volta altrimenti il risultato e' *undefined*. Per ovviare a questa soluzione si e' deciso di implementare un meccanismo di priorita' (priority encoders).

#### Priority Encoders
>Un **encoder con priorita'** e' un encoder nel quale gli input hanno, appunto, delle priorita'. Quando piu' di un input e' attivo allo stesso tempo, viene preso in considerazione quello con la priorita' piu alta.

Consideriamo un encoder con 4 ingressi e 2 uscite:
- Quando tutti gli input sono a 0 il bit di validazione *v* e' 0, quindi gli output non sono utilizzati
- Quando e' presente *x* significa che non importa quale sia il valore (*don't care*)

```
INPUT
D0 -> 0 1 x x x
D1 -> 0 0 1 x x
D2 -> 0 0 0 1 x
D3 -> 0 0 0 0 1

OUTPUT
X  -> x 0 0 1 1
Y  -> x 0 1 0 1
V  -> 0 1 1 1 1
```

D3 e' quello con la priorita' piu alta => quando D3 e' alto, non importa quale sia il valore degli altri input, l'uscita sara' sempre 11.

### Decoder
>Un **decoder** fa il lavoro opposto dell'encoder, prende in input *n* linee e restituisce $2^{n}$ linee di output

Funziona nel seguente modo:
```
INPUT
X  -> 0 0 0 0 1 1 1 1 
Y  -> 0 0 1 1 0 0 1 1
Z  -> 0 1 0 1 0 1 0 1

OUTPUT
D0 -> 1 0 0 0 0 0 0 0
D1 -> 0 1 0 0 0 0 0 0
D2 -> 0 0 1 0 0 0 0 0
D3 -> 0 0 0 1 0 0 0 0
D4 -> 0 0 0 0 1 0 0 0
D5 -> 0 0 0 0 0 1 0 0
D6 -> 0 0 0 0 0 0 1 0
D7 -> 0 0 0 0 0 0 0 1
```
Implementato come segue: 
```
D0 = !X * !Y * !Z
D1 = !X * !Y * Z
D2 = !X * Y * !Z
D3 = !X * Y * Z
D4 = X * !Y * !Z
D5 = X * !Y * Z
D6 = X * Y * !Z
D7 = X * Y * Z
```


>Se colleghiamo l'uscita di un decoder all'entrata di un encoder otteniamo la funzione d'identita'

#### Links