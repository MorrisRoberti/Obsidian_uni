Ci sono 3 modi per rappresentare un numero negativo in binario, qui sono elencati dal "peggiore" al "migliore", anche se in generale vengono usati tutti e 3 per cose diverse.

### Modulo e segno
>Per codificare un numero tramite modulo e segno basta aggiungere, prima del MSD (most significative digit) un 1 se il numero e' negativo o uno 0 se il numero e' positivo.

### Complemento a1
>Se il numero da rappresentare e' negativo lo complemento, cioe' trasformo gli 1 in 0 e viceversa

### Complemento a2
>Se il numero e' negativo faccio il complemento a1 e al risultato aggiungo 1

#### ATTENZIONE
Nel complemento a1 e complemento a2 si deve stare attenti al numero di bit che si usa per rappresentare, perche' andranno complementati anche quelli.


#### Links

