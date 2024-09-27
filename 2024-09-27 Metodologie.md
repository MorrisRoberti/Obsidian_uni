## Alias
```cpp
typedef long Integer; // alias tipo stile c++03
using VectInt = std::vector<int>; // alias tipo stile c++11
namespace ppl = Parma_Polyhedra_Library; // alias namespace
```
- un alias e' un altro nome per lo stesso tipo, *non sono un altro tipo*
- Il codice della riga `1` e' comodo per manutenere il codice: se un giorno il tipo di`Integer` dovesse aumentare allora basterebbe mettere `long long` al posto di `long` modificandolo solo nell'alias, propagando la modifica all'intero programma
- la definizione dei `namespace` e' incrementale, nel senso che quando definiamo un namespace possiamo definirne una parte e poi aggiungere codice
```cpp
namespace test {
	/* codice */
}

/*...*/

namespace test {
	/* altro codice */
}
```
