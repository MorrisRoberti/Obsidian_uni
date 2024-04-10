>Java e' un linguaggio Object Oriented creato all'inizio degli anni 90, ed e' platform-agnostic, infatti il codice java puo' essere eseguito senza modifiche su ogni piattaforma in grado di eseguire java, il suo motto e': *write once run it everywhere*

### Portabilita'
>Il punto forte di java e' la **portabilita'**, che viene raggiunta tramite la **Java Virtual Machine** (*JVM*) cioe' una macchina virtuale che si frappone tra il codice e la macchina

### Come viene compilato il codice java?
In Java il processo che trasforma il codice sorgente in eseguibile avviene tramite piu' passaggi
![[Pasted image 20240410193958.png]]
- **Compilazione** -> tramite il comando *javac* (che invoca il compilatore), il codice sorgente (*.java*) viene trasformato in **java bytecode** (*.class*)
- **Interpretazione** -> il *java bytecode* (*.class*) viene poi interpretato tramite il comando *java* ed eseguito sulla JVM

La potenza di questo meccanismo sta nel fatto che lo stesso codice possa essere compilato una sola volta e essere eseguito su tutte le macchine, indipendentemente da sistema operativo o altre caratteristiche, poiche' sara' la **JVM** ad eseguire il codice.

### Caratteristiche
>In Java tutti i dati e le funzioni sono contenuti all'interno di **classi**

Ogni classe deve essere in un file separato che porta il suo nome
![[Pasted image 20240410194826.png]]

#### Puntatori, reference e garbage
- In Java non esiste il concetto di puntatore ma viene rimpiazzato con le **reference** che non sono gestibili dal programmatore
- Essendo che non esistono i puntatori, quando creo un oggetto dinamico con la *new*, l'identificatore di questo non sara' un puntatore all'oggetto nello heap ma una reference
- Non essendoci puntatori non c'e' nemmeno aritmetica dei puntatori
- Se non ci sono i puntatori, chi dealloca la memoria dinamica allocata dal programmatore? Lo fa un programma chiamato **garbage collector** che entra in gioco quando c'e' bisogno di liberare memoria nello heap e si occupa appunto di gestire il **garbage** cioe' tutta quella memoria allocata che ormai non serve piu'

#### Entrypoint
L'entrypoint del programma e' un metodo chiamato *main* ed e' quello che viene invocato non appena viene lanciato il programma:
```java
public class HelloWorld {
	public static void main(String[] args) {
		System.out.println("Hello World");
	}
}
```

#### Links
[[Tipi primitivi]]
[[Conversioni di tipo (casting)]]
[[Funzioni]]
[[Classi]]