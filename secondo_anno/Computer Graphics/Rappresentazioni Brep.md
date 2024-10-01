## Rappresentazioni mesh
[[Rappresentazioni con le mesh]]

## Rappresentazioni implicite
>Sono rappresentazioni di una curva/superficie (chiusa o aperta) come luogo dei punti dove una funzione implicita si annulla.

![[Pasted image 20240929154034.png]]

## Rappresentazioni parametriche
>Sono rappresentazioni di una curva o di una superficie in forma parametrica.

![[Pasted image 20240929154121.png]]
Sono flessibili ed efficienti dal punto di vista della memoria e consentono un'elaborazione analitica. Possono essere facilmente convertite in mesh poligonali.

## Brep proprieta'

|                            | Mesh poligonali                          | Rappresentazioni implicite | Rappresentazioni parametriche |
| -------------------------- | ---------------------------------------- | -------------------------- | ----------------------------- |
| **Dominio**                | buono (con approssimazione)              | limitato                   | limitato                      |
| **Validita**'              | difficile da validare (regola di Eulero) | facile da validare         | facile da validare            |
| **Completezza**            | si                                       | si                         | si                            |
| **Unicita**'               | no                                       | no                         | no                            |
| **Concisione**             | no                                       | si                         | si                            |
| **Facilita' di creazione** | difficile                                | facile                     | facile                        |
## Rappresentazioni wireframe
>Sono rappresentazioni che prendono l'oggetto 3D e' tracciano delle linee che rappresentano i vari solidi che lo compongono.

![[Pasted image 20240929160751.png]]
**PRO**
- Forniscono un modello unico da cui derivare disegni 2D
- Semplici e facili da modificare
- Basso costo computazionale
**CONTRO**
- Geometria povera
- **Ambiguita' nella rappresentazione**
- Possibilita' di creare oggetti privi di senso
- Non e' facile distinguere le linee visibili
- Molto complicati da leggere e interpretare
- Mancanza di standard
#### Links
[[Modelli e rappresentazioni]]
