>Un **B Tree** e' un *albero di ricerca n-ario* **bilanciato** progettato per operare su dischi o altre unita' di memoria secondaria ad accesso diretto.

Sono ampiamente utilizzati nello sviluppo di database, cache e tutto cio' che riguarda gli accessi in memoria secondaria, poiche' sono progettati per ridurre al minimo il numero di questi ultimi.
### Come sono fatti
Essendo simili agli [[RB Trees]] hanno un'altezza logaritmica, dunque le operazioni possono essere implementate in tempo $O\left (\log n \right)$. I B trees sono una generalizzazione naturale dei [[Binary Search Trees]].

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