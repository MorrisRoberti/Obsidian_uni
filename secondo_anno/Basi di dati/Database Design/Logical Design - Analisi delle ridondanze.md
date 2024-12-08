Abbiamo 2 tipi di ridondanze nel data model relazionale:
- Derivabili dagli attributi
	- Da altri attributi della stessa entita'/associazione
	- Da altri attributi di un'entita'/associazione diversa
- Associazioni derivabili dalla composizione di differenti associazioni (in generale associazioni cicliche)

## Derivabili dagli attributi
### Da altri attributi nella stessa entita'/assoc.
![[Pasted image 20241208190402.png]]
Possiamo derivare `Net value` dagli altri due.
### Da altri attributi di altre entita'/assoc.
![[Pasted image 20241208190434.png]]
Possiamo derivare `Total` da `Price * Quantity`.

## Associazioni derivabili dalla composizione di altre associazioni
![[Pasted image 20241208190622.png]]


## Esempio di analisi
Consideriamo il seguente schema
![[Pasted image 20241208190659.png]]

| Name   | Type | Size    |
| ------ | ---- | ------- |
| City   | E    | 200     |
| Person | E    | 1000000 |
| Stay   | R    | 1000000 |
- **Operazione #1** -> Inserire una nuova persona con la sua citta' di permanenza (500 volte al giorno)
- **Operazione #2** -> Stampare i dati di tutte le citta', incluso il numero degli abitanti (2 volte al giorno)
### Con ridondanza
- **Operazione #1**

| Name   | Type | Accesses Number | Accesses Type |
| ------ | ---- | --------------- | ------------- |
| Person | E    | 1               | W             |
| Stay   | R    | 1               | W             |
| City   | E    | 1               | R             |
| City   | E    | 1               | W             |
`City` viene acceduta una volta in lettura per prendere il valore di `Inhabitants` e una volta in scrittura per incrementare di uno lo stesso attributo.

- **Operazione #2**

| Name | Type | Accesses Number | Accesses Type |
| ---- | ---- | --------------- | ------------- |
| City | E    | 1               | R             |
Con la ridondanza possiamo leggere direttamente il numero di abitanti.

**Costo**
- **Op #1** -> 1500 scritture + 500 letture al giorno
- **Op #2** -> trascurabile
Siccome le scritture vengono conteggiate x2 abbiamo 3000+500 = 3500 operazioni.

### Senza ridondanza
- **Operazione #1**

| Name   | Type | Accesses Number | Accesses Type |
| ------ | ---- | --------------- | ------------- |
| Person | E    | 1               | W             |
| Stay   | R    | 1               | W             |
- **Operazione #2**

| Name | Type | Accesses Number | Accesses Type |
| ---- | ---- | --------------- | ------------- |
| City | E    | 1               | R             |
| Stay | R    | 5000            | R             |
**Costo**
- **Op #1** -> 1000 scritture
- **Op #2** -> 10000 letture al giorno
Siccome le scritture vengono conteggiate x2 abbiamo 2000 + 10000 = 12000.

>Si capisce che in questo caso la versione che mantiene la ridondanza sia molto piu' efficiente.

#### Links
[[Logical Design]]