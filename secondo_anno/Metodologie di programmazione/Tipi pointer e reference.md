>Informalmente la differenza tra un puntatore e un riferimento e' la seguente:
>Un **puntatore** e' un oggetto il cui valore (un indirizzo) si puo' *riferire* ad un altro oggetto (necessariamente diverso)
>Un **riferimento** non e' un oggetto vero e proprio, ma e' una sorta di "nome alternativo" fornito per accedere ad un oggetto esistente.

Facciamo alcune osservazioni
- Quando viene creata una reference questa deve sempre essere inizializzata, in quanto si deve sempre *riferire ad un oggetto esistente*, in altre parole non puo' esistere il *riferimento nullo*. In contrasto un puntatore puo' essere inizializzato con il letterale `nullptr`.
- Una volta creata la reference, questa fara' sempre riferimento allo stesso oggetto; non c'e' modo di "riassegnare" una reference ad un oggetto diverso, invece un puntatore (che non sia qualificato `const`) puo' essere sempre modificato per puntare a qualcosa di diverso.
- Ogni volta che si effettua un'operazione sulla reference in realta' si sta operando sull'oggetto riferito. Nel caso dei puntatori abbiamo a che fare con due oggetti diversi: il puntatore e l'oggetto puntato. Possiamo lavorare sul puntatore o sull'oggetto puntato cambiando la sintassi:
	- `p // puntatore`
	- `*p // valore puntato (puntatore dereferenziato)`
- Un eventuale qualificatore `const` aggiunto al riferimento si applica necessariamente all'oggetto riferito e non al riferimento stesso. In contrasto nel caso del puntatore, avendo due oggetti e' possibile qualificare o meno i diversi oggetti (puntatore o oggetto puntato).
```cpp
int i = 5; // oggetto modificabile
const int ci = 5; // oggetto NON modificabile

int& r_i = i; // ok: posso modificare i usando r_i
const int& cr_i = i; // ok: inizializzo cr_i con i, dicendo che non lo modifichero'
int& r_ci = ci; // errore: non posso usare un riferimento non-const per accedere ad un oggetto const, perche' potrei modificare r_ci e quindi ci andando ad eludere la qualificazione di quest'ultimo

const int& cr_ci = c; // ok

int& const cr = i; // errore: const puo' stare solo a sx di &

int* p_i; // *p_i e p_i sono entrambi modificabili
const int* p_ci; // p_ci e' modificabile mentre *p_ci non lo e'
int* const cp_i = &i; // cp_i non e' modificabile, *cp_i e' modificabile
const int* const cp_ci = &i; // entrambi non modificabili

p_i = &i; // ok
p_i = &ci; // errore: non posso inizializzare un puntatore non-const usando un indirizzo di un oggetto const

p_ci = &i; //ok
p_ci = &ci; // ok

cp_i = nullptr; // errore: cp_i e' non modificabile
cp_ci = &ci; // errore: cp_ci e' non modificabile

```

## Somiglianze
>Quando termina il lifetime di un puntatore, viene distrutto l'oggetto puntatore **ma non l'oggetto puntato**, analogamente quando un riferimento va fuori scope l'oggetto riferito non viene distrutto.

Chiaramente se il riferimento e' inizializzato con un oggetto temporaneo, questo verra' distrutto nel momento in cui il lifetime del riferimento termina, come nell'esempio sotto
```cpp
void foo(int& x) {
	x++;
} // il lifetime dell'oggetto temporaneo x finisce

int main() {
	int i = 5;
	foo(i);
	std::cout << i << std::endl; // stampa 6
}
```

>Analogamente al *dangling pointer* e' possibile creare un **dangling reference**, ovvero una reference che fa riferimento ad un oggetto non piu' esistente
```cpp
struct S {/*...*/}

S& foo() {
	S s;
	// ...
	return s;
}
```

Si tratta di un **grave errore di programmazione** in quanto la funzione ritorna per riferimento un oggetto che e' stato allocato automaticamente e che quindi verra' automaticamente distrutto appena la funzione termina. Quindi l'approccio corretto e' modificare l'interfaccia della funzione affinche' ritorni per valore invece che per riferimento, oppure, si puo' restituire il puntatore all'oggetto dinamico come segue

```cpp
struct S {/*...*/}

S* foo() {
	S* s = new S();
	// ...
	return s;
}
```

**ATTENZIONE**
>Il puntatore al quale verra' poi assegnato cio' che la funzione restituisce si dovra' occupare della deallocazione, altrimenti si otterra' un *memory leak*.

```cpp
int main(){
	S* s_ptr = foo();
	// ...
	delete s_ptr;
}
```
#### Links
[[Scope]]
[[Tipi, qualificatori, costanti letterali]]
[[Lifetime di oggetti]]