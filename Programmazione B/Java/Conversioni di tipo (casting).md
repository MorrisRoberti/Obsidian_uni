>Java converte implicitamente valori di un tipo piu' *piccolo* in un tipo piu' *grande* ma non viceversa

es
```java
float x = 1.5;
double y = 2.3;

y = x; // OK
x = y; // NON FUNZIONA
```
Bisogna utilizzare cio' che si chiama **casting esplicito**, cioe' bisogna specificare il tipo *piu' piccolo* in cui vogliamo convertire il dato (anche essendo a conoscenza della possibile perdita di informazione)
```java
x = y // NO

x = (float) y; // OK
```

#### Links
[[Tipi primitivi]]