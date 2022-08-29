//
// Created by hgallegos on 17/08/2022.
//

#include "Camara.h"

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

void Camara::renderizar(vector<Objeto*> &objetos, vector<Luz*> &luces) {
    pImg = new CImg<BYTE>(w, h, 1, 10);
    CImgDisplay dis_img((*pImg), "Imagen RayCasting en Perspectiva ");
    vec3 color;
    Rayo rayo;
    rayo.ori = eye;
    float t_tmp, t;
    Objeto *pObj;
    Luz luz = *(luces[0]);
    vec3 normal, N, L;
    bool hay_interseccion;
    // Para cada pixel lanzar un rayo
    for (int x=0; x < w; x++){
        for (int y=0; y < h; y++){
            rayo.dir = -f*ze + a*(y/h -0.5)*ye + b*(x/w-0.5)*xe;
            // color = vec3(1,1,1);

            color = calcularColor(rayo, objetos, luces, 1);

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

vec3 Camara::calcularColor(Rayo rayo, vector<Objeto*> &objetos, vector<Luz*> &luces, int prof){
    vec3 color(1,1,1);
    float t_tmp, t;
    Objeto *pObj;
    Luz luz = *(luces[0]);
    vec3 normal, N, L;
    bool hay_interseccion;
    if ( prof > 7) {
        return vec3(1,1,1);
    }
    hay_interseccion = false;
    t = 100000;
    for(auto pObjeto : objetos){
        if (pObjeto->interseccion(rayo, t_tmp, normal)) {
            if (t_tmp < t) {
                hay_interseccion = true;
                t = t_tmp;
                N = normal;
                pObj = pObjeto;
            }
        }
    }
    if (hay_interseccion) {
        vec3 pi = rayo.ori + t * rayo.dir;
        //N = normal;
        L = luz.pos - pi;
        L.normalize();

        // componente ambiente
        vec3 ambiente = vec3(0.1,0.1,0.1) * pObj->kd;

        // calcular si hay sombra
        // lanzar rayo hacia la luz
        Rayo rayo_sombra;
        rayo_sombra.ori = pi + N*0.01;
        rayo_sombra.dir = L;
        bool sombra = false;
        vec3 v = -rayo.dir;
        v.normalize();

        for(auto pObjeto : objetos){
            if (pObjeto->interseccion(rayo_sombra, t_tmp, normal)) {
                sombra = true;
                break;
            }
        }
        if (sombra){
            color = pObj->color * (ambiente);
        } else {
            // componente difusa
            float factor_difuso = N.punto(L);
            vec3 difusa(0, 0, 0);
            if (factor_difuso > 0) {
                difusa = luz.color * pObj->kd * factor_difuso;
            }

            // componente especular

            vec3 r = 2*(L.punto(N))*N - L;
            r.normalize();
            float factor_especular = r.punto(v);
            vec3 especular(0,0,0);
            if (factor_especular > 0) {
                especular = luz.color * pObj->ks * pow(factor_especular , pObj->n);
            }
            color = pObj->color * (ambiente + difusa + especular);
            color.max_to_one();
        }

        // Rayos Reflexivos
        // -----------
        if (pObj->ks > 0) {
            Rayo rayo_reflexivo;
            rayo_reflexivo.ori = pi + N * 0.01;
            rayo_reflexivo.dir = 2 * (v.punto(N)) * N - v;
            vec3 color_reflexivo = calcularColor(rayo_reflexivo, objetos, luces, prof + 1);
            color = color + color_reflexivo;
            color.max_to_one();
        }

    }
    return color;
}