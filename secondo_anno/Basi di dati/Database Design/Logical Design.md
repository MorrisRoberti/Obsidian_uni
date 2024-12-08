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
>Questa e' un'operazione **obbligatoria** per tradurre il nostro schema concettuale ER nel nostro schema logico finale. Vogliamo scegliere la primary key in base a dei criteri di: *semplicita'* e *frequenza di utilizzo*. Se non ci sono attributi che rispettano tali criteri utilizziamo dei **codici** appositi.

## Traduzione delle associazioni
### Associazioni Many-To-Many
![[Pasted image 20241208210540.png]]
```
EMPLOYEE(Number(pk), Surname, Wage)
PROJECT(Code(pk), Name, Budget)
ENROLLMENT(Number(pk), Code(pk), StartDate)
```

C'e' un vincolo di integrita' referenziale tra:
- `Number` in `ENROLLMENT` e la chiave di`EMPLOYEE`
- `Code` in `ENROLLMENT` e la chiave di `PROJECT`
**ATTENZIONE**
>La traduzione effettuata non tiene conto della *cardinalita' minima* delle associazioni molti a molti.

### Associazioni ricorsive
![[Pasted image 20241208211038.png]]
```sql
PRODUCT(Code(pk), Name, Cost)
MADEOF(MadeUp(pk), Element(pk), Number)
```

### Associazioni N-arie
![[Pasted image 20241208211138.png]]
```sql
SUPPLIER(VAT(pk), Name)
PRODUCT(Code(pk), Type)
DEPARTMENT(Name(pk), Phone)
SUPPLY(Supplier(pk), Product(pk), Department(pk), Number)
```

### Associazioni One-To-Many
![[Pasted image 20241208211318.png]]
```sql
PLAYER(Surname(pk), BirthD(pk), Role)
AGREEMENT(SurnameP(pk), BirthDP(pk), Team(pk), Hire)
TEAM(Name(pk), City, Team Colors)
```
puo' essere semplificato rimuovendo la ridondanza e quindi raggruppando `PLAYER` e `AGREEMENT` 
```sql
PLAYER(Surname(pk), BirthD(pk), Team(pk), Role, Hire)
TEAM(Name(pk), City, Team Colors)
```
- C'e' un vincolo di integrita' referenziale tra `Team` in `PLAYER` e la chiave in `TEAM`
- Se la cardinalita' minima dell'associazione e' 0, allora `Team` in `PLAYER` deve permettere valori NULL

**NOTA**
>Questa traduzione puo' rappresentare il caso in cui 0 sia la cardinalita' minima e 1 quella massima: 0 -> NULL allowed, 1 -> NULL not allowed.

### Associazioni One-To-One
![[Pasted image 20241208212031.png]]
Abbiamo due opzioni differenti
```sql
HEAD(Code(pk), Surname, Wage, Department, StartDate)
DEPARTMENT(Name(pk), Office, Phone)
```
oppure
```sql
HEAD(Code(pk), Surname, Wage)
DEPARTMENT(Name(pk), Office, Phone, Head, StartDate)
```

**ATTENZIONE**
>Un piccolo cambiamento nella cardinalita' e la scelta degli identificatori puo' portare a significati completamente diversi.


#### Links
[[Conceptual Design]]
[[Entity-Relationship Model]]
[[UML]]
