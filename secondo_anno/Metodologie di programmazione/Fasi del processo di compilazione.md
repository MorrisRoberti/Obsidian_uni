>Il processo di compilazione (in C++) e' quella sequenza di passi che permette, tramite il compilatore, di ottenere un file eseguibile partendo dal codice sorgente

Si divide in 4 fasi:
- **Preprocessing** -> *input*: codice sorgente *.cpp*  - *output:* translation unit
- **Compilation** -> *input:* sorgente preprocessato - *output:* assembly .asm
- **Assembling** -> *input:* assembly .asm - *output:* object file .o
- **Linking** -> *input:* object file / librerie - *output:* eseguibile (.exe nel caso di windows)

## Preprocessing
>Il **preprocessing** e' la prima fase del processo di compilazione, in cui il compilatore si occupa di unire il codice del nostro sorgente con quello delle librerie e generare una **translation unit** che fondamentalmente e' una sorta di codice sorgente che viene espanso con il codice delle librerie e altre cose e metterlo in un file temporaneo.

Durante la compilazione e' possibile dire al compilatore di fermarsi subito dopo la fase di preprocessing
```
g++ main.cpp -E -o main.i
```
Il flag `-E` dice al compilatore di restituire il sorgente preprocessato, mentre il flag `-o` gli dice di inserire l'output nel file `main.i`

#### Errori e preprocessore
>Le righe iniziali nel file preprocessato servono per rimappare gli errori che il compilatore trova nel codice preprocessato in quelle del codice sorgente.

## Compilation
>La **compilazione** in senso stretto e' il processo che, data una (o piu') translation unit la traduce in codice assembly.

E' possibile fermarsi subito dopo la compilazione
```
g++ main.cpp -S -o main.asm
```
### Name mangling
>Il **name mangling** e' il processo utilizzato dal compilatore per modificare i nomi di funzioni, variabili etc. per fare in modo che siano univoci indipendentemente da namespace e overloading

```cpp
void funzione(int a);
void funzione(double b);
```
Il name mangling e' necessario, perche' altrimenti il compilatore non sarebbe in grado di distinguere le due funzioni

#### Come funziona
Ad esempio, la funzione intera sopra potrebbe essere trasformata in `_Z8funzionei` dove:
- `_Z` -> e' un prefisso che indica che si tratta di una funzione mangled
- `8funzione` -> rappresenta il nome della funzione con la lunghezza del nome
- `i` -> e' il tipo del parametro
quindi banalmente, se facciamo l'overloading di questa funzione solo la parte `8funzione` rimarra' necessariamente uguale, perche' dovro' necessariamente cambiare numero o tipo di parametri.
>Il name mangling *non tiene conto del tipo di ritorno*.

```cpp
int foo() {
	return 3;
}


double foo() {
	return 4;
}
```
Il nome associato ad entrambi sara' qualcosa del tipo `_Z3foov` (dove `v` indica parametro void).

## Assembling
>L'**assembling** e' il processo nel quale, **l'assembler** prende un file **assembly** e genera un *object file* che in buona sostanza e' un file binario.

Come sopra, e' possibile fermarsi subito dopo questa fase
```
g++ main.cpp -c -o main.o
```

### Object file
>Un **object file** e' file che contiene codice macchina e altre informazioni utili al processo successivo, cioe' quello di **linking**.

## Linking
>Il **linking** e' l'ultimo passo del processo di compilazione. Il linker prende gli *object file* generati dall'assembler, rimpiazzando tutte le reference a simboli undefined con i corretti indirizzi (dove e' definito il codice di quel qualcosa). La definizione puo' essere in uno degli altri object file che vengono linkati oppure fare parte di librerie esterne, in questo caso, bisogna specificare manualmente il percorso in cui trovare i file con tali definizioni.

Solitamente, quando importiamo qualcosa di "standard" come *iostream* lo facciamo con le parentesi angolari
```cpp
#include <iostream>
```
questo fa si che il linker vada a cercare solo in una lista di directory standard del linguaggio. In pratica le parentesi angolari indicano che il codice utilizzato fa parte della libreria standard.
Diversamente, quando vogliamo linkare verso una libreria esterna dobbiamo specificare il path
```
g++ main.cpp -Ipath -o main
```
in questo modo specifichiamo dove si trova la libreria in cui trovare gli indirizzi da andare a sostituire ai simboli undefined.

Esistono due tipi di linking
### Linking dinamico
>Il **linking dinamico** e' quello che avviene in automatico senza che specifichiamo il tipo, solitamente il linker dinamico predefinito degli ambienti linux e' `ld` (quindi quando un errore contiene `ld` sappiamo che e' un errore di linking). In pratica si occupa di collegare le librerie, senza pero' includere il loro codice nell'eseguibile.

Il linking dinamico ha pro e contro
**PRO**
- Le dimensioni dell'eseguibile sono estremamente contenute
**CONTRO**
- Per compilare ed eseguire il programma, le librerie collegate dinamicamente devono essere presenti nella macchina dell'utilizzatore (che sia un altro programmatore o lo stesso utente finale)

>Le librerie dinamiche in linux hanno l'estensione `so` (*shared object*) mentre in windows sono `dll` (*dinamically linked libraries*).

### Linking statico
>Il **linking statico** e' quello che avviene quando decidiamo *attivamente* di includere il codice delle librerie utilizzate, nell'eseguibile finale. Per dire al compilatore di eseguire un linking statico bisogna specificare il flag `--static` al momento della compilazione.

**PRO**
- L'utilizzatore finale non avra' bisogno di installare librerie ma avra' tutto disponibile all'interno dell'eseguibile
**CONTRO**
- Le dimensioni dell'eseguibile saranno esponenzialmente piu' grandi di quelle della versione compilata con *dynamic linking*

#### Links