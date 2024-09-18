>Per permettere un approccio completamente orientato agli oggetti, Java mette a disposizione delle **classi wrapper**, cioe' delle classi che rappresentano i [[Tipi primitivi]]

| Tipi Primitivi | Classi Wrapper |
| -------------- | -------------- |
| int            | Integer        |
| short          | Short          |
| byte           | Byte           |
| long           | Long           |
| float          | Float          |
| double         | Double         |
| char           | Char           |
| boolean        | Boolean        |
Gli oggetti wrapper sono **immutabili**. Non sono altro che contenitori dei valori primitivi corrispondenti. Quando effettuiamo un'operazione del genere
```java
int j = 3;
Integer i = j;
i = 7;
```
In realta' viene creato un altro valore e la *reference* rappresentata da `i` punta a tale spazio in memoria.

I costruttori delle classi wrapper permettono di creare oggetti che contengono i valori primitivi corrispondenti. Es
```java
Integer x = 3;
Float z = 2.3;

// oppure

Integer x = new Integer(3);
Float z = new Float(2.3);
```
Il compilatore traduce la prima versione nella seconda.

### Autoboxing and Unboxing
#### Autoboxing
L'**autoboxing** e' l'operazione che fa il compilatore per convertire una variabile di tipo primitivo in un oggetto della rispettiva classe wrapper
```java
int j = 3;
Integer i = j; // ----> Integer i = new Integer(j);
i = 7;// ----> i = new Integer(7);
```

#### Unboxing
L'**unboxing** e' l'operazione che serve a recuperare il valore primitivo dall'oggetto della classe wrapper
```java
Integer x = new Integer(7);

x.intValue() // 7 di tipo int
```

>Da Java 5.0 (vecchissima versione) le operazioni di *unboxing* e *autoboxing* vengono eseguite in modo **automatico**
```java
Integer x = new Integer(7);
int y = x.intValue() + 2; // 9

//  viene tradotto in 

Integer x = 7;
int y = x + 2; // 9
```

### Metodi classi wrapper
- `toString()` -> ritorna la stringa corrispondente al valore contenuto nell'oggetto wrapper
- `equals(k)` -> come per le stringhe confronta il valore dell'oggetto su cui viene chiamato con `k`
- `Integer.parseInt(s)` -> ritorna il valore intero di una stringa `s`, se la stringa non rappresenta un numero lancia un'eccezione

#### Links