$\Theta\left(n\right)$
$O\left(n\log n\right)$
$\Omega\left(n\log n\right)$ 
--- 
### Algoritmo
Il **Merge Sort** e' implementato tramite il **Divide et Impera** basato **su confronti**.
E' ideale per ordinare grandi quantita' di dati.
**Merge Sort** e' **ottimo** tra gli algoritmi di ordinamento basati su confronti.
. E' una ricorrenza del tipo $$T\left(n\right)=2T\left(\frac{n}{2}\right)+\Theta\left(n\right)$$
### Principio di base
Alla base e' molto semplice:
- L'array viene diviso ricorsivamente in $n/2$ parti
- Ogni parte viene ordinata
- Alla fine si avranno due array ordinati e gli elementi andranno confrontati e ricombinati per ottenere l'array completo

![[Merge_sort_algorithm_diagram.svg.png]]


**Attenzione**:
>Nello pseudocodice saranno presenti due valori $\infty$, questi sono le cosidette *sentinelle*, che verranno usate nel caso uno dei due array abbia ancora elementi e l'altro no. Confrontando gli elementi dell'array ancora popolato con $\infty$ saranno inseriti in ordine nell'array totale 
### Pseudocodice
Funzione ausiliaria che si occupa di riunire iterativamente gli elementi dei due sottoarray ordinati
```
Merge(A, p, q, r) {
n1 = q - p + 1 
n2 = r- q
crea due nuovi array L[1...n1+1] e R[1...n2+1]
for i = 1 to n1
	L[i] = A[p + i - 1]
for j = 1 to n2
	R[j] = A[q + j]
L[n1 + 1] = infinity
R[n2 + 1] = infinity
i = 1
j = 1
for k = p to r
	if L[i] <= R[j]
		A[k] = L[i]
		i = i + 1
	else A[k] = R[j]
		j = j + 1
	
}
```
- 5-8 -> carica gli elementi della meta' sinistra nell'array *L* e gli elementi della meta' destra in *R*
- 9-10 -> inizializza l'ultimo elemento di ogni array a $\infty$ questo sara' il valore sentinella
- 13-18 -> confronta iterativamente i valori dei due sottoarray e li carica nell'array finale in modo ordinato

Funzione Merge Sort vera e  propria
```
Merge_sort(A, p, r) {
if p < r
	q = (p + r) / 2
	Merge_sort(A, p, q)
	Merge_sort(A, q + 1, r)
	Merge(A, p, q, r)
}
```
- 2 -> il controllo serve da caso base, se *p = r* significa che l'array e' vuoto o che e' gia' stato ordinato dal merge
- 3 -> definisce *q* come l'indice a meta' tra i due array (*Divide*)
- 4-5 -> usa *p, q* e *r* passandoli a ``Merge_sort()`` per delimitare i due sottoarray (*Impera*)
- 6 -> chiama la funzione ``Merge()`` definita sopra sull'array totale per riunire gli elementi (*Combina*)

#### Links