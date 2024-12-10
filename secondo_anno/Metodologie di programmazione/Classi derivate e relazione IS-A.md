>Consideriamo una classe `Base` e una classe `Derived` fatte nel seguente modo.

```cpp
class Base {
	// ...
};

class Derived : public Base {
	// ..
};
```

La *derivazione pubblica* consente di effettuare l'up-cast, ovvero la conversione implicita da un puntatore o riferimento per un oggetto `Derived` a un puntatore o riferimento per un oggetto `Base`

```cpp
Base* base_ptr = new Derived;
```

**NOTA** 
>Se la derivazione fosse stata *privata o protected* tale conversione sarebbe stata leggittima solo se effettuata all'interno di una funzione *friend* della classe.

Questa conversione ci dice che possiamo utilizzare un oggetto `Derived` dove e' richiesto un oggetto `Base`. Si dice che la classe `Derived` e' in relazione **IS-A** con la classe `Base`, cioe' e' una particolare *concretizzazione* della classe `Base`.

### Derivazione per relazioni HAS-A
>Talvolta la derivazione potrebbe essere usata (secondo alcuni a sproposito) per definire relazioni di tipo **HAS-A**, ovvero: la classe `Derived` ha un sotto-oggetto di tipo `Base`, ovvero lo "possiede" quindi lo puo' utilizzare.

Questo tipo di relazione puo' essere codificata anche in 2 modi altrenativi:
- Tramite **eredita' privata**: `class Utilitaria : private Motore { /* ... */ };`
- Tramite **contenimento**: `class Utilitaria { Motore motore; /* ... */ };`
Tra le due opzioni si preferisce il **contenimento**, anche perche' con il contenimento possiamo facilmente estenderci al caso in cui l'automezzo debba contenere piu' di un solo sotto-oggetto.

#### Links
[[Metodi virtuali e classi dinamiche]]