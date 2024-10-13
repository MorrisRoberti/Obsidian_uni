>Il **modello matematico** di un oggetto fisico e' la rappresentazione di quest'ultimo e delle sue proprieta' tramite formule e strumenti matematici. Un **modello** puo' avere piu' **rappresentazioni**.

## Schema di rappresentazione
>Definiamo lo **schema di rappresentazione** come l'insieme delle regole utilizzate per la descrizione del modello. Lo schema di rappresentazione puo' essere visto come una **relazione** che collega il modello matematico (dominio) ad una sua rappresentazione (codominio).

### Proprieta' di uno schema di rappresentazione
#### Dominio
>Il dominio indica il potere descrittivo: piu' ampio e' il dominio e maggiore e' la varieta' degli oggetti solidi rappresentabili tramite il nostro schema di rappresentazione.

#### Validita'
>La **validita'** indica se esiste un algoritmo (semplice) per determinare se una rappresentazione nel codominio corrisponde ad un solido. Quindi *uno schema di rappresentazione e' valido se esiste un'algoritmo che permette di determinare se una rappresentazione nello schema corrisponde ad un determinato oggetto fisico*

#### Non ambiguita'
>Uno schema di rappresentazione e' **non ambiguo (o completo)** se ad ogni rappresentazione corrisponde uno e un solo solido.

#### Unicita'
>Uno schema di rappresentazione e' **unico** se ciascun solido ha (al massimo) una sola possibile rappresentazione.

#### Concisione
>Uno schema di rappresentazione e' **conciso** se necessita di una ridotta quantita' di memoria.


## Diversi Schemi di rappresentazione

### Brep (rappresentazioni del contorno)
>Una **Brep** ("*boundary rep*") o **rappresentazione del contorno** e' un tipo di rappresentazione che definisce i contorni del solido con delle linee. Alcuni esempi rilevanti sono le [[Mesh]].

### Rappresentazioni volumetriche
>La **rappresentazione volumetrica** e' un tipo di rappresentazione che definisce il modello di un oggetto solido non solo tramite piani ma tenendo conto anche del suo volume. Si pensi ad esempio a dei test in cui si vuole vedere se la luce passa attraverso un oggetto.

#### Rappresentazioni per decomposizione
>Le rappresentazioni per decomposizione si occupa di suddividere la geometria degli oggetti fisici in componenti piu' piccoli e facili da gestire.

Esempi di rappresentazioni per decomposizione:
- Decomposizione in celle 
- Enumerazione per occupazione spaziale (voxel)
- Binary Space Partitioning (octree)

#### Rappresentazioni costruttive
>La rappresentazione costruttiva e' un metodo che consiste nel partire da rappresentazioni esistenti semplici e appunto combinarle per ottenere rappresentazioni piu' elaborate.

Esempi di rappresentazioni costruttive:
- Constructive Solid Geometry (CSG)
- Istanza di primitive

### Rappresentazioni di tipo sweep
>Sono tipi di rappresentazioni che si basano sul far scorrere una forma bidimensionale lungo un percorso tridimensionale per generare un oggetto tridimensionale.

Alcuni software di modellazione avanzati permettono di convertire i modelli da uno schema di rappresentazione all'altro.

Si riporta sotto una classificazione topologica delle rappresentazioni![[Pasted image 20240926202502.png]]


#### Links
[[Rappresentazioni Brep]]
[[Rappresentazioni Volumetriche]]
[[Rappresentazioni di Sweep]]