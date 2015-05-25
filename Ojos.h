/* 
 * File:   Ojos.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 20:47
 */

#ifndef OJOS_H
#define	OJOS_H

#include "Objeto3D.h"
#include "Cilindro.h"
#include "ObjetoCompuesto.h"


class Ojos : public ObjetoCompuesto {
public:
    Ojos();
    Ojos(GLdouble radio, GLdouble largo);
    void dibuja();
private:
    GLdouble _radio;
    GLdouble _largo;
};

#endif	/* OJOS_H */

