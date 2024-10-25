
### Soluzione naive
- Quando si vogliono gestire gli errori, talvolta si vuole solo segnalarli, senza "fare rumore" cioe' senza interrompere il programma
```cpp
bool codice_utente() {
Risorsa* r1 = new acquisisci_risorsa();
if (r1 == nullptr) {
	// log di errore durante l'acquisizione di r1: non devo rilasciare la risorsa
	return true;
}

}
```
- la restituzione della risorsa PUO' fallire ma non dipende da noi e non possiamo farci niente
- solitamente si rilasciano le risorse in modo inverso rispetto a come sono state acquisite

### Try-catch (eccezioni)

- Il modo **convenzionale** per gestire gli errori e' utilizzando le eccezioni
```cpp
struct 

Risorsa* acquisisci_risorsa_exc() {

}

void usa_risorse_exc(Risorsa* r1 ,Risorsa* r2) {
	if(usa_risorse(r1, r2)){
		throw error;
	}
}
```
- Possiamo acquisire le risorse anche fuori dal blocco *try-catch* poiche' se l'acquisizione fallisce non acquisisco memoria e quindi non devo rilasciarla, se c'e' un errore semplicemente restituisco il controllo al chiamante
- vogliamo un blocco try che "protegga" la risorsa i-esima quando viene usata (quindi dopo l'acquisizione), se viene lanciato un errore, nel blocco catch viene rilasciata la risorsa
- La cosa importante dal punto di vista di chi implementa non e' gestire l'errore ma *proteggere le risorse*
- Quando usiamo try-catch vogliamo restituire la risorsa *sia nel flusso di esecuzione normale che nel flusso eccezionale*

#### Osservazioni
1. Si crea un blocco try-catch per ogni singola **risorsa acquisita** 
2. Il blocco si apre *subito dopo* l'acquisizione della risorsa (se l'acquisizione fallisce, non c'e' nulla da rilasciare)
3. La responsabilita' del blocco try-catch e' di proteggere *quella* singola risorsa
4.  Al termine del blocco try (prima del catch) va effettuata la "normale" restrizione della risorsa (caso NON eccezionale)
5. La clausola *catch* usa "..." per catturare qualunque eccezione: non ci interessa l'errore, vogliamo solo rilasciare la risorsa
6. Nella clausola catch, dobbiamo fare due operazioni:
	- rilasciare la risorsa protetta
	- rilanciare l'eccezione catturata restituendo il controllo al chiamante (throw)

### RAII-RRID 
>Il metodo RAII-RRID (o solo RAII) e' quello **idiomatico** sfrutta il fatto che i **distruttori** vengono invocati indipendentemente dal flusso di esecuzione in cui si trovano.

- **RAII** -> Resource Acquisition is Initialization
- **RRID** -> Resource Release Is Destruction

Quindi quello che si vuole fare e' costruire una classe che crea l'oggetto e nella sua creazione acquisisce la risorsa e quando l'oggetto viene distrutto rilascia la risorsa

```cpp
class Gestore_Risorsa {
		private: 
			Risorsa* res_ptr;
		public: 
			// Costruttore che acquisisce la risorsa: RAII
			Gestore_Risorsa : res_ptr(acquisisci_risorsa_exc()) {}

			// Distruttore che rilascia la risorsa: RRID
			~Gestore_Risorsa {
				restituisci_risorsa(res_ptr);
			}

			// Disabilitazione delle copie
			Gestore_Risorsa(const Gestore_Risorsa&) = delete;
			Gestore_Risorsa& operator=(const Gestore_Risorsa&) = delete;

			// Costruzione per spostamento
			Gestore_Risorsa(Gestore_Risorsa&& y) : res_ptr(y.res_ptr) {
					y.res_ptr = nullptr;
			}

			// Assegnamento per spostamento
			Gestore_Risorsa& operator=(Gestore_Risorsa&& y) {
				restituisci_risorsa(res_ptr);
				res_ptr = y.res_ptr;
				y.res_ptr = nullptr;
				return *this;
			}

			// Accessori per l'uso
			const Risorsa* get() const {return res_ptr;}
			Risorsa* get() { return res_ptr; }
};
```
**ATTENZIONE**
>E' vero che per ogni risorsa si deve scrivere il gestore, ma ogni volta che poi la risorsa viene utilizzata noi sappiamo che non dobbiamo preoccuparci della gestione.

**IMPORTANTE**
>Vogliamo che gli oggetti "gestori" vengano **allocati automaticamente** proprio perche' vogliamo che questi vengano deallocati in modo automatico rilasciando le risorse.

```cpp
void codice_utente() {
	Gestore_Risorsa r1;
	usa_risorsa_exc(r1.get());
	{
		Gestore_Risorsa r2;
		usa_risorse_exc(r1.get(), r2.get())
	}
	Gestore_Risorsa r3;
	usa_risorse_exc(r1.get(), r3.get());
}
```
- Le linee `5-6` vengono messe in un blocco, perche' in questo modo la distruzione di `r2` avviene *prima* della creazione di `r3` 

## Exception Safety
