//
// Created by hgallegos on 24/08/2022.
//

#include "Mundo.h"
void Mundo::Escenario1(){
    camara.crear(vec3(0,0,0), vec3(0,1,0), vec3(3,15,0), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 5);
    pEsf->set(vec3(0,1,0), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,0,0), 0.9, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0,0,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7);

    objetos.emplace_back( pEsf );
    //objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    //objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
}

void Mundo::Escenario2(){
    camara.crear(vec3(0,0,0), vec3(0,1,0), vec3(3,15,30), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 5);
    pEsf->set(vec3(0,1,0), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,0,0), 0.9, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0,0,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7,0.5,8);

    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
}

void Mundo::Escenario3(){
    camara.crear(vec3(0,0,0), vec3(0,1,0), vec3(3,15,40), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(10, 30, 20), vec3(1,1,1));
    luces.emplace_back(pLuz);

    Esfera *pEsf = new Esfera(vec3(3,3,0), 3);
    pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,0.1,0.1), 0.9, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0.1), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),2);
    pPlano->set(vec3(0.1,0.1,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),20);
    pPlano2->set(vec3(0,1,0), 0.7);

    Cilindro *pCil1 = new Cilindro(vec3(1,10,1), vec3(2,10,1), 6);
    pCil1->set(vec3(0.1,1,1), 0.7);

    objetos.emplace_back( pEsf );
    //objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    //objetos.emplace_back( pPlano2 );
    objetos.emplace_back(pCil1);

    camara.renderizar(objetos, luces);
}