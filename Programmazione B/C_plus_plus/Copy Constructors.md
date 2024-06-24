>I **Copy Constructor** sono particolari tipi di costruttore che permettono di istanziare un nuovo oggetto con i valori di uno gia' esistente. Eseguono due cose in contemporanea: *creano l'oggetto* e *copiano il vecchio oggetto nel nuovo*.

esempio
```cpp
class Razionale {
private:
	int num;
	int den;
public: 
	Razionale(int n, int d) {
		... 
	}

	Razionale(const Razionale& r){
		this->num = r.num;
		this->den = r.den;
	}
};

int main() {
	Razionale r(2, 3);
	Razionale r2(r);
}
```

Nel codice di sopra l'oggetto ``r2`` sara' creato e inizializzato con i valori di ``r``.
### Com'e' fatto
>Ogni classe puo' avere **un solo copy constructor**.

Questo per definizione e':
- *public*
- prende un unico parametro che e' un oggetto della classe in cui e' definito passato per *constant reference*

### Cosa interessante
Il parametro del copy constructor deve essere **necessariamente** passato per constant reference, questo perche' C++ *under the hood* usa i copy constructor nel passaggio degli oggetti per valore ad una funzione.
Il flusso e' simile al seguente:
- Viene passato un oggetto per valore ad una funzione
- C++ chiama automaticamente il copy constructor di default che crea un nuovo oggetto, locale alla funzione, con gli stessi valori di quello passato
- Quando la funzione termina, lo stack frame(dove era stato messo quell'oggetto) viene poppato dallo stack e quindi viene eliminato, senza intaccare l'oggetto passato come parametro attuale

**Da questo meccanismo dipende il fatto che il parametro formale nella signature del copy constructor sia passato per constant reference invece che per valore. Se fosse passato per valore C++ cercherebbe di richiamare "all'infinito" il copy constructor su se stesso** 

#### Links
[[Copia di oggetti]]