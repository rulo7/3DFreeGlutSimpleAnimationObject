/* 
 * File:   VerticeNormal.cpp
 * Author: furia
 * 
 * Created on 3 de diciembre de 2013, 18:06
 */

#include "VerticeNormal.h"

VerticeNormal::VerticeNormal() {
    _indiceVertice = 0;
    _indiceNormal = 0;
}

VerticeNormal::VerticeNormal(int indiceV, int indiceN) {
    _indiceVertice = indiceV;
    _indiceNormal = indiceN;
}

int VerticeNormal::getIndiceVertice() {
    return _indiceVertice;
}

int VerticeNormal::getIndiceNormal() {
    return _indiceNormal;
}