>Le **conversioni implicite** del C++ si possono suddividere in 4 categorie (+ quella della sintassi `...` ereditata dal C che consente di avere un numero arbitrario di parametri).

## 1) Corrispondenze esatte
>Le **corrispondenze esatte** sono delle conversioni implicite di tipo che garantiscono di preservare il valore dell'argomento (attenzione: ci sono conversioni che pur preservando il valore non sono corrispondenze esatte).
#### a) Match perfetti (identita')
>In realta' non e' una conversione perche' tipo di partenza e tipo di destinazione coincidono e appunto si verifica nel momento in cui cio' che viene passato come parametro corrisponde esattamente al tipo che la funzione si aspetta.

| argomento | tipo argomento | tipo parametro |
| --------- | -------------- | -------------- |
| 5         | int            | int            |
| i         | int&           | int&           |
| &i        | int*           | int*           |
| r         | const int&     | const int&     |
| 5.2       | double         | double         |

#### b) Trasformazioni di lvalue
>Sono corrispondenze esatte che intervengono nel modo in cui un *lvalue* viene interpretato, una trasformazione da *lvalue* a *rvalue* si verifica quando siamo interessati al valore di una locazione e non alla locazione stessa.

| argomento | tipo argomento | tipo parametro |                             |
| --------- | -------------- | -------------- | --------------------------- |
| i         | int&           | int            | da lvalue a rvalue          |
| a         | int[10]        | int*           | decay array -> puntatore    |
| foo       | void(int)      | void(*)(int)   | decay funzione -> puntatore |
**CASO SPECIALE**
>Un caso speciale di trasformazioni di *lvalue* e' quello dei **type decay**, che avviene ad esempio quando passiamo un array come argomento ad una funzione, questo, all'interno della funzione *decadra'* ad un puntatore al suo primo elemento.

#### c) Conversioni di qualificazione
>Aggiungono al tipo del parametro il qualificatore *const*.

| argomento | tipo argomento | tipo parametro |
| --------- | -------------- | -------------- |
| i         | int&           | const int&     |
| &i        | int*           | const int*     |

## 2) Promozioni
>Corrispondono ad alcune conversioni implicite di tipo che, come le corrispondenze esatte sono garantite preservare il valore dell'argomento. Solitamente ogni implementazione del linguaggio e' specifica per una determinata architettura, quindi i tipi possono essere rappresentati con parole di grandezza diversa. Per tradizione, i tipi `int` e `unsigned int` vengono rappresentati nella dimensione adeguata ad ottenere la massima efficienza, al contrario, i tipi piu' piccoli di `int` a volte non sono direttamente rappresentabili all'interno del processore quindi ogni volta che si vuole operare su un tipo di dato piu' piccolo di `int` questo deve essere **promosso** a `int` o `unsigned int`.

#### a) Promozioni intere
>Sono le promozioni da tipi interi piccoli (`char/short`, `signed` o `unsigned`) al tipo `int` (o `unsigned int`).
>Oppure da `bool` a `int` (*caso speciale*).

#### b) Promozioni floating point
>Da `float` a `double`.

#### c) Promozione delle costanti di enumerazione del C++ 2003
>Al piu' piccolo tipo intero (almeno `int`) sufficientemente grande per contenerle.


## 3) Conversioni standard
>In pratica tutte le altre conversioni implicite che non coinvolgono conversioni definite dall'utente.

**ATTENZIONE**
>Da `int` a `long` NON E' UNA PROMOZIONE, ma una conversione standard, cosi' come da `char` a `double` etc.

Tra le conversioni standard da tenere in considerazione vi sono le conversioni tra *riferimenti* e tra *puntatori*, in particolare:
- La costante intera 0 e il valore `nullptr` (di `std::nullptr_t`) sono le costanti puntatore nullo; esse possono essere convertite implicitamente nel tipo `T*`; la costante intera 0 puo' essere convertita in `nullptr`
- Ogni puntatore `T*` puo' essere convertito nel tipo `void*` che corrisponde ad un puntatore ad un tipo *sconosciuto* (in modo implicito, non funziona l'inverso)
- Se una classe `D` derivata (direttamente o indirettamente) dalla classe base `B`, allora ogni puntatore `D*` puo' essere convertito implicitamente in `B*`, si parla di **upcast**, perche' tradizionalmente nei diagrammi che rappresentano le relazioni tra i tipi di dato, le classi base, che sono piu' astratte vengono rappresentate *sopra* alle classi derivate che sono piu' concrete; un'analoga conversione sui riferimenti consente di trasformare un `D&` in un `B&` -> anche in questo caso si noti che non esiste la possibilita' di fare **downcast** esplicito da `B*` a `D*` o da `B&` a `D&`

## 4) Conversioni implicite definite dall'utente
#### a) Uso (implicito) di costruttori
>Un esempio di conversione implicita di conversione definita dall'utente e' quella dei costruttori che possono essere invocati con un solo argomento (di tipo diverso) e non sono marcati `explicit`.

```cpp
class Razionale {
	Razionale(int num, int den = 1); // conv. implicita da int a Razionale
};
```

#### b) Uso di operatori di conversione da tipo utente verso altro tipo
```cpp
class Razionale {
	operator double() const; // conversione da Razionale a double
};
```


**ATTENZIONE**
>E' possibile usare la parola chiave `explicit` per impedire l'uso implicito delle conversioni.

#### Links
[[Tipi pointer e reference]]
[[Tipi, qualificatori, costanti letterali]]
