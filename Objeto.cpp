//
// Created by hgallegos on 18/08/2022.
//

#include <cmath>
#include "Objeto.h"

bool Esfera::interseccion(Rayo &rayo, float &t) {
    vec3 d = rayo.dir;
    vec3 o_c = rayo.ori - cen;
    float a = d.punto(d);
    float b = 2 * d.punto(o_c);
    float c = o_c.punto(o_c) - radio*radio;

    float det = b*b - 4*a*c;
    if ( det > 0) {
        float t1 = (-b - sqrt(det)) / (2*a);
        float t2 = (-b + sqrt(det)) / (2*a);
        t = std::min(t1, t2);
        if ( t <= 0 ) { return false;}
        return true;
    }
    return false;
}