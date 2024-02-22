Ci sono 3 modi per rappresentare un numero negativo in binario, qui sono elencati dal "peggiore" al "migliore", anche se in generale vengono usati tutti e 3 per cose diverse.

### Modulo e segno
>Per codificare un numero tramite modulo e segno basta aggiungere, prima del MSD (most significative digit) un 1 se il numero e' negativo o uno 0 se il numero e' positivo.

Nella codifica modulo e segno l'intervallo di numeri codificabili su $n$ bit e': **$\left\lbrack-2^{n-1}-1,2^{n-1}-1\right\rbrack$**
per questo motivo si avranno 2 zeri: -0, +0

| Num. intero base 10 | Num. intero base 2 modulo e segno |
| ---- | ---- |
| -3 | 111 |
| -2 | 110 |
| -1 | 101 |
| -0 | 100 |
| +0 | 000 |
| +1 | 001 |
| +2 | 010 |
| +3 | 011 |
|  |  |

### Complemento a1
>Se il numero da rappresentare e' negativo lo complemento, cioe' trasformo gli 1 in 0 e viceversa

### Complemento a2
>Se il numero e' negativo faccio il complemento a1 e al risultato aggiungo 1


Sia nel complemento a1 che nel complemento a2, su $n$ bit si ha un intervallo di valori codificabili del tipo: $\left\lbrack-2^{n-1},2^{n-1}-1\right\rbrack$

| Num. intero base 10 | Num. intero base 2 Complemento a 2 |
| ---- | ---- |
| -4 | 100 |
| -3 | 101 |
| -2 | 110 |
| -1 | 111 |
| 0 | 000 |
| +1 | 001 |
| +2 | 010 |
| +3 | 011 |
#### ATTENZIONE
Nel complemento a1 e complemento a2 si deve stare attenti al numero di bit che si usa per rappresentare, perche' andranno complementati anche quelli.


#### Links

[[Overflow]]
