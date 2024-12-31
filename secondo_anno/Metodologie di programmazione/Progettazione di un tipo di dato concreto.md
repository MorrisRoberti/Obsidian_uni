>Esistono diversi approcci per progettare un tipo di dato concreto e per verificarne la correttezza.

### Test Driven Design
>Ci si mette nei panni dell'utilizzatore del tipo di dato, si scrive il codice di test delle singole funzionalita'. L'attivita' di sviluppo dell'interfaccia e dell'implementazione viene cosi' guidata dai test. Tramite gli errori del compilatore possiamo verificare la correttezza della nostra implementazione.

Il **testing dinamico** e' essenziale per verificare che l'implementazione della nostra classe si comporti correttamente nei casi specificati, **tuttavia** non e' sempre possibile scrivere test che siano sufficienti a coprire i casi in modo esaustivo: *con il testing dinamico possiamo verificare la presenza di errori nel codice ma non possiamo dimostrarne la totale assenza*.

### Invariante di classe
>L'**invariante di classe** e' *una proprieta' che deve essere soddisfatta dalla rappresentazione scelta per il tipo di dato*. Quando e' possibile si vuole codificarne il controllo in un metodo della classe e verificarne la validita' mediante le *asserzioni*.

**NOTA**
>Solitamente gli header file delle librerie C, sono indicate con `<nomelibreria.h>` tuttavia, utilizzare librerie C in progetti C++ e' considerato cattivo stile, quindi si utilizzano le varianti specifiche per C++ che per convenzione hanno lo stesso nome ma con una 'c' davanti: `assert.h` -> `cassert`, `math.h` -> `cmath` etc.

Si chiama *invariante* perche' deve essere sempre verificata, o quasi. Talvolta, durante l'esecuzione di un metodo della classe, tale invariante puo' essere temporaneamente violata.
```cpp
Razionale& operator+=(const Razionale& y) {
	Razionale& x = *this;
	assert(x.check_inv());
	assert(y.check_inv());

	x.num = (x.num_ * y.den_ + y.num_ * x.den_);
	// qui l'invariante NON e' verificata
	x.den *= y.den;
	// qui l'invariante NON e' verificata
	normalize();
	// qui l'invariante viene ristabilita
	assert(x.check_inv());
	return *this;
}
```

Un oggetto che non viola l'invariante di classe e' *ben formato*.
Lo sviluppatore deve garantire che le operazioni della classe rendano vera l'invariante quando vengono creati nuovi oggetti e che la mantengano valida quando oggetti gia' esistenti sono modificati.

**ATTENZIONE**
>Bisogna stare attenti a non fornire all'utente la possibilita' di *rompere* l'invariante. Per esempio nella classe `Razionale` quando abbiamo aggiunto `const Int& num() const;` e `const Int& den() const;` siamo stati attenti a fornire un accesso in sola lettura alla rappresentazione interna della classe. Se avessimo fornito anche l'accesso in scrittura, avremmo dato all'utente la possibilita' di rompere l'invariante.

>**L'attivita' di progettazione dell'interfaccia deve quindi valutare se l'aggiunta di un metodo possa dare accesso incontrollato alla rappresentazione interna e, di conseguenza mettere a rischio l'invariante.**

>Possiamo decidere di compilare il codice con le asserzioni facendo in modo che queste vengano *scartate* durante il processo, tramite il flag `-DNDEBUG`.

### Precondizioni e postcondizioni
>L'invariante di classe e' parte delle precondizioni e post condizioni dei metodi della classe. Queste formano il [[Programmazione per contratto|Contratto]] tra lo sviluppatore e l'utilizzatore della classe.

#### Links
[[Programmazione per contratto]]