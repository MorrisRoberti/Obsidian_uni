>L'attributo **this** e' un puntatore costante all'oggetto corrente della classe. E' privato e viene inizializzato automaticamente a puntare all'oggetto attuale.

```cpp
class Razionale {
private: 
	int n;
	int d;
public: 
	Razionale somma(Razionale other) {
		Razionale r;
		r.n = (this->n * other.d) + (this->d * other.n);
		r.d = this->d * other.d;
		return r;
	}
}
```
