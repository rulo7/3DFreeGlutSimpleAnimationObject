/*
 * File:   ObjetoCuadrico.h
 * Author: raul
 *
 * Created on 20 de enero de 2014, 23:52
 */

#ifndef OBJETOCUADRICO_H
#define	OBJETOCUADRICO_H

#include "Objeto3D.h"
#include "freeglut.h"

class ObjetoCuadrico : public Objeto3D {
    public:
        ObjetoCuadrico() : Objeto3D(){
            _q = gluNewQuadric();  
            gluQuadricDrawStyle(_q, GLU_FILL);
        }
    
protected:
    GLUquadricObj* _q;
};

#endif	/* OBJETOCUADRICO_H */

