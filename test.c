#include <limits.h>
#include <stddef.h>
#include <stdio.h>

#include "metodosBusqueda.h"

typedef int (*MetodoBusqueda)(const int[], int, int);

typedef struct {
    const char *nombre;
    MetodoBusqueda metodo;
} PruebaMetodo;

int main(void)
{
    const int datos[] = {
        INT_MIN, INT_MIN, -100, -1, 0, 0, 1, 25, 100, INT_MAX
    };
    const int objetivos[] = {
        INT_MIN, -100, -1, 0, 1, 25, 100, INT_MAX,
        INT_MIN + 1, -101, 2, INT_MAX - 1
    };
    const PruebaMetodo metodos[] = {
        {"Lineal", busquedaLineal},
        {"Binaria", busquedaBinaria},
        {"Binaria recursiva", busquedaBinariaRecursiva},
        {"Salto", busquedaSalto},
        {"Interpolacion", busquedaInterpolacion},
        {"Exponencial", busquedaExponencial},
        {"Fibonacci", busquedaFibonacci},
        {"Ternaria", busquedaTernaria}
    };
    const int cantidad_datos = (int)(sizeof datos / sizeof datos[0]);
    int fallos = 0;

    for (size_t i = 0; i < sizeof metodos / sizeof metodos[0]; i++) {
        int metodo_correcto = 1;
        for (size_t j = 0; j < sizeof objetivos / sizeof objetivos[0]; j++) {
            int posicion = metodos[i].metodo(
                datos, cantidad_datos, objetivos[j]);
            int esperado = -1;
            for (int k = 0; k < cantidad_datos; k++) {
                if (datos[k] == objetivos[j]) {
                    esperado = k;
                    break;
                }
            }

            if ((esperado == -1 && posicion != -1) ||
                (esperado != -1 &&
                 (posicion < 0 || posicion >= cantidad_datos ||
                  datos[posicion] != objetivos[j]))) {
                metodo_correcto = 0;
                break;
            }
        }

        if (metodos[i].metodo(NULL, cantidad_datos, 0) != -1 ||
            metodos[i].metodo(datos, 0, 0) != -1) {
            metodo_correcto = 0;
        }

        printf("%-24s %s\n", metodos[i].nombre,
               metodo_correcto ? "OK" : "FALLO");
        if (!metodo_correcto) fallos++;
    }

    return fallos == 0 ? 0 : 1;
}
