>Le espressioni in C++ possono essere classificate in 3 modi: *lvalue* (left value), *xvalue* (expiring lvalue) e *prvalue* (primitive rvalue).

- L'unione di *lvalue* e *xvalue* forma i **glvalue** (*generalized lvalue*)
- L'unione di *xvalue* e *prvalue* forma gli **rvalue** (*right value*)

#### glvalue
>Un **glvalue** e' un'espressione che permette di stabilire l'identita' di un oggetto in memoria. Il nome "left value", in origine indicava che tali espressioni potevano comparire a sinistra dell'assegnamento (*ATTENZIONE* essi potevano comparire *anche* a sinistra dell'assegnamento ma non solo).

Esempi
```cpp
int i;
int ai[10];
i = 7; // l'espressione i e' un lvalue (quindi un glvalue)
ai[5] = 7; // l'espressione ai[5] e' un lvalue (quindi un glvalue)
```

#### xvalue
>Un **xvalue** e' un *glvalue* che denota un oggetto le cui risorse possono essere riutilizzate, tipicamente perche' sta terminando il suo lifetime (expiring lvalue). Un *lvalue* e' un glvalue che non sia un xvalue.

Esempi
```cpp
Matrix foo1() {
	Matrix m;
	// ...codice
	return m; // l'espressione m e' un xvalue
}
```

`m` verra' distrutto automaticamente in uscita dal blocco nel quale e' stato creato. Il valore ritornato dalla funzione non e' `m` ma una sua "copia".

```cpp
void foo2() {
	Matrix m1;
	m1 = foo1(); // l'espressione foo1(), cioe' il risultato ottenuto dalla chiamata di funzione e' un xvalue
}
```

#### prvalue
>Un **prvalue** e' una espressione che denota un valore "primitivo", ovvero un valore costante o il risultato di una computazione. Il nome "right value", in origine indicava che tali espressioni potevano comparire **solo** a destra dell'operatore di assegnamento (se tali espressioni comparissero a sinistra si verificherebbe un errore). Intuitivamente un *prvalue* NON identifica un oggetto in memoria, quindi non e' lecito assegnarvi un valore e non ha nemmeno senso prenderne l'indirizzo.

Esempi
```cpp
int i;
i = 5; // 5 e' un prvalue (quindi un rvalue)
i = 4 + 1; // l'espressione 4 + 1 e' un prvalue (quindi un rvalue)
i = i + 1; // l'espressione i + 1 e' un prvalue (quindi un rvalue)
```