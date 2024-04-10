>In Java, come gia' accennato non esistono i puntatori, per cui la gestione della memoria dinamica non e' a carico del programmatore, ma di un programma della JVM chiamato **garbage collector**.

Un oggetto viene "classificato" come **garbage** nel momento in cui non e' referenziato da nessuna reference

### Pro
- Non a carico del programmatore
- Non e' possibile che ci sia garbage alla fine dell'esecuzione
### Contro
- Il programmatore non ha pieno controllo sulla memoria
- L'attivita' del garbage collector puo' rallentare l'esecuzione del programma

#### Links