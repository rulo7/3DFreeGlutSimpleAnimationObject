/* 
 * File:   Camara.hpp
 * Author: furia
 *
 * Created on 17 de enero de 2014, 18:43
 */

#ifndef CAMARA_HPP
#define	CAMARA_HPP

class Camara {
public:
    Camara();
    Camara(PV3D* eye, PV3D* look, PV3D* up);
    virtual ~Camara();
    void recorridoEje(GLfloat desX, GLfloat desY, GLfloat desZ);
private:
    void setModelViewMatrix();
    PV3D* _eye, * _look, * _up, * _u, * _v, * _n;
};

#endif	/* CAMARA_HPP */

