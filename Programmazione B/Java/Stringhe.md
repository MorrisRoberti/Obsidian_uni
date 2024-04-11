>In Java le stringhe sono istanze della classe **String**. Non sono realizzate come array di caratteri terminati da un carattere speciale.
### Cose importanti
- Le stringhe in Java sono **immutabili**.
- Le costanti:
```java
String e = "hello";
```
sono **oggetti** della classe *String*.
- 
### Costruttori della classe String
La classe *String* offre due costruttori:
- Senza parametri
```java
String e = new String();
```
- Con un parametro di tipo array di caratteri
```java
char elem[] = {'h', 'e', 'l', 'l', 'o'};
String s = new String(elem);
```
- Costruttore di copia
```java
String r = new String("abc");
String t = new String(r);
```
Crea una copia della stringa *r*.

### Operatori
L'unico operatore messo a disposizione della classe *String* e' il `+` che concatena due stringhe
```java
String k = "abc";
String x = "def";

String y = k + x; // abcdef
```
Non e' possiblie fare l'overloading degli operatori in Java

#### Operatori di assegnamento e confronto
- E' possibile assegnare una stringa ad un'altra, questo effettuera' un'assegnamento **della reference**
```java
String r = "ciao";
String x = r;
```
In questo caso `x` e `r` punteranno alla stessa stringa in memoria, questo non causa problemi poiche' in Java le stringhe sono **immutabili** e quindi non c'e' pericolo di cambiare il valore in modo inaspettato
- Gli operatori di confronto, effettueranno un confronto non tra gli oggetti ma tra le reference
```java
String s = "ciao";
String c = "ciao";
System.out.println(s == c); // true
```
Questo confronto fra reference andra' a buon fine ma questo perche' il compilatore rileva che le due stringhe sono uguali e quindi fa puntare le reference allo stesso spazio in memoria. Per tali motivi bisogna stare attenti ad usare `==` con le stringhe, se si vuole confrontare i valori si deve usare il metodo `equals(s)`.
```java
String s = "ciao";
String c = "ciao";
System.out.println(s.equals(c)); // true
```

### Metodi
- `length()` -> ritorna la lunghezza della stringa
- `equals(s)` -> confronta **i valori** della stringa su cui e' chiamato il metodo e `s`
- `charAt(i)` -> ritorna l'i-esimo carattere della stringa (**non e' possibile usare la bracket notation per accedere ai caratteri di una stringa** poiche' essendo implementate tramite oggetti e non tramite array quest'operazione deve essere definita in un metodo e non in un'operatore)
- `indexOf(c)` -> prende un carattere `c` e restituisce l'indice della prima occorrenza di quel carattere
- `substring(init, end)` -> `init` e `end` sono interi da 0 a `s.length() - 1` e ritorna la sottostringa a partire dalla posizione`init` fino a `end`- 1 

#### Links
