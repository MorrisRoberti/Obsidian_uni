>Le **viste** sono delle *relazioni derivate*, solitamente risultanti dall'esecuzione di query e servono generalmente per due cose: mostrare all'utente solo i dati che lo interessano o comunque di sua competenza e immagazzinare dei dati che si vogliono richiedere frequentemente ma che non fanno parte dello schema originale.

Esistono due tipi di viste
### Viste materializzate
>Una **vista materializzata** e' una vista che e' immagazzinata in modo permanente e fisicamente nel database. I pro sono dati dal fatto che i dati della vista sono velocemente accessibili, i contro sono dati dalla lentezza delle operazioni di aggiornamento e dalla ridondanza del dato

### Viste virtuali
>Una **vista virtuale** e' una vista che in realta' e' generata da una query, quindi e' facilmente riutilizzabile in altre query come se fosse una tabella.

#### Links
[[Database & DBMS]]