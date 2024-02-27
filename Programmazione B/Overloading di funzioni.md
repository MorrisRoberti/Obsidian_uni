>L'**overloading** e' la pratica che ci consente di definire piu' volte la stessa funzione. I vincoli sono che il tipo di ritorno non cambi e che le funzioni differiscano o per numero di parametri o per il tipo di questi.

Esempio di overloading
```cpp
class Razionale {
private:
	int n;
	int d;
public: 
	Razionale somma(int k) {
		Razionale r;
		r.n = this->n + (this->d * k);
		r.d = this->d;
		return r;
	}

	Razionale somma(int num, int den){
		Razionale r;
		r.n = this->n * den + this->den * num;
		r.d = this->d * den;
		return r;
	}
}
```

Le due funzioni somma hanno lo stesso nome e lo stesso tipo di ritorno ma un numero di parametri differenti quindi 
```cpp
int main() {
	Razionale r(1,2);
	Razionale r2 = r.somma(5); // chiama la prima e restituisce 11/5
	Razionale r3 = r.somma(2,3); // chiama la seconda e restituisce 7/6
}
```

#### Links
[[Overloading di operatori]]