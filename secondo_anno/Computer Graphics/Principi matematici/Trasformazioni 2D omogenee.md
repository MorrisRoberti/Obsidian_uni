>Come visto in [[Trasformazioni 2D]], le rappresentazioni matriciali per *traslazione, scaling* e *rotazione* sono
>$$P' = T + P,\space P' = S \cdot P, \space P' = R \cdot P$$

La *traslazione* e' trattata in modo diverso dalle altre, sarebbe meglio poter esprimere tutte le trasformazioni nello stesso modo
## Coordinate omogenee
>La rappresentazione **omogenea** di un punto $P$ nel piano e': $P = [xw \space yw \space w], \space w \neq 0$ dunque
>il punto *bidimensionale* $P=(x, y)$ diventera' $P'= (xw, yw, w)$.

Alcune considerazioni
- La rappresentazione omogenea non e' univoca a meno di un fattore moltiplicativo
- La terna $(0, 0, 0)$ non e' ammessa
- Le terne $(12, 8, 4)$, $(6, 4, 2)$ e $(3, 2, 1)$ rappresentano tutte il punto $(3, 2)$
- Adottiamo $w=1$, quindi avremo terne della forma $P=(x, y, 1)$

Poiche' i punti sono ora rappresentati da tre coordinate, le matrici che definiscono le trasformazioni geometriche bidimensionali saranno $3\times3$
$$\begin{bmatrix} x' \\ y' \\ 1 \end{bmatrix} = M \cdot \begin{bmatrix} x \\ y \\ 1 \end{bmatrix}$$
Dove $M$ e' una matrice $3 \times 3$ opportuna.

### Trasformazioni con coordinate omogenee
#### Traslazione
>La traslazione diventa

$$\begin{bmatrix} x' \\ y' \\ 1 \end{bmatrix} = \begin{bmatrix} 1 & 0 & d_x \\ 0 & 1 & d_y \\ 0 & 0 & 1\end{bmatrix} \cdot \begin{bmatrix} x \\ y \\ 1 \end{bmatrix}$$
Se si indicano con $P$ e $P'$ i vettori colonna di tre elementi in coordinate omogenee possiamo scrivere in forma compatta
$$ P' =T(d_x, d_y) \cdot P $$
dove 
$$ T = \begin{bmatrix} 1 & 0 & d_x \\ 0 & 1 & d_y \\ 0 & 0 & 1\end{bmatrix}$$

**ATTENZIONE**
>Cosa succede se noi trasliamo prima il punto $P$ di $T(d_{x1}, d_{y1})$ fino a $P'$ e poi trasliamo questo di nuovo di $T(d_{x2}, d_{y2})$ da $P'$ a $P''$ ?
>Come intuibile si tratta di una traslazione complessiva $T(d_{x1}+d_{x2}, d_{y1}+d_{y2})$.

Tuttavia possiamo ricavare un'importante uguaglianza.
Sapendo che $P' = T(d_{x1}, d_{y1}) \cdot P$ e che $P'' = T(d_{x2}, d_{y2}) \cdot P'$ possiamo sostituire la prima nella seconda e ottenere  $P'' = T(d_{x2}, d_{y2}) \cdot (T(d_{x1}, d_{y1}) \cdot P) = (T(d_{x2},d_{y2}) \cdot T(d_{x1}, d_{y1})) \cdot P$
Il prodotto delle due matrici e'
$$ \begin{bmatrix} 1 & 0 & d_{x2} \\ 0 & 1 & d_{y2} \\ 0 & 0 & 1\end{bmatrix} \cdot \begin{bmatrix} 1 & 0 & d_{x1} \\ 0 & 1 & d_{y1} \\ 0 & 0 & 1\end{bmatrix} = \begin{bmatrix} 1 & 0 & d_{x_1} + d_{x2} \\ 0 & 1 & d_{y1} + d_{y2} \\ 0 & 0 & 1\end{bmatrix}$$
La traslazione complessiva e' quindi
$$T(d_{x1} + d_{x2}, d_{y1} + d_{y2}) = T(d_{x2}, d_{y2}) \cdot T(d_{x1}, d_{y1})$$
Abbiamo dimostrato che **la composizione di traslazioni si traduce in una moltiplicazione tra matrici**.

#### Scaling con coordinate omogenee
>In modo analogo l'equazione di scaling diventa

$$\begin{bmatrix} x' \\ y' \\ 1\end{bmatrix} =
\begin{bmatrix} s_x & 0 & 0 \\ 0 & s_y & 0 \\ 0 & 0 & 1\end{bmatrix} \cdot \begin{bmatrix} x \\ y \\ 1\end{bmatrix}$$
Definendo
$$S(s_x, s_y) = \begin{bmatrix} s_x & 0 & 0 \\ 0 & s_y & 0 \\ 0 & 0 & 1\end{bmatrix}$$
Si ottiene
$$P' = S(s_x, s_y) \cdot P$$


Composizione di due trasformazioni di scaling $P' = S(s_{x1}, s_{y1}) \cdot P$ e $P' = S(s_{x2}, s_{y2}) \cdot P'$.
Sostituendo la prima nella seconda si ottiene
$$P'' = S(s_{x2}, s_{y2}) \cdot (S(s_{x1}, s_{y1}) \cdot P) = (S(s_{x2}, s_{y2}) \cdot S(s_{x1}, s_{y1})) \cdot P$$
Dove il prodotto delle due matrici
$$\begin{bmatrix} s_{x2} & 0 & 0 \\ 0 & s_{y2} & 0 \\ 0 & 0 & 1\end{bmatrix} \cdot 
\begin{bmatrix} s_{x1} & 0 & 0 \\ 0 & s_{y1} & 0 \\ 0 & 0 & 1\end{bmatrix} = \begin{bmatrix} s_{x1} \cdot s_{x2} & 0 & 0 \\ 0 & s_{y2}\cdot s_{y1} & 0 \\ 0 & 0 & 1\end{bmatrix}$$

#### Rotazione con coordinate omogenee
>Analogamente

$$\begin{bmatrix} x' \\ y' \\ 1\end{bmatrix} = \begin{bmatrix} \cos{\theta} & -\sin{\theta} & 0 \\ \sin{\theta} & \cos{\theta} & 0 \\ 0 & 0 & 1\end{bmatrix} \cdot \begin{bmatrix} x \\ y \\ 1\end{bmatrix} $$
Ponendo
$$R(\theta) = \begin{bmatrix} \cos{\theta} & -\sin{\theta} & 0 \\ \sin{\theta} & \cos{\theta} & 0 \\ 0 & 0 & 1\end{bmatrix} $$
Otteniamo
$$P' = R(\theta) \cdot P$$
#### Shear con coordinate omogenee
>Lo **shear** o deformazione di taglio
>![[Pasted image 20241013221721.png]]
>Data la forma normale a sinistra, la trasformazione centrale si ottiene tramite la matrice definita come segue
>$$SH_x = \begin{bmatrix} 1 & a & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1\end{bmatrix}$$
>Mentre la trasformazione a destra si ottiene con
>$$SH_y =  \begin{bmatrix} 1 & 0 & 0 \\ b & 1 & 0 \\ 0 & 0 & 1\end{bmatrix}$$ Dove $a$ e $b$ sono costanti di proporzionalita'.

Considerando la deformazione di taglio lungo $x$ di un generico punto si ottiene
$$SH_x \cdot P = \begin{bmatrix} 1 & a & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1\end{bmatrix} \cdot \begin{bmatrix} x \\ y \\ 1\end{bmatrix} = \begin{bmatrix} x+ay \\ y \\  1\end{bmatrix}$$
Si tratta di una traslazione lungo $x$ che dipende da $y$.

### Altre trasformazioni

#### Riflessione
>Rispetto all'asse $x$ con $y=0$

![[Pasted image 20241013224514.png]]

$$T_{RFL_x} = 
\begin{bmatrix} 1 & 0 & 0 \\ 0 & -1 & 0 \\ 0 & 0 & 1\end{bmatrix}$$


>Rispetto all'asse $y$ con $x=0$

![[Pasted image 20241013224620.png]]
$$T_{RFL_y} = 
\begin{bmatrix} -1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1\end{bmatrix}$$


>Rispetto all'origine $(0,0)$

![[Pasted image 20241013224709.png]]
$$T_{RFL(0,0)} = 
\begin{bmatrix} -1 & 0 & 0 \\ 0 & -1 & 0 \\ 0 & 0 & 1\end{bmatrix}$$

## Importante
>Una matrice di trasformazione (omogenea) puo' essere suddivisa in 4 zone

![[Pasted image 20241013224804.png]]
1. $2 \times 2$ Rotazione e/o scale differenziata, riflessione e shear
2. $2 \times 1$ Traslazione
3. $1\times2$ Proiezione
4. $1 \times 1$ Fattore di scaling uniforme

#### Links
[[Trasformazioni 2D]]
[[Cheatsheet matematico#Matrici]]