/* 
 * File:   Cara.cpp
 * Author: furia
 * 
 * Created on 3 de diciembre de 2013, 18:05
 */

#include "Cara.h"
#include "Malla.h"

Cara::Cara() {
}

Cara::Cara(int numVertices) {
    _numVertices = numVertices;
    _arrayVN = new VerticeNormal*[_numVertices];
    /* Posible error*/
}

Cara::Cara(int numVertices, VerticeNormal** vN) {
    _numVertices = numVertices;
    _arrayVN = vN;
    /* Posible error*/
}

int Cara::getNumeroVertices() {
    return _numVertices;
}

int Cara::getIndiceNormalK(int posicion) {
    return _arrayVN[posicion]->getIndiceNormal();
}

int Cara::getIndiceVerticeK(int posicion) {
    return _arrayVN[posicion]->getIndiceVertice();
}

void Cara::addVerticeNormal(VerticeNormal *vn, int indx) {
    _arrayVN[indx] = vn;
}

