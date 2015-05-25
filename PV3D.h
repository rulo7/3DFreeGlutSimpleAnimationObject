/**
 * Clase PV3D. Representa un vector o un punto en un espacio de tres dimensiones.
 * Autores: Álvar Soler y Raúl Cobos.
 */

#ifndef PV3D_H
#define	PV3D_H

#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

class PV3D {
public:
    PV3D();
    PV3D(GLdouble x, GLdouble y, GLdouble z);

    /* Métodos de la clase */
    GLdouble modulo();
    void normaliza();
    PV3D* clona();
    GLdouble productoEscalar(PV3D* p);
    PV3D* productoVectorial(PV3D* p);


    /* Sobrecarga */
    PV3D& operator +(const PV3D &p);
    PV3D& operator -(const PV3D &p);
    bool operator ==(const PV3D &p);
    bool operator !=(const PV3D &p);
    friend std::ostream& operator <<(std::ostream &o, const PV3D &p);
    
    /* Getters */
    GLdouble getX();
    GLdouble getY();
    GLdouble getZ();
    
    /* Setters */
    void setX(GLdouble _valor);
    void setY(GLdouble _valor);
    void setZ(GLdouble _valor);

private:
    GLdouble _x, _y, _z;
};

#endif	/* PV3D_H */

