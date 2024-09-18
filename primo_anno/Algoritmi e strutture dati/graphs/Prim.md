>L'algoritmo di **Prim** e' un algoritmo **goloso** per la generazione di [[Minimum Spanning Tree]].

Ha la proprieta' che gli archi nell'insieme $A$ formano sempre un albero singolo.

### Come funziona
A ogni passo viene aggiunto all'albero $A$ un **arco leggero** che collega $A$ con un vertice isolato. Questa regola fa si che vengano aggiunti soltanto **archi sicuri**, quindi quando l'algoritmo termina viene restituito $A$ che e' un MST.

>La chiave per implementare con efficienza l'algoritmo di Prim sta nel trovare un modo veloce per scegliere un nuovo arco da aggiungere all'albero formato dagli archi in $A$.

Durante l'esecuzione dell'algoritmo tutti i vertici che *non* si trovano nell'albero sono in una *coda di min-priorita'* ([[Priority Queue]]) basata sul campo *key*. Per ogni vertice *v* l'attributo *key* e' il peso minimo di un arco qualsiasi che collega *v* a un vertice nell'albero

Durante l'esecuzione dell'algoritmo, l'inisieme $A$ e' mantenuto implicitamente come: $A = \{ (v, v.\pi) : v \in V - \{r \} - Q \}$.

Quando l'algoritmo termina, la coda di min-priorita' $Q$ e' vuota, quindi $A$ sara':
$A = \{ (v, v.\pi): v \in V - \{r\} \}$ 

### Pseudocodice
```
mst_prim(G, w, r){
for u in G.V
	u.key = infinity
	u.pi = NIL
	
r.key = 0
Q = G.V

while Q is not empty
	u = extract_min(Q)
	for v in G.Adj[u]
		if v in Q and w(u,v) < v.key
			v.pi = u
			v.key = w(u,v)
}
```
- 2-4 -> inizializza i vertici
- 6-7 -> inserisco i vertici nella coda di min-priorita'
- 9-14 -> fintantoche' la coda non e' vuota, tiro fuori il vertice piu' piccolo `u` e, per ogni vertice `v`nella sua lista di adiacenza, verifico se: `v` e' presente nella coda e se il peso dell'arco tra `u` e `v` sia inferiore al peso di `v` se si aggiorno la chiave di `v` e come predecessore gli assegno `u`. Cosi' facendo sono certo di scegliere il cammino minimo ad ogni iterazione
*Complessita'*: 
- $O \left (E \log V \right)$ se utilizziamo una coda di min-priorita' implementata tramite **heap binario** ([[Heap]]), il tempo e' lo stesso di [[Kruskal]]
- $O \left(E + V \log V \right)$ se utilizziamo un **heap di Fibonacci** per implementare la coda di min-priorita'

#### Links
[[Minimum Spanning Tree]]
[[Kruskal]]
[[Disjointed Sets]]