//
// Created by hgallegos on 17/08/2022.
//

#include "Camara.h"
#include "Objeto.h"

#include "Luz.h"

void Camara::renderizar(){
    pImg = new CImg<BYTE>(w, h, 1, 10);
    CImgDisplay dis_img((*pImg), "Imagen RayCasting en Perspectiva ");
// Algoritmo de Ray Casting
Luz luz;
luz.pos = vec3(10, 30, 20);
luz.color = vec3(1,1,1);
Esfera esf(vec3(3,3,0), 4);
esf.color = vec3(1,0,0);
esf.kd = 0.9;
esf.ks = 0.5;
vec3 color;
Rayo rayo;
rayo.ori = eye;
float t_tmp;
vec3 normal, N, L;
// Para cada pixel lanzar un rayo
for (int x=0; x < w; x++){
    for (int y=0; y < h; y++){
        rayo.dir = -f*ze + a*(y/h -0.5)*ye + b*(x/w-0.5)*xe;
        color = vec3(1,1,0);
        if ( esf.interseccion(rayo, t_tmp, normal)) {
            // componente difusa
            vec3 pi = rayo.ori + t_tmp * rayo.dir;
            N = normal;
            L = luz.pos - pi;
            L.normalize();
            float factor_difuso = N.punto(L);
            vec3 difusa(0,0,0);
            if (factor_difuso > 0) {
                difusa = luz.color * esf.kd * factor_difuso;
            }
            color = esf.color * difusa;
        }
        // pintar el pixel con el color
        (*pImg)(x,h-1-y,0) = (BYTE)(color.x * 255);
        (*pImg)(x,h-1-y,1) = (BYTE)(color.y * 255);
        (*pImg)(x,h-1-y,2) = (BYTE)(color.z * 255);
    }
    dis_img.render((*pImg));
    dis_img.paint();
}
    while (!dis_img.is_closed()) {
        dis_img.wait();
    }
}