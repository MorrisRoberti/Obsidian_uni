>In Java le classi che sono logicamente collegate possono essere raggruppate in *package*.

### Come creare un package
Per inserire la classe attuale nel *package* p la prima riga deve essere la seguente
```java
package p;
```
e il nome della cartella che contiene le classi del package deve essere il nome del package stesso, altrimenti non funziona.
### Caratteristiche
- I nomi dei package devono essere in minuscolo (convenzione)
- Una classe puo' appartenere ad un solo package
- Ogni package introduce un nuovo *namespace* 
### Come accedo ad una classe in un package?
Se devo accedere ad una classe che si trova in un package diverso da quello della classe corrente devo fare nel seguente modo
```java
package calcolatrice;

public class Calcolatrice {
	public static numeri.Complesso somma (numeri.Complesso c1, numeri.Complesso) {
		...
	}
}
```

posso anche importare direttamente la classe
```java
package calcolatrice;

import numeri.Complesso;

public class Calcolatrice {
	public static Complesso somma(Complesso c1, Complesso c2){
		...
	}
}

```

- `java.lang` -> String, Integer, Boolean etc. viene importata di default
- `java.io` cosi' come altri package devono essere importati manualmente

#### Links
[[Scaffolding progetto Java]]
