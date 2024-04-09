>La classe **vector< T >** realizza il tipo di dato astratto vettore tramite template.

E' realizzata con array dinamici (allocati dinamicamente) e consente l'accesso diretto tramite gli indici agli elementi del vettore
### Utilizzo e struttura
Per importare **vector** e' necessario includerlo: ``#include<vector>``.
Proprieta':
- *size* -> numero di elementi presenti nel vettore
- *capacity* -> memoria disponibile
- *elements* -> array dinamico che contiene gli elementi del vettore

In sostanza *capacity* rappresenta la grandezza dell'array dinamico mentre *size* e' il puntatore all'ultima cella occupata
![[Pasted image 20240409220030.png]]
#### Alcune accortezze
- La memoria per un oggetto puo' essere espansa automaticamente se necessario
- La memoria inutilizzata serve per future crescite del vettore
- Se la memoria finisce si deve procedere alla riallocazione ``reserve`` (in [[#Metodi]])

>La riallocazione e' un'operazione **costosa** (creazione di un nuovo array dinamico, copia di tutti gli elementi nel nuovo array, deallocazione del vecchio array) 
### Costruttori
- ``vector()`` -> crea un vettore vuoto (*size*=0, *capacity*=0)
- ``vector(int n)`` -> crea un vettore di dimensione *n* (*size*=0, *capacity*=*n*)
- ``vector(int n, const T& k)`` -> crea un vettore con *n* elementi inizializzati con il valore *k*
- ``vector(const vector<T>& V)`` -> e' il **copy constructor**

### Metodi
- ``reserve(int n)`` -> alloca un'area di memoria di dimensione sufficiente a contenere *n* elementi (quindi modifica *capacity*)
- ``size()`` -> ritorna il numero di elementi del vettore
- ``capacity()`` -> ritorna la quantita' di memoria allocata per questo vettore
- ``empty()`` -> elimina *tutti* gli elementi del vettore
- ``push_back(x)`` -> aggiunge l'elemento *x* in fondo al vettore
- ``pop_back()`` -> elimina l'ultimo elemento del vettore (senza ritornarlo)

### Metodi overloaded
- *operator=* -> assegnamento
- operator[] -> accesso tramite indice
- operator== , operator!=, etc. -> operatori di confronto

#### Links