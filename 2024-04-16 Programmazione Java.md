### Campi di istanza
- un campo di istanza e' relativo solo appunto all'istanza

### Campi di classe
- A differenza dei campi d'istanza dono condivisi fra TUTTE le istanze della classe
	- esiste un'unica copia di un campo classe
- Per definire un campo di classe in Java si usa la parola *static* 
```java
public class Punto {
	private final int x; // campo d'istanza
	private final int y; // campo d'istanza

	private static int allocations = 0; // campo di classe
}
```

### Metodi statici
- E' possibile dichiarare metodi di classe con *static* esattamente come per i campi e poi richiamarli direttamente dalla classe, senza creare un'istanza
```java
public class Punto {
	private final int x; // campo d'istanza
	private final int y; // campo d'istanza

	private static int allocations = 0; // campo di classe

	public static int getAllocations() {
		return allocations;
	}

	public static void main(String [] args) {
		System.out.println(Punto.getAllocations());
	}
}
```