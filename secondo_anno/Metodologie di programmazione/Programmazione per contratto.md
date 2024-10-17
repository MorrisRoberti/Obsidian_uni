>Una corretta definizione dell'interfaccia di una classe prevede la stesura di una sorta di **contratto tra lo sviluppatore della classe e l'utilizzatore**. Per ogni funzionalita' fornita, il contratto stabilisce quali sono le *precondizioni* che l'utilizzatore deve soddisfare per poter invocare la funzionalita' e quali sono le *postcondizioni* che l'implementatore deve garantire in seguito all'esecuzione della funzionalita'.

Tra precondizioni e postcondizioni sono sempre incluse le [[Progettazione di un tipo di dato concreto#Invariante di classe|Invarianti di classe]].

>Il *contratto* si specifica in questo modo
>*precondizioni* ==> *postcondizioni*

Si noti che se le precondizioni NON sono valide, allora l'implicazione del contratto e' vera a prescindere.
Questo significa che se l'utilizzatore non soddisfa una precondizione l'implementatore *non ha alcun obbligo*.

>Spesso si preferisce esplicitare le condizioni sulle invarianti di classe, includendole nel contratto: 
>*precondizioni AND invarianti* ==> *postcondizioni AND invarianti*

In questo caso, precondizioni e postcondizioni sono intese "al netto" delle invarianti di classe.

Esempio
```cpp
Razionale operator/(const Razionale& x, const Razionale& y) {
	assert(x.check_inv() && y.check_inv()); // invarianti di ingresso
	assert(y != Razionale(0)); // precondizione "al netto" delle invarianti

	Razionale res = x;
	res /= y;

	// invarianti in uscita (omesso per x e y, perche' costanti)
	assert(res.check_inv());
	return res;
}
```

La precondizione "al netto delle invarianti" dice che l'oggetto `y` deve essere diverso dal Razionale 0.
Analogamente la postcondizione "al netto delle invarianti" richiede che il valore restituito sia effettivamente il risultato della divisione di `x` per `y`.

**ATTENZIONE**
>I controlli sulle postcondizioni sono spesso difficili se non impossibili da automatizzare all'interno della classe, quindi si codificano direttamente nei test, indicando i risultati attesi.

## Contratti Narrow e Contratti Wide
>Un operatore di divisione, come specificato sopra e' un esempio di **contratto narrow**. Nei contratti *narrow* l'implementatore si impegna a fornire la funzionalita' solo quando ha senso farlo, cioe' quando i valori forniti in input sono legittimi, in questo senso i contratti *narrow* sono quelli in cui l'onere di verificare la legittimita' delle operazioni sta **all'utilizzatore**.

>Nei **contratti wide**, invece, l'onere di verificare la legittimita' delle invocazioni ricade sull'implementatore. Scegliere un contratto *wide* equivale quindi a spostare alcuni elementi del contratto dal lato della precondizione al lato della postcondizione.

Esempio di divisione con contratto *wide*
```cpp
Razionale operator/(const Razionale& x, const Razionale& y) {
	assert(x.check_inv() && y.check_inv()); // invarianti di ingresso

	// il contratto wide prevede, come postcondizione, che nel caso 
	// y sia 0 venga lanciata un'opportuna eccezione
	if(y == Razionale(0))
		throw DivByZero();

	Razionale res = x;
	res /= y;

	// invarianti in uscita (omesso per x e y, perche' costanti)
	assert(res.check_inv());
	return res;
}
```

>Notare come nel caso del contratto *wide* sia l'implementatore a verificare che la condizione venga rispettata tramite un controllo **esplicito**, inoltre, anche se la condizione viene controllata all'inizio dell'implementazione, si tratta comunque di una *postcondizione*, perche' in questo caso l'utent puo' legittimamente pretendere di ottenere l'eccezione quando `y` e' uguale a 0.

I contratti *wide* sono quindi **piu' onerosi** sia in termini di efficienza che di codice da scrivere.

### I contratti C++ e la libreria standard
>Ogni volta che lo standard descrive una funzionalita' del linguaggio o della libreria standard, ne viene descritto il contratto in termini di precondizioni e postcondizioni, in particolare sono classificati i *behaviors* che una specifica implementazione e' tenuta a rispettare.

#### Specified Behavior
>E' il comportamento *corretto* definito dallo standard, al quale l'implementazione deve uniformarsi.

#### Implementation-Defined Behavior
>Ogni implementazione puo' scegliere come realizzare una determinata funzionalita', con l'obbligo di documentare la scelta fatta. Ad esempio la scelta della dimensione di ognuno dei tipi interi standard (signed, unsigned etc.).
#### Unspecified Behavior
>Comportamento che dipende dal'implementazione, che pero' non e' tenuta a documentare la scelta fatta. Ad esempio l'ordine delle valutazione delle sottoespressioni e' non specificato.

#### Undefined Behavior
>Comportamento ottenuto a causa della violazione di una precondizione. In seguito alla quale l'implementazione non ha piu' nessuna prescrizione da seguire, quindi potrebbe comportarsi in modo estremamente arbitrario: indicizzazione di un array al di fuori dei limiti, tentativo di scrivere su un oggetto definito const, overflow su tipi interi con segno etc.

Si indica spesso con la sigla **UB**.

#### Links
[[Progettazione di un tipo di dato concreto#Precondizioni e postcondizioni]]