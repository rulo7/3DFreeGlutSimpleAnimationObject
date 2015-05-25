/* 
 * File:   Disco.cpp
 * Author: raul
 * 
 * Created on 21 de enero de 2014, 11:01
 */

#include "Disco.h"

Disco::Disco() {

}

Disco::Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint rings) : ObjetoCuadrico() {

    _innerRadius = innerRadius;
    _outerRadius = outerRadius;
    _slices = slices;
    _rings = rings;

}

void Disco::dibuja() {
    
    glPushMatrix();
    glRotated(-90.0, 1.0, 0.0, 0.0);
    gluDisk(_q, _innerRadius, _outerRadius, _slices, _rings);
    glPopMatrix();

}