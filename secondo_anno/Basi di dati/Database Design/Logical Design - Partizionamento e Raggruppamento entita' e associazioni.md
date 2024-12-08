Abbiamo 4 tipi di partizionamento/raggruppamento ricorrenti:
1. **Entity Vertical Partitioning**
2. **Restructuring Multi-Valued Attributes**
3. **Raggruppamento di entita'**
4. **Relationship Horizontal Partitioning**

## Entity Vertical Partitioning
![[Pasted image 20241208193827.png]]

>Spezziamo l'entita' in due entita' collegate da un'associazione.

![[Pasted image 20241208193911.png]]

## Restructuring Multi-Valued Attributes
![[Pasted image 20241208193950.png]]

>Siccome un ufficio puo' avere molti numeri di telefono, vogliamo spostare `Phone` in un'entita' separata e avere un'associazione 1-N tra `Office` e quest'ultima.

![[Pasted image 20241208194045.png]]

## Raggruppamento di entita'
![[Pasted image 20241208194129.png]]

>Abbiamo due entita' collegate tramite un'associazione 1-1. Concettualmente non c'e' bisogno di tenerle entrambe, quindi spostiamo gli attributi di `Apartment` dentro `Person`.

![[Pasted image 20241208194239.png]]

## Relationship Horizontal Partitioning
![[Pasted image 20241208194301.png]]


![[Pasted image 20241208194317.png]]

#### Links 
[[Logical Design]]