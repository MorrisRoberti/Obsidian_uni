>I **generics** in Java e' simile a cio' che in C++ chiamavamo *template*, ossia un modo per creare classi generiche (in realta' non solo classi).

```java
public class Couple<T> {..}
```
Dove `T` e' il **type parameter** cioe' il tipo (*reference*) con il quale andremo a specializzare gli oggetti al momento dell'istanziazione.

**ATTENZIONE** 
Non e' possibile passare come `T` un tipo primitivo (int, double, bool etc.) in quanto questi non sono tipi accettati, tuttavia  e' comunque possibile passare valori di tipi primitivi utilizzando [[Le Classi Wrapper]]
```java
public class Main {

	public static void main(String[] args) {
		Couple<Integer> c = new Couple<Integer>();
	}
}
```

Questo limite esiste perche' la signature della classe generica in realta' viene vista dal compilatore come
```java
public class Couple<T extends Object> {...}
```
(*vedere sotto per capire la sintassi*)

**ATTENZIONE** 
Per lo stesso motivo possiamo, tuttavia, passare array di tipi primitivi, poiche' gli array sono tipi reference
```java
public class Main {

	public static void main (String[] args) {
		Couple<int[]> c = new Couple<>();
	}
}
```

### Bounded Type Parameter
>Ci sono dei casi in cui vorremmo fare in modo che la nostra classe generica accetti soltanto **type parameter** che rispettino determinati criteri, qundi introduciamo i cosidetti **Bounded Type Parameter**

In breve andiamo a dire a java che quella classe accetta come parametro di tipo solo quelli che rispettano una determinata condizione
```java
public class Couple<T extends Comparable<T>> {...}
```

`Comparable<T>` e' un'interfaccia (possiede un solo metodo `compareTo(T o)`). In questo modo noi *limitiamo* i tipi passabili come type parameter a quelli che implementano l'interfaccia `Comparable<T>`.

Questo puo' essere necessario nel momento in cui andiamo a *comparare* due oggetti di tipo `T` nella classe `Couple<T>`. Se il tipo `T` implementa `Comparable` vuol dire che *necessariamente* contiene un'override di `compareTo()` e quindi possiamo utilizzarlo in modo safe.

### Altre limitazioni
- Non e' possibile istanziare oggetti con i type parameters
- Non e' possibile usare casting o `instanceof` con i type parameters (in realta' questa limitazione e' legata a versioni molto vecchie di java)
- Non e' possibile creare array di type parameters

### Naming convention dei generics
Non fondamentale ma comunque degna di nota e' la *naming convention* dei type parameters nei generics:
- T - Type
- E - Element
- K - Key
- V - Value
- N - Number

#### Links
