>In Java la visibilita' dei metodi e dei campi delle classi deve essere specificata singolarmente per ognuno di essi

```java
public class C1{
	private int x;
	public C1() {...}
	private void func1() {...}
	public int f2(int x) {...}
}
```

### Instanziazione di Oggetti
>L'instanziazione di oggetti in Java avviene **sempre** tramite l'operatore *new*

```java
C1 x;
x = new C1();
```
- 1 -> dichiarazione di una variabile di tipo `C1`, viene creata una **reference** ad un oggetto di tipo `C1` inizializzato a *null*
- 2 -> creazione dinamica dell'oggetto di tipo `C1` e ritorno della **reference** all'oggetto appena creato

#### Sempre sugli oggetti
Non esistono *shallow copy* e *deep copy*, semplicemente se assegniamo un oggetto ad un altro verra' copiato l'oggetto puntato dalla reference di dx in quello di sx, in questo modo le due reference punteranno allo stesso spazio in memoria

### Accesso a campi e metodi
>Banalmente l'accesso ai campi e ai metodi di un oggetto di una classe avviene tramite la *dot notation*

```java
C1 x = new C1();
int k = x.f2(3);
```


**ATTENZIONE**
La dot notation di Java non ha lo stesso significato della dot notation di C++, ma e' piu' assimilabile alla ->

#### Links