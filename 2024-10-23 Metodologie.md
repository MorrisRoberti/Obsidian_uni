# Gestione delle risorse
L'interazione del software con la risorse deve avvenire tramite queste 3 fasi ordinate
- **acquisizione della risorsa**
- **uso della risorsa**
- **rilascio della risorsa**
### Memoria ad allocazione dinamica
- acquisita in modo diretto o indiretto di *new*
- usata per leggere e scrivere valori mediante dereferenziazione di un puntatore
- rilasciata mediante l'uso diretto o indiretto di *delete*
### Altri esempi di risorse
- descrittori dei **file system** -> acquisiti con l'apertura del file, utilizzati per leggere e/o scrivere su file e infine rilasciati con la chiusura
- i **lock** (condiviso o esclusivo) a risorse condivise -> l'acquisizione dei lock e' necessaria per evitare *race condition* nell'accesso concorrente alle risorse; il mancato rilascio di un lock puo' causare *deadlock* (sistema completamente bloccato) o *starvation* (una parte del programma non ha piu' accesso alle risorse di cui ha bisogno)
- **connessioni** di rete a server etc.

**ATTENZIONE**
Quando si verificano errori (eccezioni) e' necessario tenere conto del fatto che le risorse utilizzate fino a quel punto devono essere *rilasciate*.
```cpp
void foo() {
	int* pi = new int(42);
	do_the_job(pi);
	delete pi;
}
```
se `do_the_job` lancia un'eccezione allora il rilascio di `pi` non avviene e quindi ci troviamo un **memory leak**. Per evitare questi casi vogliamo seguire la pratica metodologica di *exception safety*.
Si puo' tralasciare l'*exception safety* in due casi:
- la risorsa in questione e' poco importante
- il contesto non richiede lo "sforzo" di implementare l'exception safety (magari il programma non e' importante, oppure utilizza poca memoria

**IMPORTANTE**
Se il ciclo di vita di un oggetto e' iniziato, indipendentemente da se siamo in modalita' normale o eccezionale **verra' chiamato il distruttore**


