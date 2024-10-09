>Avendo visto di di cosa si occupa la ODR, vogliamo vedere come soddisfarla in modo pratico. La linea guida principale e' la **DRY** cioe' *Don't Repeat Yourself*, cioe' scrivere una sola volta dichiarazioni e/o definizioni negli header file e includere questi dove necessario.

### Esempio
Supponiamo di avere un programma che effettua calcoli matematici. Il programma utilizza una classe *Razionale* in`Razionale.hpp`
```cpp
// Razionale.hpp
class Razionale {
	// ... le cose giuste
}
```

Poi supponiamo di avere un'altra parte del programma che gestisce polinomi a coefficienti razionali
```cpp
// Polinomio.hpp
#include "Razionale.hpp"
class Polinomio {
	// ... le cose giuste utilizzando anche Razionale
}
```

Una terza parte del programma definisce un algoritmo che effettua calcoli sui polinomi usando anche i razionali
```cpp
// Calcolo.cpp
#inlcude "Razinale.hpp"
#include "Polinomio.hpp"
// Codice che usa i tipi Polinomio e Razionale
```

Quando compileremo (l'unita' di traduzione corrispondente a ) `Calcolo.cpp` otterremo un errore dovuto alla violazione della clausola 1 della **ODR**.
L'unita' infatti conterra' *due* definizioni della classe *Razionale*, la prima ottenuta dalla prima direttiva di inclusione, la seconda ottenuta *indirettamente* dalla seconda direttiva. Quindi banalmente la violazione sta nel fatto che incudiamo *Razionale* sia direttamente che tramite l'inclusione di Polinomio (che include Razionale).

**UNA SOLUZIONE SBAGLIATA**
La soluzione naive che ci viene subito in mente e' di rimuovere l'inclusione *diretta* della classe *Razionale*
```cpp
// Calcolo.cpp
#include "Polinomio.hpp"
// Codice di Calcolo
```
Questo approccio **sembra** funzionare ma ha diversi problemi:
- Diminuisce la leggibilita' del codice, perche' ora `Calcolo.cpp` e' dipendente in modo indiretto da `Razionale.hpp` 
- Se il responsabile dello sviluppo di *Polinomio* decidesse di modificare l'implementazione della sua classe, ad esempio utilizzando *Frazione* al posto di *Razionale*, la compilazione di `Calcolo.cpp` fallirebbe

Occorre quindi consentire ad ogni unita' di traduzione di includere tutti gli header di cui necessita, trovando una soluzione alternativa a quella proposta sopra.

### Preprocessor Directives
>Le **preprocessor directives** sono, come dice il nome *direttive di preprocessore*, cioe' servono a dare al preprocessore determinati comandi per effettuare operazioni particolari

Ecco alcune direttive:

**pragma once**
>La direttiva `#pragma once`, inserita nell'header file comunica al preprocessore di evitarne l'inclusione multipla (non funziona per tutti i compilatori).

```cpp
// Razionale.hpp
#pragma once 
class Razionale {
	// ...
}
```

**ifndef**
>Una soluzione simile a *pragma once* ma che funziona su tutti i compilatori e' `#ifndef`. Se vogliamo che il programma entri nell'if se la condizione e' vera dobbiamo usare `#ifdef`.

```cpp
// Razionale.hpp
#ifndef RAZIONALE_HH_INCLUDE_GUARD
#define RAZIONALE_HH_INCLUDE_GUARD 1

class Razionale {
	// ...
};

#endif /* RAZIONALE_HH_INCLUDE_GUARD */
```
La prima volta che il file viene incluso, la **guardia**, ovvero il flag del preprocessore `RAZIONALE_HH_INCLUDE_GUARD` **NON E' ANCORA DEFINITA** quindi il preprocessore *procede all'inclusione*. 
Come prima cosa viene definita la guardia stessa e poi si includono nell'unita' di traduzione tutte le dichiarazioni e definizioni.
Se capitasse, durante il preprocessing di quella stessa unita' di traduzione di ritentare l'inclusione di `Razionale.hpp`, il preprocessore troverebbe la guardia gia' definita; la condizione di `#ifndef` valuterebbe a falso e quindi non avverrebbe nessuna inclusione ripetuta.

Banalmente `#ifndef` e' la negazione di `#ifdef`.

**ATTENZIONE**
>Questa soluzione per funzionare deve essere applicata sistematicamente su **tutti** gli header file che fanno parte del programma. Inoltre occorre prestare attenzione e evitare di usare la stessa guardia per file di inclusione distinti.

#### Links 
[[One Definition Rule (ODR) & DRY]]