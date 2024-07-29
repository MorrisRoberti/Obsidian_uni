>La visita *Depth First Search* (visita in profondita'), anche chiamata **DFS** e' un tipo di visita che consiste nel visitare il grafo in profondita' e facendo *backtracking* quando si incontra un vertice gia' scoperto

Come [[BFS]], l'algoritmo **DFS** utilizza i colori per tenere traccia dello stato di esplorazione dei vertici. Oltre ai colori utilizza anche due attributi in piu' per tracciare il tempo di completamento dell'esplorazione dei vertici:
- `u.d` -> tempo in cui e' stato scoperto il vertice 
- `u.f` -> tempo in cui e' stato esplorato (i vertici della sua lista di adiacenza sono stati scoperti tutti)

>Anche DFS genera un **sottografo dei predecessori**, che e' leggermente diverso da quello di BFS
>$$E_{\pi}=\left\lbrace\left(v.\pi,v\right):v\in V\land v.\pi\ne NIL\right\rbrace$$

#### Dove si utilizza?
L'algoritmo **DFS** viene utilizzato in diversi ambiti quali:
- **Ordinamento topologico** per ordinare i vertici di un **DAG** (*Directed Acyclic Graph*), questo e' utile nello scheduling dei processi, in cui ogni compito deve essere eseguito secondo un certo ordine
- **Individuazione dei cicli** in un grafo, e' utile ad esempio per l'analisi delle dipendenze di un progetto software
- **Trovare componenti fortemente connesse** in grafi orientati, questo puo' essere utile ad esempio per trovare communities nei social network
- **Problemi di ottimizzazione** quando si deve trovare la migliore soluzione ad un problema tra un grande insieme di soluzioni

### Pseudocodice
>Lo pseudocodice dell'algoritmo **DFS** si serve della subroutine **dfs_visit**

#### dfs
```
dfs(G, s) {
for v in G.V
	v.pi = NIL
	v.color = WHITE
time = 0
for u in G.V
	if u.color == WHITE
		dfs_visit(G, u)
}
```
- 2-4 -> inizializza i vertici
- 5-8 -> mette il tempo iniziale a 0 (e' la variabile incrementale che servira' a tenere traccia del tempo di scoperta dei vertici) e, per ogni vertice non ancora scoperto chiama **dfs_visit**
*Complessita'*: $\Theta \left (V + E \right)$ 

#### dfs_visit
```
dfs_visit(G, u) {
time = time + 1
u.d = time
u.color = GRAY
for v in Adj[u]
	if v == WHITE
		v.pi = u
		dfs_visit(G, v)
u.color = BLACK
time = time + 1
u.f = time
}
```
- 2-4 -> pongo il vertice iniziale come *scoperto* e gli do il tempo di scoperta
- 5-8 -> per ogni vertice non scoperto della lista di adiacenza di `u` metto come predecessore `u` stesso e richiamo la procedura, in modo da esplorare il grafo in profondita'
- 9-11 -> marco il vertice `u` come *esplorato* e segno il tempo di completamento in `u.f`
>Il *backtracking* avviene nelle riga 8, poiche' alla fine di ogni chiamata ricorsiva, l'esecuzione torna indietro e man mano segna i vertici come esplorati

### Proprieta'
>La visita in profondita' fornisce importanti informazioni sul grafo, forse la piu' importante e' che il sottografo dei predecessori $G_{\pi}$ forma effettivamente una **foresta di alberi**.

Un'altra proprieta' molto importante e' che i tempi di scoperta dei vertici hanno una struttura di **parentesi**, dalla quale viene il seguente teorema

#### Teorema delle parentesi
>In qualsiasi visita in profondita' di un grafo $G=(V, E)$ (orientato o non), per ogni coppia di vertici $u$ e $v$, e' soddisfatta una sola delle seguenti tre condizioni:
>	- Gli intervalli $[u.d, u.f]$ e $[v.d, v.f]$ sono completamente disgiunti; inoltre $u$ e $v$ non sono discendenti l'uno dell'altro
>	- L'intervallo $[u.d, u.f]$ e' interamente contenuto nell'intervallo $[v.d, v.f]$; inoltre $u$ e' un discendente di $v$
>	- L'intervallo $[v.d, v.f]$ e' interamente contenuto nell'intervallo $[u.d, u.f]$; inoltre $v$ e' un discendente di $u$

### Classificazione degli archi
Possiamo definire 4 tipi di archi in base alla **foresta DF** prodotta da **DFS**
1. **Archi d'albero** -> sono gli archi della **foresta DF**. L'arco $(u,v)$ e' un arco d'albero se $v$ viene scoperto per la prima volta durante l'esplorazione di $(u,v)$
2. **Archi all'indietro** -> sono quegli archi $(u, v)$ che collegano un vertice $u$ ad un suo antenato $v$ in un albero DF. I cappi dei grafi orientati sono considerati archi all'indietro
3. **Archi in avanti** -> sono quegli archi $(u, v)$ che collegano un vertice $u$ ad un suo discendente $v$ in un albero DF
4. **Archi trasversali** -> tutti gli altri archi

![[Pasted image 20240729115900.png]]
Nell'immagine viene applicato DFS al grafo in figura *a* e la foresta in figura *c* e' la risultante foresta DF. Gli archi sono contrassegnati nel seguente modo:
- **F** -> Archi in avanti
- **B** -> Archi all'indietro
- **C** -> Archi trasversali
#### Links
[[BFS]]