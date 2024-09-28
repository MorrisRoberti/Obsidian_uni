>Ogni volta che un nuovo nome viene introdotto in un'unita' di traduzione puo' essere utilizzato solo in determinati punti di tale unita', le porzioni di codice in cui quel nome e' *visibile* si chiamano **scope** di quel nome.

Esistono diversi tipi di scope e in base al tipo, la visibilita' di un nome puo' essere piu' ampia o piu' ristretta.

### Scope di namespace
>Un nome ha **scope di namespace** (che include anche lo scope globale) quando non e' incluso in nessuna struct/class o funzione. Nello scope di namespace, il nome *e' visibile all'interno del namespace a partire dal punto di dichiarazione fino al termine dell'unita' di traduzione*. In pratica questo e' il motivo per il quale gli header file vengono importati sempre in cima nel file sorgente.

```cpp
namespace N {
	void foo() {
		// errori: bar e a non sono visibili in questo punto
		bar(a);
	}

	int a; // definizione di a

	void bar(int n) {
		a += n; //OK: a e' visibile in questo punto perche' dichiarata prima
	}
}
```

### Scope di blocco
>Un nome dichiarato all'interno di un **blocco** e' locale a quel blocco, quindi la sua visibilita' *inizia dal punto di dichiarazione e termina alla fine del blocco*. Un **blocco** e' una porzione di codice racchiusa in graffe.

```cpp
void foo() {
	//...codice...
	{
		int j // inizio scope di blocco per j
		  = expr;

		std::cout << j;
	}
}
```
E' importante notare che `j` ha visibilita' dalla riga 4 non dalla riga 5, quindi dobbiamo stare attenti perche' potremmo scrivere qualcosa del tipo `int j = j;` e questo genererebbe catastrofiche conseguenze (*undefined behavior*).

#### Regole speciali per costrutti speciali
>Ci sono alcune regole che riguardano costrutti speciali: *for*, *while* (analogo a for), *if*, *switch* e *catch*.

##### for
```cpp
for(int i = 0; i < 10; ++i) {
	// i ha lo scope del blocco for
}
```
Questo e' molto comodo poiche' si evita l'ambiguita' dovuta alla funzione di `i`, ad esempio definendo il for come si faceva un tempo
```cpp
int i;
for(i = 0; i < 10; ++i) {
	// codice
}

// utilizzo i
```
In questo caso, lo scope di `i` non e' racchiuso nel blocco for ma e' piu' esterno, questo fa supporre che la variabile dovra' essere utilizzata anche dopo il blocco del for.

Un'altra problematica e' che una sintassi del genere satura lo spazio di nomi, quando in realta' noi potremmo semplicemente usare `i` in tutti i nostri cicli for senza problemi di sorta
```cpp
for(int i = 0; i < 5; ++i){
	// codice
}

for(int i = 0; i < 5; ++i){
	// codice
}
```

##### if
```cpp
  if (T* ptr = foo()) {
    // ptr è visibile qui (e vale ptr != nullptr)
  } else {
    // ptr è visibile anche qui (e vale ptr == nullptr)
  }
```

##### switch
```cpp
  switch (int c = bar()) {
  case 0:
  case 1:
    do_something(c); // c è visibile qui
    break;
  case 2:
    do_something_different();
    break;
  default:
    std::cerr << "unexpected value c = " << c;
    break;
  }
```


##### catch
```cpp
  try {
    int a = 5;
    // ...
  }
  catch (const std::string& s) {
    std::cerr << s; // s è visibile qui
    // NOTA: a NON è visibile qui
  }
```

### Scope di classe
>Nello **scope di classe** i membri della classe (dati, metodi) sono visibili all'interno della classe indipendentemente dal punto di dichiarazione. Per i tipi invece valgono le regole dello *scope di blocco*.

**ATTENZIONE** 
>A scanso di alcuni dettagli come: la possibilita' di scegliere la visibilita', la visibilita' di default e il tipo di accesso ai membri, **struct e class vengono trattati allo stesso modo da c++**.

```cpp
struct S {
  void foo() {
    bar(a); // OK: bar e a sono visibili anche se dichiarati dopo
  }

  int a;
  void bar(int n) { a += n; }
};
```
Il ragionamento e' identico per `class`.

**IMPORTANTE**
>I membri di una classe `S` possono essere acceduti anche da classi che sono derivate dalla classe `S` (si vedra' piu' avanti).

### Scope di funzione
>Lo **scope di funzione** e' quello delle cosidette **label** e sono visibili in tutta la funzione che le racchiude.

```cpp
void foo() {
	int i;
	{
		// dichiarazione della label 'inizio'
		inizio:
			i = 1;
			while(true) {
				// codice
				if(condition)
					goto fine;
			}
	}

// dichiarazione della label 'fine'
fine:
	if(i > 100)
		goto inizio
	return i;
}
```
**ATTENZIONE**
>L'uso di *label* e `goto` e' considerato cattivo stile e andrebbe limitato.

### Scope delle costanti di enumerazione
>C'e' una differenza sostanziale da fare quando si parla dello scope di costanti di enumerazione (`enum`), poiche' ci sono sostanziali differenza che intercorrono tra lo standard c++ 2003 e lo standard c++ 2011:

#### C++ 2003
>Le costanti di enumerazione in C++03 hanno come scope quello del corrispondente tipo enumerazione, ovvero sono visibili *fuori* dalle graffe che le racchiudono.

```cpp
enum Colors {red, blue, green};
```
questo puo' causare un **conflitto di nomi**
```cpp
enum Colors {red, blue, green};
enum Semaforo {red, yellow, green};

void foo() {
	std::cout << red; // a quale red si riferisce?
}
```
Questo e' causato dal fatto che nello standard 03 le costanti di enumerazione venivano automaticamente *castate* a numeri `int`, quindi nella riga 5, il compilatore non sa quale valore andare a prendere e quindi restituira' un errore.

Siccome i valori delle costanti di enumerazione non avevano scope e venivano implicitamente castati ad `int` gli veniva dato un valore incrementale, quindi nel caso sopra il `red` di `Colors` avrebbe avuto valore 0 mentre quello di `Semaforo` avrebbe avuto valore 3.

#### C++ 2011
>Nel C++2011 sono state introdotte le **enum class** che invece limitano lo scope come le classi, costringendo il programmatore a qualificare il nome e evitando potenziali errori.

```cpp
enum class Colori {red, blue, green};
enum class Semaforo {green, yellow, red};

void foo() {
	std::cout << static_cast<int>(Colori::red);
}
```
In questo caso il programmatore e' costretto ad usare il **casting esplicito** , perche', quando nelle versioni precedenti chiamavamo l'elemento di un enum questo veniva castato ad int, da c++11 il casting deve essere esplicito.

#### Links
[[Scope potenziale e Scope effettivo]]
