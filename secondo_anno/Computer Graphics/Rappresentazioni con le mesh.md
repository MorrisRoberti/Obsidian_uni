## Rappresentazione semplice
>Consiste nello specificare tutte le facce della mesh con terne di punti dello spazio tridimensionale.

Ad esempio
![[Pasted image 20240926205829.png]]
Puo' essere rappresentato nel seguente modo
- $T_1 = \lbrace { (a_x, a_y, a_z), (b_x, b_y, b_z), (c_x, c_y, c_z)}\rbrace$
- $T_2 = \lbrace { (b_x, b_y, b_z), (c_x, c_y, c_z), (d_x, d_y, d_z)}\rbrace$
E' *semplice* e *compatta* ma poco efficiente perche' i vertici vengono ripetuti.
Le ricerche di incidenza sono onerose.
Pseudocodice C++
```cpp
typedef struct {
	float v1[3];
	float v2[3];
	float v3[3];
} faccia;
```


## Rappresentazione con lista di vertici (indexed faces)
>Viene eliminata la ridondanza dei vertici inserendo una struttura che tenga traccia di tutti i vertici e facendo in modo che le facce siano triple di puntatori ai vertici, in questo modo possiamo memorizzare i vertici una sola volta.

L'esempio precedente diventa:
- $V = \lbrace {(a_x, a_y, a_z), \dots, (d_x, d_y, d_z)}\rbrace$
- $T_1 = (a, b, c)$
- $T_2 = (b, c, d)$

```cpp
typedef struct {
	float x, y, z;
} vertice;

typedef struct {
	vertice* v1, v2, v3;
} faccia;
```
Le ricerche di incidenza *continuano ad essere complesse*.

## Rappresentazione con lista di spigoli
>Si costruisce una lista di vertici senza ripetizioni e una lista di spigoli composti dai due puntatori ai vertici incidenti sullo spigolo e i due puntatori alle facce incidenti sullo spigolo. Ciascuna faccia viene descritta dai puntatori degli spigoli che la compongono.

![[Pasted image 20240926210857.png]]
Dove:
- $V = \lbrace {(a_x, a_y, a_z), \dots, (d_x, d_y, d_z)}\rbrace$
- $I_1 = (b, a, T_1, NULL)$
- $I_2 = (b, c, T_1, T_2)$
- $I_3 = (a, c, T_1, NULL)$
- $T_1 = (I_1, I_2, I_3)$
In questo modo **si semplificano di molto** le ricerche di incidenza spigolo-faccia.

## Rappresentazione Winged-edge
>E' una rappresentazione piu' dettagliata nella quale ogni spigolo e' orientato e contiene, oltre ai vertici, due puntatori alle facce adiacenti piu' i puntatori ai 4 spigoli collegati ai vertici estremi.
>Ogni vertice contiene un puntatore ad uno degli spigoli che incide su di esso e le sue coordinate.
>Una faccia e' definita da un puntatore ad uno dei lati che vi incide.

![[Pasted image 20240926211433.png]]
Il vantaggio e' che la ricerca e' ancora piu' efficiente.

## Rappresentazione Half-Edged
>Ogni spigolo viene suddiviso in due mezzi spigoli orientati in modo opposto (*half-edge*). Ogni half-edge contiene: un puntatore al vertice dal quale esce, alla faccia a cui appartiene, all'half-edge gemello ed all'half-edge successivo.
>Ogni vertice contiene un puntatore ad uno qualsiasi degli half-edge uscenti e le coordinate.
>Ogni faccia contiene il puntatore ad uno dei suoi half-edge.


![[Pasted image 20240926211836.png]]
E' piu' efficiente rispetto a Winged-Edge.

#### Links

