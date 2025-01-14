>La **ODR** (*One Definition Rule*) e' una regola di buona programmazione che ci dice che: *se diverse parti del programma devono interagire tra loro e' consono stabilire tra queste un'interfaccia comune (variabili, dichiarazioni di tipi etc.)*

Per evitare inconsistenza tra l'interfaccia e una o piu' unita' di traduzione si cerca di seguire la regola **DRY**.

>La regola **DRY** (*Don't Repeat Yourself*) prevede di scrivere le dichiarazioni dell'interfaccia una sola volta, in uno o piu' **header file**. Le varie *translation unit* includeranno gli header file di cui hanno bisogno evitando di ripetere le corrispondenti dichiarazioni.

## Cosa dice la ODR?
La *ODR* dice - in modo semplificato - quanto segue:
1. **Ogni unita' di traduzione** che forma un programma puo' contenere *non piu' di una **definizione** di una data variabile, funzione, classe, enumerazione o template*
2. Ogni **programma** deve contenere *esattamente una **definizione** di ogni variabile e di ogni funzione non-inline* usate nel programma
3. Ogni funzione inline *deve essere definita in ogni unita' di traduzione che la utilizza*
4. In un programma vi possono essere piu' definizioni di una classe, enumerazione, template di classe, template di funzione e funzione inline, **in diverse unita' di traduzione** a patto che:
	1. Tali definizioni siano **sintatticamente identiche**
	2. Tali definizioni siano **semanticamente identiche**

### Esempi di violazioni della ODR
**violazione del punto 1**
```cpp
struct S { int a; };
struct S { char c; double d; };
```
 *Una singola unita' di traduzione contiene due definizioni diverse dello stesso tipo di dato S*.

```cpp
int a;
int a;
```
*Stessa violazione, due definizioni della stessa variabile nella stessa unita' di traduzione, tuttavia se una delle due fosse stata dichiarata con `extern` il codice non avrebbe generato violazioni poiche' quella con extern sarebbe stata la sua dichiarazione pura mentre quella senza la sua definizione; allo stesso modo non sarebbe stato violazione se il nome delle variabili fosse stato completamente qualificato (`N::a` e `::a`)*

**ATTENZIONE**
>Quando questa situazione si verifica attraverso piu' unita' di traduzione differenti, il compilatore non rileva l'errore a tempo di compilazione, per questo e' stata creata la **ODR**.

esempio di codice che *non viola* il punto 1
```cpp
namespace N { int a; }
int a;
```
analogamente
```cpp
int incr(int a) { return a + 1; }
long incr(long a) { return a + 1; }
```
*Anche questa non e' una violazione, in quanto i nomi mangled delle due funzioni saranno diversi una volta precompilata l'unita' di traduzione*

**ATTENZIONE**
>E' lecito avere piu' **dichiarazioni** della stessa entita' a condizione che una sola di esse sia *definizione*, in altre parole le altre devono essere **dichiarazioni pure**.

**violazione del punto 2**
Un caso banale della violazione del punto 2 e' la *usage without definition, cioe' utilizzare una variabile (o funzione o tipo etc.) che e' stata dichiarata ma non definita*. Questo non produrra' un errore a tempo di compilazione ma nel momento in cui andremo a fare il linking per produrre l'eseguibile.

Un altro caso di violazione del punto 2 e' quello delle *definizioni multiple* in unita' di traduzione diverse
```cpp
// foo.hpp
int foo(int a);

// file1.cpp
#include "foo.hpp"
int foo(int a) { return a + 1; }

// file2.cpp
#include "foo.hpp"
int foo(int a) { return a + 2; }

// file3.cpp
#include "foo.hpp"
int bar(int a) { return foo(a); }
```
*Il linker, al momento di collegare l'object file prodotto da `file3.cpp` con il resto del programma potrebbe chiamare indifferentemente una delle funzioni `foo` definite in una delle altre unita' di traduzione in cui e' definita. Tipicamente il linker segnalera' un errore ma in realta' le regole del linguaggio dicono che non e' tenuto a farlo*.

**violazione del punto 3**
Quando utilizziamo le funzioni *inline* quello che succede e' che la chiamata di funzione viene sostituita con *l'espansione in linea* del corpo della funzione, cioe' viene copiato il corpo della funzione nel punto della chiamata, questo viene fatto a scopo di ottimizzazione. Tale espansione e' effettuata durante la fase di compilazione in senso stretto, per cui il corpo della funzione deve essere presente in ogni unita' di traduzione, cio' significa che dobbiamo avere **la stessa definizione di quella stessa funzione in ogni translation unit**.

>Per evitare problemi conviene includere le *definizioni delle funzioni inline* nell'header file in modo che poi la stessa definizione possa essere utilizzata nelle unita' di traduzione che la richiedono.

**violazione del punto 4**
```cpp
// file1.cpp
struct S { int a; int b; }; // definizione del tipo S
S s; // definizione della variabile di tipo S

// file2.cpp
struct S { int b; int a; }; // definizione del tipo S (sintassi diversa)
extern S s; // dichiarazione pura della s definita in file1.cpp
```
Quando il compilatore lavora su `file2.cpp` viene ingannato dalla diversa definizione del tipo S, ma non puo' accorgersene.

Con una piccola variante e' possibile ottenere una violazione della seconda clausola del punto 4
```cpp
// file1.cpp
using T = int;
struct S { T a; T b; }; // definizione del tipo S

// file2.cpp
using T = double;
struct S { T a; T b; }; // definizione del tipo S (sintassi identica ma semantica diversa)
```

#### Links
[[Header files]]
[[ODR nell'atto pratico]]