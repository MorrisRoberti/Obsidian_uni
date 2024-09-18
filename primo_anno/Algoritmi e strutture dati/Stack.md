>Lo **stack** e' una struttura dati di tipo *LIFO(Last In First Out)*, cio' significa che il primo elemento ad uscire e' il primo ad entrare. Es. Una pila di fogli, quando aggiungiamo un foglio lo mettiamo in cima e quando lo togliamo prendiamo appunto quello piu in alto

### Operazioni
Assumeremo che le operazioni siano metodi chiamati su un oggetto di tipo stack.
- `push(k)` -> inserisce l'elemento `k`in cima allo stack
- `pop()` -> rimuove l'elemento in cima allo stack e lo ritorna
- `stack_empty()` -> verifica se lo stack e' vuoto

Solitamente si alloca un array di dimensione $n$ e si utilizza un attributo **top** $<= n$ per indicare fin dove e' riempito lo stack:
- se `stack.top == 0` lo stack e' vuoto -> se facciamo `pop()` si verifichera' un errore di **underflow**
- se `stack.top == n` allora lo stack e' pieno -> se facciamo un operazione di `push(k)` si verifichera' un errore di **overflow**
![[photo_2024-06-24_16-53-05.jpg]]

#### Links