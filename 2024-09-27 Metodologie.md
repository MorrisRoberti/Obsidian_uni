## Alias
```cpp
typedef long Integer; // alias tipo stile c++03
using VectInt = std::vector<int>; // alias tipo stile c++11
namespace ppl = Parma_Polyhedra_Library; // alias namespace
```
- un alias e' un altro nome per lo stesso tipo, *non sono un altro tipo*
- Il codice della riga `1` e' comodo per manutenere il codice: se un giorno il tipo di`Integer` dovesse aumentare allora basterebbe mettere `long long` al posto di `long` modificandolo solo nell'alias, propagando la modifica all'intero programma
- la definizione dei `namespace` e' incrementale, nel senso che quando definiamo un namespace possiamo definirne una parte e poi aggiungere codice
```cpp
namespace test {
	/* codice */
}

/*...*/

namespace test {
	/* altro codice */
}
```

## Scope
- Quando viene introdotto un nome nella dichiarazione di un'entita', tale nome e' visibile solo in alcuni punti della translation unit
- si chiama **scope** di una dichiarazione, l'insieme delle porzioni di codice in cui tale nome e' visibile
- Ci sono diversi tipi di scope
### Scope di namespace
- una dichiarazione che non e' racchiusa in una struct/class/enum o funione
- il nome dichiarato nel namespace, e' disponibile a partire dal punto di dichiarazione dell'entita' con quel nome fino alla fine dell'unita' di traduzione
- Questo e' il motivo per cui solitamente l'inclusione degli header file e' all'inizio del file
### Scope di blocco
- un **blocco** e' il codice all'interno del corpo della funzione racchiuso tra graffe
- un nome dichiarato in un blocco e' locale a quel blocco
- la visibilita' inizia al punto di dichiarazione e termina alla fine del blocco
- I costrutti *if*, *while*, *for* e *switch* sono costrutti speciali
### Scope di classe
- i dati membro (attributi) e i metodi (della classe o della struct) sono visibili nella classe (o nella struct) indipendentemente dal punto di dichiarazione
- questo perche' si vuole consentire la definizione "inline" dei metodi
- questo ragionamento non vale per le struct e altri tipi definiti dall'utente
- un metodo nel namespace globale puo' essere dichiarato e definito, mentre nelle classi, puo' essere alternativamente o l'uno o l'altro
- e' possibile utilizzare la sintassi `S::foo()` per fare riferimento alla funzione `foo()` della classe `S`

### Scope di funzione
- riguarda le istruzioni di goto

### Scope di enum
- le costanti di enumerazione stile c++98/c++03 avevano uno scope particolare, cioe' vale fuori dall'enum
```cpp
enum Colors {red, blue, green};
enum Semaforo {red, yellow, green}; 
```
Nel caso sopra si generava un'ambiguita' MA NON un errore, quindi al red di colors veniva assegnato 1 e nel red di semaforo 3.
- enum del c++11 adottano le regole delle classi costringendo il programmatore a qualificare il nome:
```cpp
enum class Colori {rosso, blu, verde};
enum class Semaforo {verde, giallo, rosso};

void foo() {
	std::cout << static_cast<int>(Colori::rosso);
}
```
- sei costretto ad usare il cast, perche', quando nelle versioni precedenti chiamavamo l'elemento di un enum questo veniva castato ad int, da c++11 il casting deve essere esplicito

## Scope potenziale vs Scope effettivo
>Quello introdotto precedentemente e' detto **scope potenziale**, tale scope puo' essere modficato all'interno del programma da altre regole, quello che si genera' e' uno **scope effettivo**.

Queste regole possono essere diverse:
- **hiding di un nome** -> si tratta di ridefinire un un nome in uno scope piu' interno
- **classi derivate e hiding** 
```cpp
struct Base {
	int a; 
	void foo(int);
};

struct Derived : public Base {
	double a; // hiding del data member Base::a
	void foo(double d); // hiding del metodo Base::foo()
};
```
- La cosa corretta da fare e' qualificare le variabili: std::cout, Colori::rosso.
- esistono qualificazioni **parziali** e qualificazioni **totali** -> (DA SPIEGARE)
- **ADL** (*Argument Dependent Lookup*) -> e' una regola di lookup per la risoluzione dell'overloading di funzione
```
Koenig's lookup:
In una chiamata di funzione foo(..., arg, ...), se il nome della funzione (foo) non e' qualificato e se uno degli argomenti (arg) della chiamata e' di un tipo di dato N::U definito dall'utente all'interno del namespace N, allora si considerano come candidate tutte le funzioni con lo stesso nome dichiarate all'interno dello stesso namespace (cioe' N::foo)
```
questo e' quello che e' alla base del discorso dell'operator<< etc.
- **using declaration** -> se un nome deve essere usato spesso conviene usare **using** 
```cpp
void foo() {
	using std::cout;
	using std::endl;

	cout << "hello" << endl;
}
```
se faccio la using declaration di una funzione `foo`, vengono messi dentro tutti gli overloading della funzione `foo` presenti nel namespace al quale appartiene. Un uso pratico della using declaration e' la seguente
```cpp
struct Base {
	void foo(int);
	void foo(float);
};

struct Derived : public Base {

	using Base::foo;

	// foo(double) va a fare overloading dei metodi foo(int) e foo(float) di Base
	void foo(double d);
}
```
- **using directives** -> la direttiva di uso **non** introduce dichiarazioni nel punto in cui viene usata, ma **aggiunge il namespace indicato** tra gli scope nei quali e' possibile cercare un nome per il quale non si trovino dichiarazioni dello scope corrente. Solitamente non e' consigliato usare proprio perche' rompono il meccanismo di namespace.
```cpp
void foo() {
	using namespace std;
	cout << "Hello" << endl;
}
```
la semantica prevede di cercare i nomi delle entita' usate nello scope attuale e, se non vengono trovate le cerca nel namespace dichiarato con la using directive
