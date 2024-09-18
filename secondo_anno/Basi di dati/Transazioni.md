>Una **transazione** e' un insieme di operazioni atomiche che vengono effettuate sul db in modo consistente. Possono essere confermate (*commit*) o rifiutate (*rollback*).

In una transazione, le operazioni (query) devono essere svolte **tutte** fino alla fine.

### Sintassi MySQL
Le transazioni hanno varie keyword:
- `START TRANSACTION;` -> Indica che da quel punto in poi le query scritte saranno le operazioni (*atomiche*) di quella transazione
- `COMMIT;` -> Le query dall'inizio della transazione a questa keyword sono state eseguite e si accettano le modifiche
- `ROLLBACK;` -> Come `COMMIT` ma le modifiche vengono rifiutate

```mysql
START TRANSACTION;
SELECT * FROM table;

ALTER TABLE table DROP COLUMN col1;
COMMIT;
```

#### Links