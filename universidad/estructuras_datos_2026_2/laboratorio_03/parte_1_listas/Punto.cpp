#include "Punto.h"

Punto::Punto()
{
    x = 0;
    y = 0;
}

Punto::Punto(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Punto::getX() const
{
    return x;
}

double Punto::getY() const
{
    return y;
}

std::ostream& operator<<(std::ostream& os, const Punto& punto)
{
    os << "(" << punto.x << ", " << punto.y << ")";
    return os;
}