/* 
 * File:   MunecoDeNieve.h
 * Author: raul
 *
 * Created on 21 de enero de 2014, 20:46
 */

#ifndef MUNECODENIEVE_H
#define	MUNECODENIEVE_H

#include "Disco.h"
#include "ObjetoCompuesto.h"
#include "freeglut.h"


class MunecoDeNieve : public ObjetoCompuesto {
public:
    MunecoDeNieve();
    MunecoDeNieve(GLdouble radioEsferaCuerpo, GLdouble radioEsferaCabeza);
    void dibuja();
private:
    GLdouble _altura;
    GLdouble _radioEsferaCuerpo;
    GLdouble _radioEsferaCabeza;    
};

#endif	/* MUNECODENIEVE_H */

