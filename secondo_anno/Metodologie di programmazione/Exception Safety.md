>Una gestione corretta delle risorse e' tutto sommato semplice da ottenere in condizioni "di successo", ma tende a complicarsi non appena si ammetta la possibilita' che qualcosa possa andare storto, ovvero quando alcune operazioni possono generare errori che non vengono poi gestiti.

Nel C++ la tecnica idiomatica per segnalare situazioni di errore e' quella di **lanciare eccezioni** uscendo dal flusso normale del programma ed entrando nei cosidetti *flussi di esecuzione eccezionali*. Una volta lanciata un'eccezione, questa si propaga lungo la catena delle chiamate e l'unico modo di rientrare nel flusso di esecuzione normale e' di **catturare l'eccezione** in un blocco *catch* e gestirla.

Vediamo come si usa **l'exception safety**
```cpp
void foo() {
	int* pi = new int(42);
	do_the_job(pi);
	delete pi;
}
```

Il codice sopra, in condizioni normali non ha problemi, tuttavia non e' **exception safe** -> se la funzione `do_the_job` o una qualunque delle funzioni invocate da questa, lancia un'eccezione che non viene gestita internamente, il flusso di esecuzione in uscita dalla chiamata e' un flusso eccezionale che *NON* segue l'istruzione *delete pi*.
Quindi si uscirebbe dall'esecuzione di `foo` in modalita' eccezionale senza aver rilasciato la risorsa, ottenendo un **memory leak**.

**ATTENZIONE**
>Esistono contesti in cui e' perfettamente accettabile scrivere codice *non exception safe* ovvero che non gestisce correttamente le risorse in presenza di comportamenti eccezionali, ad esempio quando:

- la risorsa in questione e' poco importante
- la correttezza del software (nei casi in cui si presenta un comportamento eccezionale) e' di scarso interesse

#### Links
