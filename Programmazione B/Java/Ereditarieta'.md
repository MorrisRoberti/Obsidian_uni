>In quanto insieme, una classe C puo' essere sottoinsieme di una classe piu' ampia, cio' significa che un oggetto della classe C apparterra' anche alla classe D. Il principio di **ereditarieta'** si basa su questo: e' possibile costruire delle classi a partire da classi gia' esistenti.

### Classi, sottoclassi e superclassi
![[Pasted image 20240426132559.png]]
`Studente` e `Docente` sono *sottoclassi* di `Persona`, quindi hanno tutte le sue caratteristiche (campi e metodi).

Una classe ereditata da un'altra si dice **sottoclasse** di questa, che a sua volta' si chiamera' **superclasse**.

### Ereditarieta' in C++
```cpp
class B {
	...
};

class C : public B {
	...
};
```
la visibilita' della derivazione e' public quindi gli attributi ereditati mantengono le stesse visibilita' della superclasse

### Principio di sostituibilita'
>Il **principio di sostituibilita'** stabilisce che e' possibile utilizzare un oggetto della sottoclasse dove e' previsto un oggetto della superclasse.

```cpp
void f(B x) {
	...
}

int main() {
	B b;
	C c;
	f(b);
	f(c);
}
```
**ATTENZIONE**
Non vale il viceversa, poiche' la sottoclasse potrebbe avere dei campi o metodi aggiuntivi non presenti nella superclasse.

### Ereditarieta' *vs* Contenimento
```cpp
class DataConOrario {
private:
	Data d;
	int sec;
public:
	DataConOrario(int g, int m, int a) {
		d = Date(g, m, a);
		sec = 0;
	}
}
```
La classe `DataConOrario` *non eredita* `Data` ma la **contiene**.

### Ereditarieta' multipla
>E' possiblie fare in modo che una classe erediti da piu' superclassi, questo principio si chiama **ereditarieta' multipla**.

#### Links
