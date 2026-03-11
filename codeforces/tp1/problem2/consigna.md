# Cambiándose de Aula

Problema de Codeforces.

https://codeforces.com/gym/601138/problem/B

## Idea de la solución

Primero se calcula cuál debería ser la posición final correcta aplicando la secuencia original `s1`.
Para eso se recorre el string y se suma +1 por cada `'+'` y se resta 1 por cada `'-'`.
Luego se analiza la secuencia recibida `s2`. Como algunas instrucciones pueden haberse escuchado mal (`'?'`), se simulan todas las posibilidades usando recursión.

En cada paso:
- Si el carácter es `'+'`, se avanza una posición.
- Si es `'-'`, se retrocede una posición.
- Si es `'?'`, se consideran dos casos posibles con probabilidad 0.5 cada uno: avanzar o retroceder.

La función recursiva procesa la secuencia carácter por carácter manteniendo la posición actual.
Cuando se llega al final de `s2`, se verifica si la posición coincide con la posición final esperada. Si coincide se suma probabilidad, si no se suma 0.
Sumando las probabilidades de todos los casos posibles se obtiene la probabilidad total de terminar en la posición correcta.