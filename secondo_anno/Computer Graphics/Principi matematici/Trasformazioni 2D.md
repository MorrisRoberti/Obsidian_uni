>Sugli oggetti 2D possiamo eseguire le seguenti trasformazioni: *traslazione, rotazione, scaling* e *trasformazioni composte*.

#### Traslazione
>Dato un punto $P$ di coordinate $(x, y)$, possiamo traslare $P$ in una diversa posizione aggiungendo una certa quantita' alle sue coordinate.
>Per ogni punto $P=(x,y)$ da muovere di $d_x$ lungo $x$ e di $d_y$ lungo $y$ fino a $P=(x',y')$ possiamo scrivere:
>$$ x' = x + d_x $$
>$$ y' = y + d_y $$

![[Pasted image 20241013181204.png]]

Utilizzando la notazione per vettori colonna
$$ P = \begin{bmatrix} x \\ y \end{bmatrix}, \space P'= \begin{bmatrix} x' \\ y' \end{bmatrix}, \space T= \begin{bmatrix} d_x \\ d_y \end{bmatrix}$$
Allora 
$$P' = P + T$$
**IMPORTANTE**
>Per traslare un oggetto, non applichiamo l'incremento $T$ a tutti i suoi punti, in quanto (teoricamente) infiniti, ma applichiamo tale traslazione solo ai suoi vertici, ridisegnando successivamente le linee tra questi.

#### Scaling rispetto all'origin (0, 0)
>Le coordinate di un punto $P=(x,y)$ possono essere scalate di una quantita' $s_x$ l'ungo l'asse $x$ e $s_y$ lungo l'asse $y$ per mezzo delle formule:
>$$x'= s_x \cdot x$$
>$$y'=s_y \cdot y$$

In forma matriciale
$$\begin{bmatrix} x' \\ y' \end{bmatrix} = 
\begin{bmatrix}   s_x & 0 \\ 0 & s_y \end{bmatrix} \cdot \begin{bmatrix}x \\ y \end{bmatrix}$$
Oppure
$$P' = S \cdot P$$

![[Pasted image 20241013182145.png]]

**ATTENZIONE**
>Se facciamo lo *scaling* di un oggetto non simmetrico rispetto all'origine, anche la sua posizione rispetto a quest'ultima verra' modificata.
>![[Pasted image 20241013182638.png]]

#### Rotazione intorno all'origine
>Un punto $P=(x,y)$ puo' essere ruotato di un angolo $\theta$  rispetto all'origine, tale rotazione e' definita matematicamente da
>$$ x' = x \cdot \cos{\theta}  - y \cdot \sin{\theta}$$
>$$y' = x \cdot \sin{\theta} + y \cdot \cos{\theta} $$

In forma matriciale
$$\begin{bmatrix} x' \\ y' \end{bmatrix} =  \begin{bmatrix} \cos{\theta} & -\sin{\theta}  \\ \sin{\theta} & \cos{\theta} \end{bmatrix} \cdot \begin{bmatrix} x \\ y \end{bmatrix}$$
Oppure
$$P' = R \cdot P$$
![[Pasted image 20241013183204.png]]

>La rotazione e' **attorno all'origine** e gli angoli  positivi sono misurati in sento **antiorario** a partire dall'asse $x$  positivo (verso l'asse $y$).

#### Rotazione intorno ad un punto
>La strategia che si utilizza si compone di 3 passi: *traslare l'oggetto per fargli avere centro nell'origine, applicare la rotazione e successivamente ritraslare l'oggetto nella posizione iniziale*.

![[Pasted image 20241013184333.png]]
Quindi
$$\begin{bmatrix} x' \\ y' \end{bmatrix} = \begin{bmatrix} \cos{\theta} & -\sin{\theta} \\ \sin{\theta} & \cos{\theta} \end{bmatrix} \cdot \begin{bmatrix} x-x_0 \\  y - y_0 \end{bmatrix} + \begin{bmatrix} x_0 \\ y_0 \end{bmatrix}$$
Ovvero
$$x' = (x - x_0)\cos{\theta} - (y-y0)\sin{\theta} + x_0$$

$$y' = (x - x_0)\sin{\theta} + (y - y_0)\cos{\theta} + y_0$$


**ATTENZIONE**
>Nell'esempio sopra, il punto $(x_0, y_0)$ definisce gia' il centro dell'oggetto e non un suo vertice, il centro e' $(width / 2, height / 2)$.

#### Links
[[Trasformazioni 2D omogenee]]