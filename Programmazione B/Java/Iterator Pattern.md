>L'**iterator pattern** e' un *design pattern* che tramite un'interfaccia, permette di definire un modo per iterare sugli oggetti di una classe che la implementa.

### Quando ci serve?
Immaginiamo di dover accedere singolarmente agli elementi di una struttura senza conoscere l'implementazione di questa (es. quando iteriamo sugli array utilizziamo un ciclo for e la *square-bracket notation* perche' sappiamo che quello e' il modo di farlo). Questo e' un caso in cui vorremmo utilizzare l'iterator pattern.

### Come funziona?
Di base in Java abbiamo due interfacce diverse e sono:
- `java.lang.Iterable<T>` -> fa in modo che si possa iterare sulle classi che la implementano con il *foreach*
- `java.util.Iterator<E>` -> rappresenta un'interfaccia con la quale si puo' iterare su una collection
```java
public interface java.lang.Iterable<T> {
	Iterator<T> iterator();
}

public interface java.util.Iterator<E> {
	boolean hasNext();
	E next();
}
```

`Iterable<T>` ha solo il metodo `iterator()` di tipo `Iterator<T>` che serve a iterare sugli elementi della collection.

`Iterator<E>` ha due metodi:
- `hasNext()` -> che serve a dire se gli elementi sono terminati
- `next()` -> che restituisce l'elemento successivo della collection

### Differenze principali

| `Iterable<T>`                                                           | `Iterator<E>`                                                                   |
| ----------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| Non mantiene lo stato dell'iterazione                                   | Mantiene lo stato dell'iterazione                                               |
| Non e' possibile rimuovere elementi durante l'iterazione                | E' possibile rimuovere elementi durante l'iterazione                            |
| Rappresenta una collection sulla quale si puo' iterare con un *foreach* | Rappresenta un'interfaccia che si puo' utilizzare per iterare su una collezione |

#### Links
