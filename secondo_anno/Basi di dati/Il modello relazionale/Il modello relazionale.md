>Il **modello relazionale** e' un data model definito da E. F. Codd nel 1970 e implementato per la prima volta in un DBMS nel 1981. Esso e' basato sulla definizione logica di **relazioni** che sono rappresentate attraverso **tabelle**.

## Relazioni logiche, Relazioni e Associazioni
>Ci sono tre tipi di relazioni: **logical relations**, **relations** e **relationships**. Sono diverse sotto tutti gli aspetti ma condividono lo stesso nome (in italiano questa cosa si attenua in quanto e' possibile definire le relationships *associazioni*).

### Relazioni logiche
>Generalmente per relazioni logica si intende *sottoinsieme del prodotto cartesiano di due o piu' insiemi*. In questo caso definiamo una **relazione logica** come: 
>				***sottoinsieme di tuple ordinate*** *del prodotto cartesiano.*

$$D_1=\left\lbrace a,b\right\rbrace \space D_2=\left\lbrace x,y,z\right\rbrace$$
$$	D_1\times D_2=\left\lbrace\left(a,x\right),\left(a,y\right),\left(a,z\right),\left(b,x\right),\left(b,y\right),\left(b,z\right)\right\rbrace$$
quindi ogni coppia di $D_1\times D_2$ rappresenta una relazione poiche'
$$\lbrace{(a, x), (b, z)\rbrace} \subseteq D_1\times D_2$$
**ATTENZIONE**
- Una **relazione logica** non necessariamente e' sottoinsieme del prodotto cartesiano di *due* insiemi ma possono essere $n$
$$R \subseteq D_1 \times D_2 \space \times \space ... \times \space D_n$$
- Nel prodotto cartesiano di cui e' sottoinsieme la relazione logica e' possibile avere piu' volte lo stesso insieme
- Gli insiemi $D_1, D_2, \space ... \space , \space D_n$ sono i **domini della relazione**

Consideriamo la *relazione logica*
$$matches \subseteq string \times string \times int \times int$$ 
![[Pasted image 20241224163419.png]]

>Quindi una **relazione logica** e' un insieme di **tuple ordinate**

### Relazioni
>Una **relazione** e' come una relazione logica, la differenza sta nel fatto che una relazione e' un insieme di tuple **con ordine arbitrario**, le tuple sono **tutte distinte** e ogni tupla **e' ordinata internamente**.

- *Insieme di tuple con ordine arbitrario* significa in buona sostanza questo
$$\lbrace{(a,b), (x,y)}\rbrace = \lbrace{(x, y), (a,b)}\rbrace$$
- *le tuple sono tutte distinte* significa che NON possiamo avere
$$\lbrace{(a,b), (x,y), (a,b)}\rbrace$$
- *ogni tupla e' ordinata internamente* significa che, nonostante non conti l'ordine in cui sono le tuple nell'insieme, conta l'ordine in cui sono **gli elementi nella tupla**, quindi l'i-esimo elemento fa parte dell'i-esimo dominio
$$(a,b) \neq (b,a)$$
nella tupla di sinistra $a \in D_1$ e $b \in D_2$ mentre nella tupla di destra $b \in D_1$ e $a \in D_2$.


#### Relazioni e tabelle
>Una **tabella** rappresenta una relazione se: tutte le righe sono diverse, non conta l'ordine delle righe ne delle colonne, tutti gli header delle colonne (*attributi*) sono diversi e i valori delle colonne sono omogenei. Questo e' possibile perche' la struttura dati della tabella e' **non posizionale**.

#### Links
[[Value-based Data Model]]
[[Schemas & Instances]]
[[Vincoli di integrita']]
[[Primary key & Foreign key]]