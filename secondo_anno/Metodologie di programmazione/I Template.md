>I **template** sono costrutti del linguaggio C++ che consentono di definire uno schema dal quale istanziare oggetti. Esistono 2 tipi di template: *di funzione* e *di classe*.

## Template di funzione
>Un **template di funzione** e' un costrutto del linguaggio che consente di scrivere un *modello* parametrico per una funzione. In buona sostanza ci da la possibilita' di utilizzare un tipo astratto (parametro del template) che potra' essere istanziato $n$ volte con $n$ tipi "concreti" diversi.

```cpp
// dichiarazione pura di template di funzione
template <typename T>
T max(T a, T, b);

// definizione di un template di funzione
template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}
```

### Parametri di template
>Il parametro viene dichiarato essere un `typename` (potrebbe essere sostituito con `class` ma convenzionalmente si usa il primo) quindi un *qualunque tipo di dato*, anche built-in.
>La lista dei parametri ne possiede un numero arbitrario, separati da virgole `template<typename T, typename U>`, talvolta possono essere anche di altri tipi (valori, template).
>Nell'esempio sopra `T` e' un parametro di template.

Una naming convention che si adotta per i parametri e' la seguente:
- T - Type
- E - Element
- K - Key
- V - Value
- N - Number

```cpp
void foo(int a);
void foo(int b); // dichiariamo la stessa funzione foo

template <typename T>
T max(T a, T b);

template <typename U>
U max(U x, U y); // dichiara lo stesso template max
```

### Istanziazione di un template di funzione
>Dato un template di funzione e' possibile *generare* da esso una o piu' funzioni mediante il meccanismo di **istanziazione**. L'istanziazione fornisce un *argomento* ad ognuno dei parametri del template.

L'istanziazione avviene spesso in maniera **implicita**, quando si fa riferimento al nome del template allo scopo di usarne una particolare istanza.

```cpp
void foo(int i1, int i2, double d1, double d2) {
	// istanziazione della funzione
	// int max<int>(int, int);
	int m = max<int>(i1, i2);


	// istanziazione della funzione
	// double max<double>(double, double);
	double d = max<double>(d1, d2);
}
```
Sopra il template `max` viene istanziato *implicitamente* due volte usando le parentesi angolari per fornire **esplicitamente** l'argomento per il parametro del template.

#### Deduzione dei tipi
>Quando si istanzia un template di funzione e' possibile evitare la sintassi esplicita per gli argomenti del template, lasciando al compilatore il compito di **dedurre** tali argomenti a partire dal tipo degli argomenti passati alla chiamata di funzione.

```cpp
void foo(char c1, char c2) {
	// istanziazione della funzione
	// char max<char>(char, char);
	int m = max(c1, c2);

	// il legame T = char viene dedotto dal tipo degli argomenti c1 e c2;
	// si noti che il tipo di m (int) non influisce sul processo di deduzione
}
```

**ATTENZIONE**
>Il processo di deduzione potrebbe fallire  a causa di ambiguita'.

```cpp
voild foo(double d, int i) {
	int m = max(d, i); // errore
	// il compilatore non puo' dedurre un unico tipo T coerente con d e i
	int m = max<int>(d, i); // ok: evito la deduzione
}
```

**NOTA BENE**
E' necessario specificare che:
>*Un template di funzione NON e' una funzione, ma un "generatore" di funzioni; un'istanza di un template di funzione e' una funzione.*

Se compilo un'unita' di traduzione ottenendo un object file posso notare che il suo contenuto e' privo del "template di funzione" ma contiene solo le sue istanze.

### Specializzazione esplicita
>Capita a volte che la definizione templatica di una funzione copra molti casi *ma non tutti*, quindi e' necessario scrivere delle **specializzazioni esplicite** per questi casi limite.

Ad esempio il template `max` visto sopra puo' essere istanziato anche con il tipo `const char*`, e restituira' il massimo dei puntatori passati, quando in realta' quello che l'utente voleva era un confronto lessicografico tra due stringhe C style.

Per risolvere questo problema possiamo fornire una versione specializzata per gli argomenti problematici
```cpp
// definizione del template
template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

// specializzazione esplicita (per T = const char*) del template
template <>
const char* max<const char*>(const char* a, const char* b) {
	return strcmp(a, b) > 0;
}
```

### Istanziazione esplicita
>Esiste la possibilita' di richiedere **esplicitamente** al compilatore l'istanziazione di un template, indipendentemente dal fatto che questo venga utilizzato o meno.

Sono previste due sintassi:
1. Dichiarazione di istanza esplicita
```cpp
extern template
float max(float a, float b);
```
2. Definizione di istanziazione esplicita
```cpp
template
float max(float a, float b);
```

A livello sintattico si noti *l'assenza della lista di parametri* -> questo differenzia le istanziazioni esplicite dalle specializzazioni esplicite

Il caso 1 (dichiarazione) informa il compilatore che, quando verra' usata quell'istanza del template, NON deve essere prodotta la corrispondente definizione dell'istanza (evitando quindi la generazione del codice); intuitivamente la parola `extern` indica che il codice sara' trovato dal linker esternamente a questa unita' di traduzione, cioe' in un object file generato dalla compilazione di un'altra unita' di traduzione.
In pratica la **dichiarazione** di istanziazione esplicita impedisce che vengano effettuate le istanziazioni implicite (per diminuire i tempi di compilazione e generare object file piu' contenuti).

Il caso 2 (definizione) e' complementare al caso 1: si informa il compilatore che quella particolare istanza del template va generata a prescindere dal fatto che in questa unita' di traduzione venga o meno usata. Serve ad assicurarsi che le altre unita' di traduzione (che hanno usato il caso 1) possano essere collegate con successo.

## Template di classe
>Un **template di classe** e' un costrutto del linguaggio che consente di descrivere un *modello* parametrico per una classe.

Quasi tutti i concetti esposti nel caso dei template di funzione funzionano anche qui.

```cpp
// dichiarazione pura di un template di classe
// nota: il nome T del parametro potrebbe essere omesso
template <typename T>
class Stack;

// definizione di un template di classe
template <typename T>
class Stack {
public:
	// ...
	void push(const T& t);
	void pop();
	// ...
};
```

Nel caso dei template di classe e' ancora piu' importante distinguere tra il nome del template (`Stack`) e il nome di una specifica istanza (per esempio, `Stack<std::string>`).
Infatti per i template di classe **NON si applica la deduzione dei parametri del template**.
La lista degli argomenti va indicata *obbligatoriamente*.

```cpp
Stack<int> s1; // istanziazione implicita del tipo Stack<int>
			   // in particolare, del costruttore di default
Stack s2 = s1; // errore: non viene dedotto il tipo T = int
auto s2 = s1;  // ok: il C++11 ha introdotto una deduzione di tipo
			   // dall'inizializzatore, usando auto; viene anche istanziato
			   // implicitamente il costruttore di copia
```

L'unico caso in cui e' lecito usare il nome del template di classe per indicare il nome della classe ottenuta mediante istanziazione e' all'interno dello scope del template di classe stesso.

```cpp
template <typename T>
class Stack {
	// ...
	// qui gli usi di Stack sono abbreviazioni (lecite) di Stack<T>
	Stack& operator=(const Stack&);
	// ...
}; // usciamo dallo scope

// definizione out-of-line
template <typename T>
Stack<T>& // il tipo di ritorno e' fuori scope di classe, devo scrivere <T>
Stack<T>::operator=(const Stack& y) { // il parametro in scope di classe
	Stack tmp = y; // in scope di classe e' sufficiente Stack
	swap(tmp);
	return *this;
}
```

### Istanziazione on demand
>E' necessario specificare che quando si istanzia implicitamente una classe templatica, vengono generate solo le funzionalita' necessarie per il funzionamento del codice che causa l'istanziazione.

Questa scelta del linguaggio ha pro e contro:
- **CONTRO** -> quando scrivo i test per la classe templatica devo prestare attenzione a fornire un insieme di test che copra tutte le funzionalita' di interesse; le funzionalita' NON testate (e quindi non istanziate) potrebbero perfino generare errori di compilazione al momento dell'istanziazione da parte dell'utente
- **PRO** -> per lo stesso motivo, posso usare un sottoinsieme delle funzionalita' della classe istanziandola con argomenti che soddisfano solo i requisiti di quelle funzionalita'; il fatto che quegli argomenti siano "scorretti" per le altre funzionalita' (non usate) non mi impedisce l'utilizzo dell'interfaccia "ristretta".

Esempio:
Supponiamo che la classe `Stack<T>` fornisca un metodo `print()`, implementato invocando il corrispondente metodo `print()` del parametro `T` su ognuno degli oggetti contenuti nello stack.
Questo significa che , per usare il metodo `Stack<T>::print()` il tipo `T` *deve* fornire la sua implementazione di `T::print()`. L'errore si ottiene **solo** se effettivamente si prova ad istanziare `Stack<T>::print()`.

### Istanziazioni e specializzazioni
>Come nel caso dei template di funzione, anche i template di classe possono essere **istanziati** (esplicitamente o implicitamente) e **specializzati**.

Un esempio di specializzazione **totale** di template di classe e' fornito all'interno dell'header file standard `<limits>` che fornisce il template di classe `std::numeric_limits` attraverso il quale si possono per esempio ottenere informazione sui tipi built-in

```cpp
#include <limits>

int foo() {
	long minimo = std::numeric_limits<long>::min();
	long massimo = std::numeric_limits<long>::max();
	bool char_con_segno = std::numeric_limits<char>::is_signed;
}
```

Nell'header file `limits` troviamo, tra le altre cose, le specializzazioni totali che consentono di rispondere alle interrogazioni dell'utente

```cpp
// numeric_limits<char> specialization
template<>
struct numeric_limits<char>

// numeric_limits<long> specialization
template<>
struct numeric_limits<long>
```


### Specializzazioni parziali
>A differenza dei template di funzione, i template di classe supportano anche le *specializzazioni parziali*. Si tratta di specializzazioni di template che sono applicabili a **sottoinsiemi** di tipi. Una specializzazione parziale di un template di classe, quindi, e' ancora un template di classe ma di applicazione meno generale.

## Altri template
>Gli standard piu' recenti hanno introdotto nuove forme di template.

**Template di alias**
```cpp
template <typename T>
using Vec<T> = std::vector<T, std::allocator<T>>;
```

**Template di variabile**
```cpp
template <typename T>
const T pi = T(3.1415926535897932385L);
```


### Differenza tra istanziazione e specializzazione
Molte volte puo' essere difficile capire la differenza tra *istanziazione* e *specializzazione*, quindi ci tengo a specificarla qui sotto:

>L'istanziazione e' il processo in cui il compilatore sostituisce il tipo di dato "concreto" al parametro del template e genera il codice della funzione templatica con tale tipo. Quando chiamiamo una funzione templatica su un tipo si dice che avviene *implicitamente* ma e' possibile anche dire al compilatore "crea il codice per questa funzione con il tipo di dato x perche' sicuramente mi servira' piu' avanti" e questa e' l'istanziazione *esplicita*.

>La specializzazione e' invece il meccanismo con il quale definiamo una versione specifica della funzione templatica per un qualche tipo di dato particolare, quindi non viene creato il codice per quella funzione a prescindere ma semplicemente viene detto al compilatore "questa funzione e' templatica, quindi il codice si comporta allo stesso modo per tutti i tipi T, pero' per il tipo const char* voglio che si comporti in modo diverso".
#### Links
[[Compilazione template]]