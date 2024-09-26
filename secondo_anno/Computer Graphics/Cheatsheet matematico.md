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
### Matrice rettangolare
>Una matrice rettangolare e' una matrice di ordine $m \times n$ dove $m$ e' il numero di righe e $n$ il numero di colonne.

![[Pasted image 20240926103629.png]]

### Matrice quadrata
>Una matrice quadrata e' una matrice di ordine $n$ dove *numero righe = numero colonne = $n$*.

![[Pasted image 20240926103718.png]]
Quella nell'immagine sopra e' anche una matrice **simmetrica**.
#### Matrice simmetrica
>Una matrice **quadrata** si dice **simmetrica** quando gli elementi sono speculari rispetto alla diagonale principale.

Ad esempio
```
|1  2  3|
|2  4  5|
|3  5  6|
```
Per ogni elemento di $A$ e per ogni $i, j \in A$ vale $A_{ij} = A_{ji}$.

#### Matrice diagonale
>Una matrice **quadrata** si dice **diagonale** quando tutti gli elementi *ad esclusione di quelli sulla diagonale principale* sono 0.

![[Pasted image 20240926104558.png]]

#### Matrice identita'
>Una matrice **quadrata** e' detta **matrice identita'** quando tutti i suoi elementi sono 0 ma quelli sulla diagonale principale sono 1.

#### Determinante
>Il deteterminante di 

### Matrice trasposta
>La trasposta di una matrice $A$ di ordine $n \times m$ e' una matrice $A^T$ di ordine $m \times n$ in cui le righe di $A$ sono le colonne di $A^T$ e le colonne di $A$ sono le righe di $A^T$.

![[Pasted image 20240926103805.png]]

### Matrice nulla
>E' facile intuire che la matrice nulla e' quella in cui gli elementi sono tutti uguali a 0. *Qui bisogna fare una precisazione, perche' in realta' zero e' zucchero sintattico per indicare l'elemento neutro di quella struttura algebrica per quella particolare operazione*

### Matrici riga/colonna
>Un caso particolare che si usa di frequente e' quello in cui si hanno matrici di dimensione 1:
>le matrici riga di dimensione $1\times n$ e le matrici colonna di dimensione $n \times 1$. Queste banalmente sono vettori ma conviene vederle come matrici riga o colonna in determinati contesti


## Operazioni

### Somma
>La somma di matrici prende in input due matrici **della stessa dimensione** e somma gli elementi nelle posizioni corrispondenti. Restituisce una matrice di somma.

Esempio
```
        |1  2  3|   |0  3  5|   |1+0  2+3  3+5|   |1   5   8|
A + B = |4  5  6| + |3  6  7| = |4+3  5+6  6+7| = |7  11  13|
        |7  8  9|   |4  2  9|   |7+4  8+2  9+9|   |12 10  18|
```

La somma di matrici ha le seguenti proprieta'
- *commutativa*, quindi $A+B = B + A$
- *associativa*, quindi $(A+B)+C = A+(B+C)$
- *esistenza dell'elemento neutro*, la matrice nulla
- *esistenza dell'opposto*, quindi se esiste $A$ allora esiste $-A$

### Prodotto di una matrice per uno scalare
>E' possibile moltiplicare uno scalare ad una matrice, il risultato sara' quella matrice i cui elementi sono stati tutti moltiplicati per lo scalare

Esempio
```
            |1  2  3|   |k1 k2 k3|
k * A = k * |4  5  6| = |k4 k5 k6|
			|7  8  9|   |k7 k8 k9|
```
 Le proprieta' sono analoghe a quelle del prodotto di un vettore per uno scalare.


### Prodotto di due matrici (riga per colonna)
>Il prodotto di due matrici e' un'operazione che prende una matrice $m\times n$ e la moltiplica ad una $n \times p$. Il prodotto di queste matrici genera un'altra matrice di dimensione $m \times p$ i cui elementi sono gli elementi dell'iesima riga della prima matrice moltiplicati agli elementi dell'iesima colonna della seconda e sommati.

Esempio
![[esercizi-svolti-sulle-matrici-es3-1-2121791453.png]]

**IMPORTANTE**
>Il prodotto di matrici *non e' commutativo*.
