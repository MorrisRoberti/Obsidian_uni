>Lo scope introdotto in [[Scope]] e' in realta' cio' che si definisce **scope potenziale** nel senso che e' lo scope che *teoricamente* dovrebbero avere le varie entita' in base alle caratteristiche stabilite, tuttavia in un programma sopraggiungono eventi e situazioni che possono cambiarne lo scope, quello che si genera da tali cambiamenti viene detto **scope effettivo**.

Ci sono alcune modifiche dello scope potenziale, che portano allo scope effettivo che si vedranno e sono:
- **Name hiding**
- Uso di nomi qualificati
- **ADL** (*Argument Dependent Lookup*)
- Dichiarazioni e direttive *using*

### Name hiding
>Quando scope diversi vengono *annidati* una dichiarazione dello scope interno puo' nasconderne una con lo stesso nome, dello scope esterno.

```cpp
int a = 1;

int main() {
	std::cout << a << std::endl // stampa 1
	int a = 5; // la 'a' globale viene nascosta
	std::cout << a << std::endl; // stampa 5

	{
		int a = 10; // la 'a' esterna viene nascosta
		std::cout << a << std::endl; // stampa 10
	}

	std::cout << a << std::endl; // stampa 5
}
```

Si puo' avere l'hiding anche per membri ereditati da una classe, perche' **lo scope della classe derivata e' considerato essere incluso nello scope della classe base**.
```cpp
struct Base {
	int a;
	void foo(int);
};

struct Derived : public Base {
	double a; // hiding del data member Base::a 
	void foo(double d); // hiding del metodo Base::foo()
}
```


### Uso di nomi qualificati
>L'accesso ad alcune entita' al fi fuori del loro scope si puo' ottenere usando nomi qualificati: `std::cout`, `Colors::red`.

La qualificazione puo' essere:
- **parziale** -> punto di partenza lo scope corrente
- **totale** -> punto di partenza lo scope globale, in questo caso si parla di **FQN** (*Fully Qualified Name*)

```cpp
struct Base {
	int a;
	int foo(int);
};

struct Derived : public Base {
	double a;
	double foo(double d) {
		return a + Base::a * Base::foo(42);
	}
}
```

### ADL: Argument Dependent Lookup
>E' una regola di lookup rilevante per la risoluzione dell'overloading di funzione, ed e' detto anche **Koenig's lookup**.

```
"In una chiamata di funzione foo(..., arg, ...), se il nome della funzione (foo) non e' qualificato e se uno degli argomenti (arg) della chiamata e' di un tipo di dato N::U definito dall'utente all'interno del namespace N, allora si considerano come candidate tutte le funzioni con lo stesso nome dichiarate all'interno dello stesso namespace (cioe' N::foo)"
```
Questo e' quello che e' alla base del discorso dell'operator<< etc.
### Using declaration
>Se un nome deve essere utilizzato spesso in una posizione in cui non e' visibile senza qualificazione, puo' essere scomodo doverlo qualificare ogni volta, per questo ci vengono in aiuto le **using declaration**.

```cpp
#include <iostream>
void foo() {
	using std::cout;
	using std::endl;
	cout << "Hello" << endl;
	cout << "hello again" << endl;
}
```

Una **using declaration** rende disponibile un nome che era stato precedentemente reso visibile nel namespace indicato -> nel caso precedente e' comunque necessario includere l'header file altrimenti si ottiene un errore.

**ATTENZIONE** 
>Nel caso di una using declaration per un nome di tipo o una variabile e' necessario che nello stesso scope **non** sia gia' presente un'altra entita' con lo stesso nome, tuttavia questa cosa e' legittima nel caso delle funzioni perche' entra in gioco l'overloading.

```cpp
void foo() {
	int cout = 5;
	using std::cout; // conflitto di nomi
}

struct Base {
	void pippo(int);
	void pippo(float);
};

struct Derived : public Base {
	using Base::foo;

	void foo(double d); // questa foo va in overloading con foo(int) e foo(float)
}
```


### Using directive
>Diverse dalle dichiarazioni d'uso sono le **direttive d'uso**. Una direttiva d'uso non introduce dichiarazioni nel punto in cui viene usata ma *aggiunge il namespace indicato* tra gli scope nei quali e' possibile cercare un nome per il quale **non** si trovino dichiarazioni nello scope corrente.

```cpp
#include <iostream>

void foo() {
	int endl = 42;
	using namespace std;
	cout << "Hello" << endl;
}
```
Il compilatore cerca `cout` nello scope corrente (blocco della funzione), non trovandolo continua la ricerca anche negli scope in cui e' contenuta la funzione`foo` e grazie alla *using directive* anche nel namespace `std`. Per quanto riguarda `endl` la direttiva non entra in uso perche' trova il nome definito nello scope corrente.

**USO DELLE USING DIRECTIVES/DECLARATIONS**
- Rompono il meccanismo fornito dai namespace
- Preferire le *using declarations* alle *using directives* in quanto introducono meno nomi
- In tutti i casi **limitare** l'utilizzo di using declarations e using directives
- **NON** usarle nello scope di namespace/globale, in particolare negli header file

#### Links
[[Scope]]

