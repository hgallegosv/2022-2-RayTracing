//
// Created by hgallegos on 17/08/2022.
//

#ifndef INC_20222_RAYTRACING_CAMARA_H
#define INC_20222_RAYTRACING_CAMARA_H

#include <cmath>
#include "vector.h"
#include "CImg.h"
#include "Objeto.h"
#include "Luz.h"
using namespace std;
using namespace cimg_library;
typedef unsigned char BYTE;

class Camara {
public:
    float fov, w, h, _near;
    vec3 eye, center, up;
    float f, a, b;
    vec3 xe, ye, ze;
    CImg<BYTE> *pImg;

    void inicializar() {
        f = _near;
        a = 2 * f * tan(fov*M_PI/180/2);
        b = w / h * a;
        ze = eye-center;
        ze.normalize();
        xe = up.cruz(ze);
        xe.normalize();
        ye = ze.cruz(xe);
    }
    void renderizar() ;
    void renderizar(vector<Objeto*> &objetos, vector<Luz*> &luces);
};


#endif //INC_20222_RAYTRACING_CAMARA_H
