>Lo **schema** in un database e' l'invariante che definisce la struttura dei dati mentre le **istanze** sono i valori dei dati che hanno la struttura definita dallo schema

### Logical schema & Internal Schema
>Lo **schema logico** del database definisce la sua struttura attraverso il **logical data model** (es. la struttura delle tabelle) mentre lo **schema interno** rappresenta lo schema a livello di immagazzinamento, quindi record, file e dati in generale.

Ora in termini di database relazionali possiamo distinguere due tipi di schema particolare
### Schema of a relation
>Lo **schema di una relazione** e' la definizione della struttura di quella relazione, quindi rappresenta il dominio.

> Gli insiemi che costituiscono il dominio nel contesto di una relazione sono chiamati **attributi**

Definiamo lo **schema di una relazione** $R$ con gli attributi $A_1, A_2, ..., A_n$.
$$R(A_1, A_2, ..., A_n)$$

Un esempio concreto
```
STUDENTS(Name, Surname, Number, Year Of Birth)
```

### Schema of a database
>Lo **schema del database** e' l'insieme degli schemi di relazione delle relazioni di quel database.

Definiamo lo **schema di database** $R$ con gli *schemi di relazione* $R_n\lbrace{X_n}\rbrace$ dove $X_n$ l'insieme degli attributi, e quindi il dominio della relazione.
$$R = \lbrace{R_1(X_1), R_2(X_2), ..., R_n(X_n) }\rbrace$$

Un esempio concreto
```
R = {STUDENTS(Name, Surname, Number, Year Of Birth),
	 EXAMS(Student, Grade, Lecture),
	 LECTURES(Code, Name, Lecturer)}
```

Una **tupla** su un insieme di attributi $X$ e' una *mappatura* di ogni attributo $A \in X$ in un valore del dominio di $A$.

Prendiamo la tabella STUDENTS definita precedentemente
```
STUDENTS

	Name    Surname   Number   Year Of Birth
   -----------------------------------------
1   Mario    Rossi     12345       2000
2   Giuseppe  Verdi    54321       1995

```
Se prendiamo la prima tupla, $t[A]$ sara' il valore sara' il valore di quella colonna per la tupla presa, quindi $t[Name]=Mario$.

### Relation instance
>Una **istanza di relazione** della relazione $R(X)$ e' quindi  **un insieme di tuple** che rispettano lo *schema di relazione* $R(X)$.

Nell'esempio precedente
```
  Mario    Rossi     12345       2000  
  Giuseppe  Verdi    54321       1995  
```
E' una **istanza di relazione**.

(Banalmente una tabella riempita con dei record che rispettano lo schema di relazione e' un'istanza di relazione)
![[Pasted image 20240921200211.png]]
### Database instance
>Una **istanza di database** e' un insieme di *istanze di relazione* $r=\lbrace{r_1, r_2, ..., r_n}\rbrace$ basate sullo *schema di database* $R = \lbrace{R_1, R_2, ..., R_n}\rbrace$ dove ogni istanza $r_i$ rispetta lo schema $R_i$.

![[Pasted image 20240921200306.png]]


#### Links
[[Il modello relazionale]]