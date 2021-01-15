#include <iostream>
#include "ColaPedidos.h"

using namespace std;

// CONTRUCTORES Y DESTRUCTORES //

ColaPedidos::ColaPedidos()
{
    primero = NULL;
    ultimo = NULL;
}

ColaPedidos::~ColaPedidos()
{

}

// MÉTODOS //

void ColaPedidos::encolar(Pedido p)
{
    NodoCola* aux = new NodoCola(p, NULL);
    if (primero) {
        ultimo->siguiente_nc = aux;
    } else {
        primero = aux;
    }
    ultimo = aux;
}

void ColaPedidos::desencolar()
{
    NodoCola* aux; //guardamos primero
    if (primero != NULL) { //podemos desencolar porque la cola no esta vacia
        aux = primero;
        primero = aux->siguiente_nc; // el nuevo primero es el siguiente al que desencolo
        delete aux;
    } else {
        cout << "La cola esta vacia" << endl;
    }
}

void ColaPedidos::mostrarCola()
{
    NodoCola* aux;
    aux = primero;
    if (esVacia()) {
        cout << "La cola esta vacia" << endl;
    } else {
        cout << "Pedidos dentro de la cola: " << endl;
        while (aux->siguiente_nc != NULL) {
            cout << aux->pedido_nc.imprimir() << endl;
            aux = aux->siguiente_nc;
        }
    }
}

// GETTERS Y SETTERS //

Pedido ColaPedidos::getPrimerPedido()
{
    return primero->pedido_nc;
}

NodoCola* ColaPedidos::getPrimero()
{
    return primero;
}

NodoCola* ColaPedidos::getUltimo()
{
    return ultimo;
}

bool ColaPedidos::esVacia()
{
    if (primero) {
        return false;
    } else {
        return true;
    }
}
