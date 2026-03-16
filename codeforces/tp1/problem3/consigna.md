# Aggressive Cows

consigna: https://www.spoj.com/problems/AGGRCOW

## Idea

Queremos ubicar `C` vacas en `N` establos de manera que la **distancia mínima entre cualquier par de vacas sea lo más grande posible**.

1. Primero **ordenamos las posiciones de los establos**.
2. Observamos que la respuesta está entre `0` y `max(x) - min(x)`.
3. Hacemos **binary search sobre la distancia mínima** `d`.

Para verificar si una distancia `d` es posible:

- Colocamos la primera vaca en el primer establo.
- Luego recorremos los establos y colocamos otra vaca cada vez que la distancia al último establo ocupado sea **≥ d**.
- Si logramos colocar las `C` vacas, entonces `d` es posible.

Si `d` es posible, intentamos una distancia mayor.  
Si no es posible, probamos con una menor.

La mayor distancia `d` que funcione es la respuesta.

**Complejidad:**  
- Ordenamiento: `O(N log N)`  
- Binary search con chequeo greedy: `O(N log D)`  
donde `D = max(x) - min(x)`.
