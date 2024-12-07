In linea di massima ogni iteratore dovrebbe avere gli alias di tipo descritti in [[Concetto di Iteratore#2) iterator_category|iterator category]] tuttavia non e' possibile utilizzare la tecnica usata per i contenitori standard, perche' tra i nostri iteratori ci sono anche tipi che non sono classi (i puntatori) e che quindi non consentono di essere interrogati tramite la sintassi dell'operatore di scope

`Iter::value_type`

Tale problema si risolve con gli **iterator traits**.

>Con il template di classe `std::iterator_traits` possiamo interrogare la classe **traits** ottenuta istanziando il template con quel tipo di iteratore, invece di interrogare direttamente il tipo (come con l'operatore di scope).

Per cui se vogliamo conoscere il `value_type` di `Iter` scriviamo

`std::iterator_traits<Iter>::value_type`


### Concetto generale di trait
>L'uso di `iterator_traits` e' solo uno degli esempi di uso di classi *traits* ovvero tipi di dato che hanno lo scopo di fornire qualche informazione (*traits* ovvero le caratteristiche) di altri tipi di dato. In particolare possiamo effettuare queste analisi anche sui tipi di dato built-in.

Altri esempi di classi traits sono:
- Il template di classe `std::numeric_limits<T>` che consente di interrogare tipi numerici per ottenere informazioni quali i valori minimi e massimi, se sono con segno o meno, il fatto di supportare calcoli esatti o meno etc.
- Il template di classe `std::char_traits<T>`, che consente di interrogare i tipi carattere per ottenere accesso, ad esempio alle funzioni di confronto da usare per l'ordinamento lessicografico.

#### Implementazione generale della classe iterator_traits
>Intuitivamente gli `iterator_traits` devono distinguere i tipi puntatore dagli altri iteratori (definiti dall'utente). Nel secondo caso, che corrisponde al template non specializzato, si "delega" al tipo `Iter` (definito dall'utente) il compito di effettuare l'introspezione

```cpp
template<typename Iter>
struct iterator_trais {
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};
```

Quando invece il tipo `Iter` e' un puntatore, il template di classe si attiva per restituire all'utente le informazioni che il tipo built-in non sarebbe in grado di fornire.
Vengono quindi fornite le due specializzazioni parziali (non-const e const) del template di classe

```cpp
template<typename T>
struct iterator_traits<T*> {
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};


template<typename T>
struct iterator_traits<const T*> {
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};


```


#### Links
[[Concetto di Iteratore]]
[[secondo_anno/Metodologie di programmazione/I Template|I Template]]
[[Programmazione generica]]