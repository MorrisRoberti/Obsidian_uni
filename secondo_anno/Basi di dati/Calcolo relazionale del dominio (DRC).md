>Nel *calcolo relazionale del dominio* un'espressione e' nella forma
$$\lbrace{A_1: x_1, \dots, A_k:x_k \vert f}\rbrace$$

dove $A_1: x_1, \dots, A_k: x_k$ e' la *target list*:
- $A_1, \dots, A_k$ -> sono i diversi attributi (possono essere anche in database diversi)
- $x_1, \dots, x_k$ -> variabili diverse
- $f$ -> e' una formula con operatori e quantificatori booleani

La risultante e' una relazione su $A_1, \dots, A_k$ che contiene tuple di valori per $x_1, \dots, x_k$ che soddisfano la formula $f$.

### Esempi
>Prendiamo in esame le seguenti relazioni
>
>		`EMPLOYEE(Number, Name, Age, Wage) e SUPERVISOR(Chief, Employee)`
>		
>con `Number` e `Employee` come chiavi.

**Esempio 1**
$$\sigma_{Wage > 40} (EMPLOYEE)$$
in DRC 
$$\lbrace{Number: m, Name: n, Age: a, Wage: w \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w) \wedge w \gt 40}\rbrace$$


**Esempio 2**
$$\Pi_{Number, Name, Age}(EMPLOYEE)$$
in DRC
$$\lbrace{Number: m, Name: n, Age: a \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w)}\rbrace$$

**Esempio 3**
$$\Pi_{Number, Name, Age}(\sigma_{Wage>40}(EMPLOYEE))$$
in DRC
$$\lbrace{Number: m, Name n, Age: a \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w) \wedge w > 40}\rbrace$$

**Esempio 4**
$$\Pi_{Chief}(SUPERVISOR \bowtie_{Employee=Number} \sigma_{Wage \gt 40}(EMPLOYEE))$$
in DRC
$$\lbrace{Chief: c \vert SUPERVISOR(Chief: c, Employee: e) \wedge EMPLOYEE(Number: e, Name: n, Age: a, Wage: w) \wedge w \gt 40}\rbrace$$


**Esempio 5**
$$\Pi_{NameC, WageC}(\rho_{NumC, NameC, WageC, AgeC \leftarrow Number, Name, Wage, Age} (EMPLOYEE) \bowtie_{NumC=Chief} (SUPERVISOR \bowtie{Employee=Number}(\sigma_{Wage \gt 40}(EMPLOYEE))))$$
in DRC
$$\lbrace{NameC: nc, WageC: wc \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w) \wedge w \gt 40 \wedge SUPERVISOR(Chief: c, Employee: m) \wedge EMPLOYEE(Number: c, Name: nc, Age: ac, Wage: wc)}\rbrace$$


**Esempio 6**
$$\Pi_{Number, Name}(EMPLOYEE \bowtie_{Number=Chief} (\Pi_{Chief}(SUPERVISOR) - \Pi_{Chief}(SUPERVISOR \bowtie_{Empolyee=Number} \sigma_{Wage \leq 40}(EMPLOYEE)))) $$
in DRC
$$\lbrace{Number: c, Name: n \vert EMPLOYEE(Number: c, Name: n, Age: a, Wage: w) \wedge SUPERVISOR(Chief: c, Employee: m) \wedge ¬ \exists m'(\exists n'(\exists a'(\exists w'(EMPLOYEE(Number: m', Name: n', Age: a', Wage: w') \wedge w' \leq 40 \wedge SUPERVISOR(Chief: c, Employee: m')))))}\rbrace $$

## Regole di De Morgan
- $¬ (A \wedge B) = (¬ A) \vee (¬ B)$
- $¬(A \vee B) = (¬A) \wedge (¬B)$

### Altre regole
- $¬\forall x A = \exists x ¬A$
- $¬\exists x A = \forall x ¬A$
- $\forall x A = ¬\exists ¬A$
- $\exists x A = ¬\forall x ¬A$
- $¬A \vee B \rightarrow$ if $A$ then $B$


## Pro e contro del calcolo relazionale del dominio
**PRO**
- Dichiarativo


**CONTRO**
- Molto verboso
- Ci sono espressioni non significative es. $\lbrace{A: x \vert ¬R(A: x)}\rbrace$ 

>L'algebra relazionale (RA) e il Calcolo relazionale del domino (DRC) sono "equivalenti". Per ogni espressione DRC *domain independent* esiste un'espressione RA equivalente e viceversa.

#### Links
[[Calcolo relazionale]]
[[Algebra relazionale]]