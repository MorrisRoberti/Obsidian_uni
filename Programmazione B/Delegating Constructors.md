>Alcune volte si vuole riutilizzare il codice di un costruttore in un altro, quando questo avviene si usano i *delegating constructors*. Altro non sono che una diversa sintassi.

Sintassi intesa
```cpp
class Razionale {
private: 
	int num;
	int den;
public:
	Razionale() {
		this->num = 1;
		this->den = 1;
	}

	Razionale(int n, int d) {
		if (n != 0 && d != 0) {
			this->num = n;
			this->den = d;
		} else {
			Razionale();
		}
		
	}
};
```

Sintassi con Delegating Constructors
```cpp
class Razionale {
private: 
	int num;
	int den;
public:
	Razionale() {
		this->num = 1;
		this->den = 1;
	}

	Razionale(int n, int d) : Razionale() {
		if (n != 0 && d != 0) {
			this->num = n;
			this->den = d;
		} 
	}
};
```

Quando dichiariamo un costruttore in questo modo il compilatore per prima cosa inizializzera' un oggetto tramite il costruttore delegato e, se l'oggetto non verra' inizializzato nel corpo della funzione, verra' usato l'oggetto creato all'inizio
#### Links