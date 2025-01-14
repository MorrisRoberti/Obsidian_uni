>Una gestione corretta delle risorse e' tutto sommato semplice da ottenere in condizioni "di successo", ma tende a complicarsi non appena si ammetta la possibilita' che qualcosa possa andare storto, ovvero quando alcune operazioni possono generare errori che non vengono poi gestiti.

Nel C++ la tecnica idiomatica per segnalare situazioni di errore e' quella di **lanciare eccezioni** uscendo dal flusso normale del programma ed entrando nei cosiddetti *flussi di esecuzione eccezionali*. Una volta lanciata un'eccezione, questa si propaga lungo la catena delle chiamate e l'unico modo di rientrare nel flusso di esecuzione normale e' di **catturare l'eccezione** in un blocco *catch* e gestirla.

Vediamo come si usa **l'exception safety**
```cpp
void foo() {
	int* pi = new int(42);
	do_the_job(pi);
	delete pi;
}
```

Il codice sopra, in condizioni normali non ha problemi, tuttavia non e' **exception safe** -> se la funzione `do_the_job` o una qualunque delle funzioni invocate da questa, lancia un'eccezione che non viene gestita internamente, il flusso di esecuzione in uscita dalla chiamata e' un flusso eccezionale che *NON* segue l'istruzione `delete pi`.
Quindi si uscirebbe dall'esecuzione di `foo` in modalita' eccezionale senza aver rilasciato la risorsa, ottenendo un **memory leak**.

## Livelli di Exception Safety
Esistono 3 livelli di *exception safety*: base, forte e nothrow. Il livello base e' il meno restrittivo mentre il nothrow e' il piu' restrittivo, cioe' fornisce maggiori garanzie di sicurezza.

#### 1) Livello Base
>Una porzione di codice si dice *exception safe* a **livello base** se, anche nel caso in cui si verifichino delle eccezioni durante la sua esecuzione rispetti le tre regole:

1. Non si hanno **memory leak**
2. Si e' *neutrali* rispetto alle eccezioni
3. **Preservazione delle invarianti**: anche in caso di uscita dalla modalita' eccezionale, gli oggetti sui quali si stava lavorando possono essere distrutti senza causare comportamenti non definiti
4. E' possibile la presenza di *side effect*


Il punto **1** e' auto esplicativo.
Il punto **2** dice che una eventuale **segnalazione di errore tramite eccezione** deve essere **propagata al chiamante**, che cosi' potra' prenderne atto ed eseguire a sua volta le eventuali azioni correttive necessarie.
Il punto **3** afferma che **lo stato interno di un oggetto**, pur se parzialmente inconsistente, **deve comunque consentirne la corretta distruzione** (o il riassegnamento con un oggetto consistente), cioe' se un oggetto e' costruito parzialmente (quindi ha dei sotto-oggetti come dati membro o ereditati), le parti costruite dovranno essere distrutte con successo.
Il punto **4** dice che, **l'oggetto viene posto in uno stato interno accettabile ma che tuttavia non si assicura che il valore rimanga invariato**.

#### 2) Livello Forte
>Il **livello forte** di *exception safety* si ottiene quando, oltre a tutte le garanzie fornite a livello base, si aggiunge una sorta di *atomicita'* delle operazioni. Intuitivamente l'invocazione di una funzione exception safe forte, garantisce, *in caso di eccezione*, che lo stato degli oggetti manipolati sia rimasto inalterato.

Esempio:
*Supponiamo di avere una classe che implementa una certa operazione `insert` su una collezione ordinata di elementi, se si verifica un'eccezione all'interno della funzione e questa implementa l'exception safety forte, cio' che succede e' che la collezione, alla fine del flusso eccezionale, si trovera' esattamente nello stesso stato in cui si trovava prima dell'eccezione*

#### 3) Livello Nothrow
>E' il massimo livello di *exception safety*: una funzione e' **nothrow** se la sua esecuzione e' garantita non terminare in modalita' eccezionale, cioe' quando, *anche se dovesse verificarsi una situazione eccezionale* questa verra' gestita interamente all'interno e sara' trasparente all'utente che quindi non dovra' occuparsi di gestirla.

Tale livello viene raggiunto in un numero limitato di casi:
- Quando l'operazione e' cosi' semplice da garantire l'assenza di eccezioni (es. operazioni su tipi built-in)
- Quando la funzione e' in grado di gestire completamente al suo interno eventuali eccezioni
- Quando la funzione di fronte ad eventuali eccezioni interne, di fronte all'impossibilita' di risolvere tali eccezioni, determina l'azione di terminazione del programma; questo e' il caso delle funzioni che sono dichiarate implicitamente o esplicitamente **noexcept**, come **i distruttori**

**IMPORTANTE**
>Il livello *nothrow* non e' immune alle eccezioni ma ci dice soltanto che in caso dovessero essercene, l'utente non ne sara' affetto.

## Libreria standard e exception safety
>I contenitori (vector, queue, list, map, etc.) forniti dalla libreria standard sono exception safe. Chiaramente una tale affermazione vale sotto determinate condizioni.

Le condizioni di cui si parla sopra sono relative al fatto che tali classi siano templatiche, quindi le garanzie di exception safety del contenitore sono valide a condizione che il tipo di dato T fornisca analoghe garanzie.

Molte (*ma non tutte*) le operazioni su questi contenitori forniscono la garanzia forte (*strong exception safety*), tuttavia per alcune operazioni, fornire la garanzia forte e' troppo costoso, quindi si fornisce la garanzia di base. Tipicamente questo succede quando una operazione opera su molti elementi contemporaneamente.


**ATTENZIONE**
>Esistono contesti in cui e' perfettamente accettabile scrivere codice *non exception safe* ovvero che non gestisce correttamente le risorse in presenza di comportamenti eccezionali, ad esempio quando:

- la risorsa in questione e' poco importante
- la correttezza del software (nei casi in cui si presenta un comportamento eccezionale) e' di scarso interesse

#### Links
[[Approcci per gestire le risorse]]