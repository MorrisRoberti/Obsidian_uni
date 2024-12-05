>La **template type deduction** e' un meccanismo che il compilatore usa per dedurre automaticamente i tipi delle funzioni templatiche, semplificando l'istanziazione (esplicita o implicita) e la specializzazione (esplicita) dei template di funzione.

Supponiamo di avere il seguente template di funzione
```cpp
template<typename TT>
void f(PT param)
```
dove:
- **TT** e' il parametro del template
- **PT** e' un'espressione che denota il tipo del parametro `param`

Definiamo un po di terminologia
- *te* -> tipo dell'espressione `expr`
- *tt* -> tipo del parametro del template
- *tp* -> tipo dedotto del parametro `param`

Il compilatore, di fronte ad una chiamata del tipo:
```cpp
f(expr)
```
usa il tipo di `expr` per dedurre 
- un tipo **tt** per TT
- un tipo **pt** per PT

causando l'istanziazione del template e ottenendo la funzione `void f<tt>(pt expr)`

### Casi possibili del processo di deduzione
Possiamo distinguere 3 casi principali del processo di deduzione:
1. PT e' sintatticamente uguale a TT&& (*universal reference*)
2. PT e' un puntatore o un riferimento (ma non una *universal reference*)
3. PT non e' ne un puntatore ne un riferimento

#### 1) PT e' sintatticamente uguale a TT&&
>Nella terminologia del Meyers, **TT&&** indica una **universal reference** cioe' una reference che puo' essere a *rvalue* o a *lvalue*.
>Per essere una *universal reference* dobbiamo avere un'applicazione di && a TT senza alcun modificatore.

`const TT&&` -> non e' una universal reference
`std::vector<TT>&&` -> non e' una universal reference

Quando abbiamo una universal reference puo' essere dedotto per PT un riferimento a *rvalue* o a *lvalue* a seconda del tipo **te** di `expr`.

Assumiamo
```cpp
int i = 0;
const int ci = 0;
```

es 1
- `f(5);` -> **te**=int, deduco **pt**=int&&, **tt** = int
- `f(std::move(i));` -> **te**=int&&, deduco **pt**=int&&, **tt**=int

es 2
- `f(i);` -> **te**=int&, deduco **pt**= int&, **tt**=int&
- `f(ci);` -> **te**=const int&, deduco **pt**=const int&, **tt**=const int&

#### 2) PT puntatore o riferimento (diverso da TT&&)

**Puntatori**
es 1
```cpp
template<typename TT>
void f(TT* param);
```

- `f(&i);` -> **te**=int*, deduco **pt**=int*, **tt**=int
- `f(&ci);` -> **te**=const int*, deduco **pt**=const int*, **tt**=int

es 2
```cpp
template<typename TT>
void f(const TT* param);
```
- `f(&i);` -> **te**=int*, deduco **pt**=const int*, **tt**=int
- `f(&ci);` -> **te**=const int*, deduco **pt**=const int*, **tt**=int

**Riferimenti**
es 1
```cpp
template<typename TT>
void f(TT& param);
```

- `f(i);` -> **te**=int&, deduco **pt**=int&, **tt**=int
- `f(ci);` -> **te**=const int&, deduco **pt**=const int&, **tt**=int

es 2
```cpp
template<typename TT>
void f(const TT& param);
```

- `f(&i);` -> **te**=int&, deduco **pt**=const int&, **tt**=int
- `f(&ci);` -> **te**=const int&, deduco **pt**=const int&, **tt**=int

#### 3) PT ne puntatore ne riferimento
```cpp
template<typename TT>
void f(TT param);
```

es 1
- `f(i);` -> **te**=int&, deduco **pt**=int, **tt**=int
- `f(ci);` -> **te**=const int&, deduco **pt**=int, **tt**=int

>Siccome avviene un passaggio per valore, questo viene copiato e quindi argomento e parametro diventano entita' diverse, per questo motivo non viene mantenuto il modificatore `const` **esterno**.

es 2
```cpp
const char* const p = "hello";
```

- `f(p);` -> **te**=const char* const&, deduco **pt**=const char*, **tt**=const char*

>Diversamente da sopra i modificatori `const` interni vengono mantenuti.

## Auto Type Deduction
>A partire dallo standard C++11, nel linguaggio e' stata introdotta la possibilita' di definire variabili tramite la parola chiave **auto**, lasciando al compilatore il compito di dedurre il tipo.

```cpp
auto i = 5; // i ha tipo int
const auto d = 5.3; // d ha tipo double
auto ii = i * 2.5; // ii ha tipo double
const auto p = "hello"; // p ha tipo const char* const
```

La keyword **auto** segue all'incirca le stesse linee guida elencate nella *template type deduction* 
```cpp
auto& ri = ci;
```

1. La parola chiave `auto` svolge il ruolo di parametro TT del template
2. La sintassi `auto` corrisponde a PT
3. L'inizzializzatore `ci` corrisponde all'espressione *expr*

Per **auto** si deduce il tipo `const int` e quindi per `ri` deduciamo il tipo `const int&`.

**NOTA**
>Alcune linee guida di programmazione seguono il cosiddetto paradigma **AAA** (*Almost Always Auto*), cioe' consigliano di usare **quasi sempre** auto per definire le variabili.

#### Links
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]
[[Tipi pointer e reference]]