>Un grafo **non orientato** (o *non diretto*) e' un grafo in cui non viene tenuto conto della direzione degli archi, quindi $(u, v) = (v, u)$ 

- Se un arco $(u, v)$ e' un arco in un grafo orientato, diciamo che questo e' **incidente** nei vertici $u$ e $v$
- Vale la relazione di **adiacenza** come per i grafi orientati, tuttavia in questo caso e' **sempre simmetrica**

### Grado di un vertice
>Il **grado di un vertice** in un grafo non orientato, e' il numero di archi che incidono nel vertice.

![[Pasted image 20240628124113.png]]
- Grado(1) -> 2
- Grado(4) -> 0

Un vertice con grado 0 si dice **isolato**

### Cicli
>in un grafo non orientato un cammino forma un **ciclo semplice** se $v_0 = v_k$ e $k\ge3$
![[Pasted image 20240628130732.png]]

**ATTENZIONE**
In un grafo non orientato **i cappi non sono ammessi**
### Grafi connessi
>Un grafo non orientato si dice **connesso** se ogni coppia di vertici e' collegata attraverso un cammino

Le **componenti connesse** di un grafo non orientato sono le classi di equivalenza secondo la relazione "e' raggiungibile da"
![[Pasted image 20240628130441.png]]
#### Links