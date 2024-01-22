Per sopperire alla **pesantezza** delle istruzioni nei CISC e per evitare di dover costruire sistemi sempre piu' complessi negli anni 70/80 si e' pensato ad un nuovo metodo per velocizzare la decodifica delle istruzioni e li nacque la **microprogrammazione**.

>La **microprogrammazione** e' un processo nel quale, invece di creare una ROM capace di contenere e (un decoder) di decodificare le innumerevoli istruzioni CISC, si utilizza un **microprocessore** che data l'istruzione **calcola** i comandi da eseguire.

In questo modo e' stato inserito un **microprocessore** (praticamente identico alla CPU) nella CU che si occupa solo di prendere in input **le istruzioni** e tirare fuori, tramite un calcolo i **comandi**.

![[Pasted image 20231206172645.png]]

==Quindi per velocizzare un processore CISC si e' adottata una soluzione completamente **Hardware**== 

>Essendo di vari formati e dimensioni i comandi, nella microprogrammazione vengono **calcolati** dalle istruzioni e **NON decodificati**

	Si puo' andare ricorsivamente a creare microprocessori sempre piu' innestati (fino al raggiungimento di limiti fisici) nel quale un microprocessore calcola le istruzioni per il processore nel quale e' inserito.

#### Links
