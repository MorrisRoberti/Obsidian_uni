>La **classe di origine** e' la classe utilizzata nell'operatore *new* (e' unica). Le **classi di appartenenza** sono la classe di origine e le sue superclassi.

es
```java
Quadrato q = new Quadrato(7);
```


![[Pasted image 20240505210840.png]]

![[Pasted image 20240505210905.png]]
- La **classe di origine** e' semplicemente la classe da cui istanzio l'oggetto
- Le **classi di appartenenza** sono la classe d'origine e tutte le superclassi dalle quali questa deriva

### Operatore instanceof
>Dato un oggettto *o* e' possibile stabilire se *C* e' **una** sua classe di appartenenza

```java
Quadrato q = new Quadrato(5);

q instanceof Rettangolo // true
q instanceof Object // true
q instanceof String // false

```

#### Links