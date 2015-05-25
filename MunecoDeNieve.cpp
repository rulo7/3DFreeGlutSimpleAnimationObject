/* 
 * File:   MunecoDeNieve.cpp
 * Author: raul
 *
 * Created on 21 de enero de 2014, 20:46
 */

#include "MunecoDeNieve.h"
#include "Esfera.h"
#include "Ojos.h"
#include "Sombrero.h"
#include "Tablero.h"
#include "Botones.h"

MunecoDeNieve::MunecoDeNieve() {
}

MunecoDeNieve::MunecoDeNieve(GLdouble radioEsferaCuerpo, GLdouble radioEsferaCabeza) : ObjetoCompuesto(7) {

    
    _radioEsferaCuerpo = radioEsferaCuerpo;
    _radioEsferaCabeza = radioEsferaCabeza;

    _altura = (_radioEsferaCabeza * 2.0) + (_radioEsferaCuerpo * 2.0);
    
    //Suelo
    _componentes[0] = new Tablero(5, _radioEsferaCabeza * 2.0, _altura);
    //EsferaCuerpo
    _componentes[1] = new Esfera(_radioEsferaCuerpo, 20, 20);
    //Botones
    _componentes[2] = new Botones(radioEsferaCuerpo / 6.0, radioEsferaCuerpo);
    //EsferaCabeza
    _componentes[3] = new Esfera(_radioEsferaCabeza, 20, 20);
    //nariz
    _componentes[4] = new Cilindro(_radioEsferaCabeza / 6.0, 0.0, _radioEsferaCabeza * 0.75, 40, 1);
    //Ojos
    _componentes[5] = new Ojos(radioEsferaCabeza / 5.0, radioEsferaCabeza / 5.0);
    //Sombrero
    _componentes[6] = new Sombrero(_radioEsferaCabeza, _radioEsferaCabeza * 0.75);


}

void MunecoDeNieve::dibuja() {

    //pintarSuelo
    glColor3d(0.8,0.3,0.1);
    _componentes[0]->dibuja();
    
    //pintarCuerpo
    glColor3d(1.0,1.0,1.0);
    glPushMatrix();
    glTranslated(0.0, (_radioEsferaCabeza * 2.0) + _radioEsferaCuerpo, 0.0);
    _componentes[1]->dibuja();
    glPopMatrix();

    //pintarBotones;
    glColor3d(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(0.0, (_radioEsferaCabeza * 2.0) + _radioEsferaCuerpo, _radioEsferaCuerpo);
    _componentes[2]->dibuja();
    glPopMatrix();

    //pintarCabeza
    glColor3d(1.0,1.0,1.0);
    glPushMatrix();
    glTranslated(0.0, (_radioEsferaCabeza * 3.0) + (_radioEsferaCuerpo * 2.0), 0.0);
    _componentes[3]->dibuja();
    glPopMatrix();

    //pintarNariz
    glColor3d(0.8,0.3,0.0);
    glPushMatrix();
    glTranslated(0.0, (_radioEsferaCabeza * 3.0) + (_radioEsferaCuerpo * 2.0), _radioEsferaCabeza);
    glRotated(90,1.0,0.0,0.0);
    _componentes[4]->dibuja();
    glPopMatrix();

    //pintarOjos
    glColor3d(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(0.0, (_radioEsferaCabeza * 3.0) + (_radioEsferaCuerpo * 2.25),_radioEsferaCabeza * 0.9);
    _componentes[5]->dibuja();
    glPopMatrix();

    //pintarSombrero
    glPushMatrix();
    glTranslated(0.0, (_radioEsferaCabeza * 3.0) + (_radioEsferaCuerpo * 2.5), 0.0);
    _componentes[6]->dibuja();
    glPopMatrix();

}