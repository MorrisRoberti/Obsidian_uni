>Un **template** in C++ e' un concetto che permette di generalizzare una funzione o una classe a tipi generici, quindi aumenta la leggibilita' del codice, evita ripetizioni inutili e rende i dati nel programma piu' consistenti.

In generale se pensiamo a una classe come *Stack* noi vorremmo, con la stessa classe, rappresentare gli stack di interi, come di stringhe come di un qualsiasi tipo T.
### Come e' fatto (funzioni)
Un template per le funzioni e' dichiarato nel seguente modo:
```cpp
template <class T>
T testFunc(const T& obj) {}
```

- La sintassi ``template <class T>`` (``template <typename T>`` e' equivalente) serve da *wrapper* per la funzione immediatamente sotto
- **T** rappresenta un tipo di dato generico che puo' essere utilizzato nella funzione
- **T** puo' essere usato nei parametri, nella creazione di variabili e oggetti e come tipo di ritorno della funzione stessa 

### Come e' fatto (classi)
Allo stesso modo per le classi:
```cpp
template <typename T>
class C {
private:
	T z;
public:

	C(T z){
		this->z = z;
	}

	int f(T x) {
	...
	}

	T f() {}
};
```

Nella classe e' possibile usare T. Bisogna fare attenzione a quando si usa una classe templatica:
```cpp
int main() {
	int k = 3;
	C obj(k); // non funziona
	C<int> obj(k); // funziona
}
```

### In generale
- E' possibile dichiarare piu' tipi generici diversi facendo:
```cpp
template <typename T, typename U>
void test(const T& objectT, U object U) {}
```
- Bisogna fare molta attenzione a cio' che usiamo nelle classi/funzioni con i template perche' alcune cose potrebbero non essere implementate per tutti i tipi e questo potrebbe causare problemi es
```cpp
template <typename T>
class C {
private:
	T z;
public:

	C(T& z, T& k){
		this->z = z + k; 
	}

	int f(T x) {
	...
	}

	T f() {}
};

int main() {
	Razionale r();
	Razionale r2(1, 2);
	C<Razionale> c = new C<Razionale>(r, r2);
}
```
Nel caso sopra se l'assegnamento e la somma non sono definiti per la classe ``Razionale`` il codice non compila

#### Links