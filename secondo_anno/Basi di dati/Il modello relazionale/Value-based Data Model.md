>La struttura dati a tabella utilizzata dai database relazionali e' **basata sui valori**, questo significa che ogni *riferimento* tra i dati e' fatto tramite valori nelle tuple.

![[Pasted image 20240921115218.png]]
La differenza con le strutture dati *basate sui puntatori* e' la seguente
![[Pasted image 20240921115330.png]]
## Pro della struttura basata sui valori
- Indipendente dalla struttura dati fisica sottostante
- Gli unici dati immagazzinati sono quelli strettamente relativi all'applicativo (non ci sono metadati o appunto puntatori)
- L'utente (o l'applicazione) e il programmatore vedono gli stessi dati (con i puntatori l'applicazione vedrebbe celle di memoria che puntano a valori di altre tabelle)
- I dati possono essere facilmente condivisi tra diversi ambienti
- **I puntatori sono unidirezionali**

#### Links
[[Il modello relazionale]]