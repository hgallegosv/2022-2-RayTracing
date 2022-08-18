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
    virtual bool interseccion(Rayo &rayo, float &t) = 0;
};

class Esfera : public Objeto {
public:
    vec3 cen;
    float radio;
    Esfera(vec3 _cen, float _radio) {
        cen = _cen;
        radio = _radio;
    }
    bool interseccion(Rayo &rayo, float &t);
};

#endif //INC_20222_RAYTRACING_OBJETO_H
