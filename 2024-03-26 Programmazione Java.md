### Conversioni
Le conversioni di tipo in java sono piu' strict:
```java
float x = 1.2f;
double y = 2.3
y = x // ok
x = y // NON FUNZIONA
```

- L'istanziazione degli oggetti avviene solo tramite operatore *new*
```java
C1 x; // crea un oggetto null
x = new C1(); // crea una reference che punta a quell'oggetto
```
- Non esistono *shallow copy* e *deep copy* semplicemente se assegniamo un oggetto ad un altro verra' copiato l'oggetto puntato dalla reference di quello di dx in quello di sx in questo modo le due reference punteranno allo stesso spazio di memoria
- **final**  indica un campo che, una volta assegnato NEL COSTRUTTORE non potra' piu' essere modificato