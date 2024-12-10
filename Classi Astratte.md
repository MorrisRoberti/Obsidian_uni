>Una classe che contiene [[Metodi virtuali e classi dinamiche#Metodi virtuali puri|metodi virtuali puri]] e' detta **classe astratta**. Il fatto che un metodo virtuale sia puro significa che *ogni classe concreta che eredita dalla classe astratta deve fare overriding del metodo*, se non viene fatto l'overriding il metodo rimane puro e quindi anche la classe derivata rimane una *classe astratta*.

**ATTENZIONE**
>NON E' POSSIBILE ISTANZIARE CLASSI ASTRATTE.

```cpp
class Printer {
public:
	virtual std::string name() const = 0;
	virtual void print(const Doc& doc) = 0;
};

int main() {
	Printer p; // ERRORE
}
```