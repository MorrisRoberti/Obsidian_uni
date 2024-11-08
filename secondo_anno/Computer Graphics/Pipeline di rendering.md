>La **pipeline di rendering** e' quella serie di passi che trasforma la rappresentazione geometrica di una scena in un'immagine sullo schermo.

## Com'e' fatta?
>La pipeline di rendering si divide in due parti: il **sottosistema geometrico** e il **sottosistema raster**.

### Sottosistema geometrico
>Il **sottosistema geometrico** in una pipeline di rendering e' quello che si occupa di convertire il modello 3D nelle coordinate del mondo 2D (cioe' quelle dello schermo).

Come esempio possiamo utilizzare l'ombra: se noi mettiamo un solido 3D al sole, l'ombra che generera' sara' 2D, in questo senso possiamo pensare al sottosistema geometrico come la proiezione del modello 3D del solido su una superficie (la sua ombra).

### Sottosistema raster
>Il **sottosistema raster** prende in pasto il modello 2D convertito dal sottosistema geometrico e trasforma gli elementi della scena proiettati sullo schermo 2D nell'insieme di pixel da accendere.


L'implementazione dell'hardware della pipeline sulla scheda grafica si basa su un'ipotesi: **il mondo e' fatto di triangoli, segmenti e punti**. Perche' i triangoli? Perche' sono il poligono piu' piccolo rappresentabile da una scheda grafica.

## Complessita' computazionale della pipeline di rendering
>La seguente espressione definisce la complessita' computazionale della pipeline di rendering:
>	$$O (K_{transf}\cdot n + \Sigma_{i=0}^{i=m} R(p_i))$$

dove: 
- $K_{transf}$ indica il numero di triangoli elaborati al secondo, ed e' una costante che dipende dalla GPU
- $n$ e' il numero di vertici
- la sommatoria tutta indica il numero di pixel elaborati al secondo
	- $R$ e' il costo della rasterizzazione di un poligono
	- $p_i$ e' l'i-esimo poligono
La cosa interessante della pipeline e' il fatto che in realta' la GPU lavora in parallelo, quindi il tempo di esecuzione e' decisamente minore rispetto a quello sopra:
$$O (\space max(K_{transf}\cdot n, \Sigma_{i=0}^{i=m} R(p_i))\space)$$
#### Links
[[Pipeline grafica programmabile]]