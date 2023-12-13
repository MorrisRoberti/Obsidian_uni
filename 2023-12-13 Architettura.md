### Potenza di calcolo
>Dagli anni 80 fino ai 2000 la potenza dei processori e' cresciuta esponenzialmente fino a che non si sono raggiunti limiti fisici, da li la strategia e' diventata avere piu' di un processore: **Multiprocessori** o **Cluster**

### Multiprocessori
- alta scalabilita
- hw non troppo complicato
- per il sw scrivo algoritmi paralleli e suddivido il lavoro in n elaboratori
- comunicazione $n^{2}$ 

### Estendiamo le capacita' della CPU tradizionale
Vogliamo estendere in due strade: 
- La capacita' di elaborare istruzioni in parallelo
- La capacita' di elaborare dati in parallelo

### Tassonomia di Flynn
>Serve per categorizzare le CPU in base alla loro capacita di parallelizzazione

**SISD** -> Single Instruction Single Data (processore visto finora)
**SIMD** -> Single Instruction Multiple Data (vettore di dati) -> tante ALU che manipolano i dati ma sulla stessa istruzione (istruzioni vettoriali: SSE, AVX)
**MISD** -> Multiple Instruction Single Data 
**MIMD** -> Multiple Instruction Multiple Data (Multi-Core)

#### MIMD 
Abbiamo **piu' PC** quindi il programma viene diviso in flussi di lavoro, chiamati **Thread**.

### Graphic Processing Unit
>Dispositivo di output (principalmente) che si occupa di fare **rendering** di una matrice 2D o 3D.

- All'inizio era un'architettura simil-SIMD
- Sottoinsieme di istruzioni (UC piccola ma che gestisce tante UO)
- ALU grande
- BUS grande perche' dobbiamo gestire grandi quantita' di dati
- Trasferimento a blocchi

### GPGPU (General Purpose Graphical Processing Unit)
>GPU programmabile generale

Avra' un linguaggio assembly dedicato

==Le GPU sono decisamente piu' veloci delle CPU, se il programma sfrutta le potenzialita' del calcolo parallelo==

### SIMT
>Le GPU escono dalla tassonomia di flynn e vengono definite SIMT (Single Instruction Multiple Thread), quindi ho piu' thread che eseguono lo stesso codice (stesso PC) su dati diversi

Se due thread fanno due cose diverse (PC1 != PC2) si prosegue mettendo in sequenza le esecuzioni, quindi di fatto c'e' una degradazione del parallelismo (nel caso peggiore ogni thread esegue un'istruzione diversa)

L'UO segue i vari flussi di esecuizone e raggruppa quelli che eseguono le stesse istruzioni

La GPU opera nell'ordine dei TFLOPS (Tera Floating-Point Operations Per Second)

A parita' di elaborazione di dati le GPU consumano meno, per questo vengono utilizzate nei datacenter molto piu' delle CPU

==NON TUTTI I PROGRAMMI SONO PIU EFFICIENTI NELLE GPU, POICHE' SPOSTA DATI A BLOCCHI== 

Le GPU operano ad un clock inferiore rispetto alle CPU