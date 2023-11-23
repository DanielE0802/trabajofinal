#include <iostream>
#include <queue>
#include "arbolbinario.h"

using namespace std;

// Constructor de Nodo
Nodo::Nodo(int valor) : dato(valor), izq(nullptr), der(nullptr) {}

// Constructor de ArbolBinarioBusqueda
ArbolBinarioBusqueda::ArbolBinarioBusqueda() : raiz(nullptr) {}


// Métodos

// Añade un nuevo nodo al árbol. Si el árbol está vacío, el nuevo nodo se convierte en la raíz. 
// Si no, se compara el valor con el nodo actual y se inserta en el subárbol izquierdo o derecho según corresponda.
void ArbolBinarioBusqueda::insertar(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (raiz == nullptr) {
        raiz = nuevo;
    } else {
        Nodo* actual = raiz;
        Nodo* padre;
        
        while (true) {
            padre = actual;
            if (valor < actual->dato) {
                actual = actual->izq;
                if (actual == nullptr) {
                    padre->izq = nuevo;
                    return;
                }
            } else {
                actual = actual->der;
                if (actual == nullptr) {
                    padre->der = nuevo;
                    return;
                }
            }
        }
    }
}

// Elimina un nodo del árbol. Hay tres casos: eliminación de un nodo sin hijos, con un hijo, o con dos hijos.
Nodo* ArbolBinarioBusqueda::eliminar(Nodo* nodo, int valor) {
    if (nodo == nullptr) return nodo;
    if (valor < nodo->dato) nodo->izq = eliminar(nodo->izq, valor);
    else if (valor > nodo->dato) nodo->der = eliminar(nodo->der, valor);
    else {
        if (nodo->izq == nullptr) {
            Nodo* temp = nodo->der;
            delete nodo;
            return temp;
        } else if (nodo->der == nullptr) {
            Nodo* temp = nodo->izq;
            delete nodo;
            return temp;
        }
        
        Nodo* temp = minimoNodo(nodo->der);
        nodo->dato = temp->dato;
        nodo->der = eliminar(nodo->der, temp->dato);
    }
    return nodo;
}

// Encuentra un nodo en el árbol. Si el valor buscado es menor/mayor que el nodo actual, busca en el subárbol izquierdo/derecho.
Nodo* ArbolBinarioBusqueda::buscar(Nodo* nodo, int valor) {
    if (nodo == nullptr || nodo->dato == valor) return nodo;
    if (valor < nodo->dato) return buscar(nodo->izq, valor);
    return buscar(nodo->der, valor);
}

// Muestra el árbol de forma gráfica (lado derecho arriba y lado izquierdo abajo).
void ArbolBinarioBusqueda::mostrar(Nodo* raiz){
    if (!raiz) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        int tamanoNivel = cola.size();
        while (tamanoNivel > 0) {
            Nodo* nodo = cola.front();
            cola.pop();
            std::cout << nodo->dato << " ";
            if (nodo->izq) cola.push(nodo->izq);
            if (nodo->der) cola.push(nodo->der);
            tamanoNivel--;
        }
        std::cout << std::endl;
    }
}

// Encuentra el nodo con el valor mínimo en un subárbol dado.
Nodo* ArbolBinarioBusqueda::minimoNodo(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izq != nullptr) actual = actual->izq;
    return actual;
}

// ---------------------------------------------------------------------------------------------
