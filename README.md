**Guida all'uso per archivio condiviso facolta' di Informatica UniPr**
Il repository e' fatto per aiutare nello studio tutti gli studenti di Informatica e raccoglie appunti personali, risorse, spiegazioni e altro.

E' possibile contribuire al progetto (seguendo le linee guida riportate in [[#Contribute]]]).

==Il progetto deve essere importato su Obsidian per funzionare al 100%==
## Scaricare il progetto
**Prerequisiti**: Git, Obsidian.

Vengono riportati sotto i passi per scaricare il progetto:
1. Scaricare il progetto in locale, posizionandosi in una directory ed eseguendo il comando: 
	`git clone https://github.com/MorrisRoberti/Obsidian_uni`
2. Allinearsi sul branch master eseguendo i comandi:
	```
	git fetch
	git checkout master
	git pull
	``` ^f0eb2c
3. Infine aprire **Obsidian** e aprire come vault la cartella in cui e' stato scaricato il progetto

==Il repository e' in continuo aggiornamento quindi si consiglia di ripetere il punto [[#^f0eb2c]] per tenere il progetto aggiornato in locale==
## Struttura docs
La documentazione e' strutturata nel seguente modo: 
- Ogni materia ha una cartella (al momento c'e' solo *Architettura degli elaboratori*)
- All'interno della cartella della materia ci sono i *file* che sono effettivamente gli *argomenti*
	- I titoli si indicano con '##' 
	- Le descrizioni con '>' 
	- Alla fine del file si trova sempre un paragrafo **Links** identificato da '####' che indica i collegamenti inter-argomento (*collegamenti figli*)
- Per ogni materia e' presente un canvas chiamato *Syllabus* nel quale andranno inserite le relazioni tra i vari argomenti:
	- **Gruppi** -> identificano i *macroargomenti*
	- **Card** -> identificano i singoli *argomenti
	- **Frecce** -> collegamenti *inter-argomento* (partono dall'argomento padre e puntano al figlio)
	- **Colori**: 
		- Grigio -> *da fare*
		- Giallo -> *in corso*
		- Verde -> *completato*
- Per ogni materia e' presente una cartella *IMGs* nella quale andranno messe tutte le immagini utilizzate nei file
- Per ogni materia e' presente una cartella *Resources* nella quale sono inseriti materiali complementari (libri, slide, video etc.)

**Best practice**:
>Si consiglia di tenere i file il piu' minimali possibile e si incentiva piuttosto la creazione di nuovi file in modo da separarli ed avere un archivio il piu' atomico e interconnesso possibile
## Contribute
>Sono altamente apprezzate aggiunte, modifiche, miglioramenti ad opera di chiunque voglia contribuire ad espandere l'archivio.

Per mantenere ordine e tenere traccia delle modifiche, le contribuzioni sono soggette ad un *Approval Process* (attualmente fatto da me).

Il processo per contribuire e' il seguente:
1. Mettersi in pari con il branch `master`
2. Creare un nuovo branch con un nome significativo
3. Creare una nuova *Pull Request*
4. Inserire `Morris Roberti` come reviewer
5. Fornire nei commenti una descrizione di cio' che e' stato aggiunto/modificato e il perche'
6. Dal momento che la *PR* viene accettata e mergiata il branch viene eliminato

==E' VIETATO FARE PUSH DIRETTAMENTE SUL BRANCH MASTER== 

E' possibile proporre modifiche di qualsiasi tipo aprendo un *Issue* e selezionando il tipo di contributo tramite label:
- *Modifica* -> richiesta di correzione di errori etc.
- *Aggiunta* -> nuovi materiali, risorse, immagini, file, cartelle etc.
- *Eliminazione* -> richiesta di eliminazione di materiale errato, inattinente, ridondante
- *Modifica Strutturale* -> richiesta modifica alla struttura del progetto, delle cartelle, dei canvas, di questo doc etc.
- *Modifica Procedurale* -> richiesta di modifica delle procedure *Approval Process* etc.
- *Domande* -> domande agli altri contributors sugli argomenti es: 'Non capisco il ciclo FDE', fatto in modo che altri possano rispondere e si tenga traccia di tutte le domande gia fatte