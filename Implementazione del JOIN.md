>L'operazione di JOIN tra due o piu' tabelle e' una delle *operazioni piu' onerose* nel query processing. Vediamo alcune **implementazioni dell'operatore di JOIN** che permettono di gestire i vari casi in un modo pressoche' efficiente.

Prendiamo come caso studio un'operazione di JOIN fatta tra due tabelle $R$ e $S$ sui rispettivi attributi $A$ e $B$.

Ci sono 4 tipi di tecniche per implementare l'operatore di JOIN:
1. **Nested-loop JOIN**
2. **Single-loop JOIN**
3. **Sort-merge JOIN**
4. **Hash-based JOIN**
In base alle statistiche, l'ottimizzatore sceglie l'approccio con il minor costo stimato.

## Nested-loop Join
>Nel nested lo