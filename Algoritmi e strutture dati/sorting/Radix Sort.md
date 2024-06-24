$\Theta\left(n * d\right)$
$O\left(n *d\right)$
$\Omega\left(n * d\right)$ 
--- 
### Algoritmo
Il **Radix Sort** e' implementato in modo **iterativo** e **NON E' basato su confronti**.
E' un algoritmo di ordinamento **in place** (anche se nella versione che vedremo sfrutta [[Counting Sort]] che di per se utilizza memoria ausiliaria).
La complessita' e' legata ad un fattore *d* che rappresenta il numero di cifre del numero piu' grande.

**Radix Sort** utilizza al di sotto, un qualche meccanismo di ordinamento **stabile** come [[Counting Sort]].

### Principio di base
- Itera sul numero di cifre, partendo dalla meno significativa
- Richiama il *Counting Sort* su tutte le cifre meno significative dei numeri nel nostro array
- Ordina i numeri in base a tali cifre e poi passa alla seconda meno significativa
- Quando arriva ad ordinare quella piu' significativa l'array e' ordinato

![[Pasted image 20240324173300.png]]

**Attenzione**
>Per rendere l'algoritmo efficiente bisogna tenere i numeri in una base che bilanci il tempo di esecuzione con la memoria utilizzata.

### Pseudocodice
```
Radix_sort(A, d) {
for i = 1 to d
	// chiamo Counting_sort sull'array A
}
```
- 2-3 -> chiama un algoritmo di ordinamento stabile (*Counting Sort* in questo caso), su ogni "colonna" dell'array di numeri

#### Links
[[Counting Sort]]