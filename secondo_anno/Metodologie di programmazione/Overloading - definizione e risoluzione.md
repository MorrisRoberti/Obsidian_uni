>Il C++ supporta il meccanismo di **overloading** per i nomi di funzione: e' possibile dichiarare lo stesso nome di funzione piu' volte a patto che queste si differenzino per *numero e tipo dei parametri*.

>La **risoluzione dell'overloading** e' un processo che avviene *staticamente* durante il processo di *compilazione in senso stretto (cioe' quando l'unita' di traduzione viene trasformata in codice assembly)*. Questo anche perche', come sappiamo, in assembly *NON esiste overloading*.

#### Differenza con il C
Nel C non e' possibile fare overloading, quindi ad esempio, nella libreria matematica del C abbiamo
```c
float sqrtf(float arg);
double sqrtd(double arg);
long double sqrtl(long double arg);
```
che in sostanza fanno la stessa cosa, questo genera una ripetizione inutile di codice.
In contrasto, nella libreria *cmath* del C++ si trovano le tre funzioni
```cpp
float sqrt(float arg);
double sqrt(double arg);
long double sqrt(long double arg);
```

**NOTA**
>Si noti comunque che nel C esiste una sorta di overloading che pero' si restringe al caso degli operatori definiti su tipi built-in. Ad esempio nell'espressione `v + 1` l'operatore `+` corrisponde alla somma di interi se `v` e' intero, alla somma di double se `v` e' double etc.

## Le 3 fasi della risoluzione dell'overloading
>Il processo di *risoluzione dell'overloading* avviene in 3 fasi: *individuazione delle funzioni candidate, selezione delle funzioni utilizzabili* e *scelta della migliore funzione utilizzabile (se esiste)*.

### Fase 1 - individuazione delle funzioni candidate
>L'insieme delle funzioni candidate per una determinata chiamata di funzione e' un sottoinsieme delle funzioni dichiarate all'interno dell'unita' di traduzione che rispettano le seguenti caratteristiche:
- Hanno *lo stesso nome* della funzione chiamata
- Sono *visibili nel punto della chiamata*

**NOTA**
>Bisogna tenere presente nel primo punto che per gli operatori non conta il tipo di sintassi in quanto il compilatore andra' a prendere sempre la dichiarazione corrispondente

Es
```cpp
++a -> operator++
ai[5] -> operator[]
a - b -> operator-
```

Piu' interessante e' il secondo punto, nel quale occorre prestare attenzione ai seguenti casi
- Nel caso di invocazione di un metodo di classe mediante la sintassi `obj.metodo` (oppure `ptr->metodo`) se l'oggetto `obj` ha come tipo statico `S`, la ricerca iniziera' nello scope di classe `S`; si noti che viene considerato il tipo **statico** (cioe' quello noto a tempo di compilazione):
```cpp
struct S { /* ... */};
struct T : public S { /* ... */};
S* ptr = new T();
ptr->foo(); // chiamata
// ptr ha tipo statico S* e tipo dinamico T*
// quindi la ricerca di foo avviene a partire dallo scope di S
// (eventuali funzioni T::foo non sono visibili nel punto della chiamata)
```

- Nel caso di qualificazione della funzione chiamata, la ricerca delle funzioni candidate avverra' nello scope che ha qualificato la chiamata:
```cpp
namespace N { void foo(int); }
void foo(char); // dichiarazione NON visibile per la chiamata
int main() {
	N::foo('c'); // la ricerca inizia nello scope di namespace N
}
```

- Attenzione a non confondere l'overloading con **l'hiding**:
```cpp
struct S { void foo(int); };
struct T : public S { void foo(char); };
T t; // tipo statico e dinamico (T)
t.foo(5);
// la ricerca inizia nello scope di T; la funzione S::foo 
// non va in overloading perche' viene nascosta (hiding)
```

- Attenzione ad eventuali [[Scope potenziale e Scope effettivo#Using directive|Using directive]] o [[Scope potenziale e Scope effettivo#Using declaration|Using declaration]] che modificano la visibilita' delle dichiarazioni:
```cpp
// nell'esempio precedente, se nella classe T si fosse aggiunto 
using S::foo;
// allora S::foo e T::foo sarebbero entrabe visibili e andrebbero in overloading e non ci sarebbe hiding
```

- Attenzione all'[[Scope potenziale e Scope effettivo#ADL Argument Dependent Lookup|ADL]]. Richiamando la regola, questa stabilisce che: *nel caso di una chiamata di funzione NON qualificata, se vi sono (uno o piu') argomenti "arg" aventi un **tipo definito dall'utente** (cioe' struct/class/enum) e il suddetto tipo e' definito in un namespace N, allora la ricerca delle funzioni candidate viene effettuata ANCHE all'interno del namespace N*.
```cpp
namespace N { 

struct S { };

void foo(S s);

void bar(int n);

} // namespace N

int main() {
	N::S s;
	foo(s); // OK: ADL sul namespace del tipo di s
	int i = 0;
	bar(i); // ERRORE: non avviene ADL
}
```
Per la chiamata 1 si applica la regola *ADL* perche' il nome `foo` non e' qualificato e l'argomento `s` ha tipo struct `S` definito dall'utente all'interno di un namespace `N`. Quindi il namespace `N` viene "aperto" rendendo visibile la dichiarazione di `N::foo(S)` nel punto della chiamata (e quindi rendendola candidata).

In contrasto nella chiamata 2 NON si applica la regola ADL.

**ATTENZIONE**
>E' necessario che l'argomento qualificato faccia riferimento ad un **tipo definito dall'utente all'interno di quel namespace** e non semplicemente ad una funzione/variabile.

```cpp
namespace N {
	int a;
	void foo(int); 
}

void foo(float);

int main() {
	foo(N::a); // NON SI APPLICA L'ADL, PERCHE' 'A' NON E' DI UN TIPO DEFINITO DALL'UTENTE
}
```

### Fase 2 - Selezionare delle funzioni utilizzabili tra le candidate
>Effettuata la scelta delle funzioni candidate, occorre verificare quali di queste funzioni potrebbero essere effettivamente **utilizzabili** per risolvere la specifica chiamata considerata.

Per decidere se una funzione candidata e' utilizzabile, e' necessario verificare che:
1. Il numero degli parametri attuali sia compatibile con il numero dei parametri formali
2. Ogni parametro attuale abbia un tipo compatibile con il corrispondente parametro formale

Fare attenzione ad eventuali valori di default per i parametri e all'argomento implicito *this* nelle chiamate di metodi non statici

### Fase 3 - selezione della migliore utilizzabile (se presente)
#### Classificazione delle conversioni implicite
>Al momento della chiamata di funzione e' necessario fare attenzione alle conversioni implicite che potrebbero verificarsi.

Classifichiamo tali conversioni:
1. Corrispondenze esatte o *matching perfetto* (identita', trasformazioni di lvalue, qualificazioni)
2. Promozioni
3. Conversioni standard
4. Conversioni definite dall'utente

#### Sequenze di conversioni
>Quando si verifica se una funzione e' utilizzabile, per ogni argomento della chiamata e' possibile effettuare una **sequenza di conversioni**.

Una sequenza di conversione **standard** e' del tipo
*trasformazione di lvalue* + *promozione o conversione standard* + *qualificazione*
Le varie componenti sono *opzionali*, ma se presenti devono essere nell'ordine specificato.

Esempio
Supponendo che la classe `D` sia derivata dalla classe base `B`
```cpp
double d = 3.1415; // un lvalue di tipo double
void foo(int); // funzione che accetta un intero per valore

foo(d); // chiamata
// la funzione foo(int), se candidata, e' anche utilizzabile;
// si applica prima una trasformazione di lvalue ( nello specifico una
// trasformazione da lvalue a rvalue, che corrisponde alla lettura del valore contenuto nella locazione d)
// e quindi una conversione standard da double a int
```

Una sequenza di conversione **utente** e' composta da
*sequenza di conversione standard* + *conversione utente* + *sequenza di conversione standard*

Sia $N$ il numero di funzioni utilizzabili:
- se $N = 0$ -> ho un errore di compilazione
- se $N = 1$ -> l'unica utilizzabile e' la migliore
- se $N \gt 1$ -> occorre classificare le funzioni utilizzabili in base alla "qualita'" delle conversioni richieste; se la classificazione determina una vincitrice , quella funzione e' la migliore utilizzabile, altrimenti si ottiene un errore di compilazione

>Per ognuno degli $M$ argomenti presenti nella chiamata, si crea una *classifica* delle funzioni utilizzabili. Per decidere se una funzione $X$ e' migliore di $Y$, si confrontano $X$ e $Y$ su tutte le $M$ classifiche corrispondenti agli $M$ argomenti

$X$ e' preferibile a $Y$ se
- Non perde in nessuno degli $M$ confronti (quindi vince o pareggia)
- Vince almeno uno degli $M$ confronti

>Fissato un argomento $A_i$, la funzione $X$ vince rispetto a $Y$ se la sequenza di conversioni $X_i$ usata da $X$ per $A_i$ vince rispetto alla sequenza $Y_i$ usata da $Y$.

Le regole del linguaggio per stabilire se una sequenza vince su un'altra sono intricate, noi qui useremo una versione semplificata:
>Una sequenza $X_i$ vince sulla sequenza $Y_i$ se la *peggiore conversione* $X_{worst}$ usata in $X_i$ vince sulla peggiore conversione $Y_{worst}$ usata in $Y_i$.
>Una conversione $X_{worst}$ vince sulla conversione $Y_{worst}$ se ha un **rank** migliore (il rank e' quello nella [[Overloading - definizione e risoluzione#Classificazione delle conversioni implicite|classifica delle conversioni]], quelli con rank piu' basso sono migliori di quelli con rank piu' alto)

## Ulteriori osservazioni
1. Le regole qui esposte non tengono in considerazione alcuni casi speciali riguardanti funzioni candidate ottenute istanziando template di funzione
2. Si sottolinea che quando si scelgono le **funzioni candidate** NON sono considerati in alcun modo parametri e tipi 
3. E' opportuno evidenziare che nel caso di invocazione del metodo di una classe il fatto che tale metodo sia *public, protected o private* NON ha nessun impatto nella risoluzione dell'overloading. Semplicemente il processo determina in generale la funzione *migliore* tra quelle utilizzabili, in seguito se questa non e' accessibile al chiamante verra' dato un errore di compilazione che pero' non ha nulla a che fare con la risoluzione dell'overloading (in particolare la migliore funzione utilizzabile ma non accessibile NON viene mai sostituita da un'altra funzione utilizzabile e accessibile)

#### Links 
[[Scope potenziale e Scope effettivo]]