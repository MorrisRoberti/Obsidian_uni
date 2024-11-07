>Possiamo sfruttare delle semplici operazioni geometriche per rappresentare le proiezioni.

### Proiezioni parallele
>Proiezione ortografica sul piano $z = 0$.

La direzione di proiezione e' perpendicolare al piano di proiezione, cioe' l'asse $z$ in questo caso.
$x_p = x, \space y_p=y$
$$M_{ort} = \begin {bmatrix}1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 1 \end {bmatrix}$$

>Proiezione parallela sul piano $xy$ lungo un vettore direzione $[x_D, y_D, z_D]$. Dato un punto $P(x, y, z)$, determinare la sua proiezione $(x_p, y_p, z_p)$.

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

La distanza $d$ corrisponde quindi ad un semplice fattore di scala per $x_p$ e $y_p$. La divisione per $z$ rende la proiezione degli oggetti lontani piu' piccola di quella degli oggetti vicini. Tutti i valori di $z$ sono accettabili, tranne lo 0.

La trasformazione prospettica puo' essere espressa in coordinate omogenee mediante una matrice $4\times4$ :
