>Le **proiezioni geometriche piane** di un oggetto 3D si ottengono tramite delle *rette di proiezione* dette **proiettori**, che partono da un **centro di proiezione**, passano attraverso ciascun punto dell'oggetto e intersecano un **piano di proiezione** (detto anche **view plane**) generando la proiezione stessa.

In computer grafica specifichiamo:
- il *tipo* di proiezione -> parallela, prospettica etc.
- un **view volume** 
La proiezione degli oggetti avviene su una finestra (**window**) che verrra' poi mappata sul dispositivo di uscita, cioe' lo schermo.

**View volume**
>E' la regione di spazio tridimensionale visibile dalla camera virtuale e che contiene gli oggetti da visualizzare. E' solitamente un cubo delimitato da 6 piani: *left, right, top, bottom, near e far*.

![[Pasted image 20241108151517.png]]

## Tipologie di proiezione
### Parallela
>Nelle proiezioni **parallele** il *centro di proiezione* e' all'infinito e le rette di proiezione sono parallele.

Nelle proiezioni parallele:
- Le linee parallele rimangono tali
- Gli oggetti non cambiano dimensione quando si avvicinano -> o comunque le proporzioni vengono mantenute
- Sono utili per **verificare allineamenti e dimensioni**
- Il **view volume** specificato e' a forma di parallelepipedo

![[Pasted image 20241107222910.png]]
#### Proiezioni parallele ortografiche
>La direzione delle rette di proiezione e' **ortogonale al piano di proiezione**.

![[Pasted image 20241107222541.png]]

##### Proiezioni assonometriche ortografiche
>Le **proiezioni assonometriche ortografiche** usano un piano di proiezione che **non e' perpendicolare a nessuno degli assi principali**, quindi visualizzano piu' lati delle proiezioni insieme. 

**ATTENZIONE**
Le rette di proiezione, per definizione di proiezione parallela rimangono comunque *ortogonali* al piano di proiezione.

#### Proiezioni parallele oblique
>Nelle **proiezioni parallele oblique** la direzione delle rette di proiezione e' **obliqua rispetto al piano di proiezione**.

![[Pasted image 20241107223313.png]]

### Proiezioni prospettiche
>Nelle proiezioni **prospettiche** ogni insieme di linee parallele converge verso un unico punto.

**Vanishing points**
>Ogni insieme di linee parallele della scena 3D converge verso un **punto di fuga** o **vanishing point**. I punti di fuga possono essere infiniti.

**Punti di fuga principali**
>Definiamo **punti di fuga principali** i fasci di rette parallele agli assi principali XYZ.


Nelle proiezioni prospettiche:
- Le linee parallele non rimangono necessariamente tali
- La dimensione degli oggetti varia in base alla distanza
- Specifichiamo un *viewing volume* a forma di tronco di piramide
- Possiamo catalogarle in base al numero di *vanishing points* principali (da uno a 3, che rispecchiano gli assi principali intersecati al piano di proiezione)

![[Pasted image 20241107230929.png]]

#### Links
[[Matematica delle proiezioni]]
[[Pipeline grafica programmabile]]