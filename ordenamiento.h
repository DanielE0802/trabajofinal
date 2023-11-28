#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * Lee un archivo CSV y devuelve un vector de enteros.
 * 
 * @param nombreArchivo El nombre del archivo CSV a leer.
 * @return Un vector de enteros con los datos leídos del archivo.
 */
vector<int> leerCSV(const string& nombreArchivo);

/**
 * Realiza una búsqueda binaria en un vector ordenado.
 * 
 * @param arr El vector ordenado en el que se realizará la búsqueda.
 * @param x El elemento que se desea buscar.
 * @return El índice del elemento encontrado, o -1 si no se encuentra.
 */
int busquedaBinaria(vector<int>& arr, int x);


#endif // ORDENAMIENTO_H