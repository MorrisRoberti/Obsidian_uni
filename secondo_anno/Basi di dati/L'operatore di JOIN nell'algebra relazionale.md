>L'operatore binario **join** nell'algebra relazionale, si occupa di correlare le tuple di relazioni diverse tramite un attributo con lo stesso nome.

L'operatore di join prende due relazioni e le unisce, lo schema della relazione risultante e' l'unione degli attributi degli schemi delle due relazioni. Ogni tupla e' prodotta combinando la tupla della relazione 1 alla tupla della relazione 2

## Sintassi & Semantica
>La *sintassi* dell'operatore di join date le relazioni $R_1(X_1), R_2(X_2)$ e' la seguente:
>$$R_1 \bowtie R_2$$
>e' una relazione con attributi $X_1X_2$.

>La *semantica* dell'operatore join e':
>$$R_1 \bowtie R_2 = \lbrace{t \space on \space X_1X_2 \space|\space \exists t_1\in R_1 \space and \space \exists t_2 \in R_2 \space with \space t[X_1]=t_1 \space and t[X_2]=t_2}\rbrace$$

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
>Tiene tutte le righe di $R_1$ e mette a *NULL* le righe di $R_2$ se non ci sono.

#### Right Outer join
>Come il *left outer join* ma tiene le righe di $R_2$ e mette a *NULL* quelle di $R_1$ senza corrispondenza.

#### Full Outer join
>Banalmente e' l'insieme di *left outer join* e *right outer join*, cioe' popola la tabella con le righe delle due tabelle che hanno corrispondenza e mette a *NULL* le altre. E' come se fosse un full join ma invece di scartare le tuple senza corrispondenza le mettesse a *NULL*.

### Theta join
>Come detto sopra, quando le due relazioni non hanno attributi in comune si procede a fare il prodotto cartesiano, ora questo assume un significato preciso quando combinato con l'operatore di selezione $\sigma$, infatti cio' che si vuole fare e' $\sigma_{cond} (R_1 \bowtie R_2)$, tale operazione si definisce **theta join**  e si indica nel seguente modo:
>$$R_1 \bowtie_{condition} R_2$$
>il predicato $condition$ e' solitamente espresso come congiunzione (*AND*) di relazioni binarie atomiche $A_1 \mathit{R} A_2$ dove $R$ e' un operatore di comparazione.


### Equi join
>Un *theta join* e' chiamato **equi join** se tutte le $R$ in $condition$ sono relazioni di equivalenza.

![[Pasted image 20240927161844.png]]



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