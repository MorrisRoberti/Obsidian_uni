>L'algoritmo di **Bellman-Ford** e' un algoritmo per cammini minimi da sorgente singola ([[Shortest path from single source]]) che funziona nel caso generale in cui i pesi degli archi possono essere anche negativi. L'algoritmo restituisce un valore booleano che indica la presenza di un ciclo di peso negativo, se esiste. Se non e' presente un ciclo di peso negativo restituisce l'albero di cammini minimi

### Come funziona
L'algoritmo utilizza il rilassamento ([[Shortest path from single source#Rilassamento]]) riducendo progressivamente il valore stimato per ciascun vertice fino a raggiungere il peso minimo effettivo $\delta(s,v)$. L'algoritmo restituisce *true* soltanto se il grafo non contiene cicli di peso negativo

### Pseudocodice
```
bellman_ford(G, s, w) {
initialize_single_source(G,s)

for i to G.V - 1
	for (u, v) in G.E
		relax(u, v, w)
		
for (u, v) in G.E
	if v.d > u.d + w(u, v)
		return false

return true
}
```
- 2 -> inizializza le distanze dei vari vertici
- 4-6 -> per un numero di volte proporzionale al numero di vertici, prende gli archi e li rilassa, in questo modo ogni vertice avra' in esso la distanza minima dalla radice
- 8-10 -> per ogni arco, controlla se la stima del suo peso e' maggiore del peso stimato del predecessore + quello dell'arco che li collega, se e' cosi' siamo in presenza di un ciclo di peso negativo e quindi restituisce *false*
- 12 -> se tutto va a buon fine, l'albero di cammini minimi e' costruito e ritorna *true*
*Complessita'*: $O (VE)$ 

>Nella riga 9 noi sappiamo che in `v.d` abbiamo gia' il peso minore possibile, dunque se questo e' maggiore di `u.d + w(u,v)` vuol dire che in realta' non e' il peso minimo, questo genera una contraddizione e quindi deve esserci un ciclo di peso negativo

#### Links 
[[Shortest path from single source]]