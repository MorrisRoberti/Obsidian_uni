>Un **B Tree** e' un *albero di ricerca n-ario* **bilanciato** progettato per operare su dischi o altre unita' di memoria secondaria ad accesso diretto.

Sono ampiamente utilizzati nello sviluppo di database, cache e tutto cio' che riguarda gli accessi in memoria secondaria, poiche' sono progettati per ridurre al minimo il numero di questi ultimi.

### Importante
>Se $n \geq 1$ allora per qualsiasi B albero T di *n* chiavi, con altezza *h* e e grado minimo $t \geq 2$, si ha
>$$h\le\log_{t}\frac{n+1}{2}$$
### Come sono fatti
Essendo simili agli [[RB Trees]] hanno un'altezza logaritmica, dunque le operazioni possono essere implementate in tempo $O\left (\log n \right)$. I B trees sono una generalizzazione naturale dei [[Binary Search Trees]].
![[Pasted image 20240726144753.png]]
### Proprieta'
1. Ogni nodo `x` ha i seguenti attributi:
	1. `x.n` e' il numero di chiavi correntemente memorizzate nel nodo `x`
	2. Le `x.n` chiavi stesse, $x.key_1, x.key_2, ..., x.key_{x.n}$ sono memorizzate in ordine non decrescente
	3. `x.leaf` e' un attributo booleano che indica se un nodo e' una foglia (*true*) o meno (*false*)
2. Ogni nodo interno `x` contiene `x.n+1` puntatori $x.c_1, x.c_2, ..., x.c_{x.n+1}$ ai suoi figli, quindi i loro attributi $c_i$ non sono definiit
3. Le chiavi $x.key_i$ separano gli intervalli delle chiavi memorizzate in ciascun sottoalbero: se $k_i$ e' una chiave qualsiasi memorizzata in $c_i[x]$, allora: 
		$k_1 \leq x.key_1 \leq k_2 \leq x.key_2, ..., \leq x.key_n \leq k_{x.n+1}$ 
4. Tutte le foglie hanno la stessa profondita' che e' l'altezza *h* dell'albero
5. Ci sono limiti superiori e inferiori per il numero di chiavi che un nodo puo' contenere. Questi limiti possono essere espressi in termini di un intero $t \geq 2$ chiamato **grado minimo** del B albero:
	1. Ogni nodo, tranne la radice, deve avere almenot $t - 1$ chiavi. Ogni nodo interno, tranne la radice, quindi ha almeno $t$ figli. Se l'albero non e' vuoto la  radice deve avere almeno una chiave
	2. Ogni nodo puo' contenere al massimo $2t-1$ chiavi, dunque un nodo interno puo' avere al massimo $2t$ figli. Diciamo che un non e' **pieno** se contiene esattamente $2t - 1$ chiavi.

### Operazioni
>Le operazioni sui B Trees sono svolte in tempo proporzionale all'altezza dell'albero e al parametro **t**

In seguito sono descritte le operazioni **b_treee_search**, **b_tree_create** e **b_tree_insert**.
Per quest'ultima avremo bisogno di due subroutine: **b_tree_split_child** e **b_tree_insert_non_full**

#### b_tree_search
```
b_tree_search(x, k) {
i = 1
while i <= x.n and k > x.key_i
	i = i + 1
if i <= x.n and k == x.key_i
	return (x, i)
else if x.leaf
	return NIL
else DISK_READ(x.c_i)
	return b_tree_search(x.c_i, k)
}
```
- 3-4 -> scorre le chiavi del nodo corrente `x` fino a che sono presenti o fin quando non trova una chiave maggiore di `k` in quel modo trova il posto in cui dovrebbe essere il valore cercato
- 5-6 -> se quel posto e' occupato da una chiave con il valore di `k` allora restituisce il nodo e l'indice nell'array di chiavi
- 7-8 -> altrimenti la chiave non e' presente in quel nodo e, se il nodo e' una foglia, non potendo andare piu' in basso, vuol dire che la chiave non e' presente nell'albero
- 9-10 -> se invece non e' una foglia, vuol dire che la chiave sara' nel nodo figlio puntato da `x.key_i` quindi legge dalla memoria l'*i-esimo* figlio e richiama la procedura su quello
*Complessita'*: $O\left(t \log_t n\right)$

#### b_tree_create
```
b_tree_create(T) {
x = ALLOCATE_NODE()
x.leaf = true
x.n = 0
DISK_WRITE(x)
T.root = x
}
```
Alloca il nuovo nodo, lo salva in memoria e poi lo assegna come radice dell'albero
*Complessita'*: $O\left(1\right)$

#### b_tree_insert
```
b_tree_insert(T, k) {
r = T.root
if r.n == 2t-1
	s = ALLOCATE_NODE()
	T.root = s
	s.leaf = false
	s.n = 0
	s.c_1 = r
	b_tree_split_child(s, 1)
	b_tree_insert_non_full(s, k)
else b_tree_insert_non_full(r, k)
}
```
- 3-8 -> se la radice e' piena allora alloco un nuovo nodo, lo metto come radice e ci assegno come unico figlio il nodo presente precedentemenete (la vecchia radice)
- 9 -> quindi chiamo `b_tree_split_child` sulla nuova radice e sul figlio 1 per ribilanciare l'albero
- 10 -> una volta che l'ho ribilanciato inserisco la mia chiave `k` nell'albero
- 11 -> nel caso in cui `r` non sia pieno, semplicemente inserisco `k` come sua chiave
*Complessita'*: $O\left(t \log_t n\right)$

#### b_tree_split_child
```
b_tree_split_child(x, i) {
z = ALLOCATE_NODE()
y = x.c_i
z.leaf = y.leaf
z.n = t - 1

for j = 1 to t - 1 
	z.key_j = y.key_(j+t)
	
if not y.leaf
	for j = 1 to t
		z.c_j = y.c_(j+t)
y.n = t - 1

for j = x.n + 1 downto i + 1
	x.c_(j+1) = x.c_j
x.c_(i+1) = z

for j = x.n downto i
	x.key_(j+1) = x.key_j
x.key_i = y.key_t
x.n = x.n + 1

DISK_WRITE(y)
DISK_WRITE(z)
DISK_WRITE(x)
}
```
- 2-4 -> crea un nodo `z` con il numero minimo di chiavi e salva in `y` l'*i-esimo* figlio di `x`
- 7-8 -> carica in `z`, $t-1$ chiavi
- 10-13 -> se `y` non e' una foglia, carica in `z` i puntatori ai suoi $t$ figli, successivamente metto al minimo il numero di chiavi di `y`
- 15-17 -> faccio scorrere a dx i puntatori ai figli di `x` e inserisco nell'*i-esimo* posto il puntatore al nodo `z`
- 19-22 -> faccio scorrere a dx le chiavi di `x` e metto nell'*i-esima* posizione l'ultima chiave di `y` aumentando il numero di chiavi totali in `x`
- 24-26 -> riscrivo i tre nodi in memoria
*Complessita'*: $\Theta \left(t \right)$
#### b_tree_insert_non_full
```
b_tree_insert_non_full(x, k) {
i = x.n
if x.leaf
	while i >= 1 and k < x.key_i
		x.key_(i+1) = x.key_i
		i = i - 1
	x.key_(i+1) = k
	x.n = x.n+1
	DISK_WRITE(x)
else 
	while i >= 1 and k < x.key_i
		i = i - 1
	i = i + 1
	DISK_READ(x.c_i)
	if x.c_i.n == 2t - 1
		b_tree_split_child(x, i)
		if k > x.key_i
			i = i + 1
	b_tree_insert_non_full(x.c_i, k)
}
```
Distinguiamo due casi: quello in cui `x` e' una foglia e quello in cui e' un nodo interno.
- 3-9 -> itero sulle chiavi del nodo `x` fino a trovare il posto per `k`, lo inserisco, aumento il numero di chiavi di `x` e riscrivo il nodo in memoria
- 10-19 -> itero sulle chiavi di `x` fino a trovare l'indice `i` nel quale inserire `k`, successivamente leggo dalla memoria l'*i-esimo* figlio di `x`: se non e' pieno, richiamo su questo la procedura attuale, altrimenti faccio lo split e metto `k` nella sua posizione
*Complessita'*: $O\left(t \log_t n\right)$

>L'eliminazione non verra' trattata in quanto il procedimento e' abbastanza lungo, non e' molto complessa, invece di fare lo split dei nodi li si riunisce tenendo a mente i bound del numero di chiavi $[t-1, 2t-1]$ 

#### Links