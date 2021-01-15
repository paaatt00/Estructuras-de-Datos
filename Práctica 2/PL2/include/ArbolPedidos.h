#ifndef ARBOLPEDIDOS_H
#define ARBOLPEDIDOS_H
#include "ListaPedidos.h"
#include "NodoArbol.h"
#include "Cliente.h"
#include <string>
#include <iostream>

using namespace std;

class ArbolPedidos
{
    private:
        NodoArbol* raizz;
        NodoArbol* izquierda;
        NodoArbol* derecha;

    public:
        // Constructores y Destructores
        ArbolPedidos();
        ArbolPedidos(NodoArbol *r);
        ~ArbolPedidos();
        // Métodos
        void inorden(NodoArbol* nabb); // el primer parametro que tenemos que meter es la raiz del arbol
        void preorden(NodoArbol* nabb);
        void postorden(NodoArbol* nabb);
        void insertar(Cliente c);
        void insertar(Cliente c, NodoArbol*&); // paso por referancia para que el arbol se modifique
        void mostrarArbol(NodoArbol* nodo, int contador);
        void gestionNodo(Pedido p);
        void gestionNodo(Pedido p, NodoArbol*& nabb);
        void buscarCliente(string nombre);
        void buscarCliente(string nombre, NodoArbol*& nabb);
        int altura();
        int altura(NodoArbol*& nabb);
        void unidadesProducto(string descripcion);
        int unidadesProducto(string descripcion, int cont, NodoArbol*& nabb);
        void obtenerVIP();
        ListaPedidos obtenerVIP(ListaPedidos listaVIP, NodoArbol*& nabb);
        // Getters y Setters
        NodoArbol* getRaiz();
        void setRaiz(NodoArbol* r);
        Cliente getRaizPedido();
};

#endif // ARBOLPEDIDOS_H
