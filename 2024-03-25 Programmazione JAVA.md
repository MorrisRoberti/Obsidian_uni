>In JAVA **tutto e' una classe**, non esiste un ambiente globale per cui non esistono le funzioni cosi come sono definite ma solo metodi.
#### Compilazione
il programma .java viene compilato tramita *javac* in programma .class (scritto in java bytecode), questo successivamente interpretato per essere eseguito sulla JVM.

```java
public class HelloWorld {
	public static void main(String[] args) {
		System.out.println("Hello World");
	}
}
```

Quando dichiariamo un oggetto con *new* l'identificatore non e' un puntatore all'oggetto nello heap ma una reference