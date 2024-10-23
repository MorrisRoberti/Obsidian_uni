>Con il termine **risorse** si intende genericamente entita' disponibili in quantita' limitata e la cui mancanza potrebbe compromettere o limitare la funzionalita' del programma. Per questo motivo, il software deve necessariamente interagire con le risorse in modo corretto, evitando che alcune di esse vadano *perse* o compromesse.

L'interazione software con le risorse deve avvenire secondo uno schema predefinito:
1. **Acquisizione** della risorsa
2. **Utilizzo** della risorsa
3. **Rilascio** della risorsa

In particolare:
- La risorsa deve essere acquisita prima di essere usata (o rilasciata)
- Al termine del suo utilizzo la riso