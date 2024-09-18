>In un **problema dei cammini minimi** e' dato un grafo *orientato* *pesato* $G = (V, E)$, con una funzione peso $\omega: E \rightarrow \mathbb{R}$ che associa agli archi dei pesi di valore reale. Il **peso** $\omega(p)$ del cammino $p$ e' la somma dei pesi degli archi che lo compongono: 
>$$\omega\left(p\right)=\sum_{i=1}^{k}\omega\left(v_{i-1,}v_{i}\right)$$

### Peso di un cammino minimo
Il **peso di un cammino minimo** puo' essere definito come segue:
$$\delta\left(u,v\right)=\begin{cases}\min\left\lbrace\omega\left(p\right):u\ \widetilde{}^p v\right\rbrace\space\text{se esiste un cammino da u a v}\\ \infty\space\text{  negli altri casi}\end{cases}$$
un **cammino minimo** dal $\delta(u,v)$ dal vertice $u$ al vertice $v$ e' definito come un cammino $p$ con peso $\omega(p)=\delta(u,v)$.

**ATTENZIONE**
>*I sottocammini di un cammino minimo sono cammini minimi*

### Archi di peso negativo & cicli
Se il grafo non contiene cicli di peso negativo che sono raggiungibili dalla sorgente $s$, allora per ogni $v \in V$, il peso del cammino minimo $\delta(u,v)$ resta **ben definito** anche se ha un valore negativo.
Tuttavia, se esiste un ciclo di peso negativo che e' raggiungibile da $s$, i pesi dei cammini minimi non sono ben definiti.

Alcuni algoritmi per cammini minimi hanno come condizione preliminare quella di non avere cicli negativi all'interno del grafo ([[Dijkstra]]), mentre altri operano su qualsiasi tipo di grafo ([[Bellman-Ford]]).

Non puo' contenere nemmeno un ciclo di peso positivo, perche' eliminando il ciclo dal cammino si ottiene un cammino con la stessa sorgente la stessa destinazione e un peso piu' piccolo. Stessa cosa per i cicli di peso 0.

### Rappresentazione dei cammini minimi
>Dato un grafo $G=(V,E)$, manteniamo per ogni vertice $v\in V$ un **predecessore** $v.\pi$ che puo' essere un altro vertice o il valore *NIL*. Quindi possiamo definire il **sottografo dei predecessori** $G_\pi = (V_\pi, E_\pi)$ indotto dai valori di $\pi$: 
>						$V_\pi = \{ v\in V: v.\pi \neq NIL \} \cup \{s\}$ 
>						$E_\pi = \{ (v.\pi, v) \in E : v \in V_\pi - \{s\} \}$ 


Un **albero di cammini minimi** radicato in $s$ e' un sottografo orientato $G' = (V', E')$, dove $V' \subseteq V$ e $E' \subseteq V'$ tale che:
1. $V'$ e' l'insieme dei vertici raggiungibili da $s$ in $G$
2. $G'$ forma un albero con radice in $s$ 
3. per ogni $v\in V$, l'unico cammino semplice da $s$ a $v$ in $G'$ e' un cammino minimo da $s$ a $v$ in $G$

*I cammini minimi non sono sempre necessariamente unici ne lo sono gli alberi dei cammini minimi*

Per ogni vertice $v$ manteniamo l'attributo $v.d$, che e' un limite superiore per il peso di un cammino minimo dalla sorgente $s$ a $v$. L'attributo $v.d$ e' detto **stima del cammino minimo**. La seguente procedura inizializza le stime dei cammini minimi

```
initialize_single_source(G,s) {
for v in G.V
	v.d = infinity
	v.pi = NIL
s.d = 0
}
```
*Complessita'*: $\Theta (V)$

### Rilassamento
>Il processo di **rilassamento** di un arco $(u,v)$ consiste nel verificare se, passando per $u$, e' possibile migliorare il cammino minimo per $v$ precedentemente trovato e, in caso affermativo, nell'aggiornare $v.d$ e $v.\pi$.

```
relax(u, v, w){
if v.d > u.d + w(u,v)
	v.d = u.d + w(u,v)
	v.pi = u
}
```
In pratica va ad aggiornare la stima del cammino minimo dalla sorgente a $v$ passando per $u$ tramite l'arco $(u,v)$

#### Links
[[Dijkstra]]
[[Bellman-Ford]]