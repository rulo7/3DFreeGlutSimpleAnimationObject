/* 
 * File:   VerticeNormal.h
 * Author: furia
 *
 * Created on 3 de diciembre de 2013, 18:06
 */

#ifndef VERTICENORMAL_H
#define	VERTICENORMAL_H

class VerticeNormal {
public:
    VerticeNormal();
    VerticeNormal(int indiceV, int indiceN);
    int getIndiceVertice();
    int getIndiceNormal();
private:
    int _indiceVertice, _indiceNormal;

};

#endif	/* VERTICENORMAL_H */

