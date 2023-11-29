#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "arbolbinario.h"
#include "ordenamiento.h"

#include <clocale>

using namespace std;

void showArrayOriginal(vector<int> original) {
    cout << "-----------------------------------" << endl;
    cout << "Array original: ";
    for (int i = 0; i < original.size(); i++) {
        cout << original[i] << " ";
    }
    cout << endl;
}


int main() {
        setlocale(LC_ALL, "Spanish");

    ArbolBinarioBusqueda arbol;
    string nombreArchivo = "numeros.csv";
    vector<int> numeros = leerCSV(nombreArchivo);
    vector<int> original = numeros;

    // Búsqueda binaria (por ejemplo, buscar el número 5)
    // int resultado = busquedaBinaria(numeros, 5);
    // cout << "El número 5 está en la posición: " << resultado << endl;

    // Implementar menu
    int opcion = 0;
    int submenu = 0;
    int valor = 0;

    do {
        cout << endl;
        cout << "-----------------------------------" << endl;
        cout << "Menu" << endl;
        cout << "1. Arbol Binario" << endl;
        wcout << L"2. métodos de ordenamiento (apartir de un csv)" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "- 1 Insertar" << endl;
                cout << "- 2. Eliminar" << endl;
                cout << "- 3. Buscar" << endl;
                cout << "- 4. Mostrar" << endl;
                cout << "- 5. Salir" << endl;
                cin >> submenu;

                switch (submenu) {
                    case 1:
                        cout << "--Ingrese el valor a insertar" << endl;
                        cin >> valor;
                        arbol.insertar(valor);
                        break;
                    case 2:
                        cout << "--Ingrese el valor a eliminar" << endl;
                        cin >> valor;
                        arbol.eliminar(arbol.raiz, valor);
                        break;
                    case 3:
                        cout << "--Ingrese el valor a buscar" << endl;
                        cin >> valor;
                        arbol.buscar(arbol.raiz, valor);
                        break;
                    case 4:
                        cout << "-----------------------------------" << endl;
                        arbol.mostrar(arbol.raiz);
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                        break;
                }
                break;
            case 2:
                cout << "-----------------------------------" << endl;
                cout << "Elija el método de ordenamiento para el archivo csv cargado (llamado 'numeros.csv'):" << endl;
                cout << "" << endl;
                cout << "- 1. Selection Sort" << endl;
                cout << "- 2. Bubble Sort" << endl;
                cout << "- 3. Insertion Sort" << endl;
                cout << "- 4. Merge Sort" << endl;
                cout << "- 5. Quick Sort" << endl;
                cout << "- 6. Counting Sort" << endl;
                cout << "- 7. Radix Sort" << endl;
                cout << "- 8. Shell Sort" << endl;
                cout << "- 9. Restaurar array original" << endl;
                cout << "- 10. Salir" << endl;
                cin >> submenu;
                // Guardar array original

                switch (submenu) {

                    case 1:
                        showArrayOriginal(original);                      
                        selectionSort(numeros.data(), numeros.size());
                        break;
                    case 2:
                        showArrayOriginal(original);                      
                        bubbleSort(numeros.data(), numeros.size());
                        break;
                    case 3:
                        showArrayOriginal(original);                      
                        insertionSort(numeros.data(), numeros.size());
                        break;
                    case 4:
                        showArrayOriginal(original);                      
                        mergeSort(numeros.data(), 0, numeros.size() - 1);
                        // Imprimir el array ordenado
                        cout << "Array ordenado con Merge Sort: ";
                        for (int i = 0; i < numeros.size(); i++) {
                            cout << numeros[i] << " ";
                        }
                        cout << endl;
                        break;
                    case 5:
                        showArrayOriginal(original);                      
                        quickSort(numeros.data(), 0, numeros.size() - 1);
                        // Imprimir el array ordenado
                        cout << "Array ordenado con Quick Sort: ";
                        for (int i = 0; i < numeros.size(); i++) {
                            cout << numeros[i] << " ";
                        }
                        cout << endl;
                        break;
                    case 6:
                        showArrayOriginal(original);                      
                        countingSort(numeros.data(), numeros.size());
                        break;
                    case 7:
                        showArrayOriginal(original);                      
                        radixSort(numeros.data(), numeros.size());
                        break;
                    case 8:
                        showArrayOriginal(original);                      
                        shellSort(numeros.data(), numeros.size());
                        break;
                    case 9:
                        numeros = original;
                        cout << "Array restaurado a su estado original" << endl;
                        break;
                    case 10:
                        break;
                    default:
                        cout << "Opcion no valida" << endl;
                        break;
                }
                break;
                
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opcion != 5);


    // Pause ejecución

    system("pause");


    return 0;
}
