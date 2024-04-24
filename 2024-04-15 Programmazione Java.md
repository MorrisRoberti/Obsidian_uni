### Javadoc 

### Delegating constructors
```java
public Razionale() {
	...
}

public Razionale(Razionale other) {
	this(other.num, other.den); // chiamata al delegated constructor
}

public Razionale(Razionale other) {
	System.out.println("Hello");
	this(other.num, other.den); 
}
```
- la linea che chiama il costruttore delegato deve necessariamente essere la prima linea di codice, il blocco di codice 9-12 non funziona
### Stream
```java
public void print(PrintStream out) {
	out.println(this.num + "/" + this.den);
}

public void read(InputStream in) {
	Scanner sc = new Scanner(in);
	String line = sc.nextLine();
	if (line.indexOf('/') == -1) {
		sc.close();
		throw new RuntimeException("Carattere separatore errato");
	int num = line.substring(0, line.indexOf('/'));
	...
	}
}
```
- l'implementazione del metodo `toString()` di tutte le classi ritorna un valore del tipo `Razionale@a34a434fc` che rappresentano: oggetto statico e codice hash di quell'oggetto
- Overloading metodo `toString()`
```java
public String toString() {
	return num + "/" + den;
}
```
Viene usato per evitare di stampare quella roba strana di prima 
- L'equals degli array esegue la *reference-equality*
- Overloading del metodo *equals* tra un Razionale e un qualche altro oggetto (tranne tipi primitivi)
```java
public boolean equals(Object other) {
	if (this == other)
		return true;
	else if (!(other instanceof Razionale))
		return false;
	return false;
}
```
- in Java tutte le classi sono di tipo Object...
- `instanceof` fa un casting implicito per vedere se `other` e' un oggetto della classe Razionale
- Tutti gli oggetti hanno un metodo `clone()` -> ritorna una deep copy dell'oggetto sul quale viene chiamato per fare in modo che questo sia *equals* (rispetto alla nostra implementazione)