/* 
 * File:   Sombrero.cpp
 * Author: raul
 * 
 * Created on 21 de enero de 2014, 18:57
 */

#include "Sombrero.h"
#include "Cilindro.h"
#include "Disco.h"

Sombrero::Sombrero() {
}

Sombrero::Sombrero(GLdouble altura, GLdouble radius) : ObjetoCompuesto(5) {


    _altura = altura;
    _radius = radius;

    Cilindro* copa = new Cilindro(radius, radius, altura, 40, 1);
    Cilindro* base = new Cilindro(radius + (radius / DIVISORPROPORCIONALSOMBRERORADIO), radius + (radius / DIVISORPROPORCIONALSOMBRERORADIO), (altura / DIVISORPROPORCIONALSOMBREROALTURA), 40, 1);
    Cilindro* banda = new Cilindro(radius + 0.001, radius + 0.001, (altura / 6.0), 40, 1);
    Disco* tapaCopa = new Disco(0.0, radius, 40, 4);
    Disco* tapaBase = new Disco(radius, radius + (radius / DIVISORPROPORCIONALSOMBRERORADIO), 40, 4);

    _componentes[0] = base;
    _componentes[1] = tapaBase;
    _componentes[2] = banda;
    _componentes[3] = copa;
    _componentes[4] = tapaCopa;

}

void Sombrero::dibuja() {

    glColor3d(0.0, 0.0, 0.0);

    //Base
    _componentes[0]->dibuja();

    //TapaBase
    glPushMatrix();
    glTranslated(0.0, (_altura / DIVISORPROPORCIONALSOMBREROALTURA), 0.0);
    _componentes[1]->dibuja();
    glPopMatrix();

    glColor3d(1.0, 1.0, 1.0);
    //banda
    glPushMatrix();
    glTranslated(0.0, (_altura / DIVISORPROPORCIONALSOMBREROALTURA), 0.0);
    _componentes[2]->dibuja();
    glPopMatrix();

    glColor3d(0.0, 0.0, 0.0);

    //Copa
    glPushMatrix();
    glTranslated(0.0, (_altura / DIVISORPROPORCIONALSOMBREROALTURA), 0.0);
    _componentes[3]->dibuja();
    glPopMatrix();


    //TapaCopa
    glPushMatrix();
    glTranslated(0.0, _altura + (_altura / DIVISORPROPORCIONALSOMBREROALTURA), 0.0);
    _componentes[4]->dibuja();
    glPopMatrix();
}


