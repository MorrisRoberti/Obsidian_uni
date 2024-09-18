>L'algoritmo di **Kruskal** e' un algoritmo **goloso** per la generazione di [[Minimum Spanning Tree]], tramite la ricerca di un **arco sicuro** da aggiungere alla foresta in costruzione, facendo si che l'arco scelto sia **di peso minimo**. 

Essendo un **algoritmo goloso**, per ogni passo viene effettuata la scelta che e' localmente migliore.
Infatti l'algoritmo di Kruskal **aggiunge, ad ogni iterazione l'arco sicuro di peso minimo**.
### Pseudocodice
```
mst_kruskal(G, w) {
A = {} // empty set
for v in G.V
	make_set(v)

orders the edges of G.E in non descending order for the weight w
for (u,v) in G.E (in non descending order)
	if find_set(u) != find_set(v)
		A = A U {(u,v)}
		union(u,v)
return A
}
```
- 2-4 -> costruisce un insieme per ogni vertice
- 6 -> come scritto, *ordina gli archi di G.E in ordine non decrescente rispetto al peso w*
- 7-10 -> per ogni arco se gli insiemi degli estremi sono disgiunti allora vuol dire che l'arco e' **sicuro** e quindi lo unisce ad `A`, successivamente fa la `union`
- 11 -> restituisce `A` che e' un sottoinsieme di un albero di connessione minimo
*Complessita'*: $O \left( E \log V \right)$ (implementazione degli insiemi disgiunti con le euristiche dell'*unione per rango* e della *compressione dei cammini*)

#### Links
[[Disjointed Sets]]
[[Minimum Spanning Tree]]
[[Prim]]

