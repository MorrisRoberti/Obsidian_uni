### Modificatore const
- Se un metodo e' *const* non puo' modificare l'oggetto d'invocazione
- Se un metodo non modifica l'oggetto di invocazione e' opportuno definirlo come *const*
- Una comodita' di avere *const* nella signature del metodo e' che leggendolo so per certo che nel metodo non verra' modificato l'oggetto *this*.
### Getter e setter
- Sono metodi public e void che servono per dare i valori ai campi che solitamente sono *private*
- I loro nomi solitamente sono *void setNomeCampo ()* e *void getNomeCampo ()*.

### Delegating Constructor
``Data(int g, int m, int a) : Data() {}``
- Per prima cosa viene inizializzato un oggetto tramite il costruttore vuoto e viene usato se non vengono settati i campi con il costruttore normale