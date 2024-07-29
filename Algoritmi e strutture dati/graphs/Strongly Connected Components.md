>Le **componenti fortemente connesse** di un grafo orientato sono le classi di equivalenza dei vertici secondo la relazione: *sono mutualmente raggiungibili*

### Come si trovano?
Per trovare le *componenti fortemente connesse* di un grafo orientato si utilizza l'algoritmo [[DFS]].
L'idea di base e' quella di trovare il grafo trasposto $G^T$ tramite DFS e successivamente richiamare DFS anche su questo.

>Definiamo il grafo trasposto $G^T$ come il grafo $G$ i cui archi $(u, v) \in E$ hanno gli elementi invertiti
### Pseudocodice
```
strongly_connected_components(G) {
dfs(G) // to find the discovery time of each vertex

// computes G^T

dfs(G^T) // but in the main cycle of dfs it considers the vertices in descending order of completion time calculated at row 2

// Generates the output of vertices of each tree of the DF forest generated at row 6 as a single strongly connected component
}
```
*Complessita'*: $\Theta \left( V + E \right)$ 

#### Links
[[DFS]]