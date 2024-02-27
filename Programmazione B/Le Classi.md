>Una classe e' un'entita' che definisce la struttura e il comportamento di un oggetto.

Possiamo pensare ad una classe come alla descrizione di un oggetto del mondo fisico, che ha appunto: 
- Caratteristiche (*Attributi*)
- Comportamento (*Metodi*)

Ad esempio assumiamo di voler creare una classe ``Macchina``, questa andra' a definire cos'e' e cosa puo' fare una macchina:
```
class Macchina {
	private: 
		float velocita;
		float benzina;
		int cilindrata;
	public: 
		void accelera(){...}
		void frena(){...}
		void aggiungiBenzina(){...}
}
```
Quei **public** e **private** che vediamo nell'esempio sopra sono i cosidetti "**Modificatori di visibilita'**" e servono a stabilire da dove si puo' accedere a quell'informazione:
- public -> ovunque sia all'interno che all'esterno della classe;
- private -> solo ed esclusivamente dall'interno della classe

#### Links
[[Gli Oggetti]]
[[Incapsulamento e Information hiding]]
[[Abstract Data Type (ADT)]]
[[I Costruttori]]