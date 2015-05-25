/**
 * 
 * Autores: Raul Cobos y Alvar Soler 
 * Funciones de la clase Lapiz.
 * */
#include "Lapiz_3D.h"
#include "Lista.h"
#include <cmath>
#include <iostream>
#include <GL/freeglut.h>

#define PI 3.14159265

Lapiz_3D::Lapiz_3D() {
    _recorrido.ponDr(new PV3D(0.0, 0.0, 0.0));

    this->_direc = 0.0;
    this->_ejeFijo = EJEY;
}

/**
 *  Constructor del lapiz.
 * @param pto donde commienza el lapiz
 * @param theta angulo con el que empieza
 */
Lapiz_3D::Lapiz_3D(PV3D *pto, GLdouble direc, EJEFIJO ejeFijo) {
    this->_recorrido.ponDr(pto);
    this->_direc = direc;
    this->_ejeFijo = ejeFijo;

}

Lapiz_3D::~Lapiz_3D() {
    _recorrido.~Lista();
}

/**
 * Avanza el lápiz una distancia dada
 * @param dist que se quiere que avance
 */
void Lapiz_3D::avanza(GLdouble dist) {
    /* Almacenamos la vieja posición para poder dibujar la línea de un punto a otro */
    PV3D* vPos = this->getPosition();
    PV3D* nPos;
    GLdouble difX,difY, difZ, rad;

    switch (this->_ejeFijo) {
        
        case EJEX:

            
            /* Transformamos el ángulo a radianes */
            rad = getDirection() / 180.0 * PI;
            difY = cos((double) rad) * dist;
            difZ = sin((double) rad) * dist;

            /* Calculamos la nueva posición */
            nPos = new PV3D(vPos->getX(), vPos->getY() + difY, vPos->getZ() + difZ);

            break;
            
        case EJEY:

            
            /* Transformamos el ángulo a radianes */
            rad = getDirection() / 180.0 * PI;
            difZ = cos((double) rad) * dist;
            difX = sin((double) rad) * dist;

            /* Calculamos la nueva posición */
            nPos = new PV3D( vPos->getX() + difX, vPos->getY(), vPos->getZ() + difZ);          

            break;
            
        case EJEZ:
            
            
            /* Transformamos el ángulo a radianes */
            rad = getDirection() / 180.0 * PI;
            difX = cos((double) rad) * dist;
            difY = sin((double) rad) * dist;

            /* Calculamos la nueva posición */
            nPos = new PV3D( vPos->getX() + difX, vPos->getY() + difY, vPos->getZ());            

            break;
            
    }
    
    this->_recorrido.ponDr(nPos);

}

/**
 * Gira el lapiz giroXY grados en el plano
 * @param giroXY
 */
void Lapiz_3D::gira(GLdouble giro) {
    this->_direc += giro;
}


/* Setters */

/**
 * avanzamos el lapiz hasta la posicion indicada
 * y marcamos el eje que definira el plano
 * @param p nueva posicion del lapiz
 * 
 */
void Lapiz_3D::moveTo(PV3D* p,EJEFIJO ejeFijo) {
    this->_recorrido.ponDr(p);
    this->_ejeFijo = ejeFijo;
}

/**
 * Se cambia el angulo a otro dado en el plano XY
 * @param a nuevo ángulo
 */
void Lapiz_3D::turnTo(GLdouble a) {
    this->_direc = a;
}


/* Getters */

/**
 * Posicion actual
 * @return Punto pos. actual
 */
PV3D* Lapiz_3D::getPosition() {
    return _recorrido.ultimo();
}

/**
 * Direccion en angulos en el plano XY
 * @return direcc. angulo
 */
GLdouble Lapiz_3D::getDirection() {
    return this->_direc;
}

Lista<PV3D*> Lapiz_3D::getRecorrido() {
    return this->_recorrido;
}