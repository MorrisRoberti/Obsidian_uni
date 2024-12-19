>L'Hashing e' una tecnica che permette di mappare una *search key* direttamente sull'ID della pagina (PID) contenente la pagina stessa. Gli **indici basati su hash** sono i migliori per **equality search**, tuttavia *non supportano in modo efficiente le range search*.

Possiamo distinguere due tipi di hashing:
- *static hashing* -> per dati *di dimensione fissa e immutabili* (ad esempio nei CD-ROM)
- *extensible and linear hashing* -> quando *sia dati che dimensione dei dati possono variare nel tempo*
Come per gli indici basati sugli alberi per la memoria secondaria, anche gli indici basati su hash utilizzano **blocchi di memoria per contenere i bucket**.

## Static Hashing
>L'**hashing statico** coinvolge $N$ *bucket* e una funzione hash, che mappa la *search key* nel range da 0 a $N-1$.

Nell'esempio seguente utilizzeremo $H_i$ funzioni di hash che ritornano i primi (o gli ultimi) $i$ bits della codifica binaria della chiave di ricerca.

Se un record ha una *search key* $K$, allora salviamo il record nel bucket numerato $H(K)$.

### Ricerca
La funzione di hash calcola l'indirizzo del bucket in cui il data record con la data *search key* ($K_2=1100$) si trova

![[Pasted image 20241218113839.png]]

### Inserimento
Ora proviamo ad inserire una nuova chiave $K3=1010$

![[Pasted image 20241218114213.png]]
>L'hashing statico non puo' cambiare il numero di bucket ma puo' "modificarne la dimensione" utilizzando una **catena di blocchi di overflow**. Una lunga catena di overflow bucket puo' *degradare le performance*.

![[Pasted image 20241218114300.png]]
In questo caso abbiamo 2 bucket e 3 blocchi.

### Eliminazione
>L'eliminazione di una chiave puo' portare all'eliminazione di blocchi di overflow.

![[Pasted image 20241218114458.png]]
In questo caso eliminiamo la chiave $1100$, quindi liberiamo uno spazio nel primo blocco del bucket 1 e quindi possiamo spostare $1010$ nella posizione appena liberata eliminando il secondo blocco.

![[Pasted image 20241218114636.png]]

### Efficienza degli static-hash indexes
>Idealmente se c'e' un numero di bucket che entra in un solo blocco (perche' ricordiamo che i dati vengono caricati dal disco alla RAM in *blocchi*), allora la ricerca richiede un solo accesso al disco. Tuttavia e' bene ricordare che **lunghe catene di blocchi di overflow causano un rapido calo di performance**.

L'efficienza dipende da:
- La proporzione tra la grandezza dell'indice e i dati (fattore di carico)
- La *distribuzione delle chiavi rispetto alla funzione di hash* (chiaramente se abbiamo una funzione $H$ che per ogni chiave, la mappa nel primo bucket, si avra' una sola lunga catena di blocchi di overflow e quindi una perdita di performance non indifferente)
## Dynamic Hashing
>Abbiamo delle buone ragioni per voler tenere basso il numero di blocchi di overflow per i bucket come si vede sopra e per fare cio' possiamo utilizzare il cosiddetto **hashing dinamico** cioe' le funzioni di hash cambiano dinamicamente per adattare il numero di bucket alla dimensione del file.

Vediamo due tipi di hashing dinamico: **extendible hashing** e **linear hashing**.
### Extendible hashing
>Nell'**extendible hashing** introduciamo una **directory di puntatori ai blocchi**, che puo' crescere dinamicamente e la sua lunghezza e' sempre una potenza di 2. *Raddoppiando* la directory, il numero di blocchi *raddoppia*.

Non c'e' bisogno di un data block *per ogni bucket* ma **alcuni bucket possono condividere un blocco**, quindi l'extendible hashing rimuove il bisogno di blocchi di overflow.

La funzione di hash ritorna gli $i$ bit piu' significativi della codifica binaria della chiave di ricerca.

**LOCAL & GLOBAL DEPTH**
>Ogni blocco ha una variabile che indica *quanti bit sono utilizzati per indicizzarlo*, tale indice e' chiamato **local depth**. Mentre definiamo **global depth** la lunghezza della *directory di puntatori*.

#### Ricerca
Vogliamo cercare la chiave $K = 1100$

![[Pasted image 20241218120047.png]]
>Prendiamo l'i-esimo bit piu' significativo (cioe' il primo partendo da sinistra) della chiave $1100$, quindi 1. Sappiamo allora che la chiave si trovera' all'interno del secondo bucket. La dimensione dei bucket e' fissa, quindi scorro finche' trovo la chiave che cerco.

#### Inserimento
>Per inserire una *search key* $K$ prendiamo i primi $i$ bit di $H_i(K)$ per identificare il bucket nella directory.

Se c'e' spazio nel blocco inseriamo la chiave, altrimenti ci sono due possibilita'.

Dati $j$ il numero attuale di bit per indicizzare il blocco coinvolto $B$ (local depth), e $i$ la lunghezza della directory (global depth) abbiamo che:
- se $j \lt i$ 
	1. Il blocco $B$ e' diviso in due (*halving*)
	2. Le chiavi in $B$ sono distribuite nei due nuovi blocchi, in base al valore dei loro $j + 1$ bit
	3. Il valore di $j$ e' incrementato di 1
	4. La directory e' aggiornata con il puntatore al nuovo blocco
- se $j = i$ 
	1. Il valore di $i$ e' incrementato di 1 (*doubling*)
	2. Raddoppiamo la directory per fare in modo che ogni nuova entry indicizzata dalla sequenza di bit $w$ produca due entry $w0$ e $w1$
	3. Ora abbiamo che $j \lt i$ quindi procediamo come nel caso precedente

esempio
Vogliamo inserire la chiave $K_2 = 1010$ 

![[Pasted image 20241218161723.png]]
Non c'e' spazio, allora guardiamo *local* e *global* depth e ci accorgiamo che siamo nel caso $j = i$

![[Pasted image 20241218161836.png]]
>Incrementiamo quindi $i$ e cambiamo la funzione, in modo che adesso l'i-esimo bit piu' significativo non sia piu' il primo a partire da sinistra, ma **i primi due**.

![[Pasted image 20241218162008.png]]
>In questo modo ci ritroviamo nel caso $j \lt i$ e quindi dividiamo il blocco con i primi due bit uguali a 10.

![[Pasted image 20241218162136.png]]
>Fatto cio' inseriamo la nuova chiave e distribuiamo le chiavi tra il vecchio e il nuovo nodo attraverso i $j+1$ bit, incrementiamo $j$ e risistemiamo il puntatore sul nuovo blocco

![[Pasted image 20241218162428.png]]
#### Osservazioni
>Essendo che non abbiamo blocchi di overflow, la directory e' *ragionevolmente piccola* e quindi entra nella memoria principale, dunque una potenziale *equality search* e' effettuata con **uno/due accessi al disco**.

Lo splitting causa minori riorganizzazioni delle chiavi, tuttavia e' possibile che tale split sia sfortunato e ci sia bisogno di dividere ancora i blocchi.

Il downside di questo approccio e' che la directory puo' crescere esponenzialmente e, se la distribuzione delle chiavi e' sfavorevole, puo' diventare complicato gestirla nella memoria principale.

### Linear Hashing
>Il problema che il **linear hashing** risolve e' il bisogno di una directory. Lo fa reintroducendo i **blocchi di overflow** ma risolvendo anche cio che risolveva l'extended hashing e cioe' il problema delle *lunghe catene di blocchi di overflow*.

Nell'hashing lineare il numero di bucket **aumenta linearmente**, in particolare, l'incremento avviene quando un blocco di overflow e' creato oppure quando una certa soglia e' superata.

La **soglia** e' il *fattore di carico*. Per convenzione si sceglie $(1,7 \cdot n)$ come **numero di record nel file**, dove $n$ e' il numero di buckets.

La funzione di hash $H_i(K)$ restituisce gli $i$ bit **meno significativi** della codifica binaria della chiave di ricerca.

#### Ricerca
Vogliamo trovare la chiave $K_2 = 0101$. Definiamo $n$ il numero di buckets (dove $2^{i-1} \lt n \leq 2^i$)
- se $H_i(K) = m < n$, la chiave cercata e' nel bucket $m$
- se $H_i(K) = m \geq n$, la chiave cercata e' nel bucket ($m - 2^{i-1}$)

![[Pasted image 20241218164120.png]]
Quindi sappiamo che troviamo 0101 nel bucket 01 alla posizione 1.

**OSSERVAZIONE**
>Siccome $n$ e' in decimale e $m$ in binario, riportiamo quest'ultimo in decimale per confrontarli.

Ora vogliamo cercare la chiave $K_2=1111$.

![[Pasted image 20241218164625.png]]

#### Inserimento
>Per effettuare l'inserimento seguiamo i seguenti passi

1. Contiamo il numero di record $r$ e il numero di bucket $n$
2. Se vale $r/n \gt 1.7$ allora effettuiamo uno *split* dell'$n+1$-esimo bucket
3. Quando usiamo la funzione $H_i$ tutti i bucket fino al $2^{i-1}$-esimo sono splittati seguendo l'ordine, indipendentemente dal bucket che ha causato tale *split*
4. Se $n \gt 2^i$ , allora la funzione hash **viene cambiata** a $i+1$ e lo splitting ricomincia dal primo bucket


1. Se $H_i(K) = m \lt n$, allora
	- La chiave puo' essere inserita nell'$m$-esimo bucket, se non ce' spazio, creiamo un blocco di overflow
2. Se $H_i(K) = m \geq n$, allora
	- La chiave puo' essere inserita nel $m - 2^{i-1}$ bucket, se non c'e's spazio, creiamo un blocco di overflow
3. Incrementiamo $r$ e se $r/n \gt 1.7$, allora
	1. Se $n = 2^i$, allora incrementiamo $i$ di 1
		- $n_2=a_1a_s \dots a_i$ con $a_1=1$
		- Rimuoviamo il primo bit in $n$ e lo mettiamo in $m$. $a_1a_2 \dots a_i \rightarrow 0a_2 \dots a_i$ 
	2. Aggiungi l'$n$-esimo bucket
	3. Sposta tutti i record dal blocco $m$ avente l'$i$-esimo bit piu' a destra a 1 nell'$n$-esimo blocco
	4. Incrementa $n$ di 1

esempio
Vogliamo inserire la chiave $K_2 = 0101$. Definiamo $n$ il numero di buckets (dove $2^{i-1} \lt n \leq 2^i$)
- se $H_i(K) = m < n$, la chiave cercata e' nel bucket $m$
- se $H_i(K) = m \geq n$, la chiave cercata e' nel bucket ($m - 2^{i-1}$)

![[Pasted image 20241219105205.png]]
ci troviamo nel caso in cui $m \lt n$ quindi possiamo inserire la chiave e incrementare $r$

![[Pasted image 20241219105502.png]]
Adesso il nostro fattore di carico e' maggiore della soglia che ci eravamo prefissati, quindi dobbiamo **bilanciare il carico**.
Quindi se $n = 2^i$ allora incrementiamo $i$:
- $n_2 = a_1a_2 \dots a_i$ avente $a_1 = 1$, quindi $n_2 = 10$
- Rimuoviamo il primo bit in $n$ e lo mettiamo in $m$, quindi $m_2 = 00$

![[Pasted image 20241219110431.png]]
Aggiungiamo il bucket $n$-esimo $n_2 = 10$

![[Pasted image 20241219110514.png]]
Spostiamo tutti i record del bucket $m_2 = 0a_2a_3 \dots a_i$ aventi l'$i$-esimo bit piu' a destra uguale a 1, nel bucket $n$-esimo:
- $n = 2_{10} = 10_2 \rightarrow 10_2$ identifica il nuovo bucket
- Spostiamo i record di dati da $00_2$ a $10_2$

![[Pasted image 20241219110806.png]]
Infine incrementiamo il numero di bucket $n$ di 1

![[Pasted image 20241219110838.png]]

#### Links
[[Indexes]]