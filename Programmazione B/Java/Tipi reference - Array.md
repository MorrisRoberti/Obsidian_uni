>Oltre ai tipi primitivi definiti in [[Tipi primitivi]] esistono i cosidetti **tipi reference**, gli array ne sono un esempio.
## Array
>Gli **array** sono tipi reference predefiniti.

-  Ogni array ha un attributo *length* che definisce la lunghezza dell'array.
- Non sono aree contigue di memoria come in C++
- Non c'e' garanzia che due elementi con indici consecutivi siano allocati in celle di memoria adiacenti
#### Creazione
```java
int[] A; // non e' necessaria la dimensione poiche si sta dichiarando solo una reference ad array
```
`A` e' una **reference** ad un array di interi (inizializzato a *null*)
```java
int[] A = new int[10];
```
Creazione di un oggetto di tipo array di 10 interi e return di una reference a quell'oggetto (identificata da `A`). In questo caso e' **obbligatorio** specificare la dimensione, perche' stiamo effettivamente allocando memoria per quell'array.
E' possibile specificare la dimensione a runtime (tramite una variabile)
#### Inizializzazione
```java
int[] A = {1, 2, 3, 4, 5};
// oppure
int[] A = new int[]{1, 2, 3, 4, 5};
```

#### Selezione
```java
int[] A = {1, 2, 3};
System.out.println(A[1]); // 2
```

Se l'indice dell'array esce dai limiti viene sollevata un'**eccezione a run-time**.
*java.lang.ArrayIndexOutOfBoundException: 22*

#### Assegnamento fra array
L'assegnamento tra due array in Java avviene nel seguente modo
```java
int[] A = new int[10];
int[] B = new int[5];

A = B
```
La reference rappresentata da `A` puntera' allo spazio di memoria dove punta la reference rappresentata da `B`. L'array referenziato precedentemente da `A` diventera' **garbage**.

#### Uguaglianza e disuguaglianza
Semplicemente questi operatori verificano se le due reference puntano alla stessa porzione di memoria
```java
int[] A = new int[3]{1, 2, 3};
int[] B = new int[3]{1, 2, 3};

A == B // false

A = B // assegnamento tra array

A == B // true perche' ora puntano allo stesso spazio in memoria

```

## Array bidimensionali
Un array bidimensionale e' un array che semplicemente ha piu' di un indice
```java
int[][] M = new int[3][2]; // e' una matrice 3x2
```

#### Links