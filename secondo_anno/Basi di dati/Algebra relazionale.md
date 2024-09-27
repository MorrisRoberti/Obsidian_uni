>L'algebra relazionale e' un linguaggio **procedurale** teorico che permette di fare interrogazioni ai database ed e' il linguaggio sul quale si fondano altri linguaggi di interrogazione quali **SQL**.

### Le interrogazioni
>Un'interrogazione e' una funzione che genera una relazione risultato **E(r)** partendo da un'istanza di una relazione **r**.

## Operazioni
>Le operazioni dell'algebra relazionale sono effettuate tra relazioni e producono relazioni come risultato. Le relazioni sono insiemi a tutti gli effetti e dunque le operazioni definite su esse sono parallele a quelle degli insiemi a condizione che **le relazioni coinvolte nell'operazione abbiano lo stesso schema di relazione** ([[Schemas & Instances#Schema of a relation]]).
#### Unione
>L'unione e' come quella degli insiemi: prende 2 istanze di relazione e genera una terza istanza che contiene le tuple di entrambe le relazioni. **ATTENZIONE** se le due relazioni contengono delle tuple uguali, nella relazione risultante verranno prese una sola volta.

![[Pasted image 20240925191347.png]]


#### Intersezione
>L'intersezione prende due istanze di relazione e restituisce un'istanza nella quale sono presenti solo le tuple comuni ad entrambe le relazioni.

![[Pasted image 20240925191618.png]]

#### Differenza
>La differenza prende due istanze di relazione e restituisce una terza istanza di relazione nella quale sono presenti tutte le tuple della seconda istanza che non compaiono nella prima.

![[Pasted image 20240925191726.png]]
Chiaramente a differenza di *unione* e *intersezione* e' *NON commutativa*.

#### Renaming
>L'operatore unario di **renaming** serve per cambiare il nome degli attributi. La cosa fondamentale e' che l'operatore lavora sulle relazioni e non sulle istanze, infatti i dati della tabella non vengono toccati. Si rappresenta nel seguente modo:
>$$ \rho_{NewName \leftarrow OldName} (RELATION) $$

#### Selezione
>L'operatore unario di **selezione** prende in input un'istanza di relazione e restituisce in output un'istanza di relazione con le tuple dell'istanza in input che rispettano un certo predicato. Solitamente le tuple dell'istanza in output sono un subset di quelle dell'istanza in input.
>$$ \sigma_{predicate}(RELATION) $$
>L'interpretazione di $predicate$ e' un'espressione booleana sulle tuple dell'istanza di relazione.
>In un certo senso possiamo dire che l'operatore di selezione *affetta orizzontalmente l'istanza in input*.

![[Pasted image 20240925192556.png]]

#### Proiezione
>L'operatore unario di **proiezione** e' come l'operatore di selezione ma a differenza di questo *affetta in verticale l'istanza in input*, infatti l'output contiene tutte le tuple dell'istanza iniziale ma solo gli attributi specificati.
>$$ \Pi_{Number, Surname}(EMPLOYEE)$$

L'operazione sopra' restituisce il seguente output
![[Pasted image 20240925192945.png]]

- L'output di un'operazione di proiezione contiene al massimo un numero di tuple uguale a quello dell'istanza in input.
- Diciamo "al massimo" perche' potrebbe contenerne anche meno, se ad esempio nell'istanza sopra togliessimo la colonna `Number` allora la riga 2 e 4 sarebbero uguali, quindi per la definizione di *Relazione* una delle due dovra' essere scartata.
- Se $X$ e' una **superchiave** di $R$, allora $\Pi_X(R)$ contiene lo stesso numero di tuple di $R$ 


>Gli operatori unari di **selezione** e **proiezione** sono detti **ortogonali** in quanto "affettano" l'istanza della tabella rispettivamente orizzontalmente e verticalmente.

## Equivalenza di espressioni algebriche
>Due espressioni dell'algebra relazionale $E_1$ ed $E_2$ sono **equivalenti** se forniscono lo stesso risultato indipendentemente dallo stato del database. Le regole equivalenti sono molto importanti perche i DBMS provano a riscrivere le query in espressioni equivalenti ma che hanno un'efficienza maggiore.

[[Espressioni equivalenti]]

## Problematiche relative a valori NULL
>Come si vede e' possibile avere tuple con valori *NULL* ([[Dati parziali e valori nulli]]) quindi:
>$$\sigma_{Age \gt 30}(PEOPLE) \cup \sigma_{Age \leq 30}(PEOPLE) \neq PEOPLE $$
>poiche' i valori nulli di $PEOPLE$ non vengono presi. Per ovviare il problema esistono degli statement atomici utilizzati per riferirsi a valori nulli: **IS NULL** e **IS NOT NULL**.

#### Links 
[[Chiavi e superchiavi]]
[[Il modello relazionale#Relazioni]]

