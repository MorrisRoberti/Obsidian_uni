>La classe *Object* e' la superclasse dalla quale sono derivate tutte le classi in java

es
```java
public class Razionale {
...
}
```
cio' che succede *under the hood* e' questo
```java
public class Razionale extends Object {
...
}
```

### Metodi
La classe *Object* mette a disposizione alcuni metodi di utilita' generale che sono disponibili in tutte le classi java:
- `protected Object clone()` -> ritorna una shallow copy di `this`
- `public String toString()` -> ritorna una stringa che rappresenta la reference di `this`
- `public boolean equals(Object obj)` -> confronta la reference di `this` con la reference di `Obj`

**nella maggior parte dei casi il comportamento di questi metodi non e' soddisfacente, quindi si vuole ridefinirli appositamente nelle sottoclassi**

#### Links