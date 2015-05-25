/* 
 * File:   Disco.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 11:01
 */

#ifndef DISCO_H
#define	DISCO_H

#include "ObjetoCuadrico.h"

class Disco : public ObjetoCuadrico {
public:
    Disco();
    Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint rings);
    void dibuja();
private:
    GLdouble _innerRadius;
    GLdouble _outerRadius;
    GLint _slices;
    GLint _rings;
};

#endif	/* DISCO_H */

