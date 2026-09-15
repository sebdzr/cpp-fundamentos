#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

class Punto
{
private:
    double x;
    double y;

public:
    Punto();
    Punto(double x, double y);

    double getX() const;
    double getY() const;

    friend std::ostream& operator<<(std::ostream& os, const Punto& punto);
};

#endif