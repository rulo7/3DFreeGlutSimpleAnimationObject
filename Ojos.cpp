/* 
 * File:   Ojos.cpp
 * Author: raul
 * 
 * Created on 21 de enero de 2014, 20:47
 */

#include "Ojos.h"

Ojos::Ojos() {
}

Ojos::Ojos(GLdouble radio, GLdouble largo) : ObjetoCompuesto(2) {
    _radio = radio;
    _largo = largo;


    _componentes[0] = new Cilindro(_radio, _radio, _largo, 40, 1);
    _componentes[1] = new Cilindro(_radio, _radio, _largo, 40, 1);
}

void Ojos::dibuja() {

    // Light1
    GLfloat position[] = {-(_radio * 1.5), 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, position); // Posición de la luz
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    GLfloat direction[] = {0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);


    glPushMatrix();
    glRotated(90, 1.0, 0.0, 0.0);
    glTranslated(-(_radio * 1.5), 0.0, 0.0);
    _componentes[0]->dibuja();
    glPopMatrix();
    
    


    glPushMatrix();
    glRotated(90, 1.0, 0.0, 0.0);
    glTranslated(_radio * 1.5, 0.0, 0.0);
    _componentes[1]->dibuja();
    glPopMatrix();

}