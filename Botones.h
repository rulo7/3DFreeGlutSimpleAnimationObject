/* 
 * File:   Botones.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 21:29
 */

#ifndef BOTONES_H
#define	BOTONES_H

#include "ObjetoCompuesto.h"
#include "freeglut.h"


class Botones : public ObjetoCompuesto{
public:
    Botones();
    Botones(GLdouble radio, GLdouble radioEsfera);
    void dibuja();
private:
    GLdouble _radio;
    GLdouble _radioEsfera;
};

#endif	/* BOTONES_H */

