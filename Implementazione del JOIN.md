>L'operazione di JOIN tra due o piu' tabelle e' una delle *operazioni piu' onerose* nel query processing. Vediamo alcune **implementazioni dell'operatore di JOIN** che permettono di gestire i vari casi in un modo pressoche' efficiente.

Prendiamo come caso studio un'operazione di JOIN fatta tra due tabelle $R$ e $S$ sui rispettivi attributi $A$ e $B$.

Ci sono 4 tipi di tecniche per implementare l'operatore di JOIN:
1. **Nested-loop JOIN**
2. **Single-loop JOIN**
3. **Sort-merge JOIN**
4. **Hash-based JOIN**
In base alle statistiche, l'ottimizzatore sceglie l'approccio con il minor costo stimato.

## Nested-loop Join
>La tabella $R$ e' impostata come *outer table* mentre la $S$ e' impostata come *inner table*. Per ogni riga nell'outer table che fa match con il predicato $F_R$ il metodo recupera tutte le righe nella inner table che soddisfano il predicato di join $F_J$.

Il costo dipende dalla presenza di indici, dal ruolo di $R$ e $S$ e dalla dimensione del buffer.

![[Pasted image 20241110163108.png]]

## Single-loop Join
>Esiste un *index* (o *hash key*) per uno dei due attributi di join, ad esempio $A$ di $R$. Il metodo recupera ogni riga di $S$ una alla volta e poi usa la struttura di accesso (la struttura che tiene gli index di quella tabella) per recuperare direttamente tutte le righe di $R$ che soddisfano il predicato di join.

![[Pasted image 20241110163704.png]]

## Sort-merge Join
>Le tabelle $R$ e $S$ sono fisicamente ordinate secondo i valori di $A$ e $B$ rispettivamente. Entrambe le tabelle sono visitate una volta in modo da ottenere gli attributi di join e facendo match con i record che hanno gli stessi valori per $A$ e $B$.

L'ottimizzatore potrebbe scegliere di utilizzare un *sort-merge join* per fare join di grandi quantita' di dati quando la condizione di join tra due tabelle non e' un *equi-join* ($\lt$, $\leq$, $\gt$, $\geq$ etc.) oppure l'ordinamento e' richiesto da altre operazioni.

![[Pasted image 20241110164137.png]]

## Hash-based Join
>Agli attributi di join delle tabelle $R$ e $S$ viene applicata una qualche funzione di *hash*. Le nuove tabelle di hash, ognuna con $B$ *buckets* permette di trovare piu' velocemente le righe che fanno match, rispetto a scannerizzare tutta la tabella originale. Il risultato finale puo' essere ottenuto con $B$ join semplici tra i $B$ bucket.

Gli *hash-based join* sono tipicamente piu' efficienti quando si lavora con tabelle particolarmente grandi.

![[Pasted image 20241110164608.png]]

#### Links
[[DBMS Architecture]]