>Uno **schedule** di transazioni $S$ e' una sequenza di azioni (*read*, *write*, *commit* and *abort*) prese da un insieme di transazioni. L'ordine di azioni in $S$ e' lo stesso dell'ordine nelle singole transazioni. Uno *schedule* rappresenta un'esecuzione cronologica di transazioni.

Esempio:
Date le seguenti transazioni su $A$, $B$ e $C$ che sono oggetti del database, definiamo le seguenti transazioni:
- $T_1$ -> read$_1$($A$), write$_1$($B$), read$_1$($C$), write$_1$($C$)
- $T_2$ -> read$_2$($B$), write$_2$($B$)

Un possibile *schedule* $S$ puo' essere il seguente
- $S$ ->  read$_1$($A$), write$_1$($A$), read$_1$($B$), write$_1$($B$), read$_1$($C$), write$_1$($C$)

Gli *schedule* permettono di descrivere esecuzioni alternate di transazioni concorrenti:
- **complete schedule** -> include *commit* o *abort* per ogni transazione coinvolta
- **serial schedule** -> per ogni transazione ogni operazione e' eseguita in modo consecutivo

## Serializable Schedule
>Un **Serializable Schedule** e' uno schedule il cui effetto su un database consistente e' garantito essere *identico* a quello di un *complete serial schedule*.

![[Pasted image 20241110204905.png]]

![[Pasted image 20241110204948.png]]

![[Pasted image 20241110205000.png]]



#### Links
[[DBMS Architecture]]
[[Transazioni]]