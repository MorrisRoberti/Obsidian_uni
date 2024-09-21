>Lo **schema** in un database e' l'invariante che definisce la struttura dei dati mentre le **istanze** sono i valori dei dati che hanno la struttura definita dallo schema

### Logical schema & Internal Schema
>Lo **schema logico** del database definisce la sua struttura attraverso il **logical data model** (es. la struttura delle tabelle) mentre lo **schema interno** rappresenta lo schema a livello di immagazzinamento, quindi record, file e dati in generale.

Ora in termini di database relazionali possiamo distinguere due tipi di schema particolare
### Schema of a relation
>Lo schema di una relazione e' la definizione della struttura di quella relazione, quindi rappresenta il dominio.

```
STUDENTS(Name, Surname, Number, Year Of Birth)
```

> Gli insiemi del dominio nel contesto di una relazione sono chiamati **attributi**

### Schema of a database
>Lo schema del database e' l'insieme degli schemi di relazione delle relazioni di quel database.

```
R = {STUDENTS(Name, Surname, Number, Year Of Birth),
	 EXAMS(Student, Grade, Lecture),
	 LECTURES(Code, Name, Lecturer)}
```

# DA COMPLETARE


#### Links