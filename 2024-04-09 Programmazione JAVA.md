## Stringhe 
### Concatenazione
- L'unico operatore definito per la classe String e' + che concatena due stringhe
```java
String s = "hello";
String r = s + " world" + " !";
System.out.println(r); // non stampa la reference come per gli array ma il valore
```
Nella riga 3 viene stampata la stringa "hello world !" e non la reference perche' under-the-hood java chiama un metodo toString
- Tutte le operazioni oltre a + delle stringhe sono definite come metodi della classe String
- Le costanti stringe es `` String a = "abc";`` sono oggetti della classe String
- Non esiste la bracket notation per accedere ad un elemento della classe String, ma c'e' il metodo s.charAt(index)
- Le stringhe in Java sono **IMMUTABILI** nel momento in cui viene fatta la *new* di una stringa, questa non puo' essere modificata
- L'assegnamento fra oggetti di tipo String comporta un assegnamento fra le *reference* e non fra gli oggetti, quindi se abbiamo``String s = "Hello";`` e ``String r;``, e facciamo ``r = s;`` allora r e s puntano esattamente alla cella di memoria
- l'operatore == per le stringhe confronta le reference e non gli oggetti, verifica che le due variabili facciano riferimento allo stesso oggetto, se voglio confrontare effettivamente il valore delle stringhe devo usare il metodo *equals* della classe String
```java
String s = "ciao";
String r = "ciao";

s.equals(r) // true
```
- *s.indexOf(c)* ritorna l'indice della prima occorrenza di c in s oppure -1 se c non e' presente nella stringa s
- 