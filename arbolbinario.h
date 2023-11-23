#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    
    Nodo(int valor); // Declaración del constructor
};

struct ArbolBinarioBusqueda {
    Nodo* raiz;

    ArbolBinarioBusqueda(); // Declaración del constructor
    
    void insertar(int valor);
    Nodo* eliminar(Nodo* nodo, int valor);
    Nodo* buscar(Nodo* nodo, int valor);
    void mostrar(Nodo* raiz);
    Nodo* minimoNodo(Nodo* nodo);
};

#endif // ARBOLBINARIO_H
