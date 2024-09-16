>L'algoritmo di **Dijkstra**  e' un algoritmo **goloso** che risolve il problema dei **cammini minimi da sorgente unica** ([[Shortest path from single source]]) nel caso in cui i pesi degli archi non siano negativi. *Una buona implementazione di Dijkstra ha un tempo migliore di quello di [[Bellman-Ford]]*

### Come funziona? 
L'algoritmo mantiene un insieme $S$ di vertici i cui pesi finali dei cammini minimi sono gia' stati determinati. L'algoritmo seleziona ripetutamente il vertice $u\in V-S$ con la stima minima, aggiunge $u$ a $S$ e rilassa tutti gli archi uscenti. Mantiene anche una coda di *min-priorita'* ([[Priority Queue]]) $Q$ di vertici utilizzando come chiavi gli attributi $d$ dei vertici

### Pseudocodice
```
dijkstra(G, s, w) {
initialize_single_source(G, s)
S = {} // empty set
Q = G.V

while Q is not empty
	u = extract_min(Q)
	S = S U {u}
	for v in Adj[u]
		relax(u, v, w)
}
```
- 2-4 -> inizializza i pesi dei vertici, dichiara la lista di vertici e l'insieme che conterra' i vertici con peso minimo
- 6-10 -> fintantoche' ci sono elementi nella coda estrare il primo e lo aggiunge all'insieme di vertici `S`, successivamente scorre la lista di adiacenza di tale vertice e rilassa tutti gli archi uscenti
*Complessita'*: 
- $O (V^2)$ se utilizziamo un array -> *migliore per grafi densi*
- $O (E\log V)$ se implementiamo la coda con heap binario ([[Heap]]) -> *migliore per grafi sparsi*
- $O (E + V\log V)$ se implementiamo la coda con heap di Fibonacci -> *migliore nei casi generali*

##### Links 
[[Shortest path from single source]]
[[Heap]]
[[Priority Queue]]