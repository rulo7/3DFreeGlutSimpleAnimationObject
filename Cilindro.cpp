/* 
 * File:   Cilindro.cpp
 * Author: raul
 * 
 * Created on 21 de enero de 2014, 11:19
 */

#include "Cilindro.h"

Cilindro::Cilindro() {
}

Cilindro::Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks) : ObjetoCuadrico() {
    _baseRadius = baseRadius;
    _topRadius = topRadius;
    _height = height;
    _slices = slices;
    _stacks = stacks;
}

void Cilindro::dibuja() {
    glPushMatrix();
    glRotated(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(_q, _baseRadius, _topRadius, _height, _slices, _stacks);
    glPopMatrix();
}