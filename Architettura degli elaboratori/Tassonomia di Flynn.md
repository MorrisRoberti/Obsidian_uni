>E' una specifica che serve per categorizzare le CPU in base alla loro capacita di parallelizzazione dell'esecuzione.

### Estendiamo le capacita' della CPU tradizionale
Vogliamo estendere in due strade: 
- La capacita' di elaborare **istruzioni** in parallelo
- La capacita' di elaborare **dati** in parallelo

**SISD** -> Single Instruction Single Data (processore visto finora)
**SIMD** -> Single Instruction Multiple Data (vettore di dati) -> tante ALU che manipolano i dati ma sulla stessa istruzione (istruzioni vettoriali: SSE, AVX)
**MISD** -> Multiple Instruction Single Data 
**MIMD** -> Multiple Instruction Multiple Data (Multi-Core)


#### Links
[[GPU e GPGPU]]