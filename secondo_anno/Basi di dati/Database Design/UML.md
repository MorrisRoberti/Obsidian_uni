>I *linguaggi di modellazione* permettono la specificazione, la visualizzazione e la documentazione dello sviluppo di un sistema software. I *modelli* sono descrizioni che gli utenti e gli sviluppatori possono utilizzare per comunicare idee sul software. **UML** e' l'acronimo di *Unified Modeling Language* ed e' uno dei linguaggi di modellazione piu' usati. 

distinguiamo 2 versioni di UML:
- UML 1.* -> semplice linguaggio di modellazione
- UML 2.* -> comunque un linguaggio di modellazione ma cosi' dettagliato che puo' essere utilizzato come un linguaggio di programmazione

## Modellare dati con UML2
>UML2 puo' essere utilizzato in sostituzione ai [[Entity-Relationship Model|diagrammi ER]] per la modellazione dei dati. In UML si utilizzano i **diagrammi di classe**.

**Le classi**

![[Pasted image 20241118180008.png]]

**Le associazioni** 

![[Pasted image 20241118180037.png]]

**Associazioni come classi**

![[Pasted image 20241118180108.png]]

**Associazioni ternarie**

![[Pasted image 20241118180308.png]]

**Reificazione delle associazioni**
>Le associazioni N-arie non sono cosi' frequenti, quindi e' necessario che queste vengano trasformate in una singola classe collegata alle classi originali attraverso una relazione binaria.

![[Pasted image 20241118180448.png]]

### Aggregazione e composizione
>Sotto si ha un esempio di **aggregazione** in cui un *Technician* *appartiene* ad un *Team*. Il *Technician* puo' essere rappresentato indipendentemente dal *Team* al quale appartiene.

![[Pasted image 20241118181340.png]]

>Qui invece si ha un esempio di **composizione**. Una *Agency* appartiene ad una *Firm*, tale entita' NON PUO' essere rappresentata indipendentemente dalla *Firm*.

![[Pasted image 20241118181617.png]]

### Cardinalita' delle associazioni
>Un *Order* ha un numero di *Bill* compreso tra 0 e 1. Dall'altro lato un *Bill* ha solo 1 *Order*.

![[Pasted image 20241118181828.png]]

>Nessuna molteplicita' sta per 1 a 1, quindi una *Person* puo' essere residente in solo una *City*. Dall'altro lato, una *City* puo' avere diverse *Person*. 

![[Pasted image 20241118181949.png]]

>Un *Tourist* puo' prenotare da 1 a N hotel. Dall'altro lato *Hotel* puo' essere prenotato da 0 fino a N *Tourists*.

![[Pasted image 20241118182041.png]]

## Identificatori

![[Pasted image 20241118182108.png]]

## Identificatori esterni

![[Pasted image 20241118182129.png]]

>La scritta *identifying* specifica che l'associazione tra *Student* e *University* insieme al *Number{id}* identifica esattamente uno studente.

## Generalizzazione

![[Pasted image 20241118182358.png]]

#### Links
[[Database Design]]
[[Entity-Relationship Model]]
[[Entity-Relationship Model pt.2]]
