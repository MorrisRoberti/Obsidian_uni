Consideriamo il seguente esempio
```cpp
class Printer {
public:
	void print(const Doc& doc);
};

class FilePrinter : public Printer {
public:
	void print(const Doc& doc);
};

class NetworkPrinter : public Printer {
public:
	void print(const Doc& doc);
};
```

Supponiamo che il codice dell'utente debba stampare alcuni documenti utilizzando una stampante e utilizzi l'astrazione `Printer` nel modo seguente
```cpp
void stampa_tutti(const std::vector<Doc>& docs, Printer* printer) {
	for (const auto& doc : docs)
		printer->print(doc);
}
```
Il chiamante invochera' la funzione `stampa_tutti` passando un puntatore ad una istanza specifica di `FilePrinter` o `NetworkPrinter`, sfruttando l'up-cast fornito dalla relazione **IS-A**. Quando esamina la chiamata del metodo `print` il compilatore si trovera' a fare la risoluzione dell'overloading conoscendo solo il tipo statico di `printer` (ovvero il puntatore alla classe base `Printer`), senza sapere qual e' il tipo dinamico; di conseguenza effettuera' la ricerca delle candidate nella classe `Printer` e trovera' solo il metodo `Printer::print` che verra' scelto come migliore funzione utilizzabile.

In realta' vorremmo che fosse invocato il metodo specifico della stampante concreta passata alla funzione, che potrebbe dover fare operazioni diverse a seconda della classe di appartenenza.

Abbiamo quindi bisogno di un meccanismo tecnico che consenta di interrogare a tempo di esecuzione il puntatore, allo scopo di *ridirezionare* la chiamata del metodo `print` al corrispondente metodo della classe concreta.

>Questo meccanismo tecnico esegue la cosiddetta **risoluzione dell'overriding** e, nel caso del C++, viene attivato solo quando i metodi della classe base sono stati dichiarati essere **metodi virtuali**.

Quindi bisogna ridefinire la classe base nel modo seguente
```cpp
class Printer {
public:
	virtual void print(const Doc& doc);
};
```

## Polimorfismo dinamico
>Una classe che contenga almeno un metodo virtuale viene detta **classe dinamica**, in quanto per gli oggetti di questa classe vengono messe a disposizione le funzionalita' che consentono di implementare la risoluzione dell'overloading, la **RTTI** (*Run-Time Type Identification*) e piu' in generale il **polimorfismo dinamico**.

##### A livello implementativo
In ogni oggetto che e' istanza di una classe dinamica, viene memorizzato un puntatore non accessibile al programmatore, tramite il quale il **RTS** (*Run-Time Support*, cioe' supporto a tempo di esecuzione) del linguaggio puo' raggiungere le informazioni di tipo della classe.

L'esistenza di questo puntatore si puo' notare se si confrontano, usando l'operatore `sizeof` gli oggetti di classi dinamiche e statiche
```cpp
#include <iostream>
class Statica { ~Statica() = default; };
class Dinamica { virtual ~Dinamica() = default; };

int main() {
	std::cout << "Statica = " << sizeof(Statica) << "\n";
	std::cout << "Dinamica = " << sizeof(Dinamica) << "\n";
}

// stampa 
// Statica  = 1 (size of empty class)
// Dinamica  = 8 (size of derived class)
```
## Metodi virtuali puri
>Talvolta quando definiamo delle classi dinamiche non abbiamo in mente un'implementazione per i suoi metodi virtuali, vogliamo solo utilizzarla come interfaccia condivisa per le classi concrete che andranno ad estenderla, per cui vogliamo scrivere **metodi virtuali puri**; per farlo utilizziamo la sintassi `= 0` al termine della sua dichiarazione.

```cpp
class Printer {
public:
	virtual std::string name() const = 0;
	virtual void print(const Doc& doc) = 0;
};
```

#### Links
[[Classi Astratte]]
[[Overriding]]