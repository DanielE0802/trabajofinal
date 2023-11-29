#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "arbolbinario.h"

using namespace std;

// ---------------------------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------------------------

/**
 * Ordena un arreglo utilizando el algoritmo selectionSort.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }

    // Imprimir el array ordenado
    cout << "Array ordenado con Selection Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// ---------------------------------------------------------------------------------------------

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de ordenamiento burbuja.
 * 
 * @param arr El arreglo de enteros a ordenar.
 * @param n El tamaño del arreglo.
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    // Imprimir el array ordenado
    cout << "Array ordenado con Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------------------------------------------

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento por inserción.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    // Imprimir el array ordenado
    cout << "Array ordenado con Insertion Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// ---------------------------------------------------------------------------------------------

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Ordena un arreglo utilizando el algoritmo de Merge Sort.
 * 
 * @param arr El arreglo a ordenar.
 * @param l El índice del primer elemento del arreglo.
 * @param r El índice del último elemento del arreglo.
 */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ---------------------------------------------------------------------------------------------

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * Ordena un arreglo utilizando el algoritmo de ordenamiento rápido.
 * 
 * @param arr El arreglo a ordenar.
 * @param low El índice del primer elemento del arreglo.
 * @param high El índice del último elemento del arreglo.
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------------------------------------------------------------------------------------

/**
 * Ordena un arreglo utilizando el algoritmo de Counting Sort.
 * 
 * @param arr El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void countingSort(int arr[], int n) {
    int output[n];
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Imprimir el array ordenado
    cout << "Array ordenado con Counting Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// ---------------------------------------------------------------------------------------------

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

/**
 * Ordena un arreglo de enteros utilizando el algoritmo de ordenamiento Radix Sort.
 * 
 * @param arr El arreglo de enteros a ordenar.
 * @param n La cantidad de elementos en el arreglo.
 */
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);

    // Imprimir el array ordenado
    cout << "Array ordenado con Radix Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// ---------------------------------------------------------------------------------------------

/**
 * Ordena un arreglo utilizando el algoritmo de Shell Sort.
 * 
 * @param arr El arreglo a ser ordenado.
 * @param n El tamaño del arreglo.
 */
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    
    // mostrar arreglo ordenado
    cout << "Arreglo ordenado con shellSort: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ---------------------------------------------------------------------------------------------