>Una classe che contiene [[Metodi virtuali e classi dinamiche#Metodi virtuali puri|metodi virtuali puri]] e' detta **classe astratta**. Il fatto che un metodo virtuale sia puro significa che *ogni classe concreta che eredita dalla classe astratta deve fare overriding del metodo*, se non viene fatto l'overriding il metodo rimane puro e quindi anche la classe derivata rimane una *classe astratta*.

**ATTENZIONE**
>NON E' POSSIBILE ISTANZIARE CLASSI ASTRATTE.

```cpp
class Printer {
public:
	virtual std::string name() const = 0;
	virtual void print(const Doc& doc) = 0;
};

int main() {
	Printer p; // ERRORE
}
```

## Distruttori delle classi astratte
>I **distruttori delle classi astratte** dovrebbero essere dichiarati sempre `virtual` MA *non dovrebbero mai essere metodi puri* quindi e' opportuno fornirne l'implementazione.

L'interfaccia di una classe astratta dovrebbe essere quindi la seguente
```cpp
class Astratta {
public:
	// metodi virtuali puri
	virtual tipo_ritorno1 metodo1(parametri1) = 0;
	virtual tipo_ritorno2 metodo2(parametri2) = 0;
	virtual tipo_ritorno3 metodo3(parametri3) = 0;
	// ...

	// distruttore virtuale NON puro (definito, non fa nulla)
	virtual ~Astratta() = default;
};
```

Il motivo per cui i distruttori di una classe devono essere `virtual` e **definiti** e' legato al fatto che vorremmo consentire una corretta distruzione degli oggetti delle classi concrete derivate dalla classe astratta
```cpp
class Astratta {
public:
	virtual void print() const = 0;

	// distruttore errato: non virtuale
	~Astratta() {
		// nota: la stampa ha solo scopo didattico
		std::cout << "Distruttore Astratta" << std::endl;
	}
};

class Concreta : public Astratta {
std::vector<std::string> vs;
public:
	Concreta() : vs(20, "stringa") {}
	void print() const override {
		for (const auto& s : vs)
			std::cout << s << std::endl;
	}

	// nota: 'override' renderebbe evidente il problema, perche' segnalerebbe che il distruttore di Astratta non e' virtuale
	~Concreta() {
		// nota: la stampa ha solo scopo didattico
		std::cout << "Distruttore Concreta" << std::endl;
	}

};


int main() {
	Astratta* a = new Concreta;
	a->print();
	delete a; // invoca solo il distruttore di Astratta
	// memory leak, non viene distrutto il dato membro vector di Concreta
}
```

>Questo succede perche' il distruttore della classe *concreta* invoca implicitamente il distruttore delle sue classi base, quindi questo deve essere definito, altrimenti si ha un errore di `undefined_reference`.

#### Links
[[Metodi virtuali e classi dinamiche]]
[[Overriding]]

