>La classe *string* e' una classe che implementa l'oggetto stringa con tutti vantaggi della OOP. Gli oggetti della classe sono composti da due attributi: dimensione e array di caratteri.

Le stringhe della classe string C++ sono delimitate da doppi apici e sono **oggetti immutabili**

### Possibile implementazione

```cpp
class String {
private: 
	int dim;
	char* s;
};
```
- ``dim`` -> e' la dimensione della stringa
- ``s`` -> e' la struttura dati concreta per la stringa (array di caratteri)

Dato che la struttura sottostante e' un array di caratteri, la classe mantiene le proprieta' degli array come l'accesso diretto, pertanto e' valido:
```
String s = "hello";
s[0] = 't';
cout << s << endl; // "tello"
```
### Come si crea un oggetto string
```cpp
int main() {
	String s;
	// oppure
	String t = "hello";
}
```

### Alcuni metodi utili
- ``string.size()`` -> metodo *const* che restituisce la lunghezza della stringa
- ``string.substr(pos, count)`` -> restituisce una sottostringa della stringa data dove *pos* e' la posizione in cui inizia la sottostringa e *count* e' il numero di caratteri a prendere a partire da *pos*
- ``string.find(string, pos)`` -> cerca la stringa passata in quella che chiama il metodo a partire dalla posizione *pos*
- ``string.getline(f, s, d)`` -> legge i caratteri dallo stream di input *f* uno dopo l'altro memorizzandoli nella stringa *s* finche' non raggiunge un carattere *d
- ``string.c_str()`` -> prende l'oggetto chiamante e restituisce l'equivalente sotto forma di stringa C-Style

Valgono gli operatori definiti sotto:
- ``s + t`` -> concatenazione stringhe
- ``s + 'h'`` -> concatenazione stringa con carattere
- ``s + "hello"`` -> concatenazione stringa con stringa fissa