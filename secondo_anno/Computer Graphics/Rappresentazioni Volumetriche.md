>Si rimanda alla definizione: [[Modelli e rappresentazioni#Rappresentazioni volumetriche]]

![[Pasted image 20240929161243.png]]

## Decomposizione
>[[Modelli e rappresentazioni#Rappresentazioni per decomposizione]]

Il solido viene ottenuto dalla decomposizione in volumi elementari, questi possono avere varie forme e orientazioni:
- **Cell Decomposition**
- **Spatial-Occupancy Enumeration**
- **Binary Space Partitioning**

### Cell decomposition
>Il solido viene descritto da volumi elementari adiacenti chiamati **celle** tramite l'operatore di glueing (saldatura). Le celle sono di varia natura e orientazione: tetraedri, semplici poliedri o solidi piu' complessi.

![[Pasted image 20240929161721.png]]

>L'operazione di **glueing** e' una restrizione dell'unione, in cui gli oggetti non devono intersecarsi ma devono avere almeno: un vertice, uno spigolo o una faccia in comune.

E' difficile verificarne la validita'.

### Spatial-Occupancy Enumeration
>A differenza della *Cell-decomposition* nella **spatial-occupancy enumeration** abbiamo delle celle della stessa forma e orientazione combinate in griglie strutturate e regolari, ogni cella puo' essere occupata o meno da un solido. Esempio: modello voxel-based (voxel -> cubo).

![[Pasted image 20240929162723.png]]
Operativamente definiamo una griglia regolare orientata lungo i 3 assi principali e assegnamo **TRUE** alle celle che contengono materiale e **FALSE** a quelle che non ne contengono. Possiamo rappresentare ogni singola cella tramite le coordinate di un singolo vertice.

### Binary Space Partitioning
>Nella rappresentazione tramite **BSP** (*Binary Space Partitioning*) suddividiamo *ricorsivamente* una regione in $n$ sottoregioni uguali. 

![[Pasted image 20240929163209.png]]

L'ottimizazione avviene in quanto una sottoregione e' suddifisa solo se interseca l'oggetto. La rappresentazoine e' comunque approssimata in quanto ci deve essere un numero massimo di suddivisioni.
![[Pasted image 20240929163146.png]]
I metodi BSP piu' utilizzati sono:
- Partizionamento **quadtree** (2D), cioe' una suddivisione ricorsiva in 4 quadrati.
- Partizionamento **octree** (3D), cioe' una suddivisione ricorsiva in 8 cubi.
#### Modello octree
Il modello e' rappresentato da un albero: ogni nodo padre ha 8 figli e ad ogni chiamata ricorsiva si generano altri 8 figli.

Ad ogni figlio viene assegnato un codice:
- *completamente contenuto nel solido*
- *completamente esterno al solido*
- *parzialmente contenuto nel solido*

## Rappresentazioni volumetriche decomposizione

|                            | Decomposizione in celle | Enumerazione spaziale     | Octree                    |
| -------------------------- | ----------------------- | ------------------------- | ------------------------- |
| **Dominio**                | buono                   | buono con approssimazione | buono con approssimazione |
| **Validita'**              | difficile da validare   | facile da validare        | facile da validare        |
| **Completezza**            | si                      | si                        | si                        |
| **Unicita'**               | no                      | si                        | si                        |
| **Concisione**             | no                      | no                        | no                        |
| **Facilita' di creazione** | non direttamente        | non direttamente          | non direttamente          |
## Rappresentazioni volumetriche costruttive

### CSG - Constructive Solid Geometry
>[[Modelli e rappresentazioni#Rappresentazioni costruttive]]

Gli oggetti vengono ottenuti per composizione delle primitive euclidee.
La **composizione** di per se' e' un'operazione booleana -> unione, intersezione, differenza etc. oppure traslazione, rotazione, scala etc.
![[Pasted image 20240929175707.png]]
Il solido finale viene rappresentato tramite un **Albero CSG**, cioe' un albero ordinato che indica *come* viene modellato il solido attraverso le varie operazioni. E' interessante poiche' si ottiene un **modello procedurale** cioe' una descrizione di come ottenere il solido e non il solido stesso.

**PRO**
- Metodo procedurale
- Consistenza e validita' del risultato
- Facilita' di modifica di un oggetto costruito
**CONTRO**
- La rappresentazione non e' unica
- Non e' possibile verificare se due solidi sono uguali o no valutando le rappresentazioni, non fornisce informazioni su facce e spigoli
- Il numero di operatori usati per creare e modificare i solidi e' limitato

|                            | CSG                             |
| -------------------------- | ------------------------------- |
| **Dominio**                | buono                           |
| **Validita'**              | intrinsecamente valido          |
| **Completezza**            | si                              |
| **Unicita'**               | no                              |
| **Concisione**             | si                              |
| **Facilita' di creazione** | mediante linguaggio/interfaccia |
### Istanza di primitive
>La rappresentazione per istanza di primitive viene utilizzata nei software CAD, solitamente e' basato su famiglie di oggetti. Un solido e' creato tramite un'operazione di istanziazione specificando alcuni parametri.


|                            | Istanza di primitive |
| -------------------------- | -------------------- |
| **Dominio**                | limitato             |
| **Validita'**              | facile da validare   |
| **Completezza**            | si                   |
| **Unicita'**               | no                   |
| **Concisione**             | si                   |
| **Facilita' di creazione** | si                   |
#### Links
[[Modelli e rappresentazioni]]

