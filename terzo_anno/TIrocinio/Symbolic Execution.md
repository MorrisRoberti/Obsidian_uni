>La **symbolic execution** e' un metodo di analisi di programmi che cerca di capire **quali input fanno si che determinati parti di un programma vengano eseguite**.

Esempio banale
```cpp
int example(int data) {
int out;
if (data > 0)
	out = data;
else
	out = -data;
return(out);
}
```
- $data\in N^+ \rightarrow out\in N^+$ quindi vengono eseguite le righe 4, 7
- $data \in {[-\infty, 0]} \rightarrow out  \in {[-\infty, 0]}$ quindi vengono eseguite le righe 6,7

L'idea dietro la symbolic execution e' di utilizzare *simboli invece di numeri*, come valori di input, e rappresentare i *valori di variabili come espressioni simboliche*. 

## Per cosa si usa? 
>Viene utilizzata per: *automatic test generation*, *verifica formale del codice* (cioe' dimostrare che un programma soddisfa certe proprieta'), *semplificazione e riduzione del codice* (dice se ci sono delle parti di codice non raggiungibili).

## Principi fondamentali
Nell'esecuzione simbolica utilizziamo una rappresentazione del programma tramite simboli: 
$numeri \rightarrow simboli \newline variabili \rightarrow espressioni simboliche \linebreak output \rightarrow funzione dei simboli in input del programma$

