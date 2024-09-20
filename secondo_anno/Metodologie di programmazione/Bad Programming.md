- **Undefined Behavior** -> Quando si sfora la dimensione massima di un tipo di dato es. overflow si ha un undefined behavior quindi puo' succedere qualsiasi cosa. QUALSIASI.
- **Unspecified Behavior** -> E' possibile avere un errore di unspecified behavior
```cpp
int i = 1;
foo(++i, ++i);
```
qui si ha un **side effect** poiche' oltre a chiamare la funzione fa qualcos'altro e, siccome i parametri vengono valutati in modo arbitrario in base al compilatore (o da dx a sx o vicevera o a caso), puo' succedere che sulla mia macchina sara' diverso rispetto ad un'altra
```cpp
foo(2, 3);

// oppure

foo(3, 2);

```

#### Links