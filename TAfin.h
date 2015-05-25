/* 
 * File:   TAfin.h
 * Author: raul
 *
 * Created on 20 de enero de 2014, 23:47
 */

#ifndef TAFIN_H
#define	TAFIN_H

int const N_AFIN = 4;

class TAfin{
public:
    
    TAfin();
    
    //calcularMatrizDeTranslacion
    //calcularMatrizDeEscalacion
    //calcularMatrizDeRotacion
    
    //postMultiplicarMatriz
    
private:
    float** _matrizAfin;
    
};

#endif	/* TAFIN_H */

