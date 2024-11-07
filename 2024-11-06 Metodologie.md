- si dice **out of line** quando un metodo di una classe e' definito fuori dalla classe
- La *new* di un array e' exception safe
quando si fa l'assegnamento si usa fare
```cpp
inline Stack& Stack::operator=(const type& y) noexcept{
	type temp(y);
	std::swap(temp);
	return *this;
}
```

- Quando si prevede lo spostamento di risorse, nell'invariante di classe bisogna verificare che l'oggetto spostato sia comunque ben formato