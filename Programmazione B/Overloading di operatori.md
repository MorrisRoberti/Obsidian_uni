>In C++ e' possibile fare anche l'overloading degli operatori.

Se vogliamo fare overloading di un'operatore (+, -, etc.) la classe deve mettere a disposizione un metodo *operator op* dove *op* indica l'operatore che vogliamo sovraccaricare
```
class Razionale {
private:
	int n;
	int d;
public:
	Razionale operator+ (Razionale other) {
		return this->somma(other); // somma deve essere definito precedentemente
	}
}
```
Quando facciamo overloading di un operatore troveremo n-1 parametri formali, perche' automaticamente viene tradotto cosi: 
``Razionale r3 = r1.operator+(r2);``

Overloading >
```
bool operator>(Razionale other) {
	return this->n/this->d > other.n/other.d;
}
```

Overloading []
```
int operator[](int index) {
	if(index == 0) {
		return this->n;
	} else if(index == 1) {
		return this->d;
	} else {
		cout << "Error: value not accepted" << endl;
		return 0;
	}
}
```

Overloading ++
```
// pre-fix
int operator++(){
	...
}

// post-fix
int operator++(int){
	...
}
```

- Il *pre-fix* incrementa il valore e poi lo restituisce
- il *post-fix* restituisce il valore precedente e poi incrementa