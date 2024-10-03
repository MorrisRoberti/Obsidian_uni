>Il **calcolo relazionale** e' una famiglia di linguaggi *dichiarativi* basati sulla *logica del prim'ordine*. Abbiamo due definizioni differenti: **calcolo relazionale del dominio** e **calcolo relazionale delle tuple con range declarations**.

## Calcolo relazionale del dominio
>Nel *calcolo relazionale del dominio* un'espressione e' nella forma
$$\lbrace{A_1: x_1, \dots, A_k:x_k \vert f}\rbrace$$

dove $A_1: x_1, \dots, A_k: x_k$ e' la *target list*:
- $A_1, \dots, A_k$ -> sono i diversi attributi (possono essere anche in database diversi)
- $x_1, \dots, x_k$ -> variabili diverse
- $f$ -> e' una formula con operatori e quantificatori booleani

La risultante e' una relazione su $A_1, \dots, A_k$ che contiene tuple di valori per $x_1, \dots, x_k$ che soddisfano la formula $f$.

### Esempi
>Prendiamo in esame le seguenti relazioni
>		`EMPLOYEE(Number, Name, Age, Wage) e SUPERVISOR(Chief, Employee)`
>		
>con `Number` e `Employee` come chiavi.

**Esempio 1**
$$\sigma_{Wage > 40} (EMPLOYEE)$$
in calcolo relazionale 
$$\lbrace{Number: m, Name: n, Age: a, Wage: w \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w) \wedge w \gt 40}$$


**Esempio 2**
$$\Pi_{Number, Name, Age}(EMPLOYEE)$$
in calcolo relazionale 
$$\lbrace{Number: m, Name: n, Age: a \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w)}\rbrace$$

**Esempio 3**
$$\Pi_{Number, Name, Age}(\sigma_{Wage>40}(EMPLOYEE))$$
in calcolo relazionale
$$\lbrace{Number: m, Name n, Age: a \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w) \wedge w > 40}\rbrace$$

**Esempio 4**
$$\Pi_{Chief}(SUPERVISOR \bowtie_{Employee=Number} \sigma_{Wage \gt 40}(EMPLOYEE))$$
In calcolo relazionale
$$\lbrace{Chief: c \vert SUPERVISOR(Chief: c, Employee: e) \wedge EMPLOYEE(Number: e, Name: n, Age: a, Wage: w) \wedge w \gt 40}\rbrace$$


**Esempio 5**
$$\Pi_{NameC, WageC}(\rho_{NumC, NameC, WageC, AgeC \leftarrow Number, Name, Wage, Age} (EMPLOYEE) \bowtie_{NumC=Chief} (SUPERVISOR \bowtie{Employee=Number}(\sigma_{Wage \gt 40}(EMPLOYEE))))$$
in calcolo relazionale
$$\lbrace{NameC: nc, WageC: wc \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w) \wedge w \gt 40 \wedge SUPERVISOR(Chief: c, Employee: m) \wedge EMPLOYEE(Number: c, Name: nc, Age: ac, Wage: wc)}\rbrace$$
