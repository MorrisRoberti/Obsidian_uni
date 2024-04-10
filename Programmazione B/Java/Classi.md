>In Java la visibilita' dei metodi e dei campi delle classi deve essere specificata singolarmente per ognuno di essi

```java
public class C1{
	private int x;
	public C1() {...}
	private void func1() {...}
	public int f2(int x) {...}
}
```

### Instanziazione di Oggetti
>L'instanziazione di oggetti in Java avviene **sempre** tramite l'operatore *new*

```java
C1 x;
x = new C1();
```
- 1 -> dichiarazione di una variabile di tipo `C1`, viene creata una **reference** 
- 2 -> cr