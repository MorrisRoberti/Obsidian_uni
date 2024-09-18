### Incapsulamento
>*L'incapsulamento* e' un principio che dice che tutti i metodi e gli attributi che operano su una certa entita' devono essere racchiusi un un'unita' unica.

L'incapsulamento nella OOP aiuta a rendere le classi piu' consistenti e quindi ad avere codice piu' manutenibile, comprensibile e meno *error-prone*.

### Information Hiding
>*L'information hiding* e' un principio mirato a mantenere la sicurezza dei dati, facendo in modo di nascondere dettagli implementativi di una classe a chi vi accede, lasciando pubblica solo l'interfaccia per utilizzarla.

E' importante per diversi motivi:
- Possiamo esporre *un'interfaccia* che ci permette di decidere a quali dati puo' accedere l'utilizzatore
- Una *modifica dell'implementazione* non prevede una modifica dell'interfaccia: se qualcuno usa la nostra classe in diversi punti del programma, noi possiamo modificare la classe senza cambiare il modo in cui viene usata e di conseguenza senza bisogno di modificare il codice in tutti i punti. In questo modo si aggirano tutti gli errori che potrebbero capitare.
- Ci permette di mantenere *l'integrita' dei dati*: possiamo decidere di controllare e validare i dati che vengono usati nella nostra classe impedendo cosi' all'utilizzatore di inserire valori non consentiti

#### Links
[[Abstract Data Type (ADT)]]