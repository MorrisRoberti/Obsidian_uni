>Si e' visto nel tempo che l'ALU rimaneva ferma per piu del 50% del tempo perche' aspettava la fase di fetch e di decode. Quindi si e' pensato di creare una nuova struttura per **massimizzare** l'uso dei componenti.

```
B1  LAVA ASCIUGA STIRA ARMADIO
B2       LAVA   ASCIUGA  STIRA  ARMADIO
B3              LAVA     ASCIUGA    STIRA   ARMADIO
```

==Utilizzando le risorse in parallelo dobbiamo tenere conto del consumo e della potenza dell'hardware, senza la quale questa parallelizzazione non sarabbe possibile== 

Se una struttura sequenziale ha $n$ fasi la pipeline permette di velocizzare l'esecuzione TOTALE di $n$ volte.

>I processori moderni hanno circa 14 fasi

#### Attenzione
La singola esecuzione non viene velocizzata, viene accorciato il tempo dell'esecuzione **TOTALE**.

Tra la fase di LAVA di B1 e LAVA di B2 ci potrebbe essere un problema, quindi qui si introduce un **Buffer**.

### Esempio implementazione
La pipeline ha degli stadi (attivita') indipendenti, tutti della stessa durata. Con *N* stadi e' **teoricamente** possibile raggiungere uno speed up di *N* volte

esempio:
- Pipeline a **5 stadi**
- Processore RISC 

Cosa mappiamo nei 5 stadi?
1. **Fetch** istruzione -> IF
2. **Decodifica** istruzione + **lettura** registri -> ID
3. **Esecuzione** operazione dell'istruzione (ALU, se l'operazione lo richiede) -> EX
4. **Accedere** alla RAM -> RAM
5. **Scrittura** nei registri -> WRITE BACK

```
I0 --> IF | ID  EX  RAM  WB
I1 -->    | IF
```

==Problema==:
	 Tra IF(I0) e ID(I0) arriva IF(I0), quindi mentre ID(I0) va a decodificare l'istruzione dall'IR, IF(I1) sta andando a scriverlo, quindi c'e' la possibilita' che l'istruzione da decodificare venga sovrascritta.

==Soluzione==:
	Faccio una copia dell'IR in un registro di scrittura del **buffer** in modo da salvare il dato corretto e non sovrascriverlo.

#### Buffer
Il buffer ha una struttura con 2 colonne di registri (FF edge triggered) chiamata **Registri di pipeline IF/ID**.
- Nella parte sinistra vengono scritti i dati
- Nella parte di destra vengono letti i dati

Tale buffer assumera' un nome diverso rispetto a dove e' messo, **ID/EX**, **EX/RAM**, **RAM/WB**.

>La pipeline vale solo per le architetture RISC, poiche' le istruzioni devono OBBLIGATORIAMENTE avere *n* o meno fasi. Per cui questo tipo di meccanismo non funziona su architetture CISC.

L'istruzione di **WB** e' l'unica fase che va contro corrente, infatti va a scrivere sui registri.
### Criticita'
- Criticita' **strutturali**:
	- richiedo la stessa risorsa in due stadi diversi (quindi il bus si intasa) (si risolve con l'inserimento di bubble)
	- faccio la somma mentre un'altra istruzione incrementa il PC (per risolverlo posso duplicare il sommatore)

- Criticita' **sui dati**:
	- se faccio un'operazione con risultato x e l'istruzione successiva usa x come operando si trova un'incongruenza dei dati (si risolve inserendo stalli prima della decodifica della seconda operazione in modo da far fare il WB alla prima)-> la soluzione ottimizzata prevede di prelevare l'output dello stadio di esecuzione e utilizzarlo come input per l'operazione successiva (tecnica **Bypass**)
- Criticita' **sul controllo di flusso** (sono le piu insidiose):
	- salti
	- chiamate a funzione
	- cicli

### Ottimizzazioni
>**bypass** -> quando sono presenti stalli ma sono presenti istruzioni scollegate dalle altre i compilatori possono decidere di riordinare le istruzioni nella pipeline in modo da evitare stalli, quindi si aumenta l'efficienza. Tale meccanismo e' il vantaggio vero dei RISC, l'ottimizzazione dell'esecuzione del codice

>**stallo (bubble)** -> e' un'attivita' che dice di non fare nulla in modo da evitare criticita', quindi si fa scalare di 1 in avanti l'esecuzione. Gli stalli vengono inseriti dall'unita' di controllo a runtime per gestire la criticita'. Lo stallo aumenta il tempo d'esecuzione, quindi si passera' da uno speedup *N* ad uno speedup inferiore 

==E' possibile trovare combinazioni di istruzioni che richiedono sia Bypass che stallo==

I compilatori moderni rendono il codice piu' efficiente

### Soluzioni delle criticita' sui dati
- stalli (HW)
- bypass (HW)
- bypass + stallo (HW)
- riordino codice (SW)
#### Links