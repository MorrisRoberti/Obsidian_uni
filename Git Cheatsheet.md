### Che cos'e' Git?
>Git e' un **VCS** (*Version Control System*) cioe' un software che permette di gestire la concorrenza in un progetto.

Bisogna scaricarlo come un qualsiasi software. **Fare attenzione a selezionare LF nelle opzioni per l'EOF altrimenti ogni volta che viene fatto un commit verra' sostituito con  CRLF**

### Che cos'e' GitHub?
>**GitHub** e' un archivio di repository online in cui e' possibile gestire i progetti tramite comandi di **Git**.

Per poter accedere alle funzionalita' di GitHub ci si deve prima registrare.
### Che cos'e' un repository?
>Un **repository** puo' essere visto come una cartella contenente il nostro progetto su *GitHub*.

Un repository locale e' la cartella sul nostro PC che contiene il progetto, al suo interno e' presente un file *.git* che contiene tutte le configurazioni necessarie a farlo rilevare da Git/GitHub.

Un repository puo' essere **pubblico** o **privato**.

Un repository remoto e' "la cartella" corrispettiva al progetto in questione ma su *GitHub*.

I repository hanno una struttura **ad albero**, come nell'esempio qui sotto:
![[Pasted image 20240324221147.png]]
## Principi generali
Ci sono fondamentalmente 2 elementi principali in Git:
- I commit
- I branch
- Staging area
- Snapshot
- Fetch & pull
- Push
- Merge
- Clone

### I commit
>I **commit** sono "gli aggiornamenti" che vengono fatti al codice e caricati su GitHub. Si possono vedere come dei pacchetti contenenti cambiamenti che vengono messi su GitHub.

I commit hanno:
- un messaggio -> breve descrizione dei cambiamenti
- dei file change -> cioe' le vere e proprie modifiche apportate al codice
- un hash -> un codice univoco che permette di identificarli
- un autore
- una data

**Best practice**
I commit devono essere ben descritti e il piu' minimali possibili (per motivi che vedremo in seguito). 

### I branch
>I **branch** sono dei rami di lavoro che permettono di gestire la concorrenza, le implementazioni etc. Sono in buona sostanza dei percorsi alternativi in cui mettere i nostri commit per lavorare in modo asincrono al codice.

**USE CASE**
Voglio creare un nuovo branch quando:
- sto lavorando all'implementazione di una nuova feature
- sto facendo bug fixing
- sto facendo delle modifiche e dei test sul codice prima di distribuirlo in produzione

Esiste un branch speciale chiamato **master** (o **main**) che e' quello contenente la versione corretta, pulita e bella del codice. **NON SI CARICANO MAI AGGIORNAMENTI DIRETTAMENTE SUL BRANCH PRINCIPALE**. **MAI**.  

In tutti questi casi si vuole creare un nuovo branch, poiche' si vuole evitare di andare ad intaccare il master.

### Staging Area
>La **Staging Area** spiegata molto semplicemente e' quello spazio IN LOCALE, in cui noi mettiamo i file che vogliamo caricare su GitHub prima di impacchettarli in un *commit*

Ci possono essere file **tracked** -> sono gia presenti nel repository, se vengono modificati vengono marcati come **modified**
E anche file **untracked** -> sono file nuovi i quali vengono segnalati a git con il comando *add* 

Es:
Ho modificato i file A, B e C ma nel mio pacchetto (commit) voglio mettere solo A e B perche' C non dovra' andare nelle modifiche? Aggiungo solo A e B nella staging area, cosi' quando vado a creare il mio commit verranno presi solo quelli

### Snapshot
>Uno **snapshot** e' una "fotografia" del codice REMOTO in quel momento, si puo' dire che e' il codice aggiornato dopo l'ultimo *commit*

(piu' avanti sara' piu' chiaro)

### Fetch & Pull
>Il **fetch** e' un comando che si occupa di prendere l'ultimo snapshot dal repository remoto e usarlo per aggiornare quello locale.

Facciamo conto che la nostra copia del codice abbia i commit: 1, 2 ,3, 4.
Un altro utente carica un aggiornamento. Per fare in modo di vedere tale aggiornamento noi dobbiamo fare un **fetch**. 
Dopo questa operazione il nostro snapshot verra' aggiornato e potremmo vedere lo stato del codice REMOTO.

**Attenzione** 
Dopo il fetch il nuovo codice non l'abbiamo ancora in locale, abbiamo solo la fotografia aggiornata di cio' che succede su *GitHub*.

Per fare cio' abbiamo bisogno del **PULL**
>Il **pull** e' un comando che, dato l'ultimo snapshot, scarica gli aggiornamenti e li attacca sulla nostra copia locale.

Dopo aver fatto **pull** il nostro codice sara' aggiornato con la copia presente sul branch remoto corrispondente.

### Push
>Il **push** e' il comando che permette di caricare il nostro commit sul repository remoto. Fin quando non facciamo **push** gli aggiornamenti rimarranno in locale.

### Merge
>Il **merge** e' un comando che definisce un'operazione molto delicata e anche la piu' importante, si occupa di unire due o piu' branch in uno solo. Questo se vogliamo e' il punto forte di Git.

Durante il **merge** si potrebbero verificare dei **conflitti**. In sostanza Git rileva due modifiche incompatibili nei due branch da mergiare. Es:
```
Branch 1
modificato A
modificato B

Branch 2
modificato C
eliminato B

il conflitto si genera perche' git non sa se prendere la copia modificata di B o eliminarlo
```

Ai conflitti bisogna stare attenti perche' bisogna poi risolverli a mano (non e' una cosa piacevole, soprattutto quando hai un tot di branch che modificano gli stessi file :) )

### Clone
>Il **clone** serve per scaricare un repository in una cartella locale

Questi sono a grandi linee i concetti base per capire Git, adesso vediamo qualche comando

## Comandi
##### Fetch
``git fetch``
##### Pull
Pull del branch corrente ->``git pull``
Pull di un branch diverso -> ``git pull <nome_branch>``
##### Branch
Nuovo branch -> ``git branch <nome_branch>``
Spostarsi in un branch -> ``git checkout <nome_branch>``
Mostrare una lista di branch -> ``git branch ls --all``
Eliminare un branch (locale) -> ``git branch -d <nome_branch>``
##### Add
Aggiungo tutti i file alla staging area -> ``git add --all``
##### Commit
Creo un commit prendendo tutti i file nella staging area (-a) e aggiungendo il messaggio (-m) -> ``git commit -am 'messaggio'``
##### Push
Push sul branch corrente -> ``git push`` oppure ``git push origin <nome_branch>``
##### Merge
Merge di due branch -> ``git merge <nome_branch> && git push`` (mergia il branch specificato nel branch corrente e fa push perche' il merge e' visto come un commit)
##### Clone
``git clone <nome_repository>``
##### Status
Mostra i file attuali pre-commit -> ``git status``
##### Log
Mostra lo snapshot corrente -> ``git log``
##### Init
Inizializza un nuovo repository locale nella cartella corrente (aggiunge file *.git*) -> ``git init``

AGGIUNGERE CREAZIONE REPO