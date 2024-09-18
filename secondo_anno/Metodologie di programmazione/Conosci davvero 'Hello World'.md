>Solitamente, quando si installa una nuova libreria o si impara un nuovo linguaggio, il primo programma che si scrive e': **Hello World!**. Sembra banale ma e' di grande importanza, in quanto viene fatto per testare che tutto funzioni come dovrebbe.

### Warning del compilatore
E' legale scrivere una funzione del tipo
```cpp
int pippo(int) {
	return 10;
}
```

Il seguente frammento di codice torna un warning che ci dice che la variabile `level` non e' utilizzata, tuttavia viene allocato dello spazio per questa, o comunque il compilatore si prepara a gestirla. Quindi il warning ci avverte del fatto che *una variabile inutilizzata e' uno spreco di risorse*.
```cpp
int pippo(int level) {
	return 42;
}
```

### Good programming
In questo caso il compilatore non lancia un warning, in quanto gli specifichiamo che, a tempo di compilazione tale variabile non dovra' essere considerata.
```cpp
int pippo(int level) {
	static_cast<void>(level); // ignora esplicitamente il valore di level
	return 42;
}
```

Nel caso ad esempio `(double) level` e' considerato *stile cattivo*, poiche' esiste un metodo specifico di cpp per fare il casting esplicito. 
Nel senso: se cerco un cast in un programma cpp, quando vedo `static_cast`, immediatamente lo trovo, a differenza delle semplici parentesi che sono generiche e quindi lo rendono difficili da individuare.
```cpp
int pippo(int level) {
	static_cast<void>(level); // stile cpp
	(void) level; // stile c, che in questo caso viene considerato un buon stile
	return 42;
}
```

E' possibile fare anche il casting a void di una funzione
```cpp
int pippo(int level) {
	(void) pluto(level);
	return 42;
}
```
qui diciamo al compilatore di ignorare esplicitamente il valore di ritorno della funzione `pluto`

#### Altra convenzione
>Per convenzione quando si fanno gli `if` se ritorna `false` vuol dire che e' andato tutto bene, se invece ritorna `true`, vuol dire che si e' verificato un errore.



