>La **pipeline grafica programmabile** si riferisce ad un insieme di stadi che i dati grafici attraversano per essere trasformati in immagini che verranno poi proiettate sullo schermo.

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

### 4) Viewport Transformation
>La **viewport transformation** e' quella fase della pipeline che si occupa di mappare le coordinate 2D degli oggetti alle coordinate dello schermo (o *viewport*).

### 5) Rasterization
>La **rasterization** e' il passaggio della pipeline che converte le primitive geometriche in pixel o *fragments*. Durante la rasterizzazione il sistema determina quali pixel dello schermo sono attraversati da una primitiva e calcola i valori di colore e profondita' di ciascun pixel.

### 6) Fragment shader
>Successivamente, c'e' il **fragment shader** in cui, appunto, i *fragment shader* vengono applicati agli oggetti e quindi per ogni *fragment* generato dalla *rasterizzazione* vengono calcolati attributi visivi quali: texture, colore, illuminazione e effetti speciali.



