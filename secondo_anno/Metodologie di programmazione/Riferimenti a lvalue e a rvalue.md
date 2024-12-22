>La classificazione delle varie [[Categorie di espressioni]] e' rilevante per capire la differenza tra **riferimenti a lvalue** (`T&`) e **riferimenti a rvalue** (`T&&`). Questi ultimi sono stati introdotti nel C++ 2011 per risolvere alcuni problemi tecnici.

Nel C++ 2003, ogni classe era fornita (se non veniva fatto qualcosa per disabilitarle) di 4 funzioni speciali:
- *costruttore di default*
- *copy constructor*
- *assignment operator*
- *distruttore*

```cpp
struct Matrix {
	Matrix(); // costruttore di default
	~Matrix(); // distruttore

	Matrix(const Matrix&); // copy constructor
	Matrix& operator=(const Matrix&); // assignment operator
};
```

Nel caso in cui una funzione avesse voluto prendere in input un oggetto Matrix e produrre in output una sua variante modificata (senza modificare l'oggetto in input), doveva ricevere l'argomento per constant reference e restituire il risultato per valore
```cpp
Matrix bar(const Matrix& arg) {
	Matrix res = arg; // copia (1)
	// modifica di res
	return res; //ritorna una copia (2)
}
```
Questo era fonte di inefficienze, perche':
1. Non c'era un modo semplice per il chiamante di comunicare il fatto che, in alcuni casi (non tutti) la risorsa passata in input non era piu' di suo interesse e quindi poteva essere modificata in loco, invece di effettuare la prima copia
2. Non c'era modo semplice per la funzione per ritornare l'oggetto `res` senza fare la seconda copia

Nel C++ 2011, alle 4 funzioni speciali delle classi ne sono state aggiunte altre due:
- *move constructor*
- *move assignment*
che lavorano su riferimenti a rvalue

```cpp
struct Matrix {
	Matrix(); // costruttore di default
	~Matrix(); // distruttore

	Matrix(const Matrix&); // copy constructor
	Matrix& operator=(const Matrix&); // assignment operator

	Matrix(Matrix&&); // move constructor
	Matrix& operator=(Matrix&&); // move assignment
};
```
Intuitivamente, una funzione che riceve come argomento un riferimento a *rvalue* (`Matrix&&`) sa che l'oggetto riferito puo' essere solo un **prvalue** o un **xvalue**. In entrambi i casi le risorse contenute nell'oggetto non possono essere utilizzate da altri e quindi possono essere spostate dall'oggetto invece che copiate, guadagnando in efficienza.

In C++ 2011 dove e' presente il *move constructor* il codice sottostante sfrutta quest'ultimo e non il copy constructor
```cpp
Matrix bar(const Matrix& arg) {
	Matrix res = arg; // copia (1)
	// modifica di res
	return res; // sposta (non copia)
}
```
Volendo e' possibile ottimizzare anche la prima copia fornendo una versione alternativa
```cpp
Matrix bar(Matrix&& arg) {
	// modifica in loco di arg
	return arg; // sposta (non copia)
}
```

E' possibile fondere le due versioni in una sola usando il passaggio per valore
```cpp
Matrix bar(Matrix arg) {
	// modifica in loco di arg
	return res; // sposta (non copia)
}
```
In questo terzo caso, all'atto di effettuare il passaggio dell'argomento vi sono due possibilita':
1. Il chiamante fornisce un *lvalue* -> verra' utilizzato il *copy constructor* sull'argomento
2. Il chiamante fornisce un *rvalue* -> verra' utilizzato il *move constructor* sull'argomento

## La funzione std::move 
Supponiamo che il chiamante si trovi a dovere invocare la funzione `bar` sopra discussa con un *lvalue* `m` di tipo `Matrix`, ma non e' interessato a preservare il valore di `m` e quindi lo vorrebbe "spostare" nella funzione `bar` evitando la copia.
Se si chiama
```cpp
bar(m);
```
Siccome `m` e' un *lvalue* verrebbe comunque invocato il *copy constructor*. Per evitare questa cosa occorre un modo per convertire il tipo di `m` da *riferimento a lvalue* (`Matrix&`) a *riferimento a rvalue* (`Matrix&&`).
>Tale effetto si ottiene usando la funzione di libreria **std::move**.

```cpp
bar(std::move(m));
```

**ATTENZIONE**
>La **std::move** non muove nulla, semplicemente indica che `m` deve diventare "movable". Lo spostamento vero e proprio viene effettuato durante il passaggio del parametro.

#### Links
[[Categorie di espressioni]]