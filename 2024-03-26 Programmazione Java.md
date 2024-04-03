### Conversioni
Le conversioni di tipo in java sono piu' strict:
```java
float x = 1.2f;
double y = 2.3
y = x // ok
x = y // NON FUNZIONA
```
- Non e' previsto l'overloading degli operatori
- In java ci sono le **reference** e non i puntatori, per cui non esiste aritmetica dei puntatori
- Le **reference** sono come dei puntatori ma non e' possibile utilizzarli e manipolarli direttamente
- I parametri attuali vengono passati per **valore** o per **reference**.
- Per ogni campo va specificata la visibilita', il tipo di ritorno, il nome etc.
- L'istanziazione degli oggetti avviene solo tramite operatore *new*
```java
C1 x; // crea un oggetto null
x = new C1(); // crea una reference che punta a quell'oggetto
```
- La *dot notation* di java e' analoga alla notazione *->* del C++: in automatico va a dereferenziare la reference e va a prendere il campo di quell'oggetto
- Essendo che la memoria dinamica non e' direttamente gestita dal programmatore, per deallocare della memoria dinamica esiste un programma della JVM chiamato *garbage collector* che appunto si occupa di liberare la memoria in automatico.
- Non esistono *shallow copy* e *deep copy* semplicemente se assegniamo un oggetto ad un altro verra' copiato l'oggetto puntato dalla reference di quello di dx in quello di sx in questo modo le due reference punteranno allo stesso spazio di memoria
- **final**  indica un campo che, una volta assegnato NEL COSTRUTTORE non potra' piu' essere modificato