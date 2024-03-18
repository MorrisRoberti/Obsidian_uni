>*Il distruttore* e' un metodo presente in ogni classe che si occupa di distruggere l'oggetto di una classe.

### Funzionamento e definizione
Quando la funzione termina, le variabili allocate *automaticamente* (dal costruttore) vengono deallocate insieme a this. Tale deallocazione viene fatta in automatico dal **distruttore**.

Il distruttore di una classe e':
- un metodo
- *public*
- ha lo stesso nome della classe **ma con prefisso ~**
- **e' senza parametri** 
- **E' UNICO PER CIASCUNA CLASSE**
- non ha tipo di ritorno

Ogni classe ha un distruttore di default:
```cpp
class Razionale {
public:
~Razionale () {}
};
```

### Quando e' necessario ridefinirlo
#### Rule of thumb
>E' **necessario** ridefinire il distruttore quando la nostra classe contiene variabili allocate dinamicamente. Se non lo facciamo l'oggetto viene distrutto ma la memoria occupata da quelle variabili non viene rilasciata

Esempio
```cpp
class C {
private:
	int a;
	int b;
	int* memory;
public:
	~C() {
		delete [] memory;
		}
};
```