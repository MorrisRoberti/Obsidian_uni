>I **B-Trees** sono una struttura dinamica che ci aiuta ad indicizzare i dati mantenendo una *stratificazione di indici* proporzionata rispetto alla dimensione del file. Gestiscono lo spazio dei blocchi che utilizzano, bilanciando l'albero e facendo si che ogni blocco abbia *almeno il minimo numero di chiavi (n+1)/2* e *al piu' il massimo numero di chiavi n*. I **B+Trees** sono una variante specifica dei B-Tree.

## Regole dei B+trees
- Le **chiavi nei nodi foglia** sono *copie delle chiavi del data file* e sono distribuite da sinistra a destra
- Alla **radice** ci sono *almeno 2 puntatori*
- I nodi interni puntano ai blocchi del prossimo livello e almeno $\lceil{\frac{(n+1)}{2}}\rceil$ 
- Nelle foglie, l'ultimo puntatore punta al prossimo blocco foglia alla sua destra, almeno $\lceil{\frac{(n+1)}{2}}\rceil$  di questi devono essere usati e puntare a record di dati

## Nodo interno vs Nodo foglia
![[Pasted image 20241217174511.png]]

## Ricerca
>La complessita' per una ricerca in un B+Tree e'
>$$\log_{(n/2)}{N} \leq L \leq \log_{(n/2)}{N+1}$$
### Equality search
>Vogliamo effettuare una **equality search** cioe' vogliamo trovare nella nostra struttura quei record la cui chiave e' uguale ad una chiave data.

Cerchiamo il record con chiave $K = 40$
![[Pasted image 20241217180044.png]]
### Range Search
>Con la **Range Search** vogliamo trovare tutti i record con la chiave compresa nel range specificato.

Cerchiamo il record con chiave $K \gt 40$
![[Pasted image 20241217180820.png]]

## Inserimento
>L'inserimento di una chiave in un B+tree e' ricorsivo:
1. Scendendo nell'albero cerchiamo di trovare *la foglia giusta* per la chiave che vogliamo inserire e la inseriamo se c'e' spazio
2. Se non c'e' spazio allora dividiamo in due nodi la foglia e dividiamo le chiavi spostandole nei due nuovi nodi in modo tale che ognuno sia pieno a meta' o poco piu'di meta'
3. La divisione dei nodi compare nel livello superiore se la nuova coppia chiave-puntatore deve essere inserita ad un livello piu' alto. Possiamo ricorsivamente applicare questa strategia per inserire nel prossimo livello: se c'e' spazio inserisci, altrimenti dividi il nodo padre e risali nell'albero
4. Come eccezione, se proviamo ad inserire nella radice e non c'e' spazio, allora dividiamo la radice in due nodi e creiamo un nuovo nodo radice al prossimo livello piu' alto

**ATTENZIONE**
>Quando si divide un nodo interno, la chiave centrale non e' inserita in uno dei nuovi nodi ma solo propagata all'in su' verso la radice.

es
Vogliamo inserire la nuova chiave $K = 40$
![[Pasted image 20241217183845.png]]
Nel nodo foglia in cui vogliamo inserire la chiave non c'e' spazio, allora dobbiamo procedere allo split del nodo
![[Pasted image 20241217185054.png]]
Ora dobbiamo propagare la separazione ai nodi piu' in alto in modo da poter inserire la nostra chiave e ribilanciare l'albero
![[Pasted image 20241217185604.png]]

## Eliminazione
>In linea di principio anche l'eliminazione e' ricorsiva:
1. Cerchiamo la chiave da eliminare e la *eliminiamo dalla foglia*. **Non dobbiamo eliminare la chiave dai nodi intermedi**
2. Se la foglia ha ancora il numero minimo di chiavi allora siamo a posto
3. Altrimenti
	1. Se uno dei fratelli adiacenti al nodo ha piu' del numero minimo di chiavi, allora una coppia *chiave-puntatore* puo' essere spostata nel nodo. Le chiavi del nodo padre devono essere sistemate per mantenere le proprieta' dell'albero
	2. Altrimenti significa che i due fratelli adiacenti non hanno piu' chiavi del minimo permesso e possono essere unite. Dobbiamo aggiustare le chiavi del nodo padre. Se il padre ha ancora un numero di chiavi accettabile allora va bene, altrimenti dobbiamo applicare ricorsivamente l'algoritmo al padre
esempio 
Vogliamo eliminare la chiave $K = 7$
Innanzitutto cerchiamo la chiave nelle foglie come prima. Una volta trovata procediamo con l'eliminazione
![[Pasted image 20241217192038.png]]
E infine ribilanciamo l'albero
![[Pasted image 20241217192310.png]]
Adesso eliminiamo la chiave $K = 11$, uniamo i due nodi che da soli avrebbero meno del minimo numero di chiavi e infine ribilanciamo l'albero
![[Pasted image 20241217193345.png]]

#### Links
[[Indexes]]
[[Sequential File Index]]