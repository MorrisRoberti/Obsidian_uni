## Allocazione di variabili locali statiche
>Sono variabili allocate prima di iniziare la funzione main ma sono *inizializzate* (solo) la prima volta in cui il controllo di esecuzione incontra la loro definizione.

- L'uso di variabili globali non e' molto consigliato perche' porta a codice poco leggibile
- Se l'allocazione *statica* e' necessaria preferire i dati membro statici, se possibile dichiarati *private*

## Allocazione automatica
- L'oggetto allocato dinamicamente viene creato (a tempo di esecuzione) sullo stack ogni volta che il controllo entra nel blocco in cui si trova la dichiarazione
- Nelle funzioni ricorsive possono esserci piu' istanze della stessa variabile 
- L'oggetto viene automaticamente distrutto ogni volta che il controllo esce da quel blocco
- Quello che e' automatico e' **la fine del ciclo di vita**, perche' l'inizio viene deciso dal programmatore
## Allocazione automatica di temporanei
- avviene quando un oggetto viene creato per memorizzare il valore calcolato da una sottoespressione che compare all'interno di un'espressione
- il temporaneo viene distrutto quando termina la valutazione dell'espressione completa che contiene il punto id creazione
- il lifetime temporaneo viene esteso quando viene assegnato ad un riferimento. In questo caso alla distruzione del riferimento viene distrutto anche il temporaneo
## Allocazione dinamica
- per "allocazione dinamica" si intende che la distruzione non e' automatica
- l'espressione *new* restituisce l'indirizzo dell'oggetto allocato che va salvato in un puntatore
- l'istruzione dealloca l'oggetto puntato dal puntatore *NON ELIMINA IL PUNTATORE*
- quando si dealloca l'oggetto puntato da un puntatore questo diventa un *dangling pointer*

## Tipi integrali
- i tipi integrali *piccoli* potrebbero avere una size inferiore a int. In caso non esistano operazioni disponibili nella nostra architettura per parole di quella dimensione, questi tipi vengono **promossi** a int

## Qualificatori di tipo
- esistono due qualificatori di tipo -> **const** e **volatile**

## Costanti letterali
es
```cpp
int main() {
	int k[10]; // il 10 e' una costante letterale
}
```
- e' quasi sempre scomodo a livello di comprensione e manutenibilita' perche' in un contesto grande potrebbe sorgere la domanda: *"quel 10 che significa?"*.
- 