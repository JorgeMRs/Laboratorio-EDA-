#include <iostream>
#include <string>
using namespace std;

#define MAX_CANT_PALABRAS_X_LINEA 3


#include <iostream>
#include <string>
using namespace std;

#define MAX_CANT_PALABRAS_X_LINEA 3

struct NodoPalabra {
    string palabra;
    NodoPalabra* sig;
};

struct NodoLinea {
    NodoPalabra* palabras;
    int cantidad;
    NodoLinea* sig;
};

struct NodoTexto {
    NodoLinea* lineaIni;
    NodoLinea* lineaFin;
};

struct Diccionario {
    string palabra;
    Diccionario* izq;
    Diccionario* der;
};

NodoTexto* texto = nullptr;
Diccionario* diccionario = nullptr;

void LiberarDiccionarioRec(Diccionario* nodo) {
    if (nodo == nullptr) {
        return;
    }

    LiberarDiccionarioRec(nodo->izq);
    LiberarDiccionarioRec(nodo->der);

    delete nodo;
}

void LiberarDiccionario() {
    LiberarDiccionarioRec(diccionario);
    diccionario = nullptr;
}


void LiberarTexto() {
    if (texto == nullptr) {
        return;
    }

    NodoLinea* linea = texto->lineaIni;

    while (linea != nullptr) {
        // Guardamos la siguiente línea.
        NodoLinea* sigLinea = linea->sig;

        // Liberamos todas las palabras de esta línea.
        NodoPalabra* palabra = linea->palabras;

        while (palabra != nullptr) {
            NodoPalabra* sigPalabra = palabra->sig;

            delete palabra;

            palabra = sigPalabra;
        }

        // Liberamos la línea.
        delete linea;

        linea = sigLinea;
    }

    // Liberamos el administrador del texto.
    delete texto;
    texto = nullptr;
}

void Inicializar() {
    // Liberamos los datos anteriores, si existen.
    LiberarTexto();
    LiberarDiccionario();

    // Creamos el administrador de un texto vacío.
    texto = new NodoTexto;
    texto->lineaIni = nullptr;
    texto->lineaFin = nullptr;

    // El diccionario queda vacío.
    diccionario = nullptr;
}



int main() {
   




    return 0;
}

