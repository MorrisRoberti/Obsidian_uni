>Un **vincolo** e' una funzione booleana (*predicato*) che serve nei DBMS per garantire l'integrita' dei dati e quindi la qualita' delle informazioni.


## Tipi di vincoli
>Esistono due tipi di vincoli: **intra-relazionali** cioe' i vincoli che riguardano l'istanza di relazione corrente, e quelli **inter-relazionali** che invece riguardano l'interfacciarsi di tabelle.

### Vincoli intra-relazionali
Si dividono in due tipi
#### Vincoli sulle tuple
>Esprimono i vincoli sulle **singole tuple** in modo indipendente dalle altre tuple.

Prendiamo in esame una tabella esami
```
Esami(Matricola, Materia, Data, Voto, Lode)
```
sicuramente i valori dell'attributo `Voto` saranno dei numeri compresi tra 0 e 30 ma l'attributo `Lode` potra' assumere valore `true` solo se il valore di`Voto` e' 30. Questo e' un possibile **vincolo sulle tuple**.

#### Vincoli sul dominio
>Sono quei vincoli che sono espressi sul **singolo dominio**.

Ecco l'esempio di alcuni vincoli sul dominio:
- **NOT NULL**
- Tipo di dato del dominio
- Grandezza del valore rispetto al dominio -> VARCHAR(50)

### Vincoli inter-relazionali
>I vincoli **inter-relazionali** sono quelli che coinvolgono piu' tabelle.

##### Integrita' referenziale
>Il vincolo inter-relazionale piu' frequente e' quello di **integrita' referenziale** cioe': Quando abbiamo una tabellla `t1` collegata ad una tabella `t2` tramite chiave esterna `fk` il **vincolo di integrita' referenziale** dice che tutti i valori della colonna `fk` in `t1` devono essere: o *NULL* o presenti in `t2`.

#### Links
[[Il modello relazionale]]