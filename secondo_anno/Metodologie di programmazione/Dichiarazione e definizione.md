## La dichiarazione
>La dichiarazione (di una funzione, di una variabile, di un tipo etc.) e' un costrutto del linguaggio che serve a stabilire un nuovo nome per una certa entita'

```cpp
struct T;
extern int a;
int k(bool x);
```

Ora quella keyword `extern` serve a dire che la variabile e' *dichiarata ma non definita*, quindi che esiste ma non puo' essere inizializzato nessun oggetto di quel tipo.
Quando si fa una dichiarazione che NON e' anche una definizione si dice che questa e' una **dichiarazione pura** (o "forward").

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

### Puntatori opachi
>Quindi ci verrebbe da domandarci **a che serve una dichiarazione pura**?
>E' utile in un contesto particolare: quando occorre definire puntatori o riferimenti ad oggetti di tipo `T` senza conoscere la definizione del tipo `T`. Tali puntatori sono detti **puntatori opachi**.

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

MyType* mytype_ptr;
void createMyTypeObj(MyType& obj, int x);

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

#### Links