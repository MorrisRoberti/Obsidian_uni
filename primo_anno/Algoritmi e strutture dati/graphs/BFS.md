>La *Breadth First Search* (visita in ampiezza), anche chiamata **BFS** e' un tipo di visita dei grafi che esplora sistematicamente i vertici livello per livello a partire da una sorgente *s*.

**BFS** fa sostanzialmente 3 cose:
1. Esplora sistematicamente i vertici 
2. Calcola la distanza *minima* di tutti i vertici raggiungibili dalla sorgente *s* 
3. Genera un albero **BF** con radice *s* che contiene tutti i vertici raggiungibili da *s* 
Opera su grafi orientati e non.

#### Dove si utilizza? 
L'algoritmo BFS viene utilizzato in ambiti quali:
- **Ricerca di cammini minimi** es. nei GPS
- **Social Networking** es. BFS puo' essere utilizzato per trovare i collegamenti tra due utenti
- **Garbage Collection** 
- **Network Broadcasting** es. puo' essere utilizzato per mandare messaggi broadcast a tutti i nodi di una rete
- **Giochi e puzzle** es. nei cubi di rubik, nei labirinti e in tutti quei giochi che necessitano del calcolo di cammini minimi
### Come funziona
La procedura di BFS utilizza i colori per verificare lo stato di scoperta di un determinato vertice:
- **bianco** -> ancora da scoprire
- **grigio** -> scoperto ma ancora da esplorare
- **nero** -> scoperto ed esplorato

Ogni vertice `u` del grafo ha le seguenti proprieta':
- `u.d` -> distanza dalla sorgente
- `u.pi` -> predecessore (vertice dal quale ho scoperto `u`)
- `u.color` -> colore che indica appunto lo stato di scoperta di `u`

### Pseudocodice
```
bfs(G, s) {
for v in G.V - {s}
	v.color = WHITE
	v.pi = NIL
	v.d = infinity

s.color = GRAY
s.pi = NIL
s.d = 0
Q = {} // empty set
ENQUEUE(Q, s)

while Q is not empty
	u = DEQUEUE(Q)
	for v in Adj[u]
		if v.color == WHITE
			v.color = GRAY
			v.d = u.d + 1
			v.pi = u
			ENQUEUE(Q, v)
	u.color = BLACK
}
```
- 2-5 -> inizializzo tutti i vertici in modo che siano marcati come *da scoprire*
- 7-8 -> inizializzo `s` con grigio perche' e' il primo vertice *scoperto ma non esplorato*
- 10-11 -> dichiaro una coda e ci inserisco `s`
- 13-21 -> fintantoche' la coda non e' vuota tiro fuori un elemento `u`, scorro la sua lista di adiacenza e, per ogni vertice, se non e' stato ancora scoperto allora lo marco come *scoperto ma non esplorato* gli assegno come predecessore `u` e come distanza `u.d + 1` e lo inserisco nella coda. Infine marco `u` come *esplorato* e continuo ad iterare
>Questo procedimento fa si che i vertici vengano esplorati livello per livello e che venga salvata la distanza di ognuno di loro dalla sorgente (generando l'albero BF)

*Complessita'*: $O \left (V + E \right)$ 

### Albero BF
>Un **albero BF** con radice in *s* e' la struttura che viene generata a seguito di una chiamata a BFS su sorgente *s*. Piu' formalmente definiamo **l'albero dei predecessori** come:
>$$V_{\pi}=\left\lbrace v\in V:v.\pi\ne NIL\right\rbrace \cup \left\lbrace s\right\rbrace$$
>$$E_{\pi}=\left\lbrace\left(v.\pi,v\right):v\in V_{\pi}-\left\lbrace s\right\rbrace\right\rbrace$$

Gli archi in $E_{\pi}$ sono detti **archi d'albero**.

Possiamo usare la seguente procedura per stampare i vertici di un cammino minimo da `s` a `v` supponendo che sia gia' stato calcolato l'albero dei predecessori con la procedura BFS
```
print_path(G, s, v) {
if v == s
	print s
elseif v.pi == NIL
	print "non ci sono cammini da s a v"
else print_path(G, s, v.pi)
	print v
}
```
- 2-5 -> sono autoesplicativi
- 6-7 -> richiama se stessa sulla sorgente e `s` e sul predecessore di `v`, in questo modo cammina all'indietro fino ad `s`, lo stampa e, come terminano le chiamate ricorsive stampa tutti altri vertici del cammino nell'ordine
*Complessita'*: $O \left( V \right)$

#### Links
