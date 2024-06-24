>Ci sono due modi principali per creare oggetti in C++: in modo *statico* e in modo *dinamico*.

### Creazione statica
``Razionale r(1,2);`` oppure ``Razionale r = {1,2};`` i due modi sono equivalenti. 
Cosa succede a livello di memoria?
![[Pasted image 20240227185842.png]]
Quindi come per le variabili statiche l'oggetto viene allocato nello stack.
### Creazione dinamica
``Razionale* r = new Razionale(1,2);``. Creiamo un puntatore ad un oggetto dinamico e lo chiamiamo r.
![[Pasted image 20240227190144.png]]
Questo significa che effettivamente **r NON E' L'OGGETTO** ma il **puntatore all'oggetto**.
Quindi un'operazione del tipo ``r.n = 1;`` e' errata.
Il modo giusto per accedere all'oggetto puntato da r e' **dereferenziare il puntatore**, cioe' 
``r->n = 1;`` oppure ``(*r).n = 1``.

#### Links