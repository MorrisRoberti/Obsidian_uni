## Generalizzazione
>La **generalizzazione** associa una o piu' entita' $E_1, \space ... \space, \space E_n$ con un'altra entita' $E$ che ha $E_i$ casi specifici. $E$ e' una generalizzazione per  $E_1, \space ... \space, \space E_n$.  Mentre $E_1, \space ... \space, \space E_n$ e' una specializzazione di $E$.

La rappresentazione grafica e' la seguente

![[Pasted image 20241118103547.png]]

### Proprieta' della generalizzazione
>Se $E$ *parent* e' una generalizzazione di  $E_1, \space ... \space, \space E_n$ figli, allora, ogni proprieta' in $E$ e' significativa per  $E_1, \space ... \space, \space E_n$ e ogni occorrenza in questa sequenza e' un'occorrenza in $E$.

![[Pasted image 20241118103800.png]]

### Ereditarieta'
>Tutte le proprieta' dei parent sono ereditate dalle entita' figlio e non esplicitamente rappresentate.

## Tipi di Generalizzazioni
>La generalizzazione e' **totale** se ogni occorrenza dell'entita' *parent* e' occorrenza **di almeno una** delle entita' figlio, **parziale** altrimenti.

>La generalizzazione e' **disgiunta** se ogni occorrenza dell'entita' *parent* e' occorrenza **di al piu' una** delle entita' figlie, **sovrapposta** altrimenti.

Esempio di generalizzazione *disgiunta e parziale*
![[Pasted image 20241118104146.png]]

Esempio di una generalizzazione *disgiunta e totale*
![[Pasted image 20241118104219.png]]

Possiamo definire gerarchie multi-livello e generalizzazioni allo stesso livello. Ogni entita' puo' essere inclusa in piu' gerarchie differenti sia come *parent* che come *child*.
Una generalizzazione che ha solo un'entita' *child* e' chiamata **subset**.

#### Links
[[Database Design]]
[[Entity-Relationship Model]]
[[UML]]