>Le **espressioni equivalenti** nell'algebra relazionale sono fondamentali in quando vengono utilizzate dai DBMS *under-the-hood* per tradurre le query in un formato equivalente piu' efficiente.

### Selezioni in cascata
$$\sigma_{C_1 AND C_2}(R) = \sigma_{C_1}(\sigma_{C2}(R))$$
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



