>La **pipeline grafica programmabile** si riferisce ad un insieme di stadi che i dati grafici attraversano per essere trasformati in immagini che verranno poi proiettate sullo schermo.

## Schema generale

![[Pasted image 20241108151100.png]]

Possiamo distinguere le seguenti fasi.
### 1) Modeling Transformation
>La **modeling transformation** e' un concetto che si riferisce al processo di trasformazione di un oggetto 3D da un sistema di coordinate *locale* ad un sistema di coordinate *globale*. Tale passaggio e' fondamentale per posizionare, ruotare e scalare gli oggetti all'interno di una scena 3D.

![[Pasted image 20241108120408.png]]

### 2) Viewing Transformation
>La **viewing transformation** e' un concetto che si riferisce al processo di definire come una scena 3D viene visualizzata da un punto di vista specifico, ovvero e' il processo in cui tutti gli elementi della scena vengono convertiti nel sistema di riferimento della telecamera virtuale.

![[Pasted image 20241108121051.png]]

**IMPORTANTE**
>Si noti che nella fase di *viewing transformation*, cio' che viene modificato e' il punto di osservazione della scena, e che quindi gli oggetti restano immutati. Diversamente nella *modeling transformation* sono proprio gli oggetti ad essere modificati (applicazione di scaling, rotazione, traslazione etc).

### 3) Projection Transformation
>La **projection transformation** e' la fase della pipeline grafica, successiva alla *viewing transformation* che, una volta ottenute le coordinate degli oggetti 3D nel sistema di riferimento della camera, si occupa di convertire tali coordinate 3D in coordinate 2D seguendo il modello di [[Proiezioni Geometriche||proiezione]] stabilito.

Quindi alla fine della *projection transformation*, avviene il **clipping** della scena 3D e infine questa risulta essere contenuta in un *viewing volume* canonico, cioe' un *cubo le cui coordinate x, y e z sono comprese tra -1 e +1*.
![[Pasted image 20241108122031.png]]

**Clipping**
>Il processo di **clipping** di una scena 3D e' quello che decide quali parti della scena tenere e quali lasciare, in base al fatto che saranno visualizzate o meno. E' un modo efficiente per evitare di disegnare, ad esempio, la parte posteriore di un oggetto che non verra' mai visualizzata.

#### Per proiezioni parallele
La *projection transformation* quindi mappa il viewing volume di una generica proiezione parallela $[l,r]\times[b,t]\times[n,f]$ nel volume di vista canonico $[-1, +1] \times [-1, +1] \times [-1, + 1]$ e si ottiene come composizione di una traslazione (per portare il centro del parallelepipedo nell'origine), seguita da un'operazione di scaling:
$$ M_{orth} = \begin{bmatrix} \frac{2}{r-l} & 0 & 0 & 0 \\ 0 & \frac{2}{t-b} & 0 & 0 \\ 0 & 0 & \frac{2}{n-f} & 0 \\ 0 & 0 & 0 & 1\end{bmatrix} \begin{bmatrix} 1 & 0 & 0 & -\frac{l+r}{2} \\ 0 & 1 & 0 & -\frac{b+t}{2} \\ 0 & 0 & 1 & -\frac{n+f}{2} \\ 0 & 0 & 0 & 1\end {bmatrix} = \begin{bmatrix} \frac{2}{r-l} & 0 & 0 & -\frac{r+l}{r-l} \\ 0 & \frac{2}{t-b} & 0 & -\frac{t+b}{t-b} \\ 0 & 0 & \frac{2}{n-f} & -\frac{n+f}{n-f} \\ 0 & 0 & 0 & 1 \end {bmatrix} $$
#### Per proiezioni prospettiche
Occorre una trasformazione aggiuntiva che mappa (distorce) il *view volume* in un volume di vista ortografico, in modo che il risultato della successiva proiezione ortografica sia identico a quello che si avrebbe applicando la sola proiezione prospettica. Il vantaggio di questa operazione e' che la fase di clipping e' piu' semplice perche' avviene rispetto al volume di vista canonico.
![[Pasted image 20241108192226.png]]
La trasformazione che assolve a questa funzione e' la seguente:
$$\begin{bmatrix} n & 0 & 0 & 0 \\ 0 & n & 0 & 0 \\ 0 & 0 & n + f & -fn \\ 0 & 0 & 1 & 0 \end{bmatrix}$$
Quindi:
$$\begin{bmatrix} n & 0 & 0 & 0 \\ 0 & n & 0 & 0 \\ 0 & 0 & n + f & -fn \\ 0 & 0 & 1 & 0 \end{bmatrix}\cdot \begin{bmatrix} x \\ y \\ z \\ 1\end{bmatrix} = \begin{bmatrix} nx \\ ny \\ z(n+f)-nf \\ z \end {bmatrix} = \begin{bmatrix} \frac{nx}{z} \\ \frac{ny}{z} \\ n+f-\frac{fn}{z} \\ 1 \end{bmatrix}$$
**Attenzione**
>Il modello non gestisce le proiezioni oblique.

### 4) Viewport Transformation
>La **viewport transformation** e' quella fase della pipeline che si occupa di mappare le coordinate 2D degli oggetti alle coordinate dello schermo (o *viewport*).

Il view volume canonico e' un cubo $[-1, +1] \times [-1, +1] \times [-1, +1]$. La viewport transformation prende le coordinate 3D normalizzate, anche dette *NDC* (*Normalized Device Coordinates*) e le mappa nelle 3D *Window coordinates* -> quindi banalmente lascia il vlaore di $z$ inalterato e mappa la faccia del cubo sul *near plane*.

![[Pasted image 20241108152252.png]]

La matrice che effettua tale trasformazione e' la seguente:
$$M_{vp} = \begin{bmatrix} \frac{n_x}{2} & 0 & 0 & \frac{n_x}{2} - \frac{1}{2} \\ 0 & \frac{n_y}{2} & 0 & \frac{n_y}{2} - \frac{1}{2} \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix}$$
(l'immagine cosi' ottenuta dovra' essere ulteriormente traslata nella sua posizione finale sullo schermo)

### 5) Rasterization
>La **rasterization** e' il passaggio della pipeline che converte le primitive geometriche in pixel o *fragments*. Durante la rasterizzazione il sistema determina quali pixel dello schermo sono attraversati da una primitiva e calcola i valori di colore e profondita' di ciascun pixel.

### 6) Fragment shader
>Successivamente, c'e' il **fragment shader** in cui, appunto, i *fragment shader* vengono applicati agli oggetti e quindi per ogni *fragment* generato dalla *rasterizzazione* vengono calcolati attributi visivi quali: texture, colore, illuminazione e effetti speciali.

#### Links
[[Pipeline di rendering]]
