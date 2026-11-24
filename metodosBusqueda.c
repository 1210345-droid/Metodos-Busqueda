#include "metodosBusqueda.h"

#include <stddef.h>

int busquedaLineal(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == objetivo) return i;
    }
    return -1;
}

int busquedaBinaria(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;

    int bajo = 0;
    int alto = n - 1;
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        if (arr[medio] == objetivo) return medio;
        if (arr[medio] < objetivo) bajo = medio + 1;
        else alto = medio - 1;
    }
    return -1;
}

static int binaria_recursiva(const int arr[], int bajo, int alto, int objetivo)
{
    if (bajo > alto) return -1;
    int medio = bajo + (alto - bajo) / 2;
    if (arr[medio] == objetivo) return medio;
    if (arr[medio] > objetivo) {
        return binaria_recursiva(arr, bajo, medio - 1, objetivo);
    }
    return binaria_recursiva(arr, medio + 1, alto, objetivo);
}

int busquedaBinariaRecursiva(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;
    return binaria_recursiva(arr, 0, n - 1, objetivo);
}

int busquedaSalto(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;

    int salto = 1;
    while ((long long)salto * salto < n) salto++;
    int anterior = 0;
    int bloque = salto;

    while (bloque < n && arr[bloque] < objetivo) {
        anterior = bloque;
        bloque += salto;
    }
    if (bloque >= n) bloque = n - 1;

    for (int i = anterior; i <= bloque; i++) {
        if (arr[i] == objetivo) return i;
        if (arr[i] > objetivo) break;
    }
    return -1;
}

int busquedaInterpolacion(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;

    int bajo = 0;
    int alto = n - 1;
    while (bajo <= alto && objetivo >= arr[bajo] && objetivo <= arr[alto]) {
        if (arr[bajo] == arr[alto]) {
            return arr[bajo] == objetivo ? bajo : -1;
        }

        long long numerador =
            ((long long)objetivo - arr[bajo]) * (alto - bajo);
        long long denominador = (long long)arr[alto] - arr[bajo];
        long long posicion = bajo + numerador / denominador;
        if (posicion < bajo || posicion > alto) break;

        if (arr[posicion] == objetivo) return (int)posicion;
        if (arr[posicion] < objetivo) bajo = (int)posicion + 1;
        else alto = (int)posicion - 1;
    }
    return -1;
}

int busquedaExponencial(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;
    if (arr[0] == objetivo) return 0;

    int limite = 1;
    while (limite < n && arr[limite] <= objetivo) {
        if (limite > n / 2) {
            limite = n;
            break;
        }
        limite *= 2;
    }

    int bajo = limite / 2;
    int alto = limite < n ? limite : n - 1;
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        if (arr[medio] == objetivo) return medio;
        if (arr[medio] < objetivo) bajo = medio + 1;
        else alto = medio - 1;
    }
    return -1;
}

int busquedaFibonacci(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;

    long long fib2 = 0;
    long long fib1 = 1;
    long long fib = fib2 + fib1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    long long desplazado = -1;
    while (fib > 1) {
        long long i = desplazado + fib2;
        if (i >= n) i = n - 1;

        if (arr[(int)i] < objetivo) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            desplazado = i;
        } else if (arr[(int)i] > objetivo) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return (int)i;
        }
    }

    if (fib1 == 1 && desplazado + 1 < n &&
        arr[(int)(desplazado + 1)] == objetivo) {
        return (int)(desplazado + 1);
    }
    return -1;
}

int busquedaTernaria(const int arr[], int n, int objetivo)
{
    if (arr == NULL || n <= 0) return -1;

    int bajo = 0;
    int alto = n - 1;
    while (bajo <= alto) {
        int tercio = (alto - bajo) / 3;
        int medio1 = bajo + tercio;
        int medio2 = alto - tercio;

        if (arr[medio1] == objetivo) return medio1;
        if (arr[medio2] == objetivo) return medio2;

        if (objetivo < arr[medio1]) alto = medio1 - 1;
        else if (objetivo > arr[medio2]) bajo = medio2 + 1;
        else {
            bajo = medio1 + 1;
            alto = medio2 - 1;
        }
    }
    return -1;
}
