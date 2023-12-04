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

# In corso...


#### Links