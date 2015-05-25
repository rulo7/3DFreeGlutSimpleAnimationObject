/* 
 * File:   Objeto3D.h
 * Author: raul
 *
 * Created on 20 de enero de 2014, 23:49
 */

#ifndef OBJETO3D_H
#define	OBJETO3D_H

#include "TAfin.h"

class Objeto3D {
public:
    Objeto3D(){
        marcoDeCoordenadas = new TAfin();
    }
    virtual void dibuja() = 0;
private:
    TAfin* marcoDeCoordenadas;
};

#endif	/* OBJETO3D_H */

