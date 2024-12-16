>Un **indice** (*index*) e' una *struttura dati* che supporta accesso efficiente ai dati. Un *indice* e' una coppia $\langle key, \space label \rangle$ che, data una chiave $K$ provvede un modo efficiente per recuperare tutte le $label$ con $key = K$.

Il processo di recupero di un record e', data una chiave $K$
1. Prende la chiave $K$ e la cerca nell'*indice* 
2. Trovata la chiave nell'indice, questo contiene un riferimento (label) al blocco di memoria che contiene il record, quindi troviamo questo blocco nel disco e lo carichiamo in memoria
3. Dal blocco, accediamo al record necessario

## Labels
>Le **labels** sono i *riferimenti ai blocchi di memoria*.

Le *labels* possono essere:
1. Gli stessi **record di dati**
![[Pasted image 20241216222946.png]]
2. Gli **identificatori dei record** (*RID*) del record con valore di chiave $K$
![[Pasted image 20241216223004.png]]
3. Una **lista di RID** dei record con valore di chiave $K$
![[Pasted image 20241216223030.png]]

**OSSERVAZIONI**
- Nelle rappresentazioni 2 e 3 i valori 10 all'inizio dei record rappresentano il **RID** mentre nella 1 questo corrisponde anche alla *label* dell'indice.
- Se usiamo la rappresentazione 1 possiamo avere **al massimo un indice** e la dimensione dell'index **e' la stessa dimensione dei record di dati**.
- La rappresentazione 3 e' la piu' compatta *ma* le label hanno **dimensione variabile**

## Indici in SQL
```
CREATE [UNIQUE] INDEX IndexName ON Table(AttributeList)
DROP INDEX IndexName
```
esempio
```
CREATE INDEX EmpIdx ON Employee(Surname, Name)
DROP INDEX EmpIdx
```

#### Links
[[Sequential File Index]]
[[B+ Trees]]