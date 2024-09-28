>Un **header file** e' un file in cui vengono dichiarate le *signature* delle funzioni (e la relativa documentazione). Sono utili perche' in questo modo, se io ho una funzione scritta in un altro file e viene utilizzata in N **translation unit**, io dovrei andare a scrivere la signature in ognuna di queste, invece metto la signature in un file .h e importo questo in ogni file.

Facciamo un esempio. Mettiamo caso che io abbia 2 file:
- main.cpp
- sum.cpp
cosi' definiti
```cpp
// main.cpp
int main() {
	int x = 5;
	int y = 6;
	sum(x, y);
	return 0;
}
```

```cpp
// sum.cpp
int sum(int a, int b){
	return a + b;
}
```

Se andiamo a compilare `main.cpp` ci troveremo un errore, poiche' abbiamo utilizzato una funzione del quale il compilatore non conosce la definizione. Per risolvere una cosa del genere bisogna dichiarare la funzione in `main.cpp`
```cpp
int sum(int a, int b);

int main() {
	int x = 5;
	int y = 6;
	sum(x, y);
	return 0;
}
```
In questo modo non abbiamo errori quando compiliamo, perche' il compilatore guarda tra i file, trova la definizione di `sum` in `sum.cpp` e la incolla in `main.cpp`.

MA ATTENZIONE: se io decidessi un giorno di aggiungere un altro file chiamato `math.cpp` che definisce la propria funzione `sum`
```cpp
// math.cpp
int sum(int a, int b) {
	int k = a + b;
	return k;
}
```
a questo punto si genera un errore, perche' il compilatore non sa piu' qual e' la definizione corretta da incollare in `main.cpp`.
Altri problemi di questo approccio possono essere:
- se utilizzo la funzione `sum` di `sum.cpp` in 10 file e un giorno voglio cambiare la signature, che so, rendendola costante dovrei andare in ogni file a cambiare la definizione e tuttavia potrei comunque fare errori.
- fare decine di volte questo passaggio significa fare decine di **copia e incolla** del codice, poiche' ogni volta che viene preprocessato, il codice in `sum.cpp` viene preso e incollato nella dichiarazione in `main.cpp`

Da questo si capisce la comodita' di avere un **header file**
```cpp
// sum.hh
int sum(int a, int b);
```

```cpp
// sum.cpp
#include "sum.hh"

int sum(int a, int b) {
	return a + b;
}
```

```cpp
// main.cpp
#include "sum.hh"

int main() {
	...
}
```
in questo modo io devo soltanto includere il file con la signature e il preprocessore fara' tutto il resto, oltre a non essere soggetto a codice ridondante non sono soggetto nemmeno agli altri errori descritti sopra.

#### Links
[[Fasi del processo di compilazione]]