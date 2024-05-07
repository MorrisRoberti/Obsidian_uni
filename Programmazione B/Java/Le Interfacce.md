>Le **interfacce** sono delle entita' che definiscono il comportamento delle classi che le implementano

### A cosa servono?
>Servono a descrivere il comportamento condiviso da piu' classi e a garantire che ogni classe lo implementi correttamente secondo le proprie caratteristiche. Utilizzando le interfacce non andiamo a precludere alle classi la possibilita' di ereditare da altre (in java l'ereditarieta' e' singola).

### Cosa posso definire in un'interfaccia?
Nelle interfacce e'possibile definire solo la *signature* dei metodi, l'implementazione di questi andra' data **necessariamente** nelle classi che la implementano. In un'interfaccia non e' possibile definire campi (o meglio e' possibile definire campi di classe ma qui non verranno trattati).
```java
public interface I {
	public t1 m1 (...);
	public t2 m2 (...);
	public t3 m3 (...);
}
```

In Java una classe puo' estendere solo un'altra classe (ereditarieta' singola), tuttavia una classe **puo' implementare piu' interfacce**.

Le interfacce possono essere usate solo come tipi statici e non come tipi dinamici (non puo' essere usata la *new*)
```java
I i = new Razionale(2, 3); // ok

Razionale i = new I(); // NO
```
Per le interfacce valgono *upcasting*, *downcasting* e principio di sostituibilita'.

Quando si deve fornire l'implementazione dei metodi dell'interfaccia e' necessario utilizzare il decorator `@Override`
```java
public class C implements I {
	
	@Override
	public t1 m1() {
	return 0;
	}

	...
}
```

**ATTENZIONE**
Per i motivi descritti sopra e' possibile utilizzare le interfacce come parametri di metodi.
```java
public class C {
	public int metodo(I i) {...}
}
```

E' possibile fare in modo che un'interfaccia estenda un'altra interfaccia, cosi' facendo, la sintassi diventera' la seguente
```java
public interface K extends I {}

public class C implements K {}
```
In questo caso la classe `C` dovra' fornire un'implementazione sia per i metodi di `I` che per quelli di `K`.

#### Links