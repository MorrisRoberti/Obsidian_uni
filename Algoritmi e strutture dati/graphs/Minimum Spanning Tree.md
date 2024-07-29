>Un **albero di connessione minimo** (*Minimum Spanning Tree*) e' un sottoinsieme di archi di $G$ che connette tutti i vertici tale che il peso totale degli archi sia minimo
>$$\omega\left(T\right)=\sum_{\left(u,v\right)\in T}^{{}}\omega\left(u,v\right)$$
>In questo caso vogliamo che la sommatoria di tutti i pesi $\omega$ degli archi sia minima.
>La funzione $\omega$ definisce il peso

### Creare un MST
Utilizziamo un algoritmo generico per determinare un *albero di connessione minimo*:
Definiamo un'invariante di ciclo:
>Prima di ogni iterazione, $A$ e' un sottoinsieme di qualche albero di connessione minimo

Ad ogni passo determiniamo un arco $(u,v)$ che possa essere aggiunto ad $A$ senza violare l'invariante sopra, nel senso che $A \cup \{(u,v)\}$ e' anche un sottoinsieme di un albero di connessione minimo.
Tale arco e' detto **arco sicuro** per $A$ perche' puo' essere aggiunto a quest'ultimo preservando l'invariante.
```
generic_mst(G, w) {
A = {} // empty set
while A is not a spanning tree
	find a safe edge (u, v)
	A = A U {(u,v)}
return A
}
```
>Banalmente ad ogni iterazione trova un arco sicuro per a e lo unisce

### Trovare archi sicuri
#### Tagli
>Un **taglio** $(S, V-S)$ di un grafo non orientato e' una partizione di $V$. Si dice che un arco **attraversa** il taglio se una delle sue estremita' si trova in $S$ e l'altra in $V-S$.
>Si dice che un taglio **rispetta** un insieme $A$ se nessun arco di $A$ attraversa il taglio.

#### Archi leggeri
>Un arco e' un **arco leggero** per un taglio se il suo peso e' minimo fra i pesi degli altri archi che attraversano il taglio (*l'arco leggero potrebbe non essere unico*)

Il seguente teorema ci dice come trovare gli archi sicuri

>Sia $G=(V, E)$ un grafo connesso e non orientato con una funzione peso $\omega$ a valori reali definita in $E$. Sia $A$ un sottoinsieme di $E$ che e' contenuto in qualche albero di connessione minimo di $G$, sia $(S, V-S)$ un taglio qualsiasi per $G$ che rispetta $A$ e sia $(u,v)$ un arco leggero che attraversa $(S, V-S)$. Allora l'arco $(u,v)$ e' **sicuro** per $A$.

#### Links
[[Kruskal]]
[[Prim]]