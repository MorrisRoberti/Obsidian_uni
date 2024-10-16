>Le [[Trasformazioni 3D]] elementari possono essere composte attraverso la moltiplicazione di matrici.

#### Rotazione $\theta$ attorno a un punto $p$ e parallela a un asse coordinato
1. Traslare l'oggetto nell'origine
2. Ruotare attorno all'origine di un angolo $\theta$
3. Traslazione inversa

![[Pasted image 20241014191325.png]]
$M = T^{-1}RT$

$$T^{-1}RT= \begin{bmatrix} 1 & 0 & 0 & p_x \\ 0 & 1 & 0 & p_y \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix} \cdot \begin{bmatrix} \cos{\theta} & -\sin{\theta} & 0 & 0 \\ \sin{\theta} & \cos{\theta} & 0 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix} \cdot \begin{bmatrix} 1 & 0 & 0 & -p_x \\ 0 & 1 & 0 & -p_y \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix} = \begin{bmatrix} \cos{\theta} & -\sin{\theta} & 0 & (-p_x\cos{\theta}+p_y\sin{\theta}+p_x) \\ \sin{\theta} & \cos{\theta} & 0 & (-p_x\sin{\theta}+p_y\cos{\theta}+p_y) \\ 0 & 0 & 0 & 1 \end{bmatrix}$$

![[Pasted image 20241014192003.png]]

#### Rotazione intorno ad un asse arbitrario
>Si vuole scrivere la matrice di rotazione di un angolo $\alpha$ attorno ad un asse arbitrario (definito dal segmento disegnato in figura).

![[Pasted image 20241014192516.png]]

Un procedimento possibile e' il seguente:
1. Traslazione $T$ di $(-x_1, -y_1, -z_1)$ che porta l'asse di rotazione a passare per l'origine
2. Rotazione rispetto a $y$ di un angolo $\theta$ che porta l'asse di rotazione sul piano $yz$
3. Rotazione rispetto a $x$ di un angolo $\phi$ che porta l'asse di rotazione su $z$
4. Rotazione intorno ad asse $z$ dell'angolo voluto $\alpha$
5. Rotazione inversa del punto 3
6. Rotazione inversa del punto 2
7. Traslazione inversa del punto 1
Quindi qualcosa del tipo
$$T^{-1}*R^{-1}_y(\theta) *R^{-1}_x(\phi)*R_z(\alpha)*R_x(\phi)*R_y(\theta)*T$$

#### Links
[[Trasformazioni 3D]]