#include "Correos.h"
#include <iostream>

using namespace std;

// CONSTRUCTORES Y DESTRUCTORES //

Correos::Correos()
{

}

Correos::~Correos()
{

}

// MÉTODOS //

void Correos::gestionCorreos(ColaPedidos colaRegistrados, ColaPedidos colaNoRegistrados)
{
    ListaPedidos listaPrepEnviar;
    PilaPedidos pilaPedidosErroneos;
    Pedido pedido, pedidoCR, pedidoCNR, pedidoPE;
    // Metemos los primeros elementos de la lista de pedidos para enviar
    if (!colaRegistrados.esVacia()) {
        int contR = 0;
        while (contR != 3) {
            if (!colaRegistrados.esVacia()) {
                pedido = colaRegistrados.getPrimerPedido();
                colaRegistrados.desencolar();
                if (pedido.comprobarPedidoErroneo()) {
                    pilaPedidosErroneos.apilarPrioridad(pedido);
                    cout << "Se apila en pila de pedidos erroneos: " << pedido.imprimir() << endl;
                } else {
                    listaPrepEnviar.enlistar(pedido);
                    cout << "El pedido registrado introducido en la lista es: " << pedido.imprimir() << endl;
                    contR++;
                }
            } else {
                contR = 3;
            }
        }
    }
    if (!colaNoRegistrados.esVacia()) {
        int contNR = 0;
        while (contNR != 1) {
            if (!colaNoRegistrados.esVacia()) {
                pedido = colaNoRegistrados.getPrimerPedido();
                colaNoRegistrados.desencolar();
                if (pedido.comprobarPedidoErroneo()) {
                    pilaPedidosErroneos.apilarPrioridad(pedido);
                    cout << "Se apila en pila de pedidos erroneos: " << pedido.imprimir() << endl;
                } else {
                    listaPrepEnviar.enlistar(pedido);
                    cout << "El pedido no registrado introducido en la lista es: " << pedido.imprimir() << endl;
                    contNR++;
                }
            } else {
                contNR = 1;
            }
        }
    }
    int tiempoTotal = 0;
    while (!listaPrepEnviar.esVacia() || !colaRegistrados.esVacia() || !colaNoRegistrados.esVacia() || !pilaPedidosErroneos.esVacia()) {
        // Procesamos el primer pedido de la lista
        if (!listaPrepEnviar.esVacia()) {
            cout << "" << endl;
            pedido = listaPrepEnviar.getPrimerPedido();
            cout << "El pedido " << pedido.imprimir() << " entra en preparacion" << endl;
            while (pedido.getTiempoPrepEnvio() != 0) {
                cout << "Al pedido " << pedido.imprimir() << " le faltan " << pedido.getTiempoPrepEnvio() << " minutos" << endl;
                pedido.reducirTiempoPrepEnvio();
                tiempoTotal++;
            }
            cout << "El pedido " << pedido.imprimir() << " esta listo para ser enviado" << endl;
            cout << "" << endl;
            listaPrepEnviar.desenlistar(); // Enviamos el primer pedido de la lista
        }
        // Introducimos tres pedidos nuevos de la cola de registrados
        if (!colaRegistrados.esVacia()) {
            int contCR = 0;
            while (contCR != 3) {
                if (!colaRegistrados.esVacia()) {
                    pedidoCR = colaRegistrados.getPrimerPedido();
                    colaRegistrados.desencolar();
                    if (pedidoCR.comprobarPedidoErroneo()) {
                        pilaPedidosErroneos.apilarPrioridad(pedidoCR);
                        cout << "Se apila en pila de pedidos erroneos: " << pedidoCR.imprimir() << endl;
                    } else {
                        listaPrepEnviar.enlistar(pedidoCR);
                        cout << "El pedido registrado introducido en la lista es: " << pedidoCR.imprimir() << endl;
                        contCR++;
                    }
                } else {
                    contCR = 3;
                }
            }
        }
        // Introducimos un pedido de la cola de no registrados o de la pila de pedidos erroneos
        if (!pilaPedidosErroneos.esVacia() || !colaNoRegistrados.esVacia()) {
            if (pilaPedidosErroneos.comprobarCimaRegistrado() == 1) {
                pedidoPE = pilaPedidosErroneos.getCimaPedido();
                pilaPedidosErroneos.desapilar();
                pedidoPE.completarPedido();
                cout << "Se corrige el pedido " << pedidoPE.imprimir() << endl;
                listaPrepEnviar.enlistar(pedidoPE);
                cout << "El pedido registrado introducido en la lista es: " << pedidoPE.imprimir() << endl;
            } else if (!colaNoRegistrados.esVacia()) {
                int contCNR = 0;
                while (contCNR != 1) {
                    if (!colaNoRegistrados.esVacia()) {
                        pedidoCNR = colaNoRegistrados.getPrimerPedido();
                        colaNoRegistrados.desencolar();
                        if (pedidoCNR.comprobarPedidoErroneo()) {
                            pilaPedidosErroneos.apilarPrioridad(pedidoCNR);
                            cout << "Se apila en pila de pedidos erroneos: " << pedidoCNR.imprimir() << endl;
                        } else {
                            listaPrepEnviar.enlistar(pedidoCNR);
                            cout << "El pedido no registrado introducido en la lista es: " << pedidoCR.imprimir() << endl;
                            contCNR++;
                        }
                    } else {
                        contCNR = 1;
                    }
                }
            } else {
                pedidoPE = pilaPedidosErroneos.getCimaPedido();
                pilaPedidosErroneos.desapilar();
                pedidoPE.completarPedido();
                cout << "Se corrige el pedido " << pedidoPE.imprimir() << endl;
                listaPrepEnviar.enlistar(pedidoPE);
                cout << "El pedido no registrado introducido en la lista es: " << pedidoPE.imprimir() << endl;
            }
        }

    }
    cout << "El tiempo total es: " << tiempoTotal << " minutos" << endl;
}
