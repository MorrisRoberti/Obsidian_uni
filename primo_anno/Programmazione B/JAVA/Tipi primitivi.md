>I tipi sono praticamente analoghi a quelli di C++, tranne per il fatto che l'insieme di valori per ciascun tipo e' completamente specificato dal linguaggio e indipendente dalla macchina (*machine-indipendent*)

I tipi primitivi interi sono i seguenti:
- ``int`` -> 32 bit 
- ``byte`` -> 8 bit
- ``short`` -> 16 bit
- ``long`` -> 64 bit

Poi abbiamo
- `char` -> 16 bit (UNICODE che include ASCII)
- `float` -> 32 bit
- `double` -> 64 bit
- `boolean`

#### Il tipo boolean
Diversamente da C++ il tipo boolean e' diverso dal tipo intero, infatti
```cpp
// C++
bool b = 1 // OK

// Java
boolean b = 1 // ERRORE
```
la sintassi corretta in Java e'
```java
boolean b = true
boolean c = false
```

#### Links
