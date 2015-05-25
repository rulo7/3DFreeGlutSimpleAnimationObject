/* 
 * File:   Cilindro.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 11:19
 */

#ifndef CILINDRO_H
#define	CILINDRO_H

#include "ObjetoCuadrico.h"

class Cilindro : public ObjetoCuadrico {
public:
    Cilindro();
    Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
    void dibuja();
private:
    GLdouble _baseRadius;
    GLdouble _topRadius;
    GLdouble _height;
    GLint _slices;
    GLint _stacks;
};

#endif	/* CILINDRO_H */

