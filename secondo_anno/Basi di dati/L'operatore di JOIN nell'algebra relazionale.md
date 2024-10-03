>L'operatore binario **join** nell'algebra relazionale, si occupa di correlare le tuple di relazioni diverse tramite un attributo con lo stesso nome.

L'operatore di join prende due relazioni e le unisce, lo schema della relazione risultante e' l'unione degli attributi degli schemi delle due relazioni. Ogni tupla e' prodotta combinando la tupla della relazione 1 alla tupla della relazione 2.

## Sintassi & Semantica
### Natural join
>Il **natural join** e' il piu' banale e prevede di fare appunto il *join* tra due relazioni, tramite **un attributo con lo stesso nome**. Lo schema della relazione risultante e' l'unione degli attributi delle due relazioni, e, ogni tupla viene prodotta combinando due tuple: una per ognuna delle due relazioni.

>La *sintassi* dell'operatore di join date le relazioni $R_1(X_1), R_2(X_2)$ e' la seguente:
>$$R_1 \bowtie R_2$$
>e' una relazione con attributi $X_1X_2$.

>La *semantica* dell'operatore join e':
>$$R_1 \bowtie R_2 = \lbrace{t \space on \space X_1X_2 \space|\space \exists t_1\in R_1 \space and \space \exists t_2 \in R_2 \space with \space t[X_1]=t_1 \space and \space t[X_2]=t_2}\rbrace$$

## Tipi di join

### Full join
>Nel **full join** ogni tupla appare nel risultato finale.

![[Pasted image 20240927153005.png]]

### "Non full" join
![[Pasted image 20240927153121.png]]

### "Empty" join
![[Pasted image 20240927153147.png]]

### Outer join
>L'**outer join** mette a *NULL* le righe che normalmente sarebbero scartate con un inner join. Ne esistono di 3 tipi.

#### Left Outer join
>Tiene tutte le righe di $R_1$ e, se una tupla $t$ di $R_1$ non trova corrispondenza in $R_2$ i valori degli attributi $\in R_2$ e $\notin R_1$ vengono messi come valori nulli in $t$.

![[Pasted image 20241003095937.png]]
#### Right Outer join
>Come il *left outer join* ma tiene le tuple di $R_2$ e mette a *NULL* quelle di $R_1$ senza corrispondenza.

![[Pasted image 20241003095955.png]]
#### Full Outer join
>Banalmente e' l'insieme di *left outer join* e *right outer join*, cioe' popola la relazione con le tuple delle due relazioni che hanno corrispondenza tra di loro e mette a *NULL* le altre. E' come se fosse un full join ma invece di scartare le tuple senza corrispondenza mettesse i valori non corrisposti a *NULL*.

![[Pasted image 20241003100010.png]]
### Theta join
>Come detto sopra, quando le due relazioni non hanno attributi in comune si procede a fare il prodotto cartesiano, ora questo assume un significato preciso quando combinato con l'operatore di selezione $\sigma$, infatti cio' che si vuole fare e' $\sigma_{cond} (R_1 \bowtie R_2)$, tale operazione si definisce **theta join**  e si indica nel seguente modo:
>$$R_1 \bowtie_{condition} R_2$$
>il predicato $condition$ e' solitamente espresso come congiunzione (*AND*) di relazioni binarie atomiche $A_1 \mathit{R} A_2$ dove $R$ e' un operatore di comparazione.


### Equi join
>Un *theta join* e' chiamato **equi join** se tutte le relazioni $R$ in $condition$ sono relazioni di equivalenza.

![[Pasted image 20240927161844.png]]
Ad esempio nel caso sopra il *theta join* viene utilizzato per mettere in join le due tabelle tramite due attributi con nomi diversi, cosa che non sarebbe stata possibile facendo semplicemente $R_1 \bowtie R_2$.

**ATTENZIONE**
>Come si puo' vedere, i valori degli attributi che vengono utilizzati per il join (Depth e Code) non vengono compattati in un solo attributo, ma si mantengono nella tabella finale.

## Dimensioni del risultato di un join
>Il risultato di un join tra $R_1$ e $R_2$ ha un numero di tuple:
>$$0 \leq \vert R_1 \bowtie R_2 \vert \leq \vert R_1 \times R_2 \vert$$
>Il caso $\vert R_1 \times R_2 \vert$ avviene quando $X_1 \cap X_2 = \emptyset$ , cioe' quando gli attributi delle relazioni sono tutti diversi.

Se il join coinvolge *una chiave di $R_2$* allora il numero di tuple risultanti e' tra 0 e $R_1$:
$$0 \leq \vert R_1 \bowtie R_2 \vert \leq \vert R_1 \vert$$
se il join coinvolge *una chiave di $R_2$* e *un vincolo di integrita'*, allora il numero di tuple e' $\vert R_1 \vert$:
$$\vert R_1 \bowtie R_2 \vert = \vert R_1 \vert $$
questo e' da specificare, perche' la nozione attuale di join ci dice che possiamo eseguire l'operazione anche senza attributi comuni, quindi il join dell'algebra e' piu' generico del join di SQL.

#### Links
[[Algebra relazionale]]