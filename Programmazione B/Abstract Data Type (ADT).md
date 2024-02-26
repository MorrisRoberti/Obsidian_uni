>Per *Abstract Data Type (ADT)* si intende un'insieme di valori e tutte e sole le operazioni possibili definite per quell'insieme di valori.


Prendiamo per esempio il tipo di dato ``int``.

| Valori | Operazioni |
| ---- | ---- |
| Tutti gli interi rappresentabili su una macchina (4 bytes) | +, -, *, etc. |
### In che senso tipo di dato astratto?
Un tipo di dato si dice astratto quando e' possibile utilizzare **esclusivamente** i valori e le operazioni consentite e **non e' possibile accedere ad altri dettagli implementativi**
es.
```
struct Data {
	int day;
	int month;
	int year;
};

int main() {
	Data today = {01, 01, 1970};
	today.month = 02;
}
```
Come si vede, possiamo accedere alla proprieta' *month* e modificarne il valore, nei tipi di dati astratti questo non e' possibile.

Si ha necessita' di questi perche' ci consentono di rendere il codice meno soggetto ad errori del tipo:
- Se nell'esempio sopra modificassi *day* in *d* , il codice andrebbe cambiato in ogni punto nel quale si fa accesso al campo day
- Ad esempio 40 non e' un valore corretto per il campo day, ma nell'esempio io non ho modo di controllare se il valore inserito dall'utente e' valido o men