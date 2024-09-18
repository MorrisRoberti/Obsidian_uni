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

### Domande e questioni interessanti
Si vogliono porre alcune domande che denotano il *grado di conoscenza* del linguaggio e fornire delle risposte secche

1. Perche' la funzione `main` e' dichiarata per restituire un valore intero?
	`Perche' effettivamente restituisce un valore intero, che indica se l'esecuzione e' terminata correttamente o meno, infatti, molte volte alla fine del programma viene omesso il return 0; che indica appunto che tutto e' andato a buon fine. Il fatto che il main sia dichiarato come int e' dovuto al fatto che in c++ si utilizzano per convenzione gli interi per notificare la presenza di errori`
2. Perche' non esiste la corrispondente istruzione di `return`?
	`Come gia' detto, in realta' esiste ma e' implicita`
3. Perche' devo qualificare il nome del canale di stream `cout` con `std`?
	`Perche' e' necessario dire al compilatore il namespace di quella parte di codice, in modo che a tempo di compilazione sappia dove e' definita. Come detto sopra cout e' una variabile definita nel namespace std`
4. Che cos'e' `std`?
	`Come gia' detto e' un namespace, cioe' uno spazio di nomi che serve a raccogliere tutte le classi, variabili, costanti, funzioni sotto un unico spazio di nomi, che ne indica (sommariamente) il funzionamento (o comunque il campo di applicazione)`