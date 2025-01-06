>Il modello concettuale piu' utilizzato e' il cosiddetto modello ER che sta per **Entity-Relationship**.

## Entity
>Una **entita'** e' una classe di *oggetti* indipendenti che appartengono alla realta' di interesse e che condividono tra loro alcune proprieta'. Di un'entita' possiamo distinguere lo **schema** che e' appunto il blueprint della classe e la **istanza** che e' un elemento appartenente alla classe.

Solitamente ogni entita' ha un nome univoco e significativo, di solito al singolare.

![[Pasted image 20241117203305.png]]

## Relationships
>Le **relationships** (in italiano *associazioni* NON relazioni) stabiliscono "connessioni" tra due o piu' entita'.

Solitamente, come per le entita' si scelgono nomi singolari, univoci e significativi.

![[Pasted image 20241117203434.png]]

![[Pasted image 20241117203605.png]]

### Tipi di associazioni
**Binaria**
>L'associazione **binaria** e' un tipo di associazione che coinvolge due istanze, una per ogni entita' considerata.

**n-aria**
>Diversamente un'associazione **n-aria** e' una tupla di istanze di entita', una per ogni entita' coinvolta.

**IMPORTANTE**
>Non possono esserci coppie di tuple ripetute nella stessa relazione.

 **Due associazioni diverse per le stesse due entita'**
![[Pasted image 20241117233837.png]]

**Associazioni ricorsive**
![[Pasted image 20241117233911.png]]

**Associazioni con nomi di ruoli**
![[Pasted image 20241117233943.png]]

### Promuovere le associazioni a entita'
>L'associazione *Exam* non cattura il requisito di "uno studente puo' provare a fare l'esame per lo stesso corso piu' di una volta".

![[Pasted image 20241117204253.png]]

La soluzione e' rendere *Exam* un'entita', connessa alle altre da due associazioni.

![[Pasted image 20241117204323.png]]

## Attributi
>Un **attributo** e' una *proprieta'* che appartiene  alla propria entita' o associazione. Un insieme di attributi su una relazione e' chiamato **dominio**.

Si rappresentano visivamente nel seguente modo
![[Pasted image 20241117234218.png]]

### Attributi composti
>Gli **attributi composti** raggruppano attributi che hanno dei punti comuni, della stessa entita' o associazione. Un esempio lampante e' l'indirizzo: strada, numero civico e cap compongono il campo indirizzo.

Si rappresentano graficamente nel seguente modo
![[Pasted image 20241117234404.png]]

## Altri costrutti del modello ER
### Cardinalita'
>La **cardinalita'** e' una coppia di valori collegata ad ogni entita' *coinvolta in un'associazione*, specifica il *numero massimo e minimo di occorrenze delle entita' coinvolte nell'associazione*.

![[Pasted image 20241117234610.png]]

Un'*Employee* ha almeno 1 *Job* e al massimo 5, mentre un *Job* puo' essere assegnato a nessuno o al massimo a 50 *Employee*.

Convenzionalmente si usano i seguenti:
- 0 -> *opzionale*
- 1 -> *obbligatorio*
- 1-N -> dove N e' la massima cardinalita'

### Tipi di associazione
>In base alla cardinalita' possiamo definire 3 tipi di associazione: *One-to-One*, *One-to-Many* e *Many-to-Many*.

### Cardinalita' degli attributi
>E' possibile definire una **cardinalita' degli attributi** con due scopi: indicarne l'opzionalita' o creare attributi multivalore.

Si rappresentano graficamente nel seguente modo

![[Pasted image 20241117235145.png]]

## Identificatori di Entita'
>Un **identificatore** e' un modo univoco per identificare le occorrenze di un'entita'. Puo' essere *interno* e quindi composto dagli attributi dell'entita' o *esterno* quindi attributi dell'entita' + entita' esterne raggiungibili attraverso associazioni.

![[Pasted image 20241118100409.png]]

L'attributo *Plate* e' l'identificatore interno per *Car* perche' non ci sono 2 macchine con la stessa targa.

Gli identificatori interni possono essere composti da piu' attributi.

![[Pasted image 20241118100534.png]]

Come specificato sopra, gli identificatori di entita' possono essere anche esterni.
Nell'immagine sotto, l'attributo *Number* e l'entita' *University* formano l'identificatore esterno perche' potrebbero esserci degli studenti con lo stesso *Number* ma appartenenti a *University* diverse.

![[Pasted image 20241118100752.png]]

### Note a margine
- Ogni entita' deve avere almeno un identificatore ma puo' generalmente averne piu' di uno
- Un'identificazione esterna e' possibile solo attraverso un'associazione in cui l'identita' da essere trovata partecipa con una cardinalita' (1,1)
- Perche' le associazioni non hanno identificatori? E' meglio associare identificatori alle entita' che alle associazioni

#### Links
[[Database Design]]
[[Entity-Relationship Model pt.2]]