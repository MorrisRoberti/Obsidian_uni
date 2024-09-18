>Quando abbiamo un **DAG** (*Directed Acyclic Graph*) possiamo utilizzare un algoritmo che sfrutta l'ordinamento topologico per trovare **cammini minimi da sorgente unica** 

*I cammini minimi sono sempre ben definiti in un DAG, perche' anche se ci sono archi di peso negativo, non e' possibile avere dei cicli, per definizione*
### Come funziona?
L'algoritmo ordina topologicamente il dag e successivamente, passando per i vertici, rilassa gli archi uscenti dal vertice stesso

### Pseudocodice
```
dag_shortest_path(G, s, w) {
topological_sort(G)
initialize_single_source(G, s)
for v in G.V // in topological order
	for u in Adj[v]
		relax(u, v, w)
}
```
- 2 -> ordina topologicamente i vertici
- 3 -> inizializza le stime dei pesi
- 4-6 -> per ogni vertice, prende la sua lista di adiacenza e rilassa gli archi

#### Links 
[[DAG & Topological Sort]]
[[Shortest path from single source]]