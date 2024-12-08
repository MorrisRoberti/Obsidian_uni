E' possibile rimuovere le generalizzazioni da uno schema ER nei seguenti modi:
1. **Parent Embedding** -> i *children* vengono messi come attributi del *parent*
2. **Children Embedding** -> il *parent* viene messo come attributo in ognuno dei *children*
3. **Using Relationship** ->rimpiazzando la generalizzazione con un'*associazione*

Prendiamo come esempio il seguente schema ER
![[Pasted image 20241208192401.png]]

## Parent Embedding
>Nel **Parent Embedding** i *children* vengono messi come attributi del *parent*.

![[Pasted image 20241208192427.png]]

>Il **parent embedding** si usa quando parent e children devono essere acceduti allo stesso tempo.

## Children Embedding
>Nel **Children Embedding** il *parent* viene messo come attributo in ognuno dei *children*.

![[Pasted image 20241208192519.png]]

>Il **children embedding** si usa quando i *children* devono essere acceduti indipendentemente l'uno dall'altro.
## Using Relationship
>Nella **Using Relationship** rimpiazziamo la generalizzazione con un'*associazione*.

![[Pasted image 20241208192735.png]]

>La **using relationship** si utilizza quando i *children* devono essere acceduti in modo indipendente dal *parent*.

E' possibile combinare le strategie definendo una strategia ibrida.

#### Links
[[Logical Design]]