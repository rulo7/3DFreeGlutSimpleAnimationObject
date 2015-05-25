/* 
 * File:   Esfera.cpp
 * Author: raul
 * 
 * Created on 21 de enero de 2014, 11:17
 */

#include "Esfera.h"

Esfera::Esfera() {
}

Esfera::Esfera(GLdouble radius, GLint slices, GLint stacks) : ObjetoCuadrico() {
    _radius = radius;
    _slices = slices;
    _stacks = stacks;
}

void Esfera::dibuja() {

    glPushMatrix();
    glRotated(-90.0, 1.0, 0.0, 0.0);
    gluSphere(_q, _radius, _slices, _stacks);
    glPopMatrix();

}
