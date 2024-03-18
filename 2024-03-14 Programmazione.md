### Copy constructor
- quando passiamo un oggetto ad una funzione (per valore) questo viene copiato in un altro oggetto, locale alla funzione chiamata. Questo avviene under the hood tramite il **copy constructor**
- e' un costruttore *public* che prende come unico parametro un oggetto della classe in cui e' definito, passato per constant reference: ``Razionale(const Razionale& r) {}`` (per il discorso di richiamare se stesso quando passa un oggetto ad una funzione per valore)
- La differenza con l'operatore = e' che questo presuppone che l'oggetto in cui copiare i valori sia gia' stato creato, mentre il costruttore di copia **crea e inizializza l'oggetto con i valori dell'altro**
