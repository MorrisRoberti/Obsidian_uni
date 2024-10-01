>In questa parte verra' fatta un'overview su alcuni **algoritmi e tecniche che agiscono su mesh poligonali**.

Vedremo:
- Calcolo del *bounding box*
- Semplificazione di una mesh
- Calcolo del *Convex Hull* di un insieme di punti 3D

## Calcolo del bounding box
>Il **bounding box** non e' altro che un parallelepipedo che contiene l'oggetto. Si puo' calcolare rispetto agli *assi delle coordinate principali* o *agli assi principali dell'oggetto*.

### AABB
>**AABB** che sta per *Axis Aligned Bounding Box* e' un algoritmo che trova il bounding box rispetto agli assi delle coordinate principali, quindi se l'oggetto ruota si deve ricalcolare

Come funziona:
- Si itera sui vertici dell'oggetto per trovare le *x* e *y* massime e in base a questi valori, si costruisce una bounding box con i lati paralleli agli assi delle coordinate
![[Pasted image 20241001104819.png]]

### OOBB
>**OOBB** sta per *Object Oriented Bounding Box* e' un algoritmo che trova il bounding box rispetto agli assi principali dell'oggetto stesso, quindi se anche dovesse ruotare non sarebbe ricalcolato.
>Chiaramente e' piu' complesso.

![[Pasted image 20241001104840.png]]
## Semplificazione di una mesh
>Ci sono alcuni casi in cui si vuole semplificare una mesh, ad esempio se renderizziamo un oggetto lontano, non ha senso lasciare un livello di dettaglio alto, poiche' l'utente comunque non lo percepirebbe, quindi si tende a **semplificarne la mesh** in modo da alleggerire il carico computazionale. Quando si semplifica una mesh si applica un algoritmo incrementale che elimina dei vertici e rimpiazzi gli spazi vuoti, mantenendo una buona approssimazione della mesh originale.

Ci sono due categorie di algoritmi:
- Decimazione dei vertici
- Contrazione iterativa di spigoli

### Decimazione dei vertici
>Negli algoritmi che lavorano per **decimazione di vertici** si selezionano dei vertici "poco importanti" tramite delle euristiche, si rimuovono e si ri-triangola il vuoto risultante. Ad ogni passo di rimozione, si deve, in base a criteri euristici determinare il vertice candidato ad essere rimosso. Solitamente si tende a **diradare le zone a bassa curvatura**.

![[Pasted image 20241001105109.png]]

### Contrazione iterativa di spigoli
>Negli algoritmi di **contrazione iterativa degli spigoli** ad ogni spigolo si assegna un costo della contrazione dello spigolo stesso, in questo modo, ad ogni iterazione si puo' eliminare lo spigolo con il costo minore. Seleziona spigoli corti in zone a bassa curvatura.

Una formula per calcolare in modo semplice il costo di uno spigolo e'
$$\epsilon(P_1P_2) = \frac{\vert \vert P_2 - P_1 \vert \vert}{1 + n_1 \cdot n_r}$$
dove:
- $P_1$ e $P_2$ sono i vertici dello spigolo
- $n_1$ e $n_r$ sono i versori normali delle due facce incidenti sullo spigolo

![[Pasted image 20241001105857.png]]


### Level Of Detail (LOD)
>Per aumentare l'efficienza del sottosistema geometrico si costruiscono molteplici rappresentazioni dell'oggetto a diverse risoluzioni del mesh, poi, in base a dove si trova l'oggetto, rispetto all'osservatore si disegna l'oggetto ad alta risoluzione (se vicino) o a bassa (se lontano).

### Billboarding
>Alcune volte si ricorre a dei trucchi per alleggerire il carico computazionale, come quello del **billboarding**. Questo consiste nell'inserire nella scena 3D delle immagini 2D che vengono ruotate per fare in modo di essere sempre orientate verso l'osservatore e dando cosi' l'illusione di essere oggetti 3D.

## Convex Hull
>Il **Convex Hull** (inviluppo convesso) di un insieme $n$ di punti 3D e' il piu' piccolo poliedro convesso che li contiene.

### Algoritmo incrementale Clarkson-Shor O(n^2)
>Un algoritmo per implementare il *Convex Hull* e' l'algorimo di *Clarkson-Shor* del 1989.

Come funziona:
1. Si costruisce un tetraedro con i primi 4 punti di $n$
![[Pasted image 20241001110907.png]]
2. Si eliminano i punti che cadono all'interno del convex hull corrente. Si sceglie uno dei punti $p$ rimanenti e si determinano le facce visibili da $p$, come se in $p$ ci fosse una luce che illumina la mesh
3. Si determinano gli spigoli dell'orizzonte, cioe' gli spigoli che separano una faccia visibile da una non visibile da $p$
4. Per ogni spigolo dell'orizzonte si costruisce una nuova faccia (triangolo) connettendo uno spigolo dell'orizzonte con $p$
![[Pasted image 20241001110934.png]]
5. Si eliminano tutte le facce che erano visibili e si torna al punto 2 se ci sono altri punti da elaborare
![[Pasted image 20241001110949.png]]

#### Links

[[Mesh]]
[[Modelli e rappresentazioni]]
[[Rappresentazioni con le mesh]]
