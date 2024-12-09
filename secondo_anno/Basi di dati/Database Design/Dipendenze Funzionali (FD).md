>Una **Dipendenza Funzionale** (anche chiamata *FD*) e' un vincolo di integrita' per il modello relazionale, che descrive confini funzionali per gli attributi di una relazione.


**Definizione**
>Data una relazione $R$ con uno schema $R(X)$ e dati due sottoinsiemi non vuoti di attributi $Y$ e $Z$ ($\subseteq X$), una **dipendenza funzionale** (FD) esiste tra $Y$ e $Z$ se:
>
>*"Per ogni coppia di tuple $t_1$ e $t_2$ di $R$ aventi gli stessi valori negli attributi $Y$, risulta che $t_1$ e $t_2$ hanno gli stessi valori anche negli attributi di $Z$."*

Si indica con $Y \rightarrow Z$.

Per vederla in modo diverso, prendiamo le coppie di tuple che hanno lo stesso valore sull'attributo $Y$ ($t_1[Y]=t_2[Y]$), se esiste una dipendenza funzionale $Y \rightarrow Z$ allora queste avranno uguale valore anche nell'attributo $Z$ ($t_1[Z]=t_2[Z]$).

### FD triviale
>Una FD si dice **triviale** quando e' sempre vera.

### FD NON triviale
>Una FD $Y \rightarrow A$ **non e' triviale** se una delle seguenti condizioni e' rispettata:

- $A$ e' un attributo t.c. $A\notin Y$ 
- $A$ e' un insieme di attributi t.c. $A \cap Y = \emptyset$ 

## Implicazioni
>Da dipendenze funzionali valide possiamo determinare altre dipendenze, infatti diciamo che le prime **implicano** le seconde se:
>
>*"Un insieme di FD $F$ **implica** $f$ se, ogni relazione che soddisfa le dipendenze di $F$ soddisfa anche $f$"*.

## Chiusura di un insieme di attributi
>Data una relazione $R(U)$, un insieme $F$ di FD definite su $U$ e un insieme di attributi $X$ con $X \subseteq U$, la **chiusura** di $X$ rispetto a $F$, chiamata $X^{+}_{F}$ e' l'insieme di attributi che **dipendono funzionalmente da $X$**.
>$$ X^{+}_{F} = \lbrace{A \vert A \in U \space and \space F \space imply X \rightarrow A}\rbrace$$
>Se $A$ appartiene a $X^{+}_{F}$ allora $X \rightarrow A$ e' implicata da $F$.

### Chiusura e chiave
>Un insieme di attributi $K$ e' chiave di uno schema $R(U)$ su cui un insieme di FD $F$ e' definito, se $F$ implica $K \rightarrow U$.

Con parole diverse, se una relazione $R(U)$ soddisfa $F$ allora soddisfa anche $K \rightarrow U$, cioe' tutti gli attributi sono funzionalmente dipendenti dalla chiave $K$.

## Proprieta' desiderabili delle FD
Un insieme di *Dipendenze funzionali* $F$ deve essere:
- **Non ridondante** -> se non ci sono dipendenze $f \in F$ tali che $F - \lbrace{f}\rbrace$ implica $f$
- **Ridotto** -> se
	- E' *non ridondante*
	- Non c'e' nessun insieme $F'$ equivalente a $F$ ottenuto rimuovendo attributi dalla parte sinistra di una o piu' dipendenze di $F$

## Copertura di FD
>Due insiemi di FD $F_1$ e $F_2$ si dicono **equivalenti** se $F_1$ implica $F_2$ e $F_2$ implica $F_1$. Se due FD sono equivalenti diciamo anche che ognuno e' **copertura dell'altro**.

Questa e' una proprieta' molto utile delle FD perche' ci permette di sostituire una FD complessa con una FD equivalente piu' semplice.

#### Links
[[Normalizzazione]]
[[Forme Normali]]
