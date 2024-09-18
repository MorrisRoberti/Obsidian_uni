>Un grafo **orientato** (o *diretto*) e' un grafo in cui gli archi hanno una direzione, quindi si puo' identificare il vertice da cui parte e il vertice in cui arriva
![[Pasted image 20240628120400.png]]
- Nei grafi orientati, $\left(u,v\right)\ne\left(v,u\right)$ 
- In $\left(u,v\right)$ diciamo che, l'arco **esce** da $u$ ed **entra** in $v$
- Se esiste un arco tra due vertici diciamo che questi sono **adiacenti** (non e' sempre simmetrica)
### Grado di un vertice
Possiamo classificare 3 categorie di gradi:
- Grado **uscente** -> e' il numero di archi che escono da un determinato vertice
- Grado **entrante** -> similmente a sopra e' il numero di archi che entra in un determinato vertice
- **Grado** -> e' la somma del grado uscente e entrante

### Cappi
>Nei grafi orientati possiamo avere cicli di lunghezza 1, questi sono detti **cappi**

![[Pasted image 20240628122755.png]]

>Un grafo **orientato** e **senza cappi** e' detto **semplice**.

### Grafi fortemente connessi
>Un grafo orientato si dice **fortemente connesso** quando due vertici qualsiasi sono raggiungibili l'uno dall'altro

Le **componenti fortemente connesse** di un grafo orientato sono le classi di equivalenza dei vertici secondo la relazione "sono mutualmente raggiungibili"
![[Pasted image 20240628123234.png]]
Nell'immagine sopra i due rettangoli denotano le componenti fortemente connesse.

#### Links