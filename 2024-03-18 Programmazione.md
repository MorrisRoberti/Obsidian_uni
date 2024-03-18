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
