>Quando parliamo di **lifetime** di una determinata entita' ci riferiamo al suo *tempo di vita*, cioe' al tempo che intercorre dal momento che quell'entita' diventa disponibile, fino al tempo in cui la stessa viene distrutta.

Ci sono alcune entita' (*tipi di dato*, *funzioni*, *etichette*) che possono essere riferite in qualunque momento durante l'esecuzione del programma. Nel caso delle funzioni, non essendo considerate *oggetti in memoria* non si tiene conto del loro lifetime.

Il tempo di vita di un oggetto:
1. **Inizia** quando la sua costruzione e' completata, questa si compone di due fasi:
	1. *allocazione* della memoria grezza
	2. *inizializzazione* della memoria (quando prevista)
2. **Termina** quando inizia la sua distruzione, che e' anch'essa composta da due fasi:
	1. *invocazione del distruttore* (quando previsto)
	2. *deallocazione* della memoria grezza

**ATTENZIONE** 
>Un oggetto la cui costruzione *NON* avviene con successo, non avendo iniziato il suo lifetime non dovra' terminarlo.

Ci sono diversi tipi di **storage duration** per gli oggetti in memoria (talvolta tradotto impropriamente come "allocazione")
## Allocazione statica
>Lo spazio di memoria per un'entita' **allocata staticamente** rimane di quell'entita' per tutta l'esecuzione del programma.

### Variabili globali
>Sono variabili *ad allocazione statica* definite nello *scope di namespace*, queste sono create e inizializzate **prima** di iniziare l'esecuzione della funzione *main*, nell'ordine in cui compaiono nella *translation unit*. **ATTENZIONE** nel caso di variabili globali definite in diverse unita' di traduzione, l'ordine di inizializzazione non e' specificato.

```cpp
#include <iostream>

struct S {
	S() { std::cout << "costruzione" << std::endl; }
	~S() { std::cout << "distruzione" << std::endl; }
};

S s; // allocazione globale

int main() {}
```

**IMPORTANTE**
>L'uso di variabili globali non e' molto consigliato perche' porta a codice poco leggibile.

### I membri *static* di una classe

### Variabili *static* locali
>Queste variabili sono locali ad uno scope nel codice e sono allocate prima di iniziare l'esecuzione della funzione *main*, ma sono inizializzate solo la prima volta in cui il controllo di esecuzione incontra la corrispondente definizione.

```cpp
#include <iostream>

struct S {
	int counter;
	S() : counter(0) { }
	~S() { std::cout << "counter = " << counter << std::endl; }
};
void foo() {
	static S s; // allocazione locale statica
	++s.counter;
}

int main() {
	for (int i = 0; i < 10; ++i){
		foo();
	}
}
```

## Allocazione *thread local*
>Un oggetto **thread local** e' simile ad un oggetto globale, ma il suo ciclo di vita non e' collegato al programma, bensi' ad ogni singolo thread di esecuzione creato dal programma (esiste un'istanza distinta della variabile per ogni thread creato). Il supporto per il multithreading e' stato introdotto con lo standard C++ 2011.

## Allocazione automatica
>Una variabile locale ad un blocco di funzione e' dotata di **allocazione automatica**. L'oggetto viene creato dinamicamente (a tempo di esecuzione) sullo stack, ogni volta che il controllo entra nel blocco in cui si trova la dichiarazione e viene **automaticamente distrutto** (rimuovendolo dallo stack) ogni volta che il controllo esce da quel blocco.

```cpp
void foo() {
	int a = 5;
	{
		int b = 7;
		std::cout << a + b;
	} // b viene distrutta automaticamente all'uscita da questo blocco

	std::cout << a;
} // a viene distrutta automaticamente all'uscita da questo blocco
```

 Quello che e' automatico e' **la fine del ciclo di vita**, perche' l'inizio viene deciso dal programmatore. Le variabili allocate in modo automatico vengono distrutte ogni volta che il blocco in cui sono contenute termina. 
 **ATTENZIONE** nel caso di chiamate ricorsive sono presenti sullo stack piu' istanze distinte della stessa variabile.

## Allocazione automatica di temporanei
>L'allocazione automatica di temporanei avviene quando un oggetto viene creato per memorizzare il valore calcolato da una sottoespressione che compare all'interno di un'espressione. Banalmente quando creiamo un oggetto da passare ad una funzione come parametro attuale stiamo creando un temporaneo.

```cpp
struct S {
	S(int);
	S(const S&);
	~S() { std::cout << "distruzione"; }
};

void foo(S s);

void bar() {
	foo(S(42)); // allocazione di un temporaneo per S(42)
	std::cout << "fine";
}
```

>L'oggetto temporaneo viene distrutto quando termina la valutazione dell'espressione completa che contiene lessicalmente il punto di creazione. Nell'esempio precedente, il temporaneo e' distrutto al termine dell'esecuzione di `foo` ma prima della stampa di "fine". Quindi se anche la signature di foo fosse stata `foo(const S& s)`, l'oggetto sarebbe comunque rimasto valido, poiche' sarebbe stato distrutto alla fine di questa.

Il lifetime di un oggetto temporaneo puo' essere esteso se l'oggetto viene utilizzato per l'inizializzazione di un riferimento
```cpp
void bar2() {
	// il temporaneo S(42) e' usato per inizializzare il riferimento s
	const S& s = S(42);
	std::cout << "fine";
	// il temporaneo e' distrutto quando si esce dal blocco
	// dopo avere stampato "fine"
}
```
Nel caso sopra l'oggetto verra' distrutto nel momento in cui verra' distrutto il riferimento.

## Allocazione dinamica
>Un oggetto (senza nome) puo' essere **allocato dinamicamente** nella memoria *heap* usando l'espressione **new** (che restituisce *l'indirizzo dell'oggetto allocato, che va salvato in un opportuno puntatore*).

```cpp
int* pi = new int(42);
// pi contiene l'indirizzo di un oggetto int di valore 42
```

La distruzione dell'oggetto **non avviene in modo automatico** ma viene effettuata *dal programmatore tramite l'istruzione* **delete** (sul puntatore).

**ATTENZIONE**
```cpp
delete pi;
// l'oggetto puntato da pi e' stato distrutto 
// ma pi continua a contenere il suo indirizzo, non piu' valido;
// pi e' diventato un "dangling-pointer"
```

>Un **dangling pointer** e' un puntatore che non punta piu' a nessuna area in memoria. Si genera un dangling pointer quando si fa una delete su un puntatore, cosi' facendo lo spazio di memoria puntato viene deallocato ma il puntatore continua a puntarci.

Per evitare i **dangling pointers** possiamo utilizzare gli [[Smart Pointers]] oppure mettere a `nullptr` il puntatore dopo la delete
```cpp
delete pi;
pi = nullptr;
```
In questo modo possiamo fare un check sul puntatore per vedere se e' nullo o meno.


L'allocazione dinamica e' una sorgente di errori di programmazione:
1. **Use after free** -> e' un errore che deriva dall'utilizzare un *dangling pointer*, in pratica si utilizza un oggetto dopo che il suo lifetime e' terminato
2. **Double free** -> accade quando si usa due volte la delete sullo stesso puntatore, quindi si prova a deallocare una zona di memoria gia' vuota (o utilizzata per altro)
3. **Memory leak** -> si distrugge l'unico puntatore che contiene l'indirizzo dell'oggetto, senza aver deallocato l'oggetto, quindi l'oggetto non potra' essere mai piu' distrutto e quella memoria verra' persa
4. **Wild pointer Access** -> variante della *Use after free* in cui si segue un puntatore che indirizza memoria "casuale", leggendo o scrivendo dove non c'e' un oggetto (o, nel caso in cui quella memoria sia stata riallocata, ci sia un altro oggetto)
5. **Accesso a "null pointer"** -> si prova ad accedere ad un puntatore *nullo*

#### Links
[[Scope]]
[[Dichiarazione e definizione]]
