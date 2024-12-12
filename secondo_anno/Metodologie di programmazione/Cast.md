>Il processo di **cast** (o meglio di *type casting*) si riferisce alla conversione di un'entita' da un tipo ad un altro. Possiamo avere il casting **implicito** cioe' quello che il compilatore compie da se, perche' ritenuto safe, e il casting **esplicito** cioe' quello che il compilatore ritiene possa generare problemi e che quindi lascia nelle mani del programmatore.
>Parleremo qui di *casting esplicito*.

Abbiamo 4 tipi di *casting esplicito*:
- `static_cast`
- `dynamic_cast`
- `reinterpret_cast`
- `const_cast`

## static_cast
>Lo `static_cast` e' un tipo di casting esplicito che data l'espressione `static_cast<T>(expr)` permette la conversione del valore dal tipo di `expr` al tipo `T`.

Il cast e' legittimo in questi casi:
- e' legittima la corrispondente conversione implicita 
```cpp
double p = 3.14;
int approx = static_cast<int>(d);

// equivalente di 
int approx = d;
```
Banalmente e' una *versione esplicita* di quello che implicitamente fa il compilatore

- e' legittima la costruzione diretta di un oggetto di tipo `T` passando `expr` come argomento
```cpp
Razionale r = static_cast<Razionale>(5);
```
**ATTENZIONE**
>Se non e' definito un costruttore che accetta il tipo di dato passato, non e' possibile effettuare il cast. Il casting avviene con successo anche se c'e' un costruttore per un tipo di dato "minore" e noi passiamo un tipo di dato per il quale il compilatore riesce ad effettuare un casting esplicito.
```cpp
class Integer {
private:
	int number;
public: 
	Integer() : number(0) {}
	// se io aggiungessi una delle due sotto, funzionerebbe
	// Integer(double k) : number(k) {}
	// Integer(int k) : number(k) {} -> qui viene effettuato un downcasting implicito
};

int main() {
	Integer d = static_cast<Integer>(10.5); // errore perche' non c'e' un costruttore che accetta un double
}

```


- si effettua la conversione inversa rispetto ad una sequenza di conversione ammissibile (con alcune restrizioni, ad esempio non si possono invertire le trasformazioni di lvalue)
```cpp
int i = 42;
void* v_ptr = &i;
int* i_ptr = static_cast<int*>(v_ptr);
```
- *downcast* di una gerarchia di classi
- cast da tipo numerico a tipo enum
- il tipo destinazione e' void

## dynamic_cast
>Il `dynamic_cast` e' uno degli operatori che forniscono il supporto per la cosiddetta **RTTI** (*Run-Time Type Identification*). I `dynamic_cast` possono essere usati per effettuare conversioni all'interno di una gerarchia di classi legate da ereditarieta'.

- **up-cast** -> conversione da classe derivata a classe base: usata raramente in quanto avviene anche implicitamente
- **down-cast** -> conversione da classe base a classe derivata: e' il caso piu' frequente del *cast dinamico* in quanto sfrutta la RTTI per verificare che la conversione sia legittima
- **mixed-cast** -> caso particolare che si verifica quando si utilizza l'ereditarieta' multipla: combina *up-cast* e *down-cast*; anche in questo caso si ha un uso non banale della RTTI
Il `dynamic_cast` si puo' applicare anche ai tipi *puntatore* (caso tipico) o ai *riferimento* (piu' raro).

Supponiamo di avere le seguenti classi
```cpp
class B { /* ... */ };
class D1 : public B { /* ... */ };
class D2 : public B { /* ... */ };
```
se la classe `B` e' **dinamica**, allora e' dotata delle informazioni per la RTTI e possiamo applicare cast dinamici ai puntatori per sapere se sono di un determinato tipo
```cpp
D1* d1_ptr = dynamic_cast<D1*>(b_ptr);
```
- se `b_ptr` punta ad un oggetto di tipo `D1` allora `d1_ptr` avra' assegnato un valore NON nullo
- se `b_ptr` non punta ad un oggetto di tipo `D1` allora a `d1_ptr` verra' assegnato il puntatore nullo

**NOTA**
>Nel cast dinamico, il programmatore deve *controllare manualmente se il cast ha avuto successo*.
```cpp
if (d1_ptr != nullptr) {
	// d1_ptr e' valido
}

// oppure implicito sfruttando la conversione da T* a bool
if (d1_ptr) {
	// d1_ptr e' valido
}

// o anche compattando cast e test
if (auto d1_ptr = dynamic_cast<D1*>(b_ptr)){
	// d1_ptr e' valido
}

```
il *cast dinamico* su **tipi reference** e' diverso (e si usa raramente), poiche' non esiste il concetto di "riferimento nullo" quindi non possiamo usare facilmente cast dinamici su riferimenti per fare i controlli RTTI
```cpp
D1& d1_ref = dynamic_cast<D1&>(*b_ptr);
```
effettua la conversione se `b_ptr` punta ad un `D1`, se invece NON punta ad un oggetto di tipo `D1` il cast dinamico *fallisce* e, non potendo segnalare la cosa con il riferimento nullo, genera una eccezione (di tipo `std::bad_cast`)

## const_cast
>Il `const_cast` viene utilizzato per rimuovere la qualificazione `const`. In pratica la applichiamo ad un riferimento o puntatore ad un oggetto qualificato `const` per ottenere un riferimento o un puntatore ad un oggetto non qualificato e quindi *modificabile*.

```cpp
void promessa_non_mantenuta(const int& ci) {
	int& i = const_cast<int&>(ci);
	++i;
}
```
il parametro `ci` della funzione e' qualificato `const` quindi dovrebbe essere *non modificabile* tuttavia noi andiamo ad effettuare un `const_cast` rendendolo modificabile. Solitamente non si utilizza, poiche' va a rompere il contratto stipulato tra sviluppatore e programmatore, tuttavia ci sono alcuni casi in cui e' legittimo utilizzarlo, tra questi:
*Quando vogliamo modificare la **rappresentazione interna di un oggetto** senza pero' alterarne il significato, quindi vogliamo mantenere la **const-ness** dell'oggetto a livello logico, ma vogliamo modificarne il nome*.

## reinterpret_cast
>I `reinterpret_cast` sono tra le forme di conversione *piu' pericolose*, in quanto i controlli di correttezza sono lasciati quasi totalmente al programmatore, di conseguenza, se possibile, si cerca di evitarli.

I `reinterpret_cast` possono effettuare queste conversioni:
- da un tipo puntatore ad un tipo intero (sufficientemente grande)
- da un tipo intero/enumerazione ad un tipo puntatore
- da un tipo puntatore (oppure riferimento) ad un altro tipo puntatore (oppure riferimento)
**NOTA**
>Nel caso del `reinterpret_cast`, le conversioni tra puntatori sono consentite anche quando i due tipi puntato NON sono in alcuna relazione tra loro, ad esempio non fanno parte di una gerarchia di classi derivate. **NON** e' possibile usare questo tipo di cast per rimuovere la qualificazione `const`.

## Altri cast
### Cast funzionale
>La sintassi `T(expr)` oppure `T()` dove `T` e' il nome di un tipo, viene spesso indicata come **cast funzionale**, intuitivamente corrisponde alla costruzione diretta di un oggetto di tipo `T`, usando un costruttore. Si parla di *cast funzionale* in quanto la sintassi si puo' applicare anche al caso dei tipi builtin (che in senso tecnico non sono dotati di costruttori): per i tipi builtin, la forma `T()` produce la cosiddetta **zero-initialization**.

Esempio
```cpp
template<typename T, typename U>
void foo(T t, U u) {
	if (t == T(u)) // cast funzionale
		// ...
}
```
nell'istanza `void foo<double, int>(T t, U u)` otteniamo
```cpp
if (t == double(u))
```
nell'istanza `void foo<Razionale, int>(T t, U u)` otteniamo
```cpp
if (t == Razionale(u)) // cast funzionale dove Razionale(u) invoca il costruttore esplicito della classe
```

### C-style cast
>Banalmente e' il cast che si usa in C. Il loro uso e' considerato cattivo stile (tranne nel caso idiomatico di cast a `void` , usato per disattivare eventuali warning del compilatore). Con i cast C-style si possono implementare `static_cast`, `const_cast` e `reinterpret_cast` ma **NON si possono implementare** i `dynamic_cast` (non hanno accesso a informazioni RTTI e quindi non effettuano nessun controllo a runtime).

#### Links
