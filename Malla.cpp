/* 
 * File:   Malla.cpp
 * Author: furia
 * 
 * Created on 3 de diciembre de 2013, 18:07
 */

#include "Malla.h"

Malla::Malla() {
}

Malla::Malla(int nVertices, int nNormales, int nCaras) {

}

void Malla::dibuja() {
    
    for (int i = 0; i < _numCaras; i++) {
        glLineWidth(2.0);
        glBegin(GL_POLYGON);// glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 4; j++) {
            int iN = _caras[i]->getIndiceNormalK(j);
            int iV = _caras[i]->getIndiceVerticeK(j);
            glNormal3f(_normales[iN]->getX(), _normales[iN]->getY(), _normales[iN]->getZ());
            glVertex3f(_vertices[iV]->getX(), _vertices[iV]->getY(), _vertices[iV]->getZ());
        }

        /*Para hacer triangulos*/
        /*
        int iN = _caras[(i + 1) % _numCaras]->getIndiceNormalK(0);
        int iV = _caras[(i + 1) % _numCaras]->getIndiceVerticeK(0);
        glNormal3f(_normales[iN]->getX(), _normales[iN]->getY(), _normales[iN]->getZ());
        glVertex3f(_vertices[iV]->getX(), _vertices[iV]->getY(), _vertices[iV]->getZ());
         */

        glEnd();
    }
}

void Malla::vectoresNormalNewell() {
    for (int i = 0; i < _numCaras; i++)
        _normales[i] = newell(_caras[i]);

}

PV3D* Malla::newell(Cara* c) {
    int x = 0;
    int y = 0;
    int z = 0;
    PV3D* va;
    PV3D* vs;

    for (int i = 0; i < c->getNumeroVertices(); i++) {

        va = _vertices[c->getIndiceVerticeK(i)];

        vs = _vertices[c->getIndiceVerticeK((i + 1) % c->getNumeroVertices())];

        x += (va->getY() - vs->getY()) * (va->getZ() + vs->getZ());
        y += (va->getZ() - vs->getZ()) * (va->getX() + vs->getX());
        z += (va->getX() - vs->getX()) * (va->getY() + vs->getY());
    }

    PV3D* n = new PV3D(x, y, z);
    n->normaliza();

    return n;
}