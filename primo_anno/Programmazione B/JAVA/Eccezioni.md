>A livello di principio le **eccezioni** in java funzionano esattamente come in C++: se un'eccezione non viene catturata il programma viene terminato immediatamente

Le eccezioni sono composte da tre parti:
- `try` -> blocco di codice per rilevare le eccezioni
- `catch` -> cattura e gestisce le eccezioni del blocco `try`
- `throw` -> solleva un'eccezione

>Le eccezioni in java sono **oggetti**.Quando usiamo una classe per creare eccezioni dobbiamo derivarla da apposite classi di libreria

![[Pasted image 20240505220726.png]]
Tutte le eccezioni sono sottoclasse di `Exception`. Una classe di libreria particolare e' `RuntimeException`

## Checked and unchecked exceptions

### Checked exceptions
>Le **checked exception** sono sottoclassi di `Exception` ma non di `RuntimeException` e sono dette **eccezioni controllate**.

```java
public class Fallimento extends Exception {
...
}
```

Rappresentano una situazione anomala prevedibile (es `FileNotFoundException`).

**IMPORTANTE** 
Se un metodo solleva un'eccezione controllata, quel metodo e tutti quelli che lo richiamano (direttamente o indirettamente) devono specificarlo nella *signature* oppure quel metodo deve catturare e gestire le eccezioni

*le checked exceptions rendono il codice molto verboso*

### Unchecked exceptions
>Le **unchecked exception** sono come le eccezioni di C++: rappresentano un errore nella logica del programma, oppure uno non prevedibile dal compilatore.

esempi comuni sono `ArrayIndexOutOfBoundException` e `NullPointerException`

#### Links