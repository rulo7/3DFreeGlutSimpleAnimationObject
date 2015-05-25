/* 
 * File:   Satelite.cpp
 * Author: usuario_local
 * 
 * Created on 19 de diciembre de 2013, 15:20
 */

#include "Tablero.h"
#include "Malla.h"
#include "Lapiz_3D.h"

EJEFIJO const ejeFijo = EJEY;

Tablero::Tablero() {

}

Tablero::Tablero(int nCaras, GLdouble altura, GLdouble radio) {

    _numCaras = nCaras * nCapas;
    _numNormales = _numCaras;
    _numVertices = _numCaras * 4;
    _altura = altura;
    _radio = radio;
    _centro = new PV3D(0.0, 0.0, 0.0);


    _caras = new Cara*[_numCaras];
    _normales = new PV3D*[_numNormales];
    _vertices = new PV3D*[_numVertices];


    construirCuerpo();
    contruirTapa();


    vectoresNormalNewell();
}

void Tablero::construirCuerpo() {
    /*Creo los vertices*/

    contVertices = 0;

    GLdouble PI = 3.1415926;

    int numLados = _numCaras / nCapas;

    GLdouble alfa = (2.0 * PI) / numLados;
    GLdouble beta = (PI - alfa) / 2.0;
    GLdouble gamma = PI - beta;
    GLdouble lado = (2.0 * _radio) * cos(beta);



    Lapiz_3D l;

    l.moveTo(_centro, ejeFijo);
    l.turnTo(0.0);
    l.avanza(_radio);
    l.gira(gamma * 180.0 / PI);

    contVertices = 1;
    _vertices[0] = l.getPosition();

    for (int i = 1; i < numLados; i++) {

        l.avanza(lado);
        _vertices[i] = l.getPosition();
        contVertices++;
        l.gira(alfa * 180.0 / PI);
    }

    PV3D* p;
    for (int j = numLados; j < contVertices + numLados; j++) {
        p = _vertices[j - numLados];
        _vertices[j] = new PV3D(p->getX(), _altura + _centro->getY(), p->getZ());
    }

    contVertices += numLados;

    /*Relaciono los indices de los vertices con sus normales*/
    for (int i = 0; i < numLados; i++) {
        _caras[i] = new Cara(4);

        _caras[i]->addVerticeNormal(new VerticeNormal(i, i), 0);
        _caras[i]->addVerticeNormal(new VerticeNormal((i + 1) % numLados, i), 1);
        _caras[i]->addVerticeNormal(new VerticeNormal(((i + 1) % numLados) + numLados, i), 2);
        _caras[i]->addVerticeNormal(new VerticeNormal(i + numLados, i), 3);
    }


}

void Tablero::contruirTapa() {


    /*Creo los vertices*/

    GLdouble PI = 3.1415926;

    int numLados = _numCaras / nCapas;
    GLdouble radioBaseTapa = 0.0;

    GLdouble alfa = (2.0 * PI) / numLados;
    GLdouble beta = (PI - alfa) / 2.0;
    GLdouble gamma = PI - beta;
    GLdouble lado = (2.0 * radioBaseTapa) * cos(beta);


    Lapiz_3D l;

    _centro->setY(_altura);

    l.moveTo(_centro, ejeFijo);
    l.turnTo(0.0);
    l.avanza(radioBaseTapa);
    l.gira(gamma * 180.0 / PI);

    _vertices[contVertices] = l.getPosition();

    for (int i = contVertices + 1; i < numLados + contVertices; i++) {

        l.avanza(lado);
        _vertices[i] = l.getPosition();
        l.gira(alfa * 180.0 / PI);

    }

    /*Relaciono los indices de los vertices con sus normales*/
    for (int i = 0; i < numLados; i++) {
        _caras[i + numLados] = new Cara(4);

        _caras[i + numLados]->addVerticeNormal(new VerticeNormal(i + numLados, i), 0);
        _caras[i + numLados]->addVerticeNormal(new VerticeNormal(((i + 1) % numLados) + numLados, i), 1);
        _caras[i + numLados]->addVerticeNormal(new VerticeNormal((((i + 1) % numLados) + numLados) + numLados, i), 2);
        _caras[i + numLados]->addVerticeNormal(new VerticeNormal((i + numLados) + numLados, i), 3);
    }

}

