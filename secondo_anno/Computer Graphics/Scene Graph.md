>Lo **scene graph** e' una tecnica avanzata per la rappresentazione gerarchica di una scena costituita da un insieme di oggetti.

Lo *scene graph* e' una struttura dati ad albero in cui i nodi rappresentano gli elementi della scena. Ciascun ramo rappresenta una relazione tra "padre" e "figlio".

![[Pasted image 20241108194402.png]]

Ciascun nodo figlio e' definito dalla sua geometria e dalla matrice di trasformazione che lo lega al nodo padre:

![[Pasted image 20241108194415.png]]

Ad esempio nell'immagine sopra il nodo radice e' il torso e ha 5 figli. Quando si cambia la posa di un oggetto, automaticamente tutti gli oggetti nel sottoalbero generato subiscono la stessa trasformazione.

#### Links
[[Pipeline grafica programmabile]]
[[Matematica delle proiezioni]]
[[Proiezioni Geometriche]]