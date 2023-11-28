#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "arbolbinario.h"

using namespace std;

/**
 * Lee un archivo CSV y devuelve un vector de enteros.
 * 
 * @param nombreArchivo El nombre del archivo CSV a leer.
 * @return Un vector de enteros con los datos leídos del archivo.
 */
vector<int> leerCSV(const string& nombreArchivo) {
    vector<int> numeros;
    ifstream archivo(nombreArchivo);
    string linea, valor;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        while (getline(ss, valor, ',')) {
            numeros.push_back(stoi(valor));
        }
    }

    return numeros;
}

/**
 * Realiza una búsqueda binaria en un vector ordenado para encontrar un elemento específico.
 * 
 * @param arr El vector ordenado en el que se realizará la búsqueda.
 * @param x El elemento que se desea encontrar.
 * @return La posición del elemento en el vector si se encuentra, -1 si no se encuentra.
 */
int busquedaBinaria(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}