### Template
- Quando dichiariamo una funzione con un tipo generico bisogna fare attenzione al tipo che si passa:
```cpp
template<class T>
void scambia(T& element1, T& element2){}

int main () {
	Razionale r();
	int a = 0;
	scambia(r, a);
}
```
questa cosa si rompe

- Il tipo T puo' essere dato anche come tipo di ritorno 
```cpp
template<class T>
T scambia(T& element1, T& element2) {}
```

- Bisogna che tutto cio' che viene usato nel corpo della funzione sia definito per i tipi che possono essere passati
- Possiamo scrivere indifferentemente in questi modi: ``template<class T>`` o ``template<typename T>``
- e' possibile definire classi con i template
```cpp
template <typename T>
class C {
private:
	T z;
public: 
	int f(T x) {
		...
	}
	
	T f() {}
}
```
