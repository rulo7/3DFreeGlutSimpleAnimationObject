/* 
 * File:   ObjetoCompuesto.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 11:23
 */

#ifndef OBJETOCOMPUESTO_H
#define	OBJETOCOMPUESTO_H

#include "Objeto3D.h"


class ObjetoCompuesto : public Objeto3D{
public:
    ObjetoCompuesto();
    ObjetoCompuesto(int numElems);
    void dibuja();
protected:

    Objeto3D** _componentes;
    int _numElems;
};

#endif	/* OBJETOCOMPUESTO_H */

