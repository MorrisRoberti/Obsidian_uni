>*const* e' un modificatore (in questo caso) attribuito ai metodi che sta ad indicare che nel corpo di tale metodo non verra' modificato l'oggetto *this*

Un metodo dichiarato costante e' definito come segue:
```cpp
Razionale somma(const Razionale& r) const {
	...
}
```
Quando noi richiamiamo il metodo ``r1.somma(r)`` sull'oggetto *r1* siamo **assolutamente sicuri che r1 non verra' in alcun modo modificato nel corpo**.

C'e' da tenere conto di una cosa, cioe' il fatto che se all'interno del metodo che noi dichiariamo *const* viene chiamata una funzione, allora anche quest'ultima dovra' essere dichiarata *const* per assicurare che questa non modifichi l'oggetto corrente (*this*)

```cpp
Razionale stampaSomma() const {
	...
}

Razionale somma(const Razionale& r) const {
	...
	this->stampaSomma();
}
```

In linea di massima, avere *const* nella signature del metodo consente di capire velocemente se all'interno del suo corpo verra' o meno modificato l'oggetto corrente e questo assicura una maggiore consistenza dei dati.

#### Links