>In Java tutte le funzioni sono **metodi**, quindi non e' possibile definire una funzione al di fuori di una classe.

#### Overloading
In Java e' consentito l'overloading dei metodi esattamente come in C++, tuttavia **non e' consentito l'overloading degli operatori**.
#### Signature
```java
public int sum(int a, int b) {}
```
Nella signature dei metodi in Java vanno specificate le seguenti cose:
- *visibilita'* -> public, private etc.
- *tipo di ritorno*
- *nome*
- *parametri con il rispettivo tipo*

**ATTENZIONE**
>I parametri attuali vengono passati **per valore** o **per reference**. NON E' POSSIBILE PASSARE UN TIPO PRIMITIVO PER REFERENCE O UN TIPO REFERENCE PER VALORE

### Passaggio per parametri di array
>L'unico tipo di passaggio di parametri in Java e' quello per valore, ma se il tipo da passare e' una **reference** viene realizzato il passaggio per riferimento
```java
public class Main {
	public static void f(int[] V){}

	public static void main(String[] args){
	int[] A = {1, 2, 3};
	f(A);
	}
}
```
- `A` e' di tipo **reference**
- `A` e `V` sono reference dello stesso oggetto
- `A` e `V` condividono lo stesso array

#### Links
[[Tipi reference - Array]]