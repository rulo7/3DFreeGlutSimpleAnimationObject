/**
 * Cabeceras de la clase lápiz.
 * Autores: Raul Cobos y Alvar Soler 
 * 
 * */

#ifndef LAPIZ_3D_H
#define	LAPIZ_3D_H
#include <GL/freeglut.h>
#include "PV3D.h"
#include "Lista.h"

enum EJEFIJO { EJEX, EJEY, EJEZ };

class Lapiz_3D {
public:
    Lapiz_3D();
    Lapiz_3D(PV3D *pto, GLdouble direc, EJEFIJO ejeFijo);
    virtual ~Lapiz_3D();

    /* Métodos get */
    PV3D* getPosition();
    GLdouble getDirection();
    /* Métodos set */
    void moveTo(PV3D* p, EJEFIJO ejeFijo);
    
    /**
     * Gira el lapiz al angulo a dado en el plano
     * @param a nuevo angulo
     */
    void turnTo(GLdouble a);
    
    /* Métodos de movimiento */
    /**
     * Avanza el lapiz una distancia dada en el ángulo en el que se encuentra.
     * @param dist a avanzar
     */
    void avanza(GLdouble dist);
    
    /**
     * Gira el lapiz direccGiro grados en el plano
     * @param direccGiro grados del giro
     */
    void gira(GLdouble direccGiro);
    
    /**
     * Getter del recorrido del lapiz.
     * @return Lista<PV2D> con los puntos
     */
    Lista<PV3D*> getRecorrido();

private:
    Lista<PV3D*> _recorrido;
    GLdouble _direc;
    EJEFIJO _ejeFijo;
};

#endif	/* LAPIZ_3D_H */

