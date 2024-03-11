>Il *costruttore* di una classe e' il metodo che viene invocato automaticamente alla creazione di un oggetto di tale classe.

### Perche' serve
Quando creiamo un oggetto in C++, i suoi campi vengono inizializzati automaticamente con dei valori casuali
```cpp
class Razionale {
private: 
	int num;
	int den;
}

int main() {
  Razionale r1;
}
```
quindi i valori di r1.num e r1.den sono dei valori casuali.

Definendo un costruttore possiamo validare i valori che vengono dati ai vari attributi e in caso modificarli o scartarli in base alle esigenze.
### Qui ci viene in aiuto il costruttore
Il costruttore e':
- un metodo
- *public*
- con lo stesso nome della classe
- con 0 o piu' parametri
- senza tipo di ritorno

### Come funziona
Ogni volta che istanziamo una classe, viene automaticamente chiamato il costruttore di quest'ultima e si possono avere due casi: 
1. Il costruttore e' definito, quindi viene chiamato
2. Il costruttore non e' definitio e quindi viene chiamato il **costruttore di default** che e' semplicemente un metodo vuoto con il nome della classe (nel caso della classe sopra e' Razionale())

### Come si usa
Per prima cosa definiamo il nostro costruttore
```cpp
class Razionale {
private: 
	int num;
	int den;
public: 
	Razionale(int numeratore, int denominatore) {
		if(denominatore == 0) {
		cout << "Errore: il denominatore non puo' essere 0";
		}
	}
}

```
Una volta definito andiamo a creare un oggetto di questa classe, facendo attenzione a inserire i parametri correttamente
```cpp
int main() {
	Razionale r1(4,5);
	// sintassi alternativa
	Razionale r2 = {4, 5};
}
```

### Costruttori multipli
E' possibile definire piu' costruttori della stessa classe, solo se differiscono per una delle due cose:
- Per tipi di parametri
- Per numero di parametri
```cpp
class Razionale {
	Razionale(){}
	Razionale(int x, int y){}
	Razionale(float x, float z)
}
```

#### Links
[[Delegating Constructors]]