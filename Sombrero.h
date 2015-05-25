/* 
 * File:   Sombrero.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 18:57
 */

#ifndef SOMBRERO_H
#define	SOMBRERO_H

#include "ObjetoCompuesto.h"
#include "freeglut.h"

GLdouble const DIVISORPROPORCIONALSOMBRERORADIO = 3.0;
GLdouble const DIVISORPROPORCIONALSOMBREROALTURA = 6.0;

class Sombrero : public ObjetoCompuesto {
public:
    Sombrero();
    Sombrero(GLdouble altura, GLdouble radius);
    void dibuja();
private:
    GLdouble _altura;
    GLdouble _radius;

};

#endif	/* SOMBRERO_H */

