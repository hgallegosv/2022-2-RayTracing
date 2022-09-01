//
// Created by hgallegos on 24/08/2022.
//

#include "Mundo.h"
void Mundo::Escenario1(){
    camara.center=vec3(0,0,0);
    camara.up=vec3(0,1,0);
    camara.eye=vec3(10,5,20);
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
    pEsf->color = vec3(0,1,0);
    pEsf->kd = 0.9;
    pEsf->ks = 0.5;
    pEsf->n = 8;
    pEsf->idr = 1.5;

    Esfera *pEsf2 = new Esfera(vec3(3,9,0), 4);
    pEsf2->color = vec3(1,0,0);
    pEsf2->kd = 0.9;
    pEsf2->ks = 1;
    pEsf2->n = 32;
    Esfera *pEsf3 = new Esfera(vec3(3,3,-6), 4);
    pEsf3->color = vec3(1,1,0);
    pEsf3->kd = 0.9;

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->color=vec3(0,0,1);
    pPlano->kd = 0.7;
    pPlano->ks = 0;

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->color=vec3(0,1,0);
    pPlano2->kd = 0.7;
    pPlano2->ks = 0;

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    //objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
}