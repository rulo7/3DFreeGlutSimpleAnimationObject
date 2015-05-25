/* 
 * File:   Camara.cpp
 * Author: furia
 * 
 * Created on 17 de enero de 2014, 18:43
 */

#include "PV3D.h"
#include "Camara.hpp"
Camara::Camara(){};
Camara::Camara(PV3D *eye, PV3D* look, PV3D* up) {
    _eye = eye;
    _look = look;
    _up = up;
    _n = new PV3D(eye->getX() - look->getX(), eye->getY() - look->getY(), eye->getZ() - look->getZ());
    _n->normaliza();
    _u = _up->productoVectorial(_n);
    _u->normaliza();
    _v = _n->productoVectorial(_u);
    _v->normaliza();
    setModelViewMatrix();
}

Camara::~Camara() {
    delete _eye, _look, _up, _n, _u, _v;
}

void Camara::setModelViewMatrix() {
    GLdouble matrix[16];
    matrix[0] = _u->getX();
    matrix[1] = _v->getX();
    matrix[2] = _n->getX();
    matrix[3] = 0;
    matrix[4] = _u->getY();
    matrix[5] = _v->getY();
    matrix[6] = _n->getY();
    matrix[7] = 0;
    matrix[8] = _u->getZ();
    matrix[9] = _v->getZ();
    matrix[10] = _n->getZ();
    matrix[11] = 0;
    matrix[12] = -_eye->productoEscalar(_u);
    matrix[13] = -_eye->productoEscalar(_v);
    matrix[14] = -_eye->productoEscalar(_n);
    matrix[15] = 1;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(matrix);
}

void Camara::recorridoEje(GLfloat desX, GLfloat desY, GLfloat desZ) {
    _eye->setX(_eye->getX() + desX);
    _eye->setY(_eye->getY() + desY);
    _eye->setZ(_eye->getZ() + desZ);
    setModelViewMatrix();
}

