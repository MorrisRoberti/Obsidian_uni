## Architettura x86 (successivamente intel i)
la CPU 8086 era composta da **29k transistor** a **5MHz** di frequenza.
Componenti:
- 8 registri generali -> stack {AX, BX, SP, BD}, indicizzazione {CX, DX, SI, DI}
- 4 registri segmento -> code {CS}, data {DS}, stack {SS}, extra {ES}
- IP (PC)
- PSW

SEGMENTAZIONE 
>La segmentazione veniva usata per indirizzare dati piu grandi di quelli di una parola. Per farlo si e' utilizzata la formula ==Base * 16 + Offset== 


In pratica si divideva il dato in piu segmenti e si indirizzava solo la base e il riferimento degli altri segmenti es. 
	CS: IP
	DS: SI (anche [SI]) -> la notazione con le parentesi indica una cella in RAM
	SS: SP

- Esendo lo spazio dei registri 16bit, ogni registro avra' una parte bassa e una alta ognuna da 8 bit (es. ah, al)
- Le istruzioni nei CISC hanno lunghezze variabili
- Per azzerare il contenuto di un registro e' ottimale fare *xor ax, ax* che usa solo un'istruzione

### Esercitarsi
- Scrivere un programma ad alto livello e provare a tradurlo a basso livello


### Sources
<http://www.ingmonti.it/libri/Parte2/10%20Segmentazione%208086.pdf>
<https://www.geeksforgeeks.org/memory-segmentation-8086-microprocessor/>


##  Pipeline
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