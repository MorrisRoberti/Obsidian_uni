>Le **mesh** sono un tipo di **Brep** ([[Modelli e rappresentazioni#Brep (rappresentazioni del contorno)]]) in cui un'oggetto 3D viene rappresentato con dei poligono 2D, nel nostro caso *dei triangoli*.

In linea generale le mesh sono approssimazioni discrete di superfici tridimensionali attraverso dei poligoni (triangoli).
## I poliedri
>Un poliedro e' un solido la cui superficie e' composta da un insieme di poligoni tali che solo due di essi si intersechino in un determinato spigolo e sia possibile percorrerne la superficie spostandosi da una faccia all'altra attraversando gli spigoli finche' tutti i poligoni siano stati percorsi da questo cammino continuo.

![[Pasted image 20240926203340.png]]

#### Poliedri semplici
>Un poliedro semplice e' un poligono che puo' essere deformato in modo che ne sia sempre rispettata la continuita' in una sfera. Ovvero sia senza fori.

Per i poliedri semplici vale la **regola di Eulero**:
$$V-E+F=2$$
Dove:
- $V$ e' il numero di vertici
- $E$ e' il numero di spigoli
- $F$ e' il numero di facce
#### Poliedri regolari
>I poliedri regolari possono essere definiti come *poliedri semplici convessi*. Tutte le facce hanno un numero $h$ di spigoli, ogni vertice ha lo stesso numero $k$ di spigoli incidenti e tutti gli spigoli sono della stessa lunghezza. Esistono solo 5 poliedri regolari:

![[Pasted image 20240926204533.png]]

La modellazione tramite mesh poligonali consente di rappresentare:
- Poliedri
- Superfici aperte
- Superfici non poliedrali (non-manifold)

#### Links
[[Rappresentazioni con le mesh]]