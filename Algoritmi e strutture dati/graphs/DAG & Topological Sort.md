>Un **DAG** (*Directed Acyclic Graph*) e', come dice la parola, un **grafo diretto e aciclico**

>Chiamiamo **Topological Sort** (*Ordinamento Topologico*) un tipo di ordinamento lineare dei DAG. E' strutturato in modo che se $(u,v) \in E$ allora $u$ viene prima di $v$ nell'ordinamento

#### Dove si usa?
Il Topological Sort si utilizza in ambiti quali:
- **Task scheduling** 
- **Dependency resolution** 
- **Data Processing**

### Come funziona?
Utilizza [[DFS]] per ricavare i tempi di scoperta dei vari vertici e poi sfrutta una lista concatenata per ordinarli

### Pseudocodice
```
topological_sort(G) {
dfs(G)
// when the inspection of a vertex is complete it inserts it at the beginning of the list
}
```


#### Links
[[DFS]]