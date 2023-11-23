#include <iostream>
#include "arbolbinario.h"

using namespace std;

int main() {
    ArbolBinarioBusqueda arbol;

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
