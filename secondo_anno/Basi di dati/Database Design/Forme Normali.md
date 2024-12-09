>La **forma normale** e' la proprieta' delle relazioni di un database relazionale che ne garantisce la qualita'.

Una relazione NON e' in forma normale quando:
- Presenta **ridondanze**
- Presenta anomalie di aggiornamento

Le forme normali sono solitamente definite sul modello relazionale, ma talvolta possono essere definite anche su altri modelli, come il modello ER.

Prendiamo in considerazione la seguente relazione

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
Nella relazione sopra possiamo individuare delle **anomalie**:
- **Ridondanza** -> Ogni `Employee` ha un `Wage` ripetuto nella relazione
- **Anomalia di aggiornamento** -> Quando il `Wage` di un `Employee` cambia dobbiamo modificare tutte le sue occorrenze
- **Anomalia di cancellazione** -> Quando un `Employee` smette di partecipare in ogni suo `Project` viene cancellato dal database
- **Anomalia di inserimento** -> Non possiamo creare un `Employee` senza un `Project` associato

Come si capisce, tale situazione non e' desiderabile, per cui vogliamo poter **normalizzare** le nostre relazioni.

Talvolta (non sempre) le *anomalie* sono date dalle [[Dipendenze Funzionali (FD)|Dipendenze Funzionali]].

## Tipologie di forme normali

### Boyce-Codd Normal Form (BCNF)
>La **Boyce-Codd Normal Form** (anche chiamata *BCNF*) e' la forma normale piu' importante ed e' definita come segue:
>
>*"Una relazione $R$ e' BCNF se, per ogni sua dipendenza funzionale non triviale $X\rightarrow Y$ definita su $R$, $X$ e' una superchiave di $R$."*
> 

Quindi per essere BCNF bisogna che ogni FD non triviale la parte destra deve contenere **almeno** la primary key.
**NON E' SEMPRE POSSIBILE RAGGIUNGERE LA BCNF**.

### Terza Forma Normale (3NF)
>La **Terza Forma Normale** (*3NF*) e' una versione meno restrittiva della BCNF. Talvolta non e' possibile raggiungere la BCNF, quindi si tenta di raggiungere la 3NF che **E' SEMPRE RAGGIUNGIBILE**.

*Se una relazione ha una sola chiave, questa sara' sicuramente in BCNF se e solo se e' in 3NF*.

#### Links
[[Normalizzazione]]
[[Dipendenze Funzionali (FD)]]