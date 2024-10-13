>Le [[Trasformazioni 2D]] elementari possono essere composte attraverso la moltiplicazione di matrici.

#### Vantaggi della composizione tra matrici
- La rappresentazione con coordinate omogenee consente di combinare un numero arbitrario di trasformazioni, il risultato e' sempre una matrice $3 \times 3$. La trasformazione risultante dalla combinazione puo' essere applicata ad un punto utilizzando una sola moltiplicazione matrice per vettore
- Spesso e' piu' semplice scrivere una trasformazione complessa come composizione di trasformazioni elementari piuttosto che cercare di ottenere direttamente il risultato finale
- La **trasformazione finale** (rispetto alla terna fissa del mondo) si ottiene moltiplicando da destra a sinistra le singole matrici nell'ordine in cui si succedono (perche' la moltiplicazione di matrici non e' commutativa)


### Rotazione intorno ad un punto
**Trasformazioni da effettuare**
1. Traslazione del punto nell'origine
2. Rotazione intorno all'origine
3. Traslazione del punto nella posizione iniziale
![[Pasted image 20241013223847.png]]
$$T(x_1, y_1) \cdot R(\theta) \cdot T(-x_1, -y_1) = 
\begin{bmatrix} 1 & 0 & x_1 \\ 0 & 1 & y_1 \\ 0 & 0 & 1\end{bmatrix} \cdot
\begin{bmatrix} \cos{\theta} & -\sin{\theta} & 0 \\ \sin{\theta} & \cos{\theta} & 0 \\ 0 & 0 & 1\end{bmatrix} \cdot
\begin{bmatrix} 1 & 0 & -x_1 \\ 0 & 1 & -y_1 \\ 0 & 0 & 1\end{bmatrix}
= \begin{bmatrix} \cos{\theta} & -\sin{\theta} & x_1(1-\cos{\theta})+y_1\sin{\theta} \\ \sin{\theta} & \cos{\theta} & y_1(1-\cos{\theta})-x_1\sin{\theta} \\ 0 & 0 & 1\end{bmatrix}$$
**ATTENZIONE ALL'ORDINE DELLE TRASFORMAZIONI**

### Scale attorno ad un punto arbitrario
1. Traslazione del punto nell'origine
2. Scale
3. Traslazione del punto nella posizione iniziale
$$T(x_1, y_1) \cdot S(s_x, s_y) \cdot T(-x_1, -y_1) = 
\begin{bmatrix} 1 & 0 & x_1 \\ 0 & 1 & y_1 \\ 0 & 0 & 1\end{bmatrix} \cdot
\begin{bmatrix} s_x & 0 & 0 \\ 0 & s_y & 0 \\ 0 & 0 & 1\end{bmatrix} \cdot
\begin{bmatrix} 1 & 0 & -x_1 \\ 0 & 1 & -y_1 \\ 0 & 0 & 1\end{bmatrix}
= \begin{bmatrix} s_x & 0 & x_1(1-s_x) \\ 0 & s_y & y_1(1-s_y) \\ 0 & 0 & 1\end{bmatrix}$$

#### Links 
[[Trasformazioni 2D]]
[[Trasformazioni 2D omogenee]]