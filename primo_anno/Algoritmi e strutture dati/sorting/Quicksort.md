$\Theta\left(n\log n\right)$
$O\left(n\log n\right)$ 
$\Omega\left(n\log n\right)$ 
*caso peggiore*: $O\left(n^2\right)$

--- 
### Algoritmo
Il **Quicksort** e' implementato tramite il **Divide et impera** ed e' basato **su confronti**.
Essendo un algoritmo che opera **in place** e' ideale per quando si lavora su sistemi con poca memoria.
E' una ricorrenza del tipo $$T\left(n\right)=2T\left(\frac{n}{2}\right)+O\left(n\right)$$**Attenzione:**
>Nell'analisi della complessita' si tralascia il fatto che gli array potrebbero avere un numero di elementi diversi. In generale qualsiasi ripartizione con proporzionalita' *costante* produce un albero di ricorsione di profondita' $\Theta\left(\log n\right)$ dove il costo di ogni livello e' $O\left(n\right)$. **Il tempo di esecuzione sara' quindi $O\left(n\log n\right)$ quando la ripartizione ha proporzionalita' costante**
### Principio di base
- Si sceglie un pivot, solitamente l'ultimo elemento
- Si scorre l'array da sinistra verso destra e si fanno scorrere due indici in avanti
- Man mano che gli indici vanno avanti si confrontano gli elementi con il pivot e si fa in modo di raccogliere a sx tutti gli elementi minori del pivot e a destra tutti quelli maggiori
- Alla fine si mette il pivot al centro e si avranno due array: quello a sx contenente tutti gli elementi < del pivot e quello a dx contente tutti gli elementi maggiori
- Il processo viene poi richiamato sugli array di sx e dx e quindi ricorsivamente si otterra' l'array ordinato
![[Pasted image 20240324115514.png]]

### Pseudocodice
Funzione ausililiaria che si occupa di dividere in modo appropriato l'array
```
Partition(A, p, r) {
x = A[r]
i = p - 1
for j = p to r - 1
	if A[j] <= x
		i = i + 1
		scambia A[i] = A[j]
scambia A[i + 1] = A[r]
return i + 1
}
```
- 2 -> definisce il *pivot*
- 3 -> definisce l'indice che servira' a delimitare l'array di sinistra
- 4-7 -> itera su tutti gli elementi e quando ne trova uno (o piu') minore del *pivot* fa avanzare l'indice *i* e scambia l'elemento corrente con quello in posizione *i + 1* (significa che l'array degli elementi minori del pivot e' aumentato di 1)
- 8 -> mette il *pivot* al centro dei due array
- 9 -> restituisce l'indice del *pivot*

>Nei passi 4-7 viene popolato l'array di sinistra e, automaticamente viene definito anche quello di destra

Funzione Quicksort vera e propria
```
Quicksort(A, p, r) {
if p < r
	q = Partition(A, p, r)
	Quicksort(A, p, r - q + 1)
	Quicksort(A, q + 1, r)
}
```
- 2 -> definisce il caso base, *q >= r* significa che l'array e' ordinato
- 3 -> ordina l'array mettendo gli elementi piu' piccoli del *pivot* a sx e i piu' grandi a dx e mette in *q* l'indice del *pivot* in modo da, appunto definire gli indici dei due sottoarray (*Divide/Impera*)
- 4-5 -> fa la chiamata ricorsiva sui due sottoarray usando *q* per definire l'array di sx e quello di dx (*Combina*)

>Come si vede, qui a differenza del [[Merge Sort]] la parte piu' dispendiosa e' il *Divide* e non il *Combina*


#### Links
