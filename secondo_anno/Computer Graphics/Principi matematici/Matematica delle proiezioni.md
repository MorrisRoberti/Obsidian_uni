>Possiamo sfruttare delle semplici operazioni geometriche per rappresentare le proiezioni.

### Proiezioni parallele
>Proiezione ortografica sul piano $z = 0$.

La direzione di proiezione e' perpendicolare al piano di proiezione, cioe' l'asse $z$ in questo caso.
$x_p = x, \space y_p=y$
$$M_{ort} = \begin {bmatrix}1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 1 \end {bmatrix}$$

>Proiezione parallela sul piano $xy$ lungo un vettore direzione $[x_D, y_D, z_D]$. *Dato un punto $P(x, y, z)$, determinare la sua proiezione $(x_p, y_p, z_p)$.*

Equazione della retta passante per un punto $(x, y, z)$, con direzione parallela a quella di proiezione:
$x_p = x + x_D \cdot t$ 

$y_p = y + y_D \cdot t$ 

$z_p = z + z_D \cdot t$ 
Ponendo $z_p = 0$, si ottiene $t = - \frac{z}{z_D}$. Sostituendo nelle prime due equazioni abbiamo:
$x_p = x - z (\frac{x_D}{z_D})$

$y_p = y - z (\frac{y_D}{z_D})$
In forma matriciale in coordinate omogenee:
$$\begin{bmatrix} x_p \\ y_p \\ z_p \\ 1 \end {bmatrix} = \begin {bmatrix} 1 & 0 & -\frac{x_D}{z_D} & 0 \\ 0 & 1 & -\frac{y_D}{z_D} & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 1\end {bmatrix} \cdot \begin{bmatrix} x \\ y \\ z \\ 1 \end {bmatrix} = \begin{bmatrix} x - \frac{x_D}{z_D}z \\ y - \frac{y_D}{z_D}z \\ 0 \\ 1\end{bmatrix}$$

### Proiezioni prospettiche
>Proiezioni prospettiche aventi il piano di proiezione normale all'asse $z$ a distanza $d$ dall'origine con centro di proiezione coincidente con l'origine.

$\frac{x_p}{d} = \frac{x}{z}, \space \frac{y_p}{d} = \frac{y}{z}$

$x_p = \frac{d\cdot x}{z} = \frac{x}{z/d}, \space y_p = \frac{d \cdot y}{z} = \frac{y}{z/d}$

![[Pasted image 20241108112648.png]]

La distanza $d$ corrisponde quindi ad un semplice fattore di scala per $x_p$ e $y_p$. La divisione per $z$ rende la proiezione degli oggetti lontani piu' piccola di quella degli oggetti vicini. Tutti i valori di $z$ sono accettabili, tranne lo 0.

La trasformazione prospettica puo' essere espressa in coordinate omogenee mediante una matrice $4\times4$ :
$$M_{per} \cdot P = \begin {bmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 1/d & 0 \end {bmatrix} \cdot \begin{bmatrix} x \\ y \\ z \\ 1\end{bmatrix} = \begin{bmatrix} x & y & z & \frac{z}{d}\end {bmatrix}^T = \begin{bmatrix} \frac{x}{z/d} & \frac{y}{z/d} & d & 1\end {bmatrix}^T$$

>Proiezione prospettica sul piano $xy$ con centro di proiezione $(x_c, y_c ,z_c)$. *Dato un punto di proiezione $P(x, y, z)$, determinare la sua proiezione $(x_p, y_p, z_p)$.*

Equazione della retta passante per il centro di proiezione e per il punto $P$:
$x_p = x_c + (x - x_c)\cdot t$

$y_p = y_c + (y - y_c)\cdot t$

$z_p = z_c + (z - z_c)\cdot t$

Si pone $z_p = 0$, si ottiene $t = \frac{z_c}{z - z_c}$. Poi si sostituisce $t$ nelle espressioni di $x_p$ e $y_p$:
$x_p=x_c - z_c(\frac{x - x_c}{z - z_c}), \space y_p = y_c - z_c (\frac{y - y_c}{z - z_c})$

In forma matriciale, in coordinate omogenee:
$$\begin{bmatrix} x_p \\ y_p \\ z_p \\ 1 \end {bmatrix} = \begin {bmatrix} -z_c & 0 & x_c & 0 \\ 0 & -z_c & y_c & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 1 & -z_c\end {bmatrix} \cdot \begin{bmatrix} x \\ y \\ z \\ 1 \end {bmatrix} = \begin{bmatrix} -z_cx + x_cz \\ -z_cy + y_cz \\ 0 \\ z-z_c\end{bmatrix} = \begin{bmatrix} \frac{-z_cx + x_cz}{z-z_c} \\ \frac{-z_cy + y_cz}{z-z_c} \\ 0 \\ 1 \end{bmatrix}$$
#### Links
[[Proiezioni Geometriche]]