#include "world2D.h"

world2D::world2D() {

    agent = new agent2D(Vector(50, 50), new Target());
}

void world2D::start() {


    while(agent->decide());


}