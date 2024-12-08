>L'obiettivo della progettazione di uno **schema logico** e' quello di tradurre lo [[Conceptual Design|schema concettuale]] (ER) in uno schema che rappresenti i dati in modo efficiente.

Vogliamo quindi effettuare un'operazione di **restructuring** dello schema ER per:
- Semplificare la traduzione schema concettuale -> schema logico
- Ottimizzare le performance

## Analisi delle performance & Cost Evaluation
>Per effettuare una *ristrutturazione* dello schema ER e quindi ottimizzarlo, dobbiamo innanzitutto fare una cosiddetta **Cost Evaluation** cioe' una valutazione dei costi.

Teniamo in conto due indicatori: 
- **spazio** -> numero previsto di istanze immagazzinate
- **tempo** -> numero di istanze visitate durante un'operazione
Prendiamo come esempio il seguente schema ER
![[Pasted image 20241208184808.png]]

| Name        | Type | Size |
| ----------- | ---- | ---- |
| Office      | E    | 10   |
| Department  | E    | 80   |
| Employee    | E    | 2000 |
| Project     | E    | 500  |
| MadeOf      | R    | 80   |
| Belonging   | R    | 1900 |
| Supervision | R    | 80   |
| Enrollment  | R    | 6000 |
Esempio di *cost evaluation*
*"Vogliamo tutte le informazioni dell'Employee, i dati del Department a cui appartiene e i dati dei Project a cui lavora"*

Costruiamo una **access table** seguendo lo **schema di navigazione**, cioe' lo schema parziale che tiene conto solo delle entita' e delle associazioni interessate dalla nostra analisi
![[Pasted image 20241208185235.png]]

**Access Table**

| Name       | Type | Accesses Number | Accesses Type | Accesses Order |
| ---------- | ---- | --------------- | ------------- | -------------- |
| Department | E    | 1               | R             | 3              |
| Employee   | E    | 1               | R             | 1              |
| Project    | E    | 3               | R             | 5              |
| Belonging  | R    | 1               | R             | 2              |
| Enrollment | R    | 3               | R             | 4              |
Abbiamo assunto che l'Employee abbia 3 progetti.

## Attivita' di ristrutturazione
Abbiamo 4 attivita' di ristrutturazione fondamentali:
1. Analisi e gestione delle ridondanze
2. Eliminare le generalizzazioni
3. Raggruppamento o partizionamento delle entita' e delle associazioni
4. Identificazione delle primary key

### 1) Analisi delle ridondanze
>Una **ridondanza** in uno schema ER e' un'informazione rilevante ma che potrebbe essere ottenuta derivandola da altre informazioni.

In questa fase dobbiamo decidere se eliminare o creare/tenere le ridondanze, poiche' queste hanno PRO e CONTRO:
- PRO -> velocizzano le query
- CONTRO -> richiedono una gestione piu' onerosa

[[Logical Design - Analisi delle ridondanze|Analisi delle ridondanze]]

### 3) Eliminazione delle generalizzazioni
>Vogliamo eliminare le generalizzazioni perche' il nostro *Data Model* non permette di rappresentarle.

[[Logical Design - Eliminazione delle generalizzazioni]]

### 4) Partizionamento/raggruppamento delle entita' e delle associazioni
>Vogliamo effettuare una *ristrutturazione* degli attributi delle nostre entita'/associazioni, in modo da fornire delle operazioni piu' efficienti che *riducano il numero di accessi*.

Possiamo farlo **raggruppando** o **separando** attributi all'interno di un'entita'/associazione o attraverso piu' entita'/associazioni.

[[Logical Design - Partizionamento e Raggruppamento entita' e associazioni]]

### 5) Identificazione della primary key
>Questa e' un'operazione **obbligatoria** per tradurre il nostro schema concettuale ER nel nostro schema logico finale. Vogliamo scegliere la primary key in base a dei criteri di: *semplicita'* e *frequenza di utilizzo*.