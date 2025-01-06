>**Datalog** e' un linguaggio di programmazione *dichiarativo* logico orientato ai database, il cui ancestore e' il Prolog. Utilizza due differenti predicati: **extensional** cioe' riguardante le relazioni del database e **intensional** che corrisponde alle viste.
>I predicati **intensional** sono definiti attraverso *regole*.

## Le regole
$$head \leftarrow body$$
- $head$ e' un predicato atomico (intensional)
- $body$ e' una lista (congiunzione) di predicati atomici
Le query sono specificate da predicati atomici con il prefisso **?** 

## Esempi
**Esempio 1**
DRC
$$\lbrace{Number: m, Name: n, Age: a, Wage: w \vert EMPLOYEE(Number: m , Name: n, Age: a, Wage: w) \wedge a = 30}\rbrace$$
DATALOG
$$? EMPLOYEE(Number: m, Name: n, Age: 30, Wage: w)$$
Abbiamo bisogno di un **intensional predicate**
$$RICHER(Number: m, Name: n, Age: a, Wage: w) \leftarrow EMPLOYEE(Number: m, Name: n, Age: a, Wage: w), w \gt 40$$
E quindi
$$?RICHER(Number: m, Name: n, Age: a, Wage: w)$$

**Esempio 2**
DRC
$$\lbrace{Number: m, Name: n, Age: a \vert EMPLOYEE(Number: m, Name: n, Age: a, Wage: w)}\rbrace$$
DATALOG
$$PUBINFO(Number: m, Name: n, Age: a) \leftarrow EMPLOYEE(Number: m, Name: n, Age: a, Wage: w)$$
E quindi
$$?PUBINFO(Number: m, Name: n, Age: a)$$

**Esempio 3**
DRC
$$\lbrace{Chief: c \vert SUPERVISOR(Chief: c, Employee: e) \wedge EMPLOYEE(Number: e, Name: n, Age: a, Wage: w) \wedge w \gt 40}\rbrace$$
DATALOG
$$CHIEFSOFRICHERS(Chief: c) \leftarrow EMPLOYEE(Number: m, Name: n, Age: a, Wage: w), w \gt 40, SUPERVISOR(Chief: c, Employee: m)$$
E quindi
$$?CHIEFSOFRICHERS(Chief: c)$$

**Esempio 4**
$$ CHIEFSOFNONRICHERS(Chief: c) \leftarrow EMPLOYEE(Number: m, Name: n, Age: a, Wage: w), w \leq 40, SUPERVISOR(Chief: c, Employee: m)$$
$$CHIEFSOFONLYRICHER(Number: c, Name: n) \leftarrow EMPLOYEE(Number: c, Name: n, Age: a, Wage: w), SUPERVISOR(Chief: c, Employee: m), NOT CHIEFSOFNORICHERS(Chief: c)$$
$$?CHIEFSOFONLYRICHER(Number: c, Name: n)$$


**Esempio 5**
DATALOG
$$HIGHGRADE(Employee: e, SuperChief: c) \leftarrow SUPERVISOR(Employee: e, Chief: c)$$
$$HIGHGRADE(Employee: e, SuperChief: c) \leftarrow SUPERVISOR(Employee: e, Chief: c'), HIGHGRADE(Employee: c', SuperChief: c)$$

>La potenza espressiva del Datalog rispetto all'algebra relazionale e al calcolo relazionale sta nella negazione (*Esempio 4*) e nella ricorsione (*Esempio 5*).

#### Links
[[Calcolo relazionale]]
[[Algebra relazionale]]
[[Limiti dell'algebra e del calcolo relazionale]]