>Il passaggio degli **argomenti delle funzioni** puo' avvenire in due modi: *per valore* o *per riferimento a lvalue*.

## Passaggio per valore
>Nel passaggio per valore, viene effettuata *una copia* dell'oggetto passato come argomento alla funzione.

```cpp
void foo(int a) {
	std::cout << a << std::endl; // stampa 10
	a++;
}

int main() {
	int a = 10;
	foo(a);
	std::cout << a << std::endl; // stampa 10
}

```
Quindi viene allocato un nuovo spazio in memoria contente il valore 10.

## Passaggio per riferimento a lvalue
>Nel passaggio per riferimento a *lvalue* il parametro della funzione e' un riferimento che viene inizializzato con l'argomento stesso, senza effettuare una copia.

```cpp
void foo(int &a) {
	std::cout << a << std::endl;
	a++;
}

int main() {
	int a = 10;
	foo(a);
	std::cout << a << std::endl; // stampa 11
}

```
Quindi viene passato *effettivamente* quell'oggetto.

## Linee guida 
- Solitamente si passano per valore quegli oggetti che sono **piccoli**, di cui fare una copia non e' costoso
- Si passano per riferimento a lvalue *costante* quegli oggetti **grandi** la cui copia potrebbe essere onerosa
- Gli stessi oggetti grandi si passano per riferimento *modificabile* se appunto devono essere modificati all'interno della funzione
- Per il valore di ritorno, generalmente si opta per il ritorno del valore, perche' non si possono restituire riferimenti a variabili che sono allocate automaticamente dalla funzione
- Un caso nel quale si puo' restituire in modo *safe* il riferimento all'oggetto e' quando siamo sicuri che il suo lifetime non finisca con il corpo della funzione (quindi che sia allocato dinamicamente e non automaticamente)

**NOTE**
>Le cose sopra descritte sono parte dello standard C++2003, a partire dal C++2011 sono stati introdotti i riferimenti a *rvalue* e di conseguenza la possibilita' di passare un argomento per riferimento a rvalue.

>A volte, in maniera impropria si parla di passaggio di un argomento per *puntatore*. Tecnicamente si tratta di un caso specifico del passaggio per valore (il valore del puntatore, ovvero un indirizzo). Questo modo di procedere e' un'eredita' del C ed e' spesso rimpiazzabile dal passaggio per riferimento. Un argomento di tipo puntatore continua ad avere senso quando l'argomento e' opzionale, in questo caso, passando il puntatore nullo si segnala alla funzione che quell'argomento non e' di interesse per una determinata chiamata.

#### Links