#include "Correos.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// CONSTRUCTORES Y DESTRUCTORES //

Correos::Correos()
{

}

Correos::~Correos()
{

}

// MÉTODOS //

void Correos::lecturaTxt()
{
    string desc;
    string nombre;
    string dir;
    string type;
    long long creditCard;
    int time;
    ifstream fe;
    string str;
    fe.open("D:/Universidad/2º/1º cuatrimestre/Estructura de Datos 2.0/Laboratorio/Práctica 2/datos.txt", ios::in); //ruta de la ubicacion del txt
    if (fe.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    } else {
        do {
            getline(fe,str);
            str.empty();
            long posicion;
            posicion = str.find("//");
            desc = str.substr(0, posicion);
            str.erase(0, posicion + 2);
            long posicion1;
            posicion1 = str.find("//");
            nombre = str.substr(0, posicion1);
            str.erase(0, posicion1 + 2);
            long posicion2;
            posicion2 = str.find("//");
            dir = str.substr(0, posicion2);
            str.erase(0, posicion2 + 2);
            long posicion3;
            posicion3 = str.find("//");
            type = str.substr(0,posicion3);
            str.erase(0,posicion3 + 2);
            long posicion4;
            posicion4 = str.find("//");
            creditCard = std::stoll(str.substr(0,posicion4));
            str.erase(0,posicion4 + 2);
            long posicion5;
            posicion5 = str.find("//");
            time = stoi(str.substr(0, posicion5));
            str.erase(0,posicion5 + 2);
            Pedido pedido(desc, nombre, dir, type, creditCard, time);
            if (pedido.getTipoCliente() == "VIP" || pedido.getTipoCliente() == "NVIP"){
                colaRegistrados.encolar(pedido);
            }
            else if(pedido.getTipoCliente() == "NR"){
                colaNoRegistrados.encolar(pedido);
            }
        } while (!fe.eof());
        fe.close();
        cout << "----------------------------------------------------------\n";
        cout << "                    GESTION PEDIDOS                       \n";
        cout << "----------------------------------------------------------\n";
        cout << "Los pedidos de la cola de pedidos REGISTRADOS son: " << endl;
        colaRegistrados.mostrarCola();
        cout << "" << endl;
        cout << "Los pedidos de la cola de pedidos NO REGISTRADOS son: " << endl;
        colaNoRegistrados.mostrarCola();
        cout << "" << endl;
    }
}

void Correos::gestionCorreos()
{
    int contadorL = 1; //contador que usaremos para meter alternativamente los pedidos en las listas
    int contR = 1; //contador de pedidos Registrados iniciado a 0
    int contNR = 0;
    int tiempoTotal = 0;
    Pedido pedidoCR;
    Pedido pedidoCNR;
    Pedido pedidoPE;
    Pedido pedido1;
    Pedido pedido2;
    bool enviadoLista1 = true;
    bool enviadoLista2 = true;
    if (!colaRegistrados.esVacia()) {
        while (contR != 4) {
            if (!colaRegistrados.esVacia()) {
                pedidoCR = colaRegistrados.getPrimerPedido();
                colaRegistrados.desencolar();
                if (pedidoCR.comprobarPedidoErroneo()) {
                    cout << "Se apila en pila de pedidos erroneos: " << pedidoCR.imprimir() << endl;
                    pilaPedidosErroneos.apilarPrioridad(pedidoCR);
                } else {
                    if (contadorL % 2 == 0) {
                        listaPrepEnviar2.enlistarPrioridad(pedidoCR);
                        cout << "El pedido registrado introducido en la lista 2 es: " << pedidoCR.imprimir() << endl;

                    } else {
                        listaPrepEnviar1.enlistar(pedidoCR);
                        cout << "El pedido registrado introducido en la lista 1 es: " << pedidoCR.imprimir()<<endl;
                    }
                    contR++;
                    contadorL++;
                }
            } else {
                contR = 4;
            }
        }
   }
   if (!colaNoRegistrados.esVacia()) {
       while (contNR != 1) {
            if (!colaNoRegistrados.esVacia()) {
                pedidoCNR = colaNoRegistrados.getPrimerPedido();
                colaNoRegistrados.desencolar();
                if (pedidoCNR.comprobarPedidoErroneo()) {
                    cout << "Se apila en pila de pedidos erroneos: " << pedidoCNR.imprimir() << endl;
                    pilaPedidosErroneos.apilarPrioridad(pedidoCNR);
                } else {
                    if (contadorL % 2 == 0) {
                        listaPrepEnviar2.enlistarPrioridad(pedidoCNR);
                        cout << "El pedido no registrado introducido en la lista 2 es: " << pedidoCNR.imprimir() << endl;
                        contNR++;
                        contadorL++;
                    } else {
                        listaPrepEnviar1.enlistar(pedidoCNR);
                        cout << "El pedido no registrado introducido en la lista 1 es: " << pedidoCNR.imprimir() << endl;
                        contNR++;
                        contadorL++;
                    }
                }
            } else {
                contNR = 1;
            }
       }
    }
    contR = 0;
    contNR = 0;
    cout << "" << endl;
    while (!colaRegistrados.esVacia() || !colaNoRegistrados.esVacia() || !pilaPedidosErroneos.esVacia() || !listaPrepEnviar1.esVacia() || !listaPrepEnviar2.esVacia()) {
        if (!listaPrepEnviar1.esVacia() && enviadoLista1 == true) {
            cout << "" << endl;
            pedido1 = listaPrepEnviar1.getPrimerPedido();
            cout << "El pedido " << pedido1.imprimir() << " de la lista 1 entra en preparacion" << endl;
            cout << "" << endl;
            enviadoLista1 = false;
        }
        if (!listaPrepEnviar2.esVacia() && enviadoLista2 == true) {
             cout << "" << endl;
             pedido2 = listaPrepEnviar2.getPrimerPedido();
             cout << "El pedido " << pedido2.imprimir() << " de la lista 2 entra en preparacion" << endl;
             cout << "" << endl;
             enviadoLista2 = false;
        }
        if (listaPrepEnviar1.esVacia() && !listaPrepEnviar2.esVacia()) {
            enviadoLista1 = false;
        }
        if (listaPrepEnviar2.esVacia() && !listaPrepEnviar1.esVacia()) {
            enviadoLista2 = false;
        }
        while (enviadoLista1 == false && enviadoLista2 == false) {
            if (!listaPrepEnviar1.esVacia()) {
                if (pedido1.getTiempoPrepEnvio() > 0) {
                    pedido1.reducirTiempoPrepEnvio();
                    cout << "Al pedido " << pedido1.imprimir() << " le quedan " << pedido1.getTiempoPrepEnvio() + 1 << " minutos para ser enviado" << endl;
                    cout << "" << endl;
                } else {
                    cout << "El pedido " << pedido1.imprimir() << " esta listo para ser enviado" << endl;
                    cout << "" << endl;
                    arbolPedidosEnviados.gestionNodo(pedido1);
                    listaPrepEnviar1.desenlistar();
                    enviadoLista1 = true;
                }
            }
            if (!listaPrepEnviar2.esVacia()) {
                if (pedido2.getTiempoPrepEnvio() > 0) {
                    pedido2.reducirTiempoPrepEnvio();
                    cout << "Al pedido " << pedido2.imprimir() << " le quedan " << pedido2.getTiempoPrepEnvio() + 1 << " minutos para ser enviado" << endl;
                    cout << "" << endl;
                } else {
                    cout << "El pedido " << pedido2.imprimir() << " esta listo para ser enviado" << endl;
                    cout << "" << endl;
                    arbolPedidosEnviados.gestionNodo(pedido2);
                    listaPrepEnviar2.desenlistar();
                    enviadoLista2 = true;
                }
            }
            if (tiempoTotal % 2 == 0 && tiempoTotal != 0) {
                bool entradaLista1 = false;
                bool entradaLista2 = false;
                while ((entradaLista1 != true || entradaLista2 != true)) {
                    if (colaRegistrados.esVacia() && colaNoRegistrados.esVacia() && pilaPedidosErroneos.esVacia()){
                        entradaLista1 = true;
                        entradaLista2 = true;
                    }
                    if (!colaRegistrados.esVacia() && (entradaLista1 != true || entradaLista2 != true)) {
                        while (contR <= 3 && !colaRegistrados.esVacia() && (entradaLista1 != true || entradaLista2 != true)) {
                            if (!colaRegistrados.esVacia()) {
                                pedidoCR = colaRegistrados.getPrimerPedido();
                                colaRegistrados.desencolar();
                                if (pedidoCR.comprobarPedidoErroneo()) {
                                    pilaPedidosErroneos.apilarPrioridad(pedidoCR);
                                    cout << "Se apila en pila de pedidos erroneos: " << pedidoCR.imprimir() << endl;
                                } else {
                                    if (contadorL % 2 == 0) {
                                        listaPrepEnviar2.enlistarPrioridad(pedidoCR);
                                        cout << "El pedido registrado introducido en la lista 2 es: " << pedidoCR.imprimir() << endl;
                                        contR++;
                                        contadorL++;
                                        entradaLista2 = true;
                                    } else {
                                        listaPrepEnviar1.enlistar(pedidoCR);
                                        cout << "El pedido registrado introducido en la lista 1 es: " << pedidoCR.imprimir() << endl;
                                        contR++;
                                        contadorL++;
                                        entradaLista1 = true;
                                    }
                                }
                            } else {
                                contR = 3;
                            }
                        }
                    }
                    if (entradaLista1 != true || entradaLista2 != true) {
                        if (pilaPedidosErroneos.comprobarCimaRegistrado()==1 && !pilaPedidosErroneos.esVacia()) {
                            pedidoPE = pilaPedidosErroneos.getCimaPedido();
                            pilaPedidosErroneos.desapilar();
                            pedidoPE.completarPedido();
                            if (contadorL % 2 == 0) {
                                listaPrepEnviar2.enlistarPrioridad(pedidoPE);
                                cout << "Se corrige el pedido registrado y se introduce en la lista 2: " << pedidoPE.imprimir() << endl;
                                contNR++;
                                contadorL++;
                                entradaLista2 = true;
                            } else {
                                listaPrepEnviar1.enlistar(pedidoPE);
                                cout << "Se corrige el pedido registrado y se introduce en la lista 1: " << pedidoPE.imprimir() << endl;
                                contNR++;
                                contadorL++;
                                entradaLista1 = true;
                            }
                        } else {
                            if (!colaNoRegistrados.esVacia() && (entradaLista1 != true || entradaLista2 != true)) {
                                while (contNR != 1) {
                                    if (!colaNoRegistrados.esVacia()) {
                                        pedidoCNR = colaNoRegistrados.getPrimerPedido();
                                        colaNoRegistrados.desencolar();
                                        if (pedidoCNR.comprobarPedidoErroneo()) {
                                            cout << "Se apila en pila de pedidos erroneos: " << pedidoCNR.imprimir() << endl;
                                            pilaPedidosErroneos.apilarPrioridad(pedidoCNR);
                                        } else {
                                            if (contadorL % 2 == 0) {
                                                listaPrepEnviar2.enlistarPrioridad(pedidoCNR);
                                                cout << "El pedido no registrado introducido en la lista 2 es: " << pedidoCNR.imprimir() << endl;
                                                contNR++;
                                                contadorL++;
                                                entradaLista2 = true;
                                            } else {
                                                listaPrepEnviar1.enlistar(pedidoCNR);
                                                cout<<"El pedido no registrado introducido en la lista 1 es: " << pedidoCNR.imprimir() << endl;
                                                contNR++;
                                                contadorL++;
                                                entradaLista1 = true;
                                            }
                                        }
                                    } else {
                                        contNR = 1;
                                    }
                                }
                            } else {
                                if (!pilaPedidosErroneos.esVacia() && (entradaLista1 != true || entradaLista2 != true)) {
                                    pedidoPE = pilaPedidosErroneos.getCimaPedido();
                                    pilaPedidosErroneos.desapilar();
                                    pedidoPE.completarPedido();
                                    if (contadorL % 2 == 0) {
                                        listaPrepEnviar2.enlistarPrioridad(pedidoPE);
                                        cout << "Se corrige el pedido registrado y se introduce en la lista 2: " << pedidoPE.imprimir() << endl;
                                        contNR++;
                                        contadorL++;
                                        entradaLista2 = true;
                                    } else {
                                        listaPrepEnviar1.enlistar(pedidoPE);
                                        cout << "Se corrige el pedido registrado y se introduce en la lista 1: " << pedidoPE.imprimir() << endl;
                                        contNR++;
                                        contadorL++;
                                        entradaLista1 = true;
                                    }
                                }
                            }
                        }
                    }
                    if (colaNoRegistrados.esVacia() && pilaPedidosErroneos.esVacia()) {
                        contR = 0;
                    }
                    if (colaRegistrados.esVacia()) {
                        contNR = 0;
                    }
                    if (contNR == 1 && contR == 4) {
                        contNR = 0;
                        contR = 1;
                    }
                }
            }
            tiempoTotal++;
            cout << "" << endl;
        }
    }
    cout << "El tiempo total es de " << tiempoTotal << " minutos" << endl;
    cout << "Finaliza la gestion de pedidos" << endl;
    cout << "" << endl;
    //Comienza la gestion del arbol
    char opcion;
    string nom, articulo;
    do {
        cout << "" << endl;
        cout << "----------------------------------------------------------\n";
        cout << "                     GESTION ARBOL                        \n";
        cout << "----------------------------------------------------------\n";
        cout << "A. Buscar un cliente \n";
        cout << "B. Mostrar los clientes en preorden \n";
        cout << "C. Mostrar la altura del arbol de envios \n";
        cout << "D. Buscar un producto y cuantas veces se ha vendido \n";
        cout << "E. Mostrar los datos de los clientes VIP ordenados alfabeticamente \n";
        cout << "S. Salir del sistema\n\n";
        cout << "Introduce una opcion: ";
        cin >> opcion;
        cout << "" << endl;
        switch (opcion) {
            case 'A':
                {
                    cout << "Introduce un cliente: ";
                    cin >> nom;
                    cout << "" << endl;
                    cout << "Buscamos al cliente " << nom << " en el arbol: " << endl;
                    arbolPedidosEnviados.buscarCliente(nom);
                    break;
                }
            case 'B':
                {
                    cout << "El recorrido el arbol en preorden es : " << endl;
                    cout << "" << endl;
                    arbolPedidosEnviados.preorden(arbolPedidosEnviados.getRaiz());
                    break;
                }
            case 'C':
                {
                    cout << "La altura del arbol es: " << arbolPedidosEnviados.altura() << endl;
                    cout << "" << endl;
                    break;
                }
            case 'D':
                {
                    cout << "Introduce un articulo: " << endl;
                    cin >> articulo;
                    cout << "" << endl;
                    arbolPedidosEnviados.unidadesProducto(articulo);
                    break;
                }
            case 'E':
                {
                    cout << "La lista de clientes VIP con su informacion es: " << endl;
                    cout << "" << endl;
                    arbolPedidosEnviados.obtenerVIP();
                    break;
                }
            case 'S':
                cout << "" << endl;
                cout << "\nSaliendo del sistema\n";
                break;
            default:
                cout << "\nOpcion incorrecta!\n\n";
                break;
        }
    } while (opcion != 'S');
}
