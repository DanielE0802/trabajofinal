#include <iostream>
#include "arbolbinario.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;


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

int main() {
    ArbolBinarioBusqueda arbol;

    string nombreArchivo = "numeros.csv";
    vector<int> numeros = leerCSV(nombreArchivo);
        // Mostrar el arreglo ordenado
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    // Búsqueda binaria (por ejemplo, buscar el número 5)
    int resultado = busquedaBinaria(numeros, 5);
    cout << "El número 5 está en la posición: " << resultado << endl;

    // Implementar menu
    int opcion = 0;
    int submenu = 0;
    int valor = 0;

    do {
        cout << "-----------------------------------" << endl;
        cout << "Menu" << endl;
        cout << "1. Arbol Binario" << endl;
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
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opcion != 5);


    // Pause ejecución

    system("pause");


    return 0;
}
