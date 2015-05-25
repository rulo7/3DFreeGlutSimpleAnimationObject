/* 
 * File:   Esfera.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 11:17
 */

#ifndef ESFERA_H
#define	ESFERA_H

#include "ObjetoCuadrico.h"

class Esfera : public ObjetoCuadrico {
public:
    Esfera();
    Esfera(GLdouble radius, GLint slices, GLint stacks);
    void dibuja();

private:
    GLdouble _radius;
    GLint _slices;
    GLint _stacks;
};

#endif	/* ESFERA_H */

