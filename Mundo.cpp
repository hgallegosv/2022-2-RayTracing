//
// Created by hgallegos on 24/08/2022.
//

#include "Mundo.h"
void Mundo::Escenario1(){
    camara.center=vec3(0,0,0);
    camara.up=vec3(0,1,0);
    camara.eye=vec3(3,5,30);
    camara._near=4;
    camara.fov = 60;
    camara.w = 600;
    camara.h = 400;
    camara.inicializar();


    Luz *pLuz = new Luz;
    pLuz->pos = vec3(10, 30, 20);
    pLuz->color = vec3(1,1,1);
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 4);
    pEsf->color = vec3(1,0,0);
    pEsf->kd = 0.9;
    pEsf->ks = 0.5;

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->color=vec3(0,0,1);
    pPlano->kd = 0.7;
    pPlano->ks = 0;

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pPlano );

    camara.renderizar(objetos, luces);
}