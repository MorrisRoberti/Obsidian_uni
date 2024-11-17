>Il processo di **compilazione dei template** richiede che lo stesso codice sia analizzato dal compilatore in almeno due contesti distinti

1. al momento della *definizione* del template
2. al momento della *istanziazione* del template

Nella prima fase, il compilatore opera con una definizione incompleta
```cpp
template <typename T>
void incr(int& i, T& t) {
	++i; // esepressione indipendente dal parametro T
	++t; // espressione dipendente dal parametro T
}
```
Nella prima espressione il compilatore puo' effettuare con successo tutti i controlli di correttezza, mentre nella seconda non c'e' modo di stabilire se il tipo `T` abbia o meno l'operatore di pre-incremento, quindi tale controllo viene rimandato al momento di istanziazione del template.

## Conseguenze della compilazione in due fasi

#### 1) Inclusione delle definizioni/dichiarazioni

>Quando si scrive un'interfaccia templatica la definizione del template deve essere disponibile in tutti i punti del programma nei quali se ne richiede l'istanziazione.

Esistono 3 modi per organizzare il codice quando si usano i template:
1. includere le *definizioni* dei template prima di ogni loro uso nell'unita' di traduzione (es. tramite un header file)
2. includere le dichiarazioni del template prima di farne uso e successivamente includere le definizioni del template nell'unita' di traduzione
3. sfruttando il meccanismo delle istanziazioni esplicite, includere solo le dichiarazioni die template e le *dichiarazioni* di istanziazione esplicita prima di ogni loro uso nell'unita' di traduzione, assicurandosi che le definizioni dei template e le *definizioni* di istanziazione esplicita siano fornite in un'altra unita' di traduzione

*Solitamente* si usa il **primo** approccio, il **secondo** si usa quando si hanno funzioni templatiche che si chiamano *ricorsivamente* e il **terzo** si usa per *ridurre i tempi di compilazione*.

#### 2)  Ambiguita' sul tipo
>In alcuni casi, occorre modificare l'implementazione dei template per fornire al compilatore qualche informazione utile ad evitare errori di compilazione.

```cpp
struct S {
	using value_type = // dettaglio implementativo
};

void foo(const S& s) {
	S::value_type* ptr;
}
```

Eseguiamo il **lifting** sulla classe `S`, cioe' rendiamola templatica

```cpp
template <typename T>
struct S {
	using value_type = // dettaglio implemntativo
};

template <typename T>
void foo(const S<T>& s) {
	S<T>::value_type* ptr; // errore: ptr non dichiarato
}
```

Questo succede perche' quando esamina il codice, il compilatore si trova nella *prima fase di compilazione* e quindi non sa nulla sul tipo `T`. Questo genera l'ambiguita' e fa si che il compilatore non veda l'espressione come una definizione di variabile ma come un'espressione di moltiplicazione tra nomi di variabili gia' esistenti `nome1 * nome2`.

Per risolvere il problema, bisogna comunicare al compilatore che `S<T>::value_type` e' un nome di tipo, aggiungendo la parola chiave `typename`
```cpp
template <typename T>
void foo(const S<T>& s) {
	typename S<T>::value_type* ptr; // ok, dichiaro un puntatore
}
```

**ATTENZIONE**
>Tale problema potrebbe verificarsi in modo subdolo.

```cpp
int p = 10;

template <typename T>
void foo(const S<T>& s) {
	S<T>::value_type* p; // compila senza errori (operator* binario)
}
```

In questo caso il compilatore non segnala l'errore perche' interpreta `nome1 * nome2` e quindi diventa molto difficile accorgersi del problema.

#### Links
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]
[[Fasi del processo di compilazione]]