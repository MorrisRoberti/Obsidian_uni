## Tipi fondamentali

### Tipi integrali
>Tutti i tipi sottostanti sono detti **tipi integrali**. I booleani, caratteri narrow e short sono detti **integrali piccoli** in quanto potrebbero avere una dimensione (sizeof) inferiore a int e quindi potrebbero esser soggetti a **promozione**. Una *promozione* e' simile ad un casting implicito che avviene da un tipo integrale piccolo ad un tipo int.

- tipi booleani -> *bool*

- tipi carattere (narrow) -> *char, signed char, unsigned char*
- tipi carattere (wide) -> *wchar_t, char16_t, char32_t*

- tipi interi standard (*con segno*) -> *signed char, short, int, long, long long*
- tipi interi standard (*senza segno*) -> *unsigned char, unsigned short, unsigned int, ...*

### Altri tipi fondamentali
- floating point -> *float, double, long double*
- **tipo void** -> ha un insieme vuoto di valori
- **tipo std::nullptr_t** -> e' un tipo puntatore convertibile implicitamente in qualunque altro tipo puntatore; ha un solo valore possibile, la costante letterale *nullptr*, che indica il puntatore nullo (non dereferenziabile)

## Tipi composti
- riferimenti a **lvalue** -> *T&*
- riferimenti a **rvalue** -> *T&&*
- puntatori -> *T* * 
- tipi array -> *T[n]*
- tipi funzione -> T(T1, ..., Tn)
- enumerazioni e classi/struct

## Tipi qualificati
>I tipi sopra sono detti *non qualificati*. Nel linguaggio C++ esistono i qualificatori `const` e `volatile`, noi analizzeremo il primo.
>Dato un tipo T, e' possibile fornirne la versione qualificata `const T`. L'accesso ad un oggetto costante e' in sola lettura.

Si noti che nel caso di tipi composti e' necessario distinguere tra la qualificazione del tipo composto e la qualificazione delle sue componenti
```cpp
struct S {
	int v;
	const int c;
	S(int cc) : c(cc) { v = 10; }
};

int main() {
	const S sc(5);
	sc.v = 20; // errore: sc e' const e anche le sue componenti

	S s(5);
	s.v = 20; // legittimo: s non e' const e S::v non e' const
	s.c = 20; // errore: s non e' const, ma S::c e' const
}
```

La "modificabilita'" dell'oggetto dipende anche dal percorso fatto per accedervi
```cpp
struct S { int v; };
void foo() {
	S s;
	s.v = 10; // legittimo
	const S& sr = s; // riferimento a s, qualificato const
	sr.v = 10; // errore: non posso modificare s passando da sr.
}
```

## Costanti letterali
>Il linguaggio mette a disposizione diverse sintassi per definire valori costanti, a seconda della sintassi usata, al valore viene associato un tipo specifico, che talvolta dipende dall'implementazione.

- sintassi per gli interi -> *sintassi decimale (quella comunemente utilizzata), sintassi binaria (0b1100), sintassi ottale (014), sintassi esadecimale (0xC)*
- sintassi booleani -> *true, false*
- sintassi caratteri (*ordinary character literal*) -> *'a', '3', 'Z', ' \n' *
- sintassi caratteri (*UTF-8 character literal*) -> *u8'a', u8'3'*
- signed/unsigned char -> nessuna
- char16_t ->  *u'a', u'3'*
- char32_t -> *U'a', U'3'*
- wchar_t -> *L'a', L'3'*
(Nelle precedenti 3 il prefisso e' *case sensitive*)

- short/unsigned short -> nessuna
- int -> *12345*

**ATTENZIONE**
>In assenza di suffissi (U, LL, L) ad una costante *decimale* intera viene attribuito il primo tipo tra int, long e long long che sia in grado di rappresentare il valore. Il tipo dipende quindi dalla particolare implementazione utilizzata. I suffissi delle costanti intere e floating point *NON SONO CASE SENSITIVE*. Buona norma e' utilizzare **il suffisso maiuscolo**.

Alcune considerazioni:
- in presenza del suffisso **U** si sceglie la variante **unsigned**
- in presenza del suffisso **L** l'ampiezza e' scelta tra **long e long long**
- in presenza del suffisso **LL** l'ampiezza e' **long long**


- long -> *12345L*
- long long -> *12345LL*
- unsigned int -> *12345U*
- unsigned long -> *12345UL*
- unsigned long long -> *12345ULL*

Per i floating point si puo' scegliere tra notazione decimale e notazione scientifica:
- float -> *123.45F, 1.2345e2F*
- double -> *123.45, 1.2345e2F*
- long double -> *123.45L, 1.2345e2L*

void -> nessuna
std::nullptr_t -> nullptr

### String literals
>Il tipo associato al letterale `Hello` e' `const char[6]` cioe' array di 5 caratteri + 1 per il terminatore `\0`. E' possibile specificarne il prefisso di encoding (u8, u, U, L).

#### Raw string literal
>Usano il prefisso **R**, un delimitatore a scelta e le parentesi tonde, la sintassi generale e' la seguente
>					`R"DELIMITATORE(stringa)DELIMITATORE"`

Per esempio scegliendo `STRING` come delimitatore si puo' scrivere il letterale:
```cpp
R"STRING(la mia stringa 
di lunghezza x con vari breakline e """" apici)STRING"
```

#### User defined literal
>Il C++ 2011 ha reso possibile anche la definizione dei letterali definiti dall'utente.  Si tratta di una notazione che consente di aggiungere ad un letterale (intero, floating o stringa) un suffisso definito dall'utente: il letterale verrà usato come argomento per invocare una funzione di conversione implicita definita anch'essa dall'utente.

Per esempio, a partire dal C++ 2014, il tipo di dato delle stringhe stile C++ (std::string) fornisce la possibilità di usare il suffisso 's' per indicare che un letterale stringa deve essere convertito in std::string. L'operatore di conversione è definito nel namespace std::literals, per cui

```cpp
#include <iostream>
#include <string>

int main() {
	using namespace std::literals;
	std::cout << "Hello"; // stampa la stringa C (tipo const char[6])
	std::cout << "Hello"s; // stampa la stringa C++ (tipo std::string)
}
```

#### Links
