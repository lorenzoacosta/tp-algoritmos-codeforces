# Cambiándose de Aula

Problema de Codeforces.
https://codeforces.com/gym/601138/problem/A

## Idea

La grilla representa aulas frías (-1) y calientes (1).
Hay que ir desde la esquina superior izquierda hasta la inferior derecha moviéndose solo hacia la derecha o hacia abajo.
La condición es que el camino tenga la misma cantidad de aulas frías y calientes, es decir, que la suma total del recorrido sea 0.
Para resolverlo uso una búsqueda recursiva sobre los caminos posibles. En cada posición mantengo un **balance** con la suma acumulada del camino.
Para no recalcular estados que ya se exploraron, uso memoización guardando los resultados para cada estado `(i, j, balance)`.
Además agrego dos podas para evitar explorar caminos imposibles:
- si el balance actual es demasiado grande para compensarse con los pasos que quedan
- si la paridad entre el balance y los pasos restantes no permite terminar en 0
Si alguna de las ramas llega al final con balance 0 entonces la respuesta es **YES**, sino **NO**.

## Complejidad
Aproximadamente \(O(n \cdot m \cdot balance)\) en el peor caso, dependiendo de los balances posibles que se visiten.