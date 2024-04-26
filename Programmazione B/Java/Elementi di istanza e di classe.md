>Tutti gli attributi e i metodi visti fin'ora sono detti **di istanza**, cioe' devono necessariamente essere richiamati dall'istanza di una classe. In Java sono presenti anche  campi **di classe**, cioe' campi il cui valore e' condiviso tra tutte le istanze di tale classe.

### Campi di istanza
Ogni istanza derivata dalla classe mantiene una copia dei propri campi d'istanza.

### Campi di classe
Esiste un'unica copia di un campo di classe condiviso tra tutte le istanze

>Lo stesso discorso vale per i metodi: sono presenti **metodi di istanza** e **metodi di classe**.

### Metodi di istanza
Sono metodi che appunto vengono richiamati sull'istanza di una classe

### Metodi di classe
Sono metodi che non hanno bisogno di un'istanza per essere utilizzati ma possono essere richiamati direttamente. Quando invocati non hanno un riferimento a *this* e non e' possibile, accedere ai campi d'istanza dal loro interno.
es
```java
public Main {

	public static void main (String[] args) {
		int x = -5;
		System.out.println(Math.abs(x));
	}

}
```
`abs` e' un metodo di classe della classe `Math`.

#### Links
