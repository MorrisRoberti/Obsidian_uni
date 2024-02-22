>Un'interrupt e' una situazione che causa la momentanea sospensione dell'esecuzione del blocco di istruzioni attuale da parte del processore, questo puo' essere il caso di una richiesta **interna** o **esterna**.

Ci sono due tipi di interrupt:
- Internal (*eccezioni*)-> Possono essere ad esempio OPcode non valido, stack overflow, divisioni per 0 e comunque tutti quei casi che dipendono dal *software* (*sincroni*)
- External -> Gli interrupt esterni sono quelli *hardware* e possono provenire da periferiche I/O, es: quando si preme un tasto viene lanciato un interrupt per gestire tale evento (*asincroni*)

### Priorita' degli interrupt
>Se durante la gestione di un interrupt arriva un altro interrupt quello che succede e' che: in base alla priorita' il SO decide quale gestire prima.

Ad esempio l'interrupt *power-fail* e' quello con la priorita' piu' alta in quanto se la corrente salta possono verificarsi problemi gravi, quindi vengono interrotti tutti gli altri interrupt per gestirlo

#### Interessante
>Chi scrive i firmware puo' decidere di *disabilitare* gli interrupt, cioe' fare in modo che nessun altro interrupt possa richiedere risorse, cosi' facendo la CPU puo' dedicarsi completamente alla gestione dell'interrupt corrente.

Al posto di disabilitare l'interrupt molti processori hanno un'istruzione chiamata *lock* che disattiva gli interrupt per esattamente *16 istruzioni macchina*, dopo le quali verra' gestito immediatamente il primo interrupt in coda.

 ==E' opportuno non lasciare gli interrupt non gestiti per troppo tempo altrimenti l'esecuzione potrebbe avere problemi con cio' che e' relativo a quell'interrupt==

### Codici di interrupt
>Per gestire quegli interrupt che si verificano in modo sistematico si usano delle **istruzioni speciali**.Si usa memorizzare le istruzioni per la gestione in un determinato spazio di memoria, molte architetture fanno partire questo spazio di indirizzi da RAM[0]  

#### Links
[[Gestione delle periferiche]]