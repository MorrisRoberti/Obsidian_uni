>Le **espressioni equivalenti** nell'algebra relazionale sono fondamentali in quando vengono utilizzate dai DBMS *under-the-hood* per tradurre le query in un formato equivalente piu' efficiente.

### Selezioni in cascata
$$\sigma_{C_1 \space AND \space C_2}(R) = \sigma_{C_1}(\sigma_{C2}(R))$$
### Idempotenza della proiezione
Sapendo che $X$ e $Y$ appartengono allo schema di $R$ 
$$\Pi_{X}(R) = \Pi_{X}(\Pi_{X \space Y}(R))$$
### Proiezione vs Selezione
$$\Pi_{X \space Y}(\sigma_{X}(R)) = \sigma_{X}(\Pi_{X \space Y}(R))$$
### Push down della selezione
$$\sigma_{C} (R_1 \bowtie R_2) = R_1 \bowtie (\sigma_{C} (R_2))$$
dove $C$ coinvolge attributi che appartengono allo schema di $R_2$

**IMPORTANTE**
>Il costo dell'operazione viene notevolmente ridotto perche' invece di unire *tutte le tuple e poi tagliarle* prima taglia e poi unisce solo quelle che rispecchiano la condizione.

### Push down della proiezione
$$\Pi_{X_1 \space Y_2}(R_1 \bowtie R_2) = R_1 \bowtie \Pi_{Y_2}(R_2)$$
dove $R_1$ ha come schema $X_1$ e $R_2$ ha come schema $X_2$. 
Se $Y_2 \subseteq X_2  \space and \space (X_1 \cap X_2) \subseteq Y_2$ allora gli attributi $X_2 - Y_2$ non sono coinvolti nel join quindi non servono.

### Distributivita' di alcune espressioni
$$\sigma_{C}(R_1 \cup R_2) = \sigma_{C}(R_1) \cup \sigma_{C}(R_2)$$
$$\sigma_{C}(R_1 - R_2) = \sigma_{C}(R_1) - \sigma_{C}(R_2)$$
$$\Pi_{X}(R_1 \cup R_2) = \Pi_{X}(R_1) \cup \Pi_{X}(R_2)$$
**ATTENZIONE**
>La proiezione non e' distributiva rispetto alla differenza

## Alcune proprieta' su insiemi e selezione
$$\sigma_{C_1 \space OR \space C_2}(R) = \sigma_{C_1}(R) \cup \sigma_{C_2}(R)$$
$$\sigma_{C_1 \space AND \space C_2}(R) = \sigma_{C_1}(R) \cap \sigma_{C_2}(R) = \sigma_{C_1}(R) \bowtie \sigma_{C_2}(R)$$
$$\sigma_{C_1 \space AND \space \not C_2}(R) = \sigma_{C_1}(R) - \sigma_{C_2}(R)$$
### Proprieta' distributiva del join sull'unione
$$R_1 \bowtie (R_2 \cup R_2) = (R_1 \bowtie R_2) \cup (R_1 \bowtie R_3)$$
>In generale le proprieta' *associativa* e *commutativa* si applicano a operatori binari eccetto la differenza.

#### Links
[[Algebra relazionale]]
[[L'operatore di JOIN nell'algebra relazionale]]