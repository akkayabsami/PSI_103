#include "world2D.h"

world2D::world2D() {

    agent = new agent2D(Vector(50, 50), new Target(), 0.8);
}

void world2D::start() {


    while(agent->decide());


}

void world2D::start(int trial, float alpha) {

    delete(agent);
    agent = new agent2D(Vector(50, 50), new Target(), alpha);
    for (size_t i = 0; i < trial; i++)
    {
        agent->alpha = alpha;
        agent->setPos(Vector((float(rand()) / float((RAND_MAX)) * (100.0 - agent->size) + agent->size / 2), (float(rand()) / float((RAND_MAX)) * (200.0 - agent->size)) + agent->size / 2));
        agent->setTarget(new Target());
        agent->MyFile << "At Trial " << i + 1 << " with alpha = " << agent->alpha << "; Target is located at X: " << agent->target->getX() << ", Y: " << agent->target->getY() << "; Agent is located at X:" << agent->pos.getX() << ", Y:" << agent->pos.getY() << std::endl;
        agent->step = 1;
        while(agent->decide());
    }
}

void world2D::startWithSamePos(float* alphas) {
    Target* target = new Target();
    Vector agentPos(90, 190);
    delete(agent);
    agent = new agent2D(agentPos, target, alphas[0]);
    agent->alpha = alphas[0];
    agent->MyFile << "At Trial with alpha = " << agent->alpha << "; Target is located at X: " << agent->target->getX() << ", Y: " << agent->target->getY() << "; Agent is located at X:" << agent->pos.getX() << ", Y:" << agent->pos.getY() << std::endl;
    agent->step = 1;
    while(agent->decide());

    delete(agent);
    agent = new agent2D(agentPos, target, alphas[1]);
    agent->alpha = alphas[1];
    agent->MyFile << "At Trial with alpha = " << agent->alpha << "; Target is located at X: " << agent->target->getX() << ", Y: " << agent->target->getY() << "; Agent is located at X:" << agent->pos.getX() << ", Y:" << agent->pos.getY() << std::endl;
    agent->step = 1;
    while(agent->decide());

}