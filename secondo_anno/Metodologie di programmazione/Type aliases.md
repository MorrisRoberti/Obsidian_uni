>Un **alias di tipo** e' *un nome che si riferisce ad un tipo precedentemente definito*. In pratica e' un nuovo nome che noi utilizziamo per intendere quel tipo. Si vuole fare questo perche', soprattutto se si usano template, e' facile che il nome di un tipo diventi particolarmente lungo e dunque scomodo. **ATTENZIONE**: un alias non indica un nuovo tipo.

## Esempi
```cpp
typedef long Integer; // alias tipo stile c++03
using VectInt = std::vector<int>; // alias tipo stile c++11
namespace ppl = Parma_Polyhedra_Library; // alias namespace
```
Ad esempio, se in un certo momento noi volessimo che tutti gli interi del nostro programma diventino `int` e non `long` perche' ci siamo accorti che dichiararli `long` era solo uno spreco di memoria, allora basta cambiare nella riga 1 `long` con `int` senza dover cercare interi e cambiarli in ogni parte del programma. 




#### Links
[[Dichiarazione e definizione]]