>A differenza delle matrici nelle [[Trasformazioni 2D]], le matrici delle **trasformazioni 3D** sono $4 \times 4$. I punti si esprimono come vettori colonna di quattro elementi. Si utilizza un sistema destrorso.

![[Pasted image 20241014135436.png]]

**DIREZIONI DI ROTAZIONE**
Le rotazioni di angolo positivo rispetto a ciascun asse sono definite in senso antiorario guardando dalla parte positiva dell'asse verso l'origine.
Una rotazione di 90º (positiva) rispetto ad un asse trasforma quindi uno dei due rimanenti assi positivi nel terzo.

| Asse di rotazione | La direzione di una rotazione positiva e' |
| ----------------- | ----------------------------------------- |
| $X$               | da $Y$ verso $Z$                          |
| $Y$               | da $Z$ verso $X$                          |
| $Z$               | da $X$ verso $Y$                          |

#### Traslazione con coordinate omogenee
>La traslazione e' una semplice estensione del caso bidimensionale

$$T(d_x, d_y, d_z) = \begin{bmatrix} 1 & 0 & 0 & d_x \\ 0 & 1 & 0 & d_y \\ 0 & 0 & 1 & d_z \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

Infatti $T(d_x, d_y, d_z) \cdot [x \space y \space z \space 1]^T = [x + d_x \space y+d_y \space z+d_z \space 1]^T$
\
![[Pasted image 20241014140558.png]]

#### Scaling con coordinate omogenee
>Lo scaling, come sopra, e' una semplice estensione del caso bidimensionale.

$$S(s_x, s_y, s_z) = \begin{bmatrix} s_x & 0 & 0 & 0 \\ 0 & s_y & 0 & 0 \\ 0 & 0 & s_z & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

Infatti $S(s_x, s_y, s_z) \cdot [x \space y \space z \space 1]^T = [x \cdot s_x \space y \cdot s_y \space z \cdot s_z \space 1]^T$

![[Pasted image 20241014140912.png]]


#### Rotazione con coordinate omogenee
>La rotazione si complica leggermente rispetto al caso bidimensionale, nel senso che e' necessario definire 3 rotazioni di base, attorno a ciascuno dei 3 assi: *x, y* e *z*.

##### Rotazione intorno all'asse z

$$R_z(\theta) = \begin{bmatrix} \cos{\theta} & -\sin{\theta} & 0 & 0 \\ \sin{\theta} & \cos{\theta} & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

![[Pasted image 20241014141619.png]]


##### Rotazione intorno all'asse x

$$R_x(\theta) = \begin{bmatrix} 1 & 0 & 0 & 0 \\  0 & \cos{\theta} & -\sin{\theta} & 0 \\ 0 & \sin{\theta} & \cos{\theta} & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

![[Pasted image 20241014141751.png]]


##### Rotazione intorno all'asse y

$$R_y(\theta) = \begin{bmatrix} \cos{\theta} & 0 & \sin{\theta} & 0 \\  0 & 1 & 0 & 0 \\ -\sin{\theta} & 0 & \cos{\theta} & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

![[Pasted image 20241014141954.png]]


**ATTENZIONE**
>Le colonne e le righe delle sottomatrici $3 \times 3$ in alto a sinistra nelle 3 matrici di rotazione descritte sopra, sono vettori unitari mutuamente perpendicolari e le sottomatrici hanno determinante unitario, il che significa che sono **ortogonali**.


### Inversa delle matrici viste
>Tutte le matrici di trasformazione viste ammettono l'inversa.

- L'inversa di una *traslazione T* si ottiene cambiando segno a $d_x$, $d_y$ e $d_z$
- L'inversa dello *scaling S* si ottiene prendendo il reciproco di $s_x$, $s_y$ e $s_z$
- L'inversa delle *tre matrici di rotazione* si ottiene cambiando il segno di $\theta$

Essendo la rotazione una matrice ortogonale, l'inversa si puo' calcolare piu' semplicemente con la trasposta
$$B^{-1} = B^T$$

### Altre trasformazioni
#### Riflessione
>Rispetto al piano $zy$, con $x = 0$

$$T_{RFL_{zy}} = \begin{bmatrix} -1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

![[Pasted image 20241014144901.png]]


>Rispetto al piano $zx$, con $y=0$

$$T_{RFL_{zx}} = \begin{bmatrix} 1 & 0 & 0 & 0 \\ 0 & -1 & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

>Rispetto al piano $xy$, con $z=0$

$$T_{RFL_{xy}} = \begin{bmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & -1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

#### Shear
>Shear lungo piano $xy$, $z$ invariata

$$SH_{xy}(sh_x, sh_y) = \begin{bmatrix} 1 & 0 & sh_x & 0 \\ 0 & 1 & sh_y & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

![[Pasted image 20241014145057.png]]

## Importante
>Una matrice di trasformazione puo' essere divisa in 4 zone

![[Pasted image 20241014192906.png]]

- $3 \times 3$ Rotazione e/o scala differenziata, riflessione e shear
- $3 \times 1$ Traslazione
- $1 \times 3$ Proiezione
- $1 \times 1$ Fattore di scala uniforme

## Convenzioni
>Matrice di trasformazione **pre-moltiplicata** al vettore colonna

Convenzione per vettori colonna
$$\begin{bmatrix} x' \\ y' \\ z' \\ 1 \end{bmatrix} = \begin{bmatrix} A & B & C  & D \\ E & F & G & H \\ I & J & K & L \\ 0 & 0 & 0 & 1 \end{bmatrix} \cdot \begin{bmatrix} x \\ y \\ z \\ 1 \end{bmatrix}$$
>Matrice di trasformazione post-moltiplicata al vettore riga

Convenzione per vettori riga
$$ \begin{bmatrix} x' & y' & z' & 1 \end{bmatrix} = \begin{bmatrix} x & y & z & 1 \end{bmatrix} \cdot \begin{bmatrix} A & E & I  & 0 \\ B & F & J & 0 \\ I & J & K & 0 \\ D & H & L & 1 \end{bmatrix}$$

**SONO EQUIVALENTI**
>E' sufficiente trasporre le matrici e i vettori
>$$ (M*P)^T=P^T*M^T$$


#### Links
[[Trasformazioni 2D omogenee]]
[[Trasformazioni composte 3D]]