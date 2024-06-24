>Come in C++ la sottoclasse eredita' tutti i campi della superclasse con la differenza che ogni metodo e ogni campo della sottoclasse mantengono la visibilita' della superclasse.

```java
public class C extends B {
...
}
```
La classe `C` eredita da `B`

**ATTENZIONE**
>In java c'e' la **single inheritance**, cioe' una classe puo' ereditare solo da una classe, non da piu' di una.
### Upcasting
>L'**upcasting** non e' altro che un casting implicito da una sottoclasse ad una superclasse

```java
Object o = new Rettangolo(2, 3);
```
**IMPORTANTE**
- L'identificatore `o` rappresenta la reference ed e' di tipo `Object` (**tipo statico**)
- L'oggetto referenziato, tuttavia e' di tipo `Rettangolo` che e' la classe d'origine (**tipo dinamico**)

Il tipo della reference stabilisce i metodi che possono essere applicati ad un certo oggetto.
Nel nostro caso significa che possiamo applicare solo metodi della classe `Object`:
- `o.area()` -> **NO**
- `o.equals(q) `-> **OK**

*Quindi nella riga sopra quale versione di equals verra' chiamata? quella di Object o quella di Rettangolo?*
**Quella della classe d'origine, quindi in questo caso Rettangolo**. Tuttavia se la definizione del metodo non viene trovata nella classe d'origine si risalira' lungo la gerarchia delle classi fino a trovare una classe di appartenenza in cui e' definito.

### Downcasting
>Il **downcasting** effettua un casting tra la reference (del tipo di una superclasse) e l'oggetto referenziato (della classe d'origine)

Nel caso dell'oggetto sopra, se volessimo chiamare un metodo della classe d'origine dovremmo fare come sotto
```java
((Rettangolo o)).area();
```


**ATTENZIONE** 
Scrivere 
```java
o.area();
```
genera un errore *a compile time*.


## Override
>Se vogliamo sovrascrivere il comportamento di un metodo di una superclasse in una sottoclasse possiamo usare il cosidetto **override**, tramite il relativo decorator @Override

#### Links
[[La Classe Object]]
[[Classi di origine e classi di appartenenza]]
