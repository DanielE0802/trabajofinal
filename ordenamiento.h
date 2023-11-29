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

/**
 * Ordena un arreglo utilizando el algoritmo selectionSort.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void selectionSort(int arr[], int n);

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de ordenamiento burbuja.
 * 
 * @param arr El arreglo de enteros a ordenar.
 * @param n El tamaño del arreglo.
 */
void bubbleSort(int arr[], int n);

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento por inserción.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void insertionSort(int arr[], int n);

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento por mezcla.
 * 
 * @param arr El arreglo a ordenar.
 * @param l El índice del primer elemento del arreglo.
 * @param r El índice del último elemento del arreglo.
 */
void mergeSort(int arr[], int l, int r);

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento rápido.
 * 
 * @param arr El arreglo a ordenar.
 * @param low El índice del primer elemento del arreglo.
 * @param high El índice del último elemento del arreglo.
 */
void quickSort(int arr[], int low, int high);

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento por montículos.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void countingSort(int arr[], int n);

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de ordenamiento Radix Sort.
 * 
 * @param arr El arreglo de enteros a ordenar.
 * @param n La cantidad de elementos en el arreglo.
 */
void radixSort(int arr[], int n);

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento Shell Sort.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void shellSort(int arr[], int n);

#endif // ORDENAMIENTO_H