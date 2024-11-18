>Quando si progetta un database solitamente si usano 3 fasi: progettazione dello *schema concettuale*, progettazione dello *schema logico* e progettazione dello *schema fisico*.

Prima di tutto vogliamo definire alcuni concetti.
### Datamodel
>Il **datamodel** e' una collezione di componenti utilizzata per categorizzare dati importanti e descriverne le relative operazioni. L'elemento principale dei datamodel e' il **costruttore** che, nel caso del *modello relazionale* come nelle definizioni di tipo dei linguaggi di programmazione, crea insiemi uniformi di tuple.

### Schema & instances
>Per ogni database abbiamo:
- **Database schema** -> non cambia nel tempo e descrive la struttura dei dati (aspetto *intensivo*)
- **Istanza** -> gli effettivi valori che possono cambiare (aspetto *estensivo*)

Ora, abbiamo due modelli principali: **logico** e **concettuale**.

## Modello logico
>Il **modello logico** e' quello che organizza i dati all'interno del DBMS. E' indipendente dallo strato fisico.

## Modello concettuale
>Il **modello concettuale** e' quello che cerca di descrivere aspetti del mondo reale, e' utilizzato maggiormente nelle fasi preliminari di *software design* e permette una rappresentazione di dati indipendente dal sistema. Il *modello concettuale* piu' comune e' il modello **Entity-Relationship** (ER).

In buona sostanza e' un modo visivo per descrivere le entita' che entrano in gioco nel software e le loro relazioni in modo informale e indipendente dall'implementazione.

## Fasi del design
![[Pasted image 20241117202828.png]]

#### Links
[[Entity-Relationship Model]]