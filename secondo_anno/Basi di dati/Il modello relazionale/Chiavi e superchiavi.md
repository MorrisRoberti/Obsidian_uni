>Informalmente definiamo una **superchiave** (*superkey*) un insieme di attributi che identificano univocamente una tupla. In modo piu' formale possiamo dire:
>
>*Una superchiave e' un insieme K di attributi su r se, date due tuple distinte t1 e t2 in r NON valga t1[K] = t2[K]*.

>Una **chiave** e' una **superchiave minimale**.

![[Pasted image 20240925181346.png]]
Nel caso sopra la **chiave** e' `Number` in quanto e' una **superchiave minimale**.
Un'altra superchiave quindi puo' essere composta da `Number` e `Surname` o comunque dalla chiave e qualsiasi altro attributo.

Le istanze di relazione hanno sempre la **superchiave naive** che e' l'intera tupla. La definizione di relazione ([[Il modello relazionale#Relazioni]]) ci garantisce che *non esistono due tuple uguali*.

Le chiavi sono fondamentali perche' permettono di collegare le tuple attraverso le varie tabelle.
## Chiavi nulle
>Abbiamo detto che e' possibile che alcuni valori nelle istanze delle nostre tabelle siano nulli ([[Dati parziali e valori nulli]]), questo e' un problema quando lavoriamo con le chiavi, in quanto, se il valore di una chiave e' nulla perdiamo: la possibilita' di identificare quella tupla e la possibilita' di mantenere *l'integrita' referenziale* ([[Vincoli di integrita'#Vincoli intra-relazionali#Vincoli sul dominio]]).

A questo proposito si vogliono inserire dei [[Vincoli di integrita']] che assicurino che *i valori della chiave non siano nulli*.

#### Links
[[Il modello relazionale]]
[[Dati parziali e valori nulli]]
[[Vincoli di integrita']]
[[Primary key & Foreign key]]

