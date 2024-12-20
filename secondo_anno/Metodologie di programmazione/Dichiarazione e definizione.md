## La dichiarazione
>La dichiarazione (di una funzione, di una variabile, di un tipo etc.) e' un costrutto del linguaggio che serve a stabilire un nuovo nome per una certa entita'

```cpp
struct T;
extern int a;
int k(bool x);
```

Ora quella keyword `extern` serve a dire che la variabile e' *dichiarata ma non definita*, quindi che esiste ma non puo' essere inizializzato nessun oggetto di quel tipo.
Quando si fa una dichiarazione che NON e' anche una definizione si dice che questa e' una **dichiarazione pura** (o "forward").

Chiaramente la dichiarazione pura non puo' avvenire in contesti come *il corpo di funzioni*.

La keyword `extern` e' **obbligatoria** nelle dichiarazioni di variabili pure ma opzionale nel resto dei costrutti.

**ATTENZIONE**
```cpp
extern int a = 10; // e' una definizione poiche inizializzata
```
## La definizione
>La **definizione** (di una funzione, di una variabile, di un tipo etc.) e' un costrutto che ci permette di dichiarare un nuovo nome per un'entita' e definirne alcune caratteristiche.

```cpp
struct T {int x;};
int a = 3;
int k(bool x) {
return x && true;
}
```


Quando faccio una dichiarazione di questo tipo `struct T` il compilatore non ha alcuna informazione riguardo la struct:
- non sa che attributi ha
- non sa quanta memoria allocare
Dunque non posso creare oggetti di tipo `T`.

### Namespace e definizione incrementale
>La definizione dei *namespace* e' **incrementale**, nel senso che quando definiamo un namespace possiamo definirne una parte e poi aggiungere codice.

```cpp
namespace test {
	/* codice */
}

/*...*/

namespace test {
	/* altro codice */
}
```



### Puntatori opachi
>Quindi ci verrebbe da domandarci **a che serve una dichiarazione pura**?
>E' utile in un contesto particolare: quando occorre definire puntatori o riferimenti ad oggetti di tipo `T` senza conoscere la definizione del tipo `T`. Tali puntatori sono detti **puntatori opachi**. In questo caso il compilatore sa quanta memoria allocare per un puntatore e quindi il tipo non gli interessa.

```cpp
struct T;
T* t_ptr; // puntatori opachi a T
```

Il fatto che il compilatore richieda il *tipo* dell'oggetto dichiarato ha a che fare con il **parsing** del linguaggio, cioe' serve al compilatore per capire se quella stringa e' conforme alla grammatica del linguaggio.

>Ma quindi **a che servono**?

Sono utili per mantenere l'**information hiding**. Li utilizziamo negli header file per puntare ad oggetti dei quali poi andremo a definire la struttura nel `.cpp`
```cpp
// example.hh
struct MyType;

void initializeMyTypeObj(MyType* obj, int x);

```

```cpp
// example.cpp
#include "example.hh"

struct MyType{
	int k;
};

void initializeMyTypeObj(MyType* obj, int x) {
	obj->k = x;
}

```

**ATTENZIONE**
```cpp
// test.hpp
struct T;

void initializeT(T obj, int x);
```
il codice sopra e' corretto e **non genera errori finche' la funzione non viene definita**.
```cpp
// test.cpp
#include "test.hpp"

void initialize(T obj, int x) {
	obj.k = x;
}
```
>Il compilatore dara' errore solo in questo caso, poiche' andando a *definire* la funzione, si corre il rischio che in questa venga utilizzato un tipo di cui non si sa nulla, quindi lancia l'errore. Per risolvere tale errore bisogna dare una definizione del tipo, come segue.

```cpp
// test.cpp 
#include "test.hpp"

struct T {
	int k;
};

void initializeT(T obj, int x) {
	obj.k = x;
}
```
Tale problema non si porrebbe se passassimo un puntatore a `T` **senza accedere all'oggetto di tipo T**. Se invece vi accedessimo allora avremmo l'errore.

### Un caso speciale
>Nel caso del C++ 2011 (o successivo), è possibile anche fornire una dichiarazione pura per un tipo enumerazione, cosa che non era possibile fare con il C++ 2003:

```cpp
enum E : int;                // dichiarazione pura
enum E : int { a, b, c, d }; // definizione
```

### Dichiarazione/Definizione Template (classi e funzioni)

- Dichiarazione pura di template di classe
```cpp
template<typename T>
struct S;
```
- Definizione di template di classe
```cpp
template<typename T>
struct S {
	int k;
};
```

- Dichiarazione pura di template di funzione
```cpp
template<typename T>
T add(T t1, T, t2);
```
- Definizione di un template di funzione
```cpp
template<typename T>
T add(T t1, T t2) {
	return t1 + t2;
}
```

>Il motivo per il quale nei template si scrive `typename T` e' perche' altrimenti la grammatica, come nel caso di `nome1 * nome2` sarebbe ambigua.

#### Code
[[TestClass.hpp]]
#### Links
[[Type aliases]]

