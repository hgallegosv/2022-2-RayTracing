#include <iostream>
#include "Camara.h"

int main() {
    Camara c;
    c.center=vec3(0,0,0);
    c.up=vec3(0,1,0);
    c.eye=vec3(3,5,30);
    c._near=4;
    c.fov = 60;
    c.w = 600;
    c.h = 400;
    c.inicializar();
    c.renderizar();
    return 0;
}
