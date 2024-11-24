- Vogliamo fare la progettazione *concettuale* di una base di dati, cioe' vogliamo effettuare i seguenti compiti:
	- *Raccolta* dei requisiti
	- *Analisi* dei requisiti
	- Costruzione dello *schema concettuale*
	- Costruzione del *glossario*
#### Raccolta e Analisi dei requisiti
>La **raccolta dei requisiti** puo' essere effettuata parlando con il cliente e cercando di interpretare le sue esigenze. Successivamente, durante il processo di **analisi dei requisiti** questi vengono *rifiniti*.

In generale ci si vuole calare nella realta' del cliente e nei diversi *ruoli* per capire al meglio i casi d'uso e i punti essenziali.

##### Regole generali e consigli
- Scegliere il giusto livello di astrazione -> solitamente le persone nel management non hanno una visione tecnica dell'azienda, quindi scendere in dettagli potrebbe essere poco interessante per capire il loro caso d'uso
- Distinguere tra frasi di *dati* e frasi *funzionali*
- Creare un **glossario di termini** in modo da unificare i concetti con dei sinonimi significativi
- Ordinare le frasi per concetti

#### Creazione dello schema concettuale & Costruzione del glossario
>La **costruzione di un glossario** e' fondamentale, in quanto ci permette di identificare le componenti chiave del nostro modello e quindi scegliere il costrutto ER adatto per questo. In piu' possiamo piu' facilmente modellare i *concetti* generali che ci aiutano quando dobbiamo calarci nella realta' di riferimento.

## Design Patterns
### Reificazione degli attributi
>Quando ci accorgiamo di avere in un'entita' un attributo che in realta' e' un concetto a se stante, lo stacchiamo, rendendolo un'entita' a parte e creiamo un'associazione tra questa e quella che precedentemente la conteneva. Questa e' chiamata **reificazione degli attributi**.

![[Pasted image 20241124172942.png]]

### Part-of
>Le associazioni (1-N) possono rappresentare **associazioni part-of**. Cioe' *composizioni* o *aggregazioni*.

![[Pasted image 20241124173219.png]]

### Instance-of
>Talvolta c'e' bisogno di *due* entita' per rappresentare un concetto singolo: una *astratta* che contiene la rappresentazione e una che contiene *le informazioni concrete* di quell'istanza.

Un esempio potrebbe essere la modellazione del concetto di "Insegnamento accademico" in cui abbiamo *Course* che contiene la **struttura** dell'insegnamento, quindi *Nome, Durata, CFU, etc.* e *Edition* che contiene **informazioni** relative ad una specifica istanza del corso come *Insegnante, Anno Accademico, Modalita' Insegnamento*.

![[Pasted image 20241124173716.png]]

### Reificazione di associazioni binarie
>Quando abbiamo delle *associazioni binarie N-N* possiamo **reificare** l'associazione e promuoverla a *entita'* e quindi possiamo definire due nuove associazioni 1-N tra le vecchie entita' e l'associazione reificata.

![[Pasted image 20241124174137.png]]

### Reificazione di associazioni ricorsive
>Il discorso della *reificazione delle associazioni binarie* vale anche per le associazioni ricorsive.

![[Pasted image 20241124174428.png]]

### Casi specifici
>Un pattern usato frequentemente e' la **generalizzazione** di *concetti specifici*. Questo pattern funziona bene o male come l'ereditarieta' dei linguaggi di programmazione ad oggetti, quindi abbiamo un'entita' "parent" che e' una versione astratta di un'altra entita' "child" che, oltre ad avere gli attributi di parent ne ha anche di suoi.

![[Pasted image 20241124174705.png]]

### Storicizzazione di un concetto
>Capita frequentemente che in un database si voglia tenere lo storico di una qualche informazione: dipendenti che hanno lavorato ad un progetto, task di progetti che sono stati effettuati etc. Quindi si sfrutta il pattern di **storicizzazione**.

![[Pasted image 20241124174901.png]]

Quello che si fa e' prendere un concetto *generalizzato* e fornire due *entita' specifiche*: una riguardante l'informazione **attuale** e una riguardante **lo storico**.

![[Pasted image 20241124175328.png]]

### Estendere un concetto
>La *generalizzazione* puo' essere utilizzata per estendere un concetto **gia' presente nel database** rendendo questo generico e inserendo un'altra entita' che definisca il caso specifico.

![[Pasted image 20241124175437.png]]

## Strategie
>Vogliamo definire delle strategie per mappare i requisiti in istanze di uno schema ER, attualmente possiamo stabilirne 3: **Top-Down**, **Bottom-Up** e **Inside-Out**.

Solitamente si tende ad usare un approccio misto:
- Si crea uno sketch con le entita' piu' importanti
- Si scompone lo schema 
- Si va a rifinire (top-down), integrare (bottom-up) e espandere (inside-out)

#### Top-Down
>La strategia **Top-Down** prevede di partire dal quadro della situazione e man mano, tramite degli sketch, scendere verso i requisiti concreti. Quindi si **inizia nel generale** e si **scende nel dettaglio**.

Ad esempio partiamo dalle *frasi*, poi estrapoliamo i *termini* ricorrenti piu' importanti e da questi definiamo le *entita'* e successivamente aggiungiamo gli attributi. 

Oppure se dobbiamo fare una generalizzazione, definiamo prima *l'entita' generale* e poi *quelle specifiche*.

### Bottom-Up
>La strategia **Bottom-Up** parte dai requisiti singoli, li sviluppa e poi li combina nello schema finale. Quindi si **inizia dal dettaglio** e si **sale nel generale**.

![[Pasted image 20241124180324.png]]

Ad esempio se dobbiamo definire una generalizzazione, prima stabilitamo *tutte le entita'* e poi definiamo quale di queste e' *l'entita' generica* e quali *quelle specifiche*.

### Inside-Out
>La strategia **Inside-Out** parte dal nucleo della progettazione, quindi le parti piu' importanti (*Inside*) e man mano va a definire le parti accessorie (*Out*).

## Best practices
- **Analisi dei requisiti**
	- Si analizzano i requisiti e si risolvono le ambiguita'
	- Si crea un glossario
	- Si raccolgono i requisiti in frasi simili
- **Caso base**
	- Definire uno sketch generico di uno schema con i concetti piu' importanti
- **Passo Iterativo**
	- Raffina i concetti base utilizzando i requisiti
	- Aggiungi concetti per descrivere requisiti non completamente espressi
- **Analisi di qualita'**
	- *Correttezza*
	- *Completezza*
	- *Chiarezza*
	- *Minimalismo*

#### Links
[[Database Design]]
[[Entity-Relationship Model]]
[[Entity-Relationship Model pt.2]]