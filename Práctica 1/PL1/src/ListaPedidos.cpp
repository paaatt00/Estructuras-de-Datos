#include "ListaPedidos.h"

// CONTRUCTORES Y DESTRUCTORES //

ListaPedidos::ListaPedidos()
{
    primero = NULL;
    ultimo = NULL;
}

ListaPedidos::~ListaPedidos()
{

}

// MÉTODOS //

void ListaPedidos::enlistar(Pedido p)
{
    insertarDerecha(p);
    //insertarIzquierda(p);
}

void ListaPedidos::insertarDerecha(Pedido p)
{
    NodoLista* nodo_nuevo;
    if (!primero) { //lista vacia
        nodo_nuevo = new NodoLista (p, NULL, NULL);
        primero = nodo_nuevo;
    } else {
        nodo_nuevo = new NodoLista (p, ultimo, NULL);
        ultimo->siguiente_nl = nodo_nuevo;
    }
    ultimo = nodo_nuevo;  // el NUEVO ultimo es el nuevo que meto
}

void ListaPedidos::insertarIzquierda(Pedido p) //no lo utilizamos pero es una funcion propia de listas
{
    NodoLista* nodo_nuevo;
    if (!primero) { //lista vacia
        nodo_nuevo = new NodoLista (p, NULL, NULL);
    } else {
        nodo_nuevo = new NodoLista (p, NULL, primero);
    }
    primero = nodo_nuevo;  // el NUEVO primero es el nuevo que meto
}

void ListaPedidos::desenlistar() // Sacamos hacia el primer pedido de la lista
{
    NodoLista* nodo_aux; //guardamos primero
    if (primero != NULL) { //podemos desenlistar porque la lista no esta vacia
        nodo_aux = primero;
        primero = nodo_aux->siguiente_nl; // El nuevo primero es el siguiente al que desenlisto
        delete nodo_aux; // borrarlo de memoria
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

void ListaPedidos::mostrarLista()
{
    if (primero) {
        NodoLista* nodo;
        nodo = primero;
        while(nodo != ultimo->siguiente_nl) {
            cout << nodo->pedido_nl.imprimir() << endl;
            nodo = nodo->siguiente_nl;
        }
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

// GETTERS Y SETTERS //

bool ListaPedidos::esVacia()
{
    if (primero) {
        return false;
    } else {
        return true;
    }
}

Pedido ListaPedidos::getPrimerPedido()
{
    return primero->pedido_nl;
}

Pedido ListaPedidos::getUltimoPedido()
{
    return ultimo->pedido_nl;
}
