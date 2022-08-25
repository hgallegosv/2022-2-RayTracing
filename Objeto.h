//
// Created by hgallegos on 18/08/2022.
//

#ifndef INC_20222_RAYTRACING_OBJETO_H
#define INC_20222_RAYTRACING_OBJETO_H
#include "vector.h"
#include "Rayo.h"

class Objeto {
public:
    vec3 color;
    float kd, ks, n;
    virtual bool interseccion(Rayo &rayo, float &t, vec3 &normal) = 0;
};

class Esfera : public Objeto {
public:
    vec3 cen;
    float radio;
    Esfera(vec3 _cen, float _radio) {
        cen = _cen;
        radio = _radio;
    }
    bool interseccion(Rayo &rayo, float &t, vec3 &normal);
};

class Plano : public Objeto {
public:
    vec3 normal;
    float d;
    Plano(vec3 _normal, float _d) { normal = _normal; d=_d;}
    bool interseccion(Rayo &rayo, float &t, vec3 &normal);
};
#endif //INC_20222_RAYTRACING_OBJETO_H
