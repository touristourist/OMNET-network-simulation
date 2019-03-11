
#include "entity.h"

Define_Module(Entity);

void Entity::initialize()
{
    // Default behavior is empty
    x=par("x");
    y=par("y");
}

void Entity::handleMessage(cMessage *msg)
{
    // Default behavior is empty
}

int Entity::getX()
{
    return x;
}

void Entity::setX(int x)
{
    this->x = x;
}

int Entity::getY()
{
    return y;
}

void Entity::setY(int y)
{
    this->y = y;
}

void Entity::updateDisplay()
{
    // Default behavior is empty
}

double Entity::distance(Entity *obj)
{
    return sqrt((getX() - obj->getX()) * (getX() - obj->getX()) + (getY() - obj->getY()) * (getY() - obj->getY()));
}
