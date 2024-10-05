## ODR (One definition rule)
- Per fare in modo che le diverse unita' di traduzione interagiscono serve un'interfaccia comune, formata da dichiarazioni di tipi, variabili, funzioni etc.
- Per ridurre il rischio di inconsistenza dell'interfaccia, si cerca di seguire la regola DRY(Don't Repeat Yourself)
- Banalmente si tratta di usare gli header file includendoli nei sorgenti che li utilizzano

### Funzioni inline
>Una funzione inline e' una funzione etichettata con **inline**, che serve a dire al compilatore di effettuare un'espansione in linea, cioe' il compilatore in questo caso andra' a prendere il codice della funzione e lo incollera' nel punto della definizione.
### ODR passi
1. Ogni **translation unit** puo' contenere non piu' di una definizione di una data variabile, funzione, classe, enumerazione o template
2. Ogni **programma** deve contenere *esattamente una definizione* di ogni variabile e di ogni funzione non-inline usate nel programma 
3. Ogni **funzione inline** deve essere definita in ogni unita' di traduzione che la utilizza -> questo significa che appunto la definizione della funzione deve essere in un header file
4. in un **programma** vi possono essere *piu' definizioni* di una classe, enumerazione, funzione inline, template di classe e template di funzione (in unita' di traduzione diverse) a condizione che:
	1. tali definizioni siano sintatticamente identiche
	2. tali definizioni siano semanticamente identiche

**violazione punto 1**
```cpp
struct S { int a; };
struct S { char c; double d; };
```
altra violazione
```cpp
int a;
int a;
```
se una delle due fosse stata dichiarata `extern` allora sarebbe stato legale

**ATTENZIONE**
>Quando questa cosa si verifica attraverso piu' unita' di traduzione differenti, il compilatore non da errore, da questo e' stata creata la ODR

esempio di codice che *non viola* punto 1
```cpp
namespace N { int a; }
int a;
```
analogamente
```cpp
int incr(int a) { return a + 1; }
long incr(long a) { return a + 1; }
```


**violazione punto 2**
>Uso di una variabile  o funzione che e' stata dichiarata ma *MAI* definita nel programma (zero definizioni). La compilazione andra' a buon fine ma il linking no.

altra violazione: definizioni multiple in translation unit diverse
```cpp
// nel file foo.hpp
int foo(int a);

// nel file foo1.hpp
#include "foo.hpp"
int foo(int a) { return a + 1; }

// nel file foo2.hpp
#include "foo.hpp"
int foo(int a) { return a + 2; }

// nel file user.cpp
#include "foo.h"
int bar(int a) {return foo(a); }
```

**violazione del punto 3**
Se abbiamo una funzione **inline** possiamo mettere la dichiarazione in un header file, includerlo in diverse unita' di traduzione e in ognuna di queste bisogna definire la funzione, **in questo modo ogni unita' di traduzione ha la stessa definizione di quella stessa funzione**.


Utilizziamo `#pragma once` per dire al preprocessore di includere un'header file una sola volta
**ATTENZIONE**
>Sia per pragma che per ifndef bisogna metterli in ogni header file cambiando il nome della guardia

*namespace anonimo* -> viene definito uno spazio di nomi che non puo' essere usato da altri file, in questo modo il tuo namespace sara' unico e definibile **solo nell'unita' di traduzione corrente**