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

    Luz *pLuz = new Luz(vec3(5, 5, 5), vec3(1,1,1));
    luces.emplace_back(pLuz);
    Esfera *pEsfLuz = new Esfera( pLuz->pos, 2);
    pEsfLuz->set(pLuz->color, 0);

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

    objetos.emplace_back( pEsfLuz );
    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );

    camara.renderizar(objetos, luces);
}

void Mundo::Escenario3(){
    camara.crear(vec3(0,0,0), vec3(0,1,0), vec3(3,20,50), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(20, 5, 0), vec3(1,1,1));
    luces.emplace_back(pLuz);
    Esfera *pEsfLuz = new Esfera( pLuz->pos, 2);
    pEsfLuz->set(pLuz->color, 0);
    pEsfLuz->luz = pLuz;

    Esfera *pEsf = new Esfera(vec3(3,3,0), 3);
    pEsf->set(vec3(0.1,1,0.1), 0.9, 0.5, 8, 1.5);

    Esfera *pEsf2 = new Esfera(vec3(6,6,3), 5);
    pEsf2->set(vec3(1,1,1), 0.5, 1, 32);

    Esfera *pEsf3 = new Esfera(vec3(4,3,-6), 5);
    pEsf3->set(vec3(1,1,0.1), 0.9);

    Plano *pPlano = new Plano(vec3(0,1,0),0);
    pPlano->set(vec3(0.1,0.1,1), 0.7);

    Plano *pPlano2 = new Plano(vec3(1,0,0),-10);
    pPlano2->set(vec3(1,1,1), 0.2, 1, 8);

    Cilindro *pCil1 = new Cilindro(vec3(1,2,10), vec3(1,10,10), 6);
    pCil1->set(vec3(0.1,1,1), 0, 0.9, 8, 1.5);

    objetos.emplace_back( pEsfLuz );
    objetos.emplace_back( pEsf );
    objetos.emplace_back( pEsf2 );
    objetos.emplace_back( pEsf3 );
    objetos.emplace_back( pPlano );
    objetos.emplace_back( pPlano2 );
    objetos.emplace_back(pCil1);

    camara.renderizar(objetos, luces);
}

void Mundo::Escenario4(){
    camara.crear(vec3(0,0,0), vec3(0,1,0), vec3(3,40,30), 4, 60, 800, 600);
    camara.inicializar();

    Luz *pLuz = new Luz(vec3(4, 5, 10), vec3(1,1,1));
    luces.emplace_back(pLuz);
    Esfera *pEsfLuz = new Esfera( pLuz->pos, 0.5);
    pEsfLuz->set(pLuz->color, 0);
    pEsfLuz->luz = pLuz;
    objetos.emplace_back( pEsfLuz );

    Luz *pLuz2 = new Luz(vec3(4, 14, 10), vec3(1,1,0));
    luces.emplace_back(pLuz2);
    Esfera *pEsfLuz2 = new Esfera( pLuz2->pos, 0.5);
    pEsfLuz2->set(pLuz2->color, 0);
    pEsfLuz2->luz = pLuz2;
    objetos.emplace_back( pEsfLuz2 );

    Plano *pPlano = new Plano(vec3(0,1,0),0);
    pPlano->set(vec3(0,0,1), 0.5, 0, 8, 0, 0.4);

    Cilindro *pCil1 = new Cilindro(vec3(1,1,10), vec3(1,15,1), 10);
    pCil1->set(vec3(1,1,1), 0, 0.1, 8, 1.5, 1);

    Cilindro *pCil2 = new Cilindro(vec3(1,1.1,10), vec3(1,14.9,1), 9);
    pCil2->set(vec3(1,1,1), 0, 0.1, 8, 1, 1);


    Plano *pPlano2 = new Plano(vec3(1,0,0),-10);
    pPlano2->set(vec3(1,1,1), 0, 0, 8, 0, 1);

    objetos.emplace_back( pPlano );
    //objetos.emplace_back( pPlano2 );
    objetos.emplace_back(pCil1);
    objetos.emplace_back(pCil2);

    camara.renderizar(objetos, luces);
}