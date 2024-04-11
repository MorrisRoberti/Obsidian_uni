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
I costruttori delle classi wrapper permettono di creare oggetti che contengono i valori primitivi corrispondenti. Es
```java
Integer x = 3;
Float z = 2.3;

// oppure

Integer x = new Integer(3);
Float z = new Flota(2.3);
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

>Da Java 5.0 (vecchissima versione) le operazioni di *unboxing* e *autoboxing* vengono eseguite in modo                                                                    