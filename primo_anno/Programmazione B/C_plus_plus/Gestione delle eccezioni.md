>Solitamente nei programmi si potrebbero verificare situazioni anomale, C++ fornisce degli strumenti per gestirle.

### Situazioni eccezionali
- Errori del sistema operativo
- Indisponibilita' delle risorse
- Errori nascosti
- Comportamenti inattesi

### Eccezioni
Le eccezioni vengono utilizzate per evitare interruzioni brusche del programma e per gestire i casi di errore che potrebbero verificarsi durante l'esecuzione.

### Try, catch e throw
Le eccezioni vengono gestite tramite i tre costrutti: ``try``, ``catch`` e ``throw``.
Solitamente il ciclo e' qualcosa di questo tipo:
- Un programma prova (``try``) un'operazione
- Se si manifesta una situazione anomala il programma lancia (``throw``) un'eccezione
- E' possibile gestire tramite una qualche azione l'errore catturando (``catch``) l'eccezione
```cpp
int f(int z) {
	...
	if (z == 0) 
		throw 1;
	...
}

int main() {
	int y;
	cin << y;
	try {
		f(y);
	} catch(int x) {
		if (x == 1)
			cout << "Errore del tipo 1" << endl;
	}
	cout << "Fine" << endl;
	return 0;
}
```
Una volta finito di eseguire il blocco catch l'esecuzione prosegue.

**ATTENZIONE**: questo blocco ``catch`` cattura solo le eccezioni di tipo *int*.

### Vincoli del blocco try-catch
- Ogni ``catch`` ha un solo parametro
- Ad un ``try`` possono essere associati piu' ``catch`` distinti in base al tipo di parametro
- Un ``catch`` puo' essere associato ad un solo ``try``
- Qualsiasi eccezione verra' catturata dal *catch-all* (``catch (...) {}``)

### Osservazioni
- I metodi delle classi si limitano a sollevare eccezioni
- La gestione delle eccezioni e' lasciata al chiamante
- Cio' permette di cambiare il modo in cui l'eccezione viene gestita senza cambiare i metodi
- La chiamata di funzione che lancia l'eccezione **non e' necessariamente** contenuta nel ``try-catch`` (chiamate annidate)

### Eccezioni standard
C++ contiene una libreria standard per le eccezioni:
```cpp
#include <exception>
```
puo' essere utilizzata la classe base ``exception`` per creare nuove eccezioni (ereditarieta').
Esempi di eccezioni standard:
- ``out_of_range``
- ``invalid_argument``

#### Links