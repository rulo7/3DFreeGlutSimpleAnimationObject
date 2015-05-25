/* 
 * File:   ObjetoCompuesto.cpp
 * Author: raul
 * 
 * Created on 21 de enero de 2014, 11:23
 */

#include "ObjetoCompuesto.h"

ObjetoCompuesto::ObjetoCompuesto() {
}

ObjetoCompuesto::ObjetoCompuesto(int numElems) {
    _numElems = numElems;
    _componentes = new Objeto3D*[_numElems];
}

void ObjetoCompuesto::dibuja() {
    for (int i = 0; i < _numElems; i++) {
        _componentes[i]->dibuja();
    }
}

