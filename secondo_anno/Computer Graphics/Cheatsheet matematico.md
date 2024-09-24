# Vettori
>Consideriamo un vettore $v\in R^3$ del tipo $v = (x, y, z)$ 

#### Vettore applicativo
>C'e' un tipo di vettore particolare chiamato **vettore applicativo** fatto nel seguente modo $(P, v)$ dove $P$ rappresenta un *punto di origine* e $v$ il vettore stesso. Si usa per indicare il vettore in funzione di una particolare origine $P$.
## Operazioni

##### Calcolo della norma di un vettore (modulo)
$\vert v\vert = \sqrt{x^2 + y^2 + z^3}$  

##### Direzione di un vettore
coseni dei 3 angoli formati con le 3 direzioni principali

##### Calcolo del versore (vettore di modulo unitario)
$u = \frac{v}{\vert v\vert}$ 

##### Somma di vettori
prendiamo $u,v \in R^n$,
$u+v = (u_1,u_2,...,u_n) + (v_1, v_2, ..., v_n) = (u_1 + v_1, u_2 + v_2, ..., u_n + v_n)$ 

#### Prodotto di uno scalare per un vettore
prendiamo $\alpha \in N$ e $v \in R^n$, 
$\alpha v = (\alpha v_1, \alpha v_2, ...,  \alpha v_n)$ 
##### Proprieta'
- $(\alpha \beta)v = \alpha (\beta v)$ 
- $(\alpha + \beta)v = \alpha v + \beta v$
- $\alpha (v+w) = \alpha v + \alpha w$
- $1v = v$
- $\alpha v= (\alpha v_1, \alpha v_2, ..., \alpha v_n)$ per $v \in R^n$

#### Prodotto scalare (dot product)
prendiamo $u, v \in R^n$,
$u \cdot v = (u_1, u_2, ..., u_n) \cdot (v_1, v_2, ..., v_n) = (u_1 v_1, u_2 v_2, ..., u_n v_n)$
*oppure*
$u \cdot v = \vert u \vert \vert v \vert \cos{\theta}$ 
##### Proprieta'
- $v\cdot v = \vert v^2 \vert$ 
- $u \cdot v = v \cdot u$ (commutativita')
- $\vert u \cdot v \vert \leq \vert u \vert  \vert v \vert$ (disuguaglianza di Cauchy-Schwartz)
- **Il prodotto scalare di vettori ortogonali e' nullo** 

#### Prodotto vettoriale (cross product)
prendiamo $u, v \in R^3$,
$u \times v = (u_y v_z - u_z v_y, -u_x v_z + u_z v_x, u_x v_y - u_y v_x)$ 
*oppure*
$\vert u \times v \vert = \vert u \vert \vert v \vert \sin{\theta}$ 
il significato geometrico e' che $u \times v$ e' un vettore **ortogonale sia a u che a v**
##### Proprieta'
- $u \times v = -(v \times u)$ (antisimmetrica)
- $u \times u = 0$
- $u \times v = 0$ *sse* $u$ e $v$ sono paralleli o uno dei due e' nullo
- $\vert u \times v \vert = \vert u \vert \vert v \vert$ *se* $u$ e $v$ sono perpendicolari
- $u \times (v + w) = u \times v + u \times w$ (distributiva)


## Proprieta'

##### Commutativa
$u+v = v+u$

##### Associativa
$(u+v)+w = u+(v+w)$

##### Esistenza del vettore nullo
$u+0=0+u=u$

##### Esistenza del vettore opposto
$v+(-v)=0$

# Matrici
>Una **matrice** e' un insieme omogeneo di elementi matematici ordinato per righe e colonne, dove ogni elemento viene individuato con la notazione $a_{ij}$ dove $i$ indica la riga e $j$ indica la colonnal

## Tipi di matrici
#### Matrice rettangolare
>Una matrice rettangolare e' una matrice di ordine $n \times m$ dove $n$ e' il numero di righe e $m$ il numero di colonne.

#### Matrice quadrata
>Una matrice quadrata e' una matrice di ordine $n$ dove *numero righe = numero colonne = $n$*.

#### Matrice trasposta
>La trasposta di una matrice $A$ di ordine $n \times m$ e' una matrice $A^T$ di ordine $m \times n$ in cui le righe di $A$ sono le colonne di $A^T$ e le colonne di $A$ sono le righe di $A^T$.


