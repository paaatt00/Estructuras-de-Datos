#include "ArbolPedidos.h"
#include "ListaPedidos.h"
#include "Cliente.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// CONTRUCTORES Y DESTRUCTORES //

ArbolPedidos::ArbolPedidos()
{
    raizz = NULL;
    izquierda = NULL;
    derecha = NULL;
}

ArbolPedidos::ArbolPedidos(NodoArbol *r)
{
    this->raizz = r;
}

ArbolPedidos::~ArbolPedidos()
{
    //dtor
}

// MÉTODOS //

void ArbolPedidos::inorden(NodoArbol* nabb) //el primer parametro que tenemos que meter es la raiz del arbol
{
    if (nabb != NULL) {  //la raiz distinta de nulo
        inorden(nabb->izquierda_na);
        cout << nabb->cliente_na.imprimir() << endl;
        inorden(nabb->derecha_na);
    }
}

void ArbolPedidos::preorden(NodoArbol* nabb) //el primer parametro que tenemos que meter es la raiz del arbol
{
    if (nabb != NULL) {  //la raiz distinta de nulo
        cout << "---" << endl;
        cout << "Cliente: " << nabb->cliente_na.imprimir() << endl;
        cout << "Pedidos de " << nabb->cliente_na.getNombreCliente() << ":" << endl;
        nabb->lista_na.mostrarListaPeques();
        preorden(nabb->izquierda_na);
        preorden(nabb->derecha_na);

    }
}

void ArbolPedidos::postorden(NodoArbol* nabb) //el primer parametro que tenemos que meter es la raiz del arbol
{
    if (nabb != NULL) {  //la raiz distinta de nulo
        preorden(nabb->izquierda_na);
        preorden(nabb->derecha_na);
        cout << nabb->cliente_na.imprimir() << endl;
    }
}

void ArbolPedidos::insertar(Cliente c){
    insertar(c, raizz); //funcion para introducir usando solo pedido
}

void ArbolPedidos::insertar(Cliente c, NodoArbol*& nabb)    //nabb va a ser la raiz cuando lo llamemos por primera vez
{
    NodoArbol* nodo_nuevo = new NodoArbol(c, NULL, NULL);
    if (c.getNombreCliente().compare(nabb->cliente_na.getNombreCliente()) < 0) { //si el nombre es menor o igual, es decir, por la izquierda
        if (nabb->izquierda_na == NULL) { //si el nodo izq esta vacio
            nabb->izquierda_na = nodo_nuevo;
        } else {
            insertar(c, nabb->izquierda_na);
        }
    } else { //mayor, es decir, por la derecha
        if (nabb->derecha_na == NULL) { //si el nodo dcho esta vacio
            nabb->derecha_na = nodo_nuevo;
        } else {
            insertar(c, nabb->derecha_na);
        }
    }
}

void ArbolPedidos::mostrarArbol(NodoArbol* nodo, int contador)
{
    if (!nodo) { //nodo == NULL arbol esta vacio
        return;
    } else { //arbol no vacio
        mostrarArbol(nodo->derecha_na, contador + 1);
        for (int i = 0; i<contador; i++) {
            cout << "  ";
        }
        cout << nodo->cliente_na.imprimir() << endl;
        mostrarArbol(nodo->izquierda_na, contador + 1);
    }
}

void ArbolPedidos::gestionNodo(Pedido p){
    gestionNodo(p, raizz); //funcion para introducir usando solo pedido
}

void ArbolPedidos::gestionNodo(Pedido p, NodoArbol*& nabb)
{
    Cliente c;
    c = Cliente(p.getNombreCliente(), p.getTipoCliente(), p.getNumTarjeta());
    Pedido peque;
    peque = Pedido(p.getDescripcionArt(), p.getDireccionEntrega(), p.getTiempoPrepEnvio());
    NodoArbol* nodo_nuevo = new NodoArbol(c, NULL, NULL);
    if (!nabb) {
        nabb = nodo_nuevo;
        raizz = nabb;
        nabb->lista_na.enlistar(peque);
        cout << "Los pedidos de " << c.getNombreCliente() << " son: " << endl;
        nabb->lista_na.mostrarListaPeques();
        cout << "" << endl;
    } else {
        if (c.getNombreCliente().compare(nabb->cliente_na.getNombreCliente()) == 0) { //Compara strings y si son iguales enlista descripcion pedido
            nabb->lista_na.enlistar(peque);
            cout << "Los pedidos de " << c.getNombreCliente() << " son: " << endl;
            nabb->lista_na.mostrarListaPeques();
            cout << "" << endl;
        } else if (c.getNombreCliente().compare(nabb->cliente_na.getNombreCliente()) > 0) { //Compara strings y si es menor se va por la izquierda
            if (nabb->izquierda_na == NULL) { //si el nodo izq esta vacio
                nabb->izquierda_na = nodo_nuevo;
                nodo_nuevo->lista_na.enlistar(peque);
                cout << "Los pedidos de " << c.getNombreCliente() << " son: " << endl;
                nodo_nuevo->lista_na.mostrarListaPeques();
                cout << "" << endl;
            } else {
                gestionNodo(p, nabb->izquierda_na);
            }
        } else {
            if (nabb->derecha_na == NULL) { //si el nodo dcho esta vacio
                nabb->derecha_na = nodo_nuevo;
                nodo_nuevo->lista_na.enlistar(peque);
                cout << "Los pedidos de " << c.getNombreCliente() << " son: " << endl;
                nodo_nuevo->lista_na.mostrarListaPeques();
                cout << "" << endl;
            } else {
                gestionNodo(p, nabb->derecha_na);
            }
        }
    }
}

void ArbolPedidos::buscarCliente(string nombre)
{
    buscarCliente(nombre, raizz);
}

void ArbolPedidos::buscarCliente(string nombre, NodoArbol*& nabb)
{
    if (!nabb) {
        cout << "El arbol esta vacio" << endl;
        cout << "" << endl;
    } else {
        if (nombre.compare(nabb->cliente_na.getNombreCliente()) == 0) {
            cout << "El cliente " << nombre << " ha sido encontrado en el arbol y sus pedidos son: " << endl;
            nabb->lista_na.mostrarListaPeques();
            cout << "" << endl;
        } else if (nombre.compare(nabb->cliente_na.getNombreCliente()) > 0) { //Compara strings y si es menor se va por la izquierda
            if (nabb->izquierda_na == NULL) {
                cout << "No se ha encontrado ningun cliente con el nombre " << nombre << endl;
                cout << "" << endl;
            } else {
                buscarCliente(nombre, nabb->izquierda_na);
            }
        } else {
            if (nabb->derecha_na == NULL) {
                cout << "No se ha encontrado ningun cliente con el nombre " << nombre << endl;
                cout << "" << endl;
            } else {
                buscarCliente(nombre, nabb->derecha_na);
            }
        }
    }
}

int ArbolPedidos::altura()
{
    ArbolPedidos::altura(raizz);
}

int ArbolPedidos::altura(NodoArbol*& nabb)
{
    if (!nabb) {
        return 0;
    } else {
        int alturaIzq = altura(nabb->izquierda_na);
        int alturaDer = altura(nabb->derecha_na);
        if (alturaIzq > alturaDer) {
            return alturaIzq + 1;
        } else {
            return alturaDer + 1;
        }
    }
}

void ArbolPedidos::unidadesProducto(string descripcion)
{
    int cont = 0;
    cont = unidadesProducto(descripcion, cont, raizz);
    cout << "El producto " << descripcion << " se ha comprado " << cont << " veces" << endl;
}

int ArbolPedidos::unidadesProducto(string descripcion, int cont, NodoArbol*& nabb)
{
    if (!nabb) {
        cout << "El arbol esta vacio" << endl;
    } else {
        cont += nabb->lista_na.contar(descripcion);
        if (nabb->izquierda_na != NULL) {
            cont = unidadesProducto(descripcion, cont, nabb->izquierda_na);
        }
        if (nabb->derecha_na != NULL) {
            cont = unidadesProducto(descripcion, cont, nabb->derecha_na);
        }
    }
    return cont;
}

void ArbolPedidos::obtenerVIP()
{
    ListaPedidos listaVIP;
    listaVIP = obtenerVIP(listaVIP, raizz);
    listaVIP.mostrarListaCliente();
}

ListaPedidos ArbolPedidos::obtenerVIP(ListaPedidos listaVIP, NodoArbol*& nabb)
{
    if (!nabb) {
        cout << "El arbol esta vacio" << endl;
    } else {
        if (nabb->cliente_na.getTipoCliente() == "VIP") {
            listaVIP.ordenarLista(nabb->cliente_na);
        }
        if (nabb->izquierda_na != NULL) {
            listaVIP = obtenerVIP(listaVIP, nabb->izquierda_na);
        }
        if (nabb->derecha_na != NULL) {
            listaVIP = obtenerVIP(listaVIP, nabb->derecha_na);
        }
    }
    return listaVIP;
}

// GETTERS Y SETTERS //

NodoArbol* ArbolPedidos::getRaiz()
{
    return raizz;
}

void ArbolPedidos::setRaiz(NodoArbol* r)
{
    raizz = r;
}

Cliente ArbolPedidos::getRaizPedido()
{
    return raizz->cliente_na;
}
