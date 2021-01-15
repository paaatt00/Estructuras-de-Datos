#include "PilaPedidos.h"

using namespace std;

// CONTRUCTORES Y DESTRUCTORES //

PilaPedidos::PilaPedidos()
{
    cima = NULL;
}

PilaPedidos::~PilaPedidos()
{

}

// MÉTODOS //

void PilaPedidos::apilar(Pedido p)
{
    NodoPila* nuevo = new NodoPila(p, cima);
    cima = nuevo; //la cima es el nuevo pedido
}

void PilaPedidos::desapilar()
{
    NodoPila* aux;
    if (cima) {
        aux = cima;
        cima = aux->siguiente_np;
        delete aux;
    } else {
        cout << "La pila esta vacia" << endl;
    }
}

void PilaPedidos::mostrarCima()
{
    if (esVacia()) {
        cout << "La pila esta vacia" << endl;
    } else {
        cout << "Cima pila: " << cima->pedido_np.imprimir() << endl;
    }
}

void PilaPedidos::apilarPrioridad(Pedido p) // hay que comprobar si es erroneo y si lo es pasarlo por la funcion
{
    PilaPedidos pilaAux;
    if (esVacia()) {
        apilar(p);
    } else {
        if (p.getTipoCliente() == "VIP" || p.getTipoCliente() == "NVIP") {
            apilar(p);
        } else { // para cuando son NR
            while (!esVacia() && getCimaPedido().getTipoCliente() != "NR") {
                pilaAux.apilar(getCimaPedido());
                desapilar();
            }
            apilar(p); // apilamos en esa posicion el nuevo pedido que entra
            while (!pilaAux.esVacia()) { // recolocamos de nuevo todos los pedidos de Registrados en la pila normal
                apilar(pilaAux.getCimaPedido());
                pilaAux.desapilar();
            }
        }
    }
}

int PilaPedidos::comprobarCimaRegistrado()
{
    int i;
    if (esVacia()) {
        return i = 0;
    } else {
        if (getCimaPedido().getTipoCliente() == "VIP") {
            i = 1;
        } else if (getCimaPedido().getTipoCliente() == "NVIP") {
            i = 2;
        } else {
            i = 3;
        }
    }
    return i;
}

// GETTERS Y SETTERS //

Pedido PilaPedidos::getCimaPedido()
{
    return cima->pedido_np;
}

bool PilaPedidos::esVacia()
{
    if (cima) {
        return false;
    } else {
        return true;
    }
}


