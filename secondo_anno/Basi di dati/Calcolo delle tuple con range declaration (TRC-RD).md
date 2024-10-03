>Il **Tuples Calculus with Range Declaration** esiste per ovviare alla verbosita' del [[Calcolo relazionale del dominio (DRC)]], facendo in modo di non scrivere ogni variabile ma di restringere le variabili alle tuple.

Le espressioni hanno la seguente sintassi
$$\lbrace{TargetList \vert RangeList \vert Formula}\rbrace$$
dove
- $TargetList$ ha elementi del tipo $Y: x.Z$
- $RangeList$ mostra le variabili libere in $Formula$ specificando da quale relazione provengono
- $Formula$ possiede
	- *comparatori atomici* -> $x.A \space R \space c$, $x.A \space R \space y.B$
	- *connettivi logici*
	- *quantificatori che raggruppano le variabili per range* -> $\exists x(R)(f)$, $\forall x(R)(f)$ 

**Esempio 1**
$$\sigma_{Wage \gt 40}(EMPLOYEE)$$
in TRC-RD
$$\lbrace{e.* \vert e(EMPLOYEE) \vert e.Wage \gt 40}\rbrace$$

**Esempio 2**
$$\Pi_{Number, Name, Age}(EMPLOYEE)$$
in TRC-RD
$$\lbrace{e.(Number,Name,Age) \vert e(EMPLOYEE)\vert}\rbrace$$

**Esempio 3**
$$\Pi_{Number, Name, Age}(\sigma_{Wage>40}(EMPLOYEE))$$
in TRC-RD
$$\lbrace{e.(Number, Name, Age) \vert e(EMPLOYEE) \vert e.Wage > 40}\rbrace$$

**Esempio 4**
$$\Pi_{Chief}(SUPERVISOR \bowtie_{Employee=Number} \sigma_{Wage \gt 40}(EMPLOYEE))$$
in TRC-RD
$$\lbrace{s.Chief \vert e(EMPLOYEE), s(SUPERVISOR) \vert e.Number=s.Employee \wedge e.Wage \gt 40}\rbrace$$


**Esempio 5**
$$\Pi_{NameC, WageC}(\rho_{NumC, NameC, WageC, AgeC \leftarrow Number, Name, Wage, Age} (EMPLOYEE) \bowtie_{NumC=Chief} (SUPERVISOR \bowtie{Employee=Number}(\sigma_{Wage \gt 40}(EMPLOYEE))))$$
in TRC-RD
$$\lbrace{NameC, WageC: e'.(Name, Wage) \vert e'(EMPLOYEE), s(SUPERVISOR), e(EMPLOYEE) \vert e'.Number = s.Chief \wedge s.Employee = e.Number \wedge e.Wage \gt 40}\rbrace$$


**Esempio 6**
$$\Pi_{Number, Name}(EMPLOYEE \bowtie_{Number=Chief} (\Pi_{Chief}(SUPERVISOR) - \Pi_{Chief}(SUPERVISOR \bowtie_{Empolyee=Number} \sigma_{Wage \leq 40}(EMPLOYEE)))) $$
in TRC-RD
$$\lbrace{e.(Number, Name) \vert s(SUPERVISOR), e(EMPLOYEE) \vert s.Chief=e.Number \wedge ¬(\exists e'(EMPLOYEE)(\exists s'(SUPERVISOR) (s.Chief=s'.Chief \wedge s'.Employee=e'.Number \wedge e'.Wage \leq 40)))}\rbrace $$

**IMPORTANTE**
>Questo tipo di calcolo relazionale non puo' esprimere query importanti come le **unioni**, per tale motivo SQL, che e' basato su questo linguaggio possiede un operatore di unione esplicito.

#### Links
[[Calcolo relazionale]]
[[Algebra relazionale]]