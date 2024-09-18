>Un **grafo** e' una struttura dati tipicamente descritta come G=(V, E) dove: **V** e' l'insieme di *vertici* del grafo e **E** e' una relazione tra vertici che definisce l'insieme degli *archi*.

![[Pasted image 20240628120112.png]]
### Tipologie di grafo
Esistono due tipi di grafi:
- Grafi **orientati**
	![[Pasted image 20240628120400.png]]
	
- Grafi **non orientati** (come quello in figura all'inizio)

### Cammini
Per entrambe le tipologie di grafo possiamo definire il concetto di **cammino**

>Un **cammino** di lunghezza $k$ da un vertice $u$ a un vertice $v$ in un grafo e' una sequenza  di vertici tali che $<v_0,v_1,\ldots,v_{k}>$ e $u=v_0$ , $v=v_k$ e $\left(v_{i-1},v_{i}\right)\in E$ per $i = 1, 2, ..., k$

- Se e' presente un cammino *p* da *u* a *v* allora diciamo che *v* e' raggiungibile da *u* tramite *p*
- Un cammino e' **semplice** se tutti i vertici del cammino sono distinti
- Un **sottocammino** di $p = <v_0,v_1,\ldots,v_{k}>$ e' una sottosequenza contigua dei suoi vertici

### Cicli
>Un **ciclo** in un grafo e' un cammino $<v_0,v_1,\ldots,v_{k}>$ in cui $v_0=v_k$

Nei grafi diretti, va tenuto conto della direzione degli archi

#### Links
[[Directed graphs]]
[[Undirected graphs]]