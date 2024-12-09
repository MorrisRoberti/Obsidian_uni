>La **Normalizzazione** e' il processo di verifica della qualita' di una relazione DOPO che e' stata progettata. La normalizzazione non e' una tecnica di progettazione bensi' un controllo della qualita'.

## Le scomposizioni
>Per normalizzare una relazione e portarla in BCNF, sfruttiamo il seguente criterio:
>*"Se una relazione rappresenta piu' di un **concetto** dipendente, allora deve essere**scomposta** in relazioni piu' piccole, una per ogni concetto."*

### Qualita' delle scomposizioni
>Le scomposizioni dovrebbero, per essere ottimali, avere le seguenti caratteristiche:

- Soddisfare la **proprieta' di lossless join** (vedi sotto)
- **Preservare le dipendenze**, cosi' da mantenere i vincoli di integrita'

Una scomposizione **preserva le dipendenze** se coinvolge gli attributi che appaiono insieme in uno degli schemi scomposti.
## Normalizzazione (BCNF)
>Mostriamo come vengono normalizzate le relazioni per rispettare la [[Forme Normali#Boyce-Codd Normal Form (BCNF)|Forma Normale BCNF]].

Prendiamo come esempio la seguente relazione

| Employee (pk) | Wage | Project (pk) | Budget | Role       |
| ------------- | ---- | ------------ | ------ | ---------- |
| Jones         | 20   | Mars         | 2      | Technician |
| Smith         | 35   | Jupiter      | 15     | Designer   |
| Smith         | 35   | Venus        | 15     | Designer   |
| Williams      | 35   | Venus        | 15     | Chief      |
| Williams      | 55   | Jupiter      | 15     | Consultant |
| Williams      | 55   | Mars         | 2      | Consultant |
| Brown         | 55   | Mars         | 2      | Chief      |
| Brown         | 48   | Venus        | 15     | Designer   |
| White         | 48   | Venus        | 15     | Designer   |
| White         | 48   | Jupiter      | 15     | Designer   |
Possiamo scomporla come segue

| Employee (pk) | Wage |
| ------------- | ---- |
| Jones         | 20   |
| Smith         | 35   |
| Williams      | 55   |
| Brown         | 48   |
| White         | 48   |

| Project (pk) | Budget |
| ------------ | ------ |
| Mars         | 2      |
| Jupiter      | 15     |
| Venus        | 15     |

| Employee (pk) | Project (pk) | Role       |
| ------------- | ------------ | ---------- |
| Jones         | Mars         | Technician |
| Smith         | Jupiter      | Designer   |
| Smith         | Venus        | Designer   |
| Williams      | Venus        | Chief      |
| Williams      | Jupiter      | Consultant |
| Williams      | Mars         | Consultant |
| Brown         | Mars         | Chief      |
| Brown         | Venus        | Designer   |
| White         | Venus        | Designer   |
| White         | Jupiter      | Director   |
## Perdite (losses)
>Quando si effettua la scomposizione si puo' andare incontro a delle *perdite* (*losses*).

prendiamo in considerazione la seguente relazione

| Employee | Project | Office |
| -------- | ------- | ------ |
| Jones    | Mars    | Rome   |
| Smith    | Jupiter | Milan  |
| Smith    | Venus   | Milan  |
| White    | Saturn  | Milan  |
| White    | Venus   | Milan  |
**Employee->Office**

| Employee | Office |
| -------- | ------ |
| Jones    | Rome   |
| Smith    | Milan  |
| White    | Milan  |
**Project->Office**

| Project | Office |
| ------- | ------ |
| Mars    | Rome   |
| Jupiter | Milan  |
| Venus   | Milan  |
| Saturn  | Milan  |
Se effettuiamo un'operazione di **JOIN** su queste ultime due tabelle non otterremmo la tabella originale, perche' avremmo due record in piu'

| Employee    | Project       | Office      |
| ----------- | ------------- | ----------- |
| Jones       | Mars          | Rome        |
| Smith       | Jupiter       | Milan       |
| Smith       | Venus         | Milan       |
| ***Smith*** | ***Saturn***  | ***Milan*** |
| ***Smith*** | ***Jupiter*** | ***Milan*** |
| White       | Saturn        | Milan       |
| White       | Venus         | Milan       |
### Lossless JOIN
>Una relazione $R$ puo' essere scomposta senza perdite (*lossless*) in due relazioni $Q(X)$ e $S(Y)$ se il join della proiezione di $R$ su $X$ e su $Y$ e' equivalente a $R$:
>$$\pi_{X}(R) \bowtie \pi_{Y}(R) = R$$
>La proprieta' e' verificata se gli attributi contengono una chiave per almeno una delle relazioni scomposte.

### Condizione di non perdita
>Data una relazione $R(X)$ e $X_1$ e $X_2$ sottoinsiemi di $X$ tali che $X_1 \cup X_2 = X$ e dato $X_0=X_1 \cap X_2$,
>$R(X)$ puo' essere **scomposta senza perdite** in due relazioi $Q(X_1)$ e $S(X_2)$ se e' verificata *una delle seguenti*:
- $X_0 \rightarrow X_1$
- $X_0 \rightarrow X_2$ 

Riprendiamo la tabella di prima e vediamo se possiamo scomporla in modo da evitare le perdite

| Employee | Project | Office |
| -------- | ------- | ------ |
| Jones    | Mars    | Rome   |
| Smith    | Jupiter | Milan  |
| Smith    | Venus   | Milan  |
| White    | Saturn  | Milan  |
| White    | Venus   | Milan  |
Definiamo $X_1$ = {Employee, Project} e $X_2$ = {Employee, Office} quindi:
$X_0=X_1 \cap X_2=$ Employee 

- Vale $X_0 \rightarrow X_1$? No
- Vale $X_0 \rightarrow X_2$? **Si**

Allora possiamo scomporre la relazione *senza perdite* come segue:

| Employee | Office |
| -------- | ------ |
| Jones    | Rome   |
| Smith    | Milan  |
| White    | Milan  |

| Employee | Project |
| -------- | ------- |
| Jones    | Mars    |
| Smith    | Jupiter |
| Smith    | Venus   |
| White    | Saturn  |
| White    | Venus   |
## Normalizzazione 3NF
>Vediamo ora come normalizzare una relazione per far si che rispetti la [[Forme Normali#Terza Forma Normale (3NF)| Forma Normale 3NF]].

Prendiamo la seguente relazione

| Employee | Project | Office |
| -------- | ------- | ------ |
| Smith    | Mars    | Rome   |
| Johnson  | Jupiter | Milan  |
| Johnson  | Mars    | Milan  |
| White    | Saturn  | Milan  |
| White    | Venus   | Milan  |
**Project Office** $\rightarrow$ **Chief** e **Chief** $\rightarrow$ **Office**.

>Quello che dobbiamo fare e' creare una relazione per ogni insieme coinvolto in una FD, questo per preservare le dipendenze, successivamente andiamo a controllare che almeno una di queste relazioni abbia una chiave della relazione originale.

#### Links
[[Forme Normali]]
[[Dipendenze Funzionali (FD)]]