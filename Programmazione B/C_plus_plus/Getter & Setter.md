### Getter
>Un *Getter* e' un metodo *public* particolare che serve a recuperare il valore di un attributo facendo in modo che sia impossibile accedervi direttamente

```cpp
class Razionale {
private: 
	int num;
	int den;
public: 
	int getNum() {
		return this->num;
	}
};

int main() {
	Razionale r = new Razionale();
	cout << r.getNum() << endl;
}
```

### Setter
>Un *Setter* e' un metodo *public* che serve a impostare il valore di un attributo facendo in modo che tale valore sia validato e corretto prima di andare ad impostarlo

```cpp
class Razionale {
private:
	int num;
	int den;
public: 
	void setDen(int d) {
		if(d != 0) {
			this->den = d;
			return;
		} 
		cout << "Errore: il denominatore non puo' essere 0!" << endl;
		return;
	}
};
```

Sono fondamentali poiche' danno modo di controllare la correttezza dei dati e mantengono sicurezza e **information hiding** della classe.

#### Links