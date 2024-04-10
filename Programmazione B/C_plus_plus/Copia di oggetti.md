Quando vogliamo copiare un oggetto in un oggetto della stessa classe utilizziamo come al solito l'operatore di assegnamento **=**.

### Come si comporta
Nel caso di oggetti della stessa classe, l'operatore = esegue l'assegnamento *field-wise*, cioe' copia il valore dei campi dell'oggetto b nei campi equivalenti dell'oggetto a.
Facciamo un esempio
```cpp
int main() {
	Razionale r1(1,2);
	Razionale r2(3,4);
	r1 = r2;
	r1.stampa(); // 3, 4
}
```

### Attenzione
Un discorso particolare e' da fare per gli oggetti creati in modo dinamico, poiche'
```cpp
int main() {
	Razionale* r1 = new Razionale(1,2);
	Razionale* r2 = new Razionale(3,4);
	r1 = r2;
	r1->stampa(); // 3, 4
}
```
Il risultato e' lo stesso ma la differenza e' che se ora modifichiamo r2, anche i valori in r1 verranno modificati, poiche' adesso questi puntano allo stesso oggetto
```cpp
r2->n = 5;
r2->d = 6;
r1->stampa(); // 5, 6
```
Si vede chiaramente nel disegno
![[Pasted image 20240227192213.png]]