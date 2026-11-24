# Metodos de busqueda en C

Biblioteca en C con ocho algoritmos para buscar valores enteros. Cada metodo
devuelve el indice donde encuentra el objetivo o `-1` si no esta presente.

## Metodos incluidos

- Busqueda lineal (`busquedaLineal`)
- Busqueda binaria iterativa (`busquedaBinaria`)
- Busqueda binaria recursiva (`busquedaBinariaRecursiva`)
- Busqueda por salto (`busquedaSalto`)
- Busqueda por interpolacion (`busquedaInterpolacion`)
- Busqueda exponencial (`busquedaExponencial`)
- Busqueda de Fibonacci (`busquedaFibonacci`)
- Busqueda ternaria (`busquedaTernaria`)

## Archivos

- `metodosBusqueda.h`: declaraciones de la biblioteca.
- `metodosBusqueda.c`: implementaciones de los algoritmos.
- `test.c`: pruebas de los metodos, incluidos enteros extremos y objetivos
  ausentes.
- `Makefile`: compilacion y ejecucion de pruebas.

## Requisitos

GCC (u otro compilador compatible con C11) y GNU Make.

## Compilar y probar

Desde la raiz del repositorio:

```sh
make
make test
```

Para eliminar el ejecutable:

```sh
make clean
```

## Usar la biblioteca

Los metodos distintos de busqueda lineal necesitan que el arreglo este
ordenado de forma ascendente.

```c
#include <stdio.h>
#include "metodosBusqueda.h"

int main(void)
{
    int datos[] = {-10, 0, 5, 12, 25, 40, 60, 80};
    int indice = busquedaBinaria(datos, 8, 25);

    if (indice != -1) {
        printf("Encontrado en el indice %d\n", indice);
    }
    return 0;
}
```

Compila tu programa junto con la implementacion:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic ejemplo.c metodosBusqueda.c -o ejemplo
```
