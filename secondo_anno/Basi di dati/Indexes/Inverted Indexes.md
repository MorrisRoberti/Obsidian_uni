>Ci sono dei casi particolari di recupero informazioni che richiedono una ricerca specifica, tra questi rientra il *recupero di documenti di testo*. Diversamente da come abbiamo visto per i record di dati, qui vogliamo utilizzare gli indici per trovare dei documenti date delle query completamente testuali. A tale scopo utilizziamo i cosiddetti **inverted indexes**.

In particolare siamo interessati a due tipologie di query:
1. Restituire tutti i documenti dato un **insieme** di parole chiave $K_1, K_2, \dots , K_n$
2. Restituire tutti i documenti data una **sequenza** di parole chiave $K_1, K_2, \dots , K_n$

Il trick degli indici inversi e' che, invece di creare un indice separato per ogni attributo (ad esempio per ogni parola), *rappresentano il documento in cui una determinata parola appare*.

![[Pasted image 20241219122512.png]]
Creiamo un *inverted index* che consiste di coppie $<document, position>$.

![[Pasted image 20241219122730.png]]

## Linguisti preprocessing
Per guadagnare benefici in termini di performance e di accuratezza, possiamo attuare diverse tecniche:
- **Token normalization** -> Le parole sono normalizzate in modo che "window" e "Window" venga riconosciuta come una parola unica
- **Stemming** -> E' il processo di rimozione dei suffissi per trovare la *radice* di ogni parola, in questo modo abbiamo che "fish", "fished" e "fisher" possono essere ridotte alla radice "fish"
- **Stop words** -> Le parole comuni, le congiunzioni, gli articoli etc. sono chiamate *stop words* e sono spesso eliminate dagli indici inversi poiche' compaiono in tantissimi documenti e comunque non apportano valore nella ricerca; la loro eliminazione dall'indice riduce i tempi di ricerca

## Query su indici inversi
Vogliamo tutti i documenti che contengono sia la parola "Brutus" che "Caesar"

![[Pasted image 20241219123151.png]]

Vogliamo tutti i documenti che contengono la sequenza "a valley"

![[Pasted image 20241219123222.png]]

Vogliamo tutti i documenti che contengono la sequenza "a clear"

![[Pasted image 20241219123250.png]]

#### Links
[[Indexes]]