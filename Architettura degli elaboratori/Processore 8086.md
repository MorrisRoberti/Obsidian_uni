>La famiglia dei processori x86 e' quella che in futuro sarebbe diventata la serie *i* dell'Intel

### Struttura
la CPU 8086 era composta da **29k transistor** a **5MHz** di frequenza.
Componenti:
- 8 registri generali -> stack {AX, BX, SP, BD}, indicizzazione {CX, DX, SI, DI}
- 4 registri segmento -> code {CS}, data {DS}, stack {SS}, extra {ES}
- IP (PC)
- PSW

### Segmentazione
>La segmentazione veniva usata per indirizzare dati piu grandi di quelli di una parola. Per farlo si e' utilizzata la formula ==Base * 16 + Offset== 


In pratica si divideva il dato in piu segmenti e si indirizzava solo la base e il riferimento degli altri segmenti es. 
	CS: IP
	DS: SI (anche [SI]) -> la notazione con le parentesi indica una cella in RAM
	SS: SP

- Essendo lo spazio dei registri 16bit, ogni registro avra' una parte bassa e una alta ognuna da 8 bit (es. ah, al)
- Le istruzioni nei CISC hanno lunghezze variabili
- Per azzerare il contenuto di un registro e' ottimale fare *xor ax, ax* che usa solo un'istruzione

#### Links