#include "ListaPedidos.h"
#include "PilaPedidos.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


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

void ListaPedidos::insertarIzquierda(Pedido p)
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

void ListaPedidos::enlistarCliente(Cliente c)
{
    insertarDerechaCliente(c);
    //insertarIzquierdaCliente(c);
}

void ListaPedidos::insertarDerechaCliente(Cliente c)
{
    NodoLista* nodo_nuevo;
    if (!primero) { //lista vacia
        nodo_nuevo = new NodoLista (c, NULL, NULL);
        primero = nodo_nuevo;
    } else {
        nodo_nuevo = new NodoLista (c, ultimo, NULL);
        ultimo->siguiente_nl = nodo_nuevo;
    }
    ultimo = nodo_nuevo;  // el NUEVO ultimo es el nuevo que meto
}

void ListaPedidos::insertarIzquierdaCliente(Cliente c)
{
    NodoLista* nodo_nuevo;
    if (!primero) { //lista vacia
        nodo_nuevo = new NodoLista (c, NULL, NULL);
    } else {
        nodo_nuevo = new NodoLista (c, NULL, primero);
    }
    primero = nodo_nuevo;  // el NUEVO primero es el nuevo que meto
}

void ListaPedidos::enlistarPrioridad(Pedido p) // hay que comprobar si es erroneo y si lo es pasarlo por la funcion
{
    PilaPedidos pilaAux;
    if (esVacia()) {
        enlistar(p);
    } else {
        if (p.getTipoCliente() == "VIP") {
            while (!esVacia() && getPrimerPedido().getTipoCliente() == "VIP") {
                pilaAux.apilar(getPrimerPedido());
                desenlistar();
            }
            insertarIzquierda(p);
            while (!pilaAux.esVacia()) {
                insertarIzquierda(pilaAux.getCimaPedido());
                pilaAux.desapilar();
            }
        } else if (p.getTipoCliente() == "NVIP") {
            while (!esVacia() && getPrimerPedido().getTipoCliente() != "NR") {
                pilaAux.apilar(getPrimerPedido());
                desenlistar();
            }
            insertarIzquierda(p); //enlistamos en esa posicion el nuevo pedido que entra
            while (!pilaAux.esVacia()) { // recolocamos de nuevo todos los pedidos de Registrados en la lista normal
                insertarIzquierda(pilaAux.getCimaPedido());
                pilaAux.desapilar();
            }
        } else { // para cuando son NR
            insertarDerecha(p); //enlistamos en esa posicion el nuevo pedido que entra
        }
    }
}

void ListaPedidos::mostrarLista()
{
    if (primero) {
        NodoLista* nodo;
        nodo = primero;
        while (nodo != ultimo->siguiente_nl) {
            cout << nodo->pedido_nl.imprimir() << endl;
            nodo = nodo->siguiente_nl;
        }
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

void ListaPedidos::mostrarListaPeques()
{
    if (primero) {
        NodoLista* nodo;
        nodo = primero;
        while (nodo != ultimo->siguiente_nl) {
            cout << nodo->pedido_nl.imprimirPeque() << endl;
            nodo = nodo->siguiente_nl;
        }
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

void ListaPedidos::mostrarListaCliente()
{
    if (primero) {
        NodoLista* nodo;
        nodo = primero;
        while (nodo != ultimo->siguiente_nl) {
            cout << nodo->cliente_nl.imprimir() << endl;
            nodo = nodo->siguiente_nl;
        }
    } else {
        cout << "La lista esta vacia" << endl;
    }
}

void ListaPedidos::ordenarLista(Cliente c)
{
    NodoLista* p = new NodoLista(c, NULL, NULL);
    if (esVacia()) {
        primero = p;
        ultimo = p;
    } else {
        if (c.getNombreCliente().compare(primero->cliente_nl.getNombreCliente()) < 0) {
            p->siguiente_nl = primero;
            primero->anterior_nl = p;
            primero = p;
        } else {
            NodoLista* aux = primero;
            while (aux != NULL && c.getNombreCliente().compare(aux->cliente_nl.getNombreCliente()) > 0) {
                aux = aux->siguiente_nl;
            }
            if (aux == NULL) {
                ultimo->siguiente_nl = p;
                p->anterior_nl = ultimo;
                ultimo = p;
            } else {
                p->siguiente_nl = aux;
                aux->anterior_nl->siguiente_nl = p;
                p->anterior_nl = aux->anterior_nl;
                aux->anterior_nl = p;
            }
        }
    }
}

int ListaPedidos::contar(string descripcion)
{
    int cont = 0;
    NodoLista* aux = primero;
    while (aux != NULL) {
        if (aux->pedido_nl.getDescripcionArt() == descripcion) {
            cont += 1;
        }
        aux = aux->siguiente_nl;
    }
    return cont;
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

NodoLista* ListaPedidos::getPrimero()
{
    return primero;
}

void ListaPedidos::setPrimero(Pedido p)
{
    primero->pedido_nl = p;
}

Pedido ListaPedidos::getPrimerPedido()
{
    return primero->pedido_nl;
}

Pedido ListaPedidos::getUltimoPedido()
{
    return ultimo->pedido_nl;
}
