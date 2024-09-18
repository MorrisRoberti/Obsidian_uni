>Prima dell'esecuzione del main, a runtime vengono istanziati oggetti delle classi che vengono utilizzati nel main, e subito prima della terminazione del programma tali oggetti vengono distrutti. E' possibile che si istanzino e distruggano cosi' tante cose che non rimane quasi piu' nulla per il main.

La signature della funzione main e':
```cpp
int main(int argc, char** argv);
```
dove:
- **argc** -> e' il numero di parametri (comandi ausiliari)
- **argv** -> e' un'array di stringhe di caratteri che rappresentano i parametri stessi

### Librerie e main
**cout** e' una variabile di tipo **ostream** della variabile della standard library che serve ad interfacciarsi con lo standard output.

Quando scriviamo una cosa del tipo:
```cpp
int main() {
	std::cout << "hello, world!" << std::cout;
	// in realta' succede una cosa del genere
	operator<<(std::cout, "hello, world!");
}
```
Quello che succede e' che il compilatore vede il namespace e tipo degli argomenti e verifica che, nelle librerie importate esista *un'overloading* dell'operatore in questione, in questo caso di `<<`
