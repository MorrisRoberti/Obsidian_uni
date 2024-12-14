>I **principi SOLID** sono delle *linee guida* per lo sviluppo di progetti software *Object Oriented* piu' flessibili e manutenibili.

## SRP
>Il *Single Responsibility Principle* o **SRP** dice che *ogni porzione software (una classe, una funzione, etc.) dovrebbe avere in carico una singola responsabilita'*.

Esempio
Una classe che deve manipolare piu' risorse **NON** dovrebbe prendersi direttamente carico della corretta acquisizione e gestione delle risorse piuttosto dovrebbe **delegare** questo compito ad opportune classi *gestore*, in questo modo la classe puo' focalizzarsi sull'usp appropriato delle risorse, non preoccupandosi della loro gestione (vedi [[Approcci per gestire le eccezioni#RAII-RRID|RAII-RRID]]).

## OCP
>Il *Open-Closed Principle* o **OCP** e' una linea guida che dice che *le nostre entita' (classi, funzioni, moduli, etc.) devono essere **aperte alle estensioni** ma **chiuse alle modifiche***.

Per *"aperte alle eccezioni ma chiuse alle modifiche"* si intende che nel progetto software dovrebbe essere semplice aggiungere funzionalita' tramite la scrittura di nuovo codice, senza che per fare cio' si debba modificare il codice gia' esistente (che probabilmente e' gia' testato e funzionante).

Per ottenere il risultato che l'*OCP* si propone dobbiamo utilizzare dei **costrutti di astrazione**
```cpp
class Animale {
private:
	std::string nome;
	int num_zampe;
public:
	void setZampe(int n_zampe);
	void verso();
};

// se volessimo gestire anche i pesci dovremmo modificare il codice nel modo seguente

class Animale {
private: 
	std::string nome;
	int num_zampe;
	int num_pinne;
public:
	void setZampe(int n_zampe);
	void setPinne(int n_pinne);
	void verso();
};
```
Il codice sopra viola il principio di OCP (e anche di SRP), perche' per ogni tipologia di animale dobbiamo modificare la nostra classe, vediamo una versione che rispetta l'OCP
```cpp
class Animale {
public:
	virtual void verso();
};

class Cane : public Animale {
private: 
	std::string nome;
	int num_zampe;
public:
	void verso() override {}
	void setZampe(int num);
};

class Pesce : public Animale {
private:
	std::string nome;
	int num_pinne;
public:
	void verso() override {};
	void setPinne();
};
```
In questo modo non modifichiamo `Animale` ogni volta che inseriamo un tipo diverso di animale, possiamo creare una classe che implementa quell'interfaccia, senza andarla a modificare.

## DIP
>Il *Dependency Inversion Principle* o **DIP** dice che *i moduli di alto livello non devono dipendere da quelli di basso livello: entrambi devono dipendere da astrazioni*.

Per "*di basso livello*" si intende ad esempio una specifica versione di una libreria, oppure uno specifico dbms.

Il principio effettua una **classificazione di dipendenze** stabilendo quali sono ammesse e quali sono da evitare:
- le dipendenze **buone** sono quelle verso i concetti astratti
- le dipendenze **cattive** sono quelle verso i dettagli implementativi

Facciamo un'osservazione che ci permette di capire meglio:
spesso il software viene progettato secondo un approccio **top-down** cioe' si divide il problema in sottoproblemi, si risolvono tali sottoproblemi e poi si ricombinano le soluzioni nel problema principale. Questo approccio causa una stratificazione del codice in cui i moduli di alto livello *dipendono da quelli di basso livello*; si creano quindi delle dipendenze *cattive*.

Per invertire una dipendenza *cattiva* occorre individuare delle **interfacce astratte** che non dipendono da dettagli implementativi:
- i moduli di *alto* livello vengono modificati per **usare** le interfacce astratte
- i moduli di *basso* livello vengono modificati per **implementare** le interfacce astratte

## LSP
>*Liskov Substitution Principle* o **LSP** e' un principio che prende il nome di Barbara Liskov e che dice che ***S e' un sottotipo di T** se ad ogni modulo che usa un oggetto t di tipo T e' possibile passare invece, un oggetto s di tipo S ottenendo comunque un risultato equivalente (cioe' che soddisfa le legittime aspettative dell'utente)*.

#### Behavioral Subtyping
>L'LSP definisce il cosiddetto **behavioral subtyping**, cioe' dice che *le classi derivate devono soddisfare le legittime aspettative degli utenti che accedono ad esse usando puntatori o riferimenti alle classi astratte*.

La corrispondenza di comportamento deve essere quella stabilita dal **contratto**.

Esempio
```cpp
class Rettangolo {
	long lung;
	long larg;
public:
	bool check_inv() const { return lung > 0 && larg > 0; }

	Rettangolo(long lunghezza, long larghezza) : lung(lunghezza), larg(larghezza) {
		if (!check_inv())
			throw std::invalid_argument("Dimensioni invalide");	
	}

	long get_lunghezza() const { return lung; }
	long get_larghezza() const { return larg; }
	void set_lunghezza(long value) {
		if (value <= 0)
			throw std::invalid_argument("Dimensione invalida");
		lung = value;
	}
	void set_larghezza(long value) {
		if (value <= 0)
			throw std::invalid_argument("Dimensione invalida");
		larg = value;
	}
	long get_area() const { return lungh * larg; }

};
```
Ora vogliamo creare la classe `Quadrato`. Essendo che un quadrato e' un rettangolo con larghezza e lunghezza uguali, vogliamo trasformare la classe `Rettangolo` in una classe dinamica che andra' ereditata da `Quadrato`
```cpp
class Rettangolo {
	// ...
	virtual bool check_inv() const { /* ... */ }
	virtual long get_lunghezza() const { /* ... */ }
	virtual long get_larghezza() const { /* ... */ }
	virtual void set_lunghezza(long value) { /* ... */ }
	virtual void set_larghezza(long value) { /* ... */ }
	virtual long get_area() const { /* ... */ }
	virtual ~Rettangolo() = default;
	// ... 
};


class Quadrato : public Rettangolo {
public:
	Quadrato(long lato) : Rettangolo(lato, lato) {}
	bool check_inv() const override {
		return lung > 0 && lung == larg;
	}
	void set_lunghezza(long value) override {
		Rettangolo::set_lunghezza(value);
		Rettangolo::set_larghezza(value);
	}
	void set_larghezza(long value) override {
		set_lunghezza(value);
	}
};

```
Qui viene violato il principio LSP, cioe' e' **falso** che a qualunque funzione che usa puntatori (o riferimenti) alla classe `Rettangolo` possiamo passare (puntatori o riferimenti) alla classe derivata `Quadrato` e soddisfare le aspettative dell'utente. Pur avendo la stessa interfaccia, le due classi non si *comportano allo stesso modo*, in altre parole la relazione Quadrato IS-A Rettangolo **non e' valida**. Vediamo un esempio
```cpp
void raddoppia_area(Rettangolo& r) {
	long area_prima = r.get_area();
	long i = r.get_lunghezza();
	r.set_lunghezza(2 * i); // raddoppia la lunghezza
	long area_dopo = r.get_area();
	long area_dopo = r.get_area();
	assert(area_dopo == 2 * area_prima);
	// ...
}
```
Se a questa funzione passiamo un riferimento a `Quadrato`, il metodo `set_lunghezza()` raddoppiera' sia la lunghezza che la larghezza e otterremo una violazione dell'asserzione, perche' vale `area_dopo == 4 * area_prima`.

## ISP
>Il *Interface Segregation Principle* dice che *l'utente non dovrebbe essere forzato a dipendere da parti di un'interfaccia che non utilizza*.

Quello che vorremmo e' sostituire le poche **thick interfaces** con tante **thin interface**, in modo tale che, quando c'e' bisogno di modificare una parte di interfaccia, si possa modificare solo quella, evitando di intaccare le altre parti.

Da un punto di vista implementativo, l'applicazione dell'ISP viene dalla possibilita' di utilizzare **ereditarieta' multipla**.

#### Links
[[Classi derivate e relazione IS-A]]
[[Classi Astratte]]


