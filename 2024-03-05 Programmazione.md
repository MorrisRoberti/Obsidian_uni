### Le stringhe
- sono sequenze di 0 o *n* caratteri
- Il problema delle stringhe C-style e' il fatto che non ci sia information hiding (per lavorare con le stringhe devo necessariamente conoscere l'implementazione)
- ``string s;`` -> invoca il costruttore senza parametri
- ``string t = "Hello";`` -> invoca il costruttore con 1 parametro di tipo *const char* *
- ``string r(s);`` -> prende come parametro un dato di tipo string (costruttore di copia)
- ``string g(10, '+');`` -> costruttore con due parametri, un intero e un carattere (conterra 10 volte +)
- ``string.size()`` -> metodo const che restituisce il valore della lunghezza della stringa