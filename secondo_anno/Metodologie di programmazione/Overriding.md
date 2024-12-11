>L'**override**, *date una classe base e delle classi concrete che estendono tale classe base*, e' il meccanismo che permette di ridefinire il comportamento di un metodo della classe base, nelle sue classi concrete ([[Metodi virtuali e classi dinamiche#Polimorfismo dinamico|Polimorfismo dinamico]]). E' diverso dall'*hiding* poiche' innanzitutto questo non utilizza il polimorfismo e in secondo luogo perche' il metodo della classe concreta non va a sovrascrivere quello della classe base ma lo *nasconde* quindi non e' piu' possibile accedere al metodo della classe base tramite oggetti di quella classe concreta.
## Overriding di un metodo virtuale
Avendo dichiarato nella classe base il metodo 
```cpp
virtual void print(const Doc&);
```
una classe derivata da `Printer` che lo ridefinisca ne fa **overriding**
```cpp
class NetworkPrinter : public Printer {
public: 
	void print(const Doc& doc) override;
};
```

**ATTENZIONE**
- se il metodo della classe base non fosse dichiarato `virtual` non si avrebbe **overriding** ma **hiding** -> cioe' il nome della classe base verrebbe nascosto
- nella classe base non e' necessario, ma e' consentito ripetere la parola chiave `virtual`
- con C++11 (o superiore) e' consigliato utilizzare anche la parola chiave `override`

La parola chiave `override` **causa un errore** nel caso in cui nella classe base non esista un metodo virtuale corrispondente
```cpp
class Printer {
public:
	void print(const Doc& doc);
}

class NetworkPrinter : public Printer {
public:
	void print(const Doc& doc) override;
}

// ERRORE
// error: 'void NetworkPrinter::print(Doc&)' marked 'override', but does not override
```

## Risoluzione degli override
>Con questo nome si indica il meccanismo attraverso il quale, a fronte di una chiamata di un metodo virtuale dichiarato in una classe base, a tempo di esecuzione viene mandata in esecuzione una specifica implementazione del metodo (tipicamente della classe concreta).

La risoluzione dell'overriding si basa sul **tipo dinamico** dell'oggetto sul quale e' invocato il metodo ed e' effettuata a **tempo di esecuzione** dal **RTS** (*Run Time Support*).

In ogni caso a tempo di compilazione (quindi prima) viene fatta la risoluzione dell'overloading basandosi sul **tipo statico** dell'oggetto.

Affinche' si attivi il meccanismo di overriding devono essere soddisfatte alcune condizioni:
1. il metodo invocato deve essere `virtual`
```cpp
struct B {
	void m() const { std::cout << "B" << std::endl; }
};

struct D : public B{
	virtual void m() const { std::cout << "D" << std::endl; }
};

int main() {
	B* pb = new D;
	pb->m(); // stampa B (non D)
}
```
2. il metodo deve essere invocato tramite **puntatore o riferimento**, altrimenti non vi puo' essere distinzione tra il tipo statico e il tipo dinamico dell'oggetto; quando i due tipi coincidono non ci puo' essere overriding
```cpp
struct B {
	virtual void m() const { std::cout << "B" << std::endl; }
};

struct D : public B {
	void m() const override { std::cout << "D" << std::endl; }
};

void foo(B b) { b.m(); } // passaggio per valore?

int main() {
	D d;
	foo(d); // object slicing: stampa B (non D)
}
```
3. Almeno una delle classi lungo la catena di derivazione che porta dal tipo statico al tipo dinamico deve aver effettuato l'overriding: in assenza di overriding, si invoca il metodo come definito/ereditato dal tipo statico
```cpp
struct B {
	virtual void m() const { std::cout << "B" << std::endl; }
};

struct D : public B {
	// non c'e' overriding, manca il qualificatore 'const'
	virtual void m() { std::cout << "D" << std::endl; }
};

int main() {
	B* pb = new D;
	pb->m(); // stampa B (non D)
}
```
4. Il metodo non deve essere invocato mediante qualificazione esplicita: la qualificazione esplicita causa l'invocazione del metodo come definito nella classe nominata nella qualificazione
```cpp
struct B {
	virtual void m() const { std::cout << "B" << std::endl; }
};

struct D : public B {
	void m() const override { std::cout << "D" << std::endl; }
};

int main() {
	B* pb = new D;
	pb->B::m(); // chiamata qualificata: stampa B (non D)
}
```

#### Links
[[Classi Astratte]]
[[Metodi virtuali e classi dinamiche]]