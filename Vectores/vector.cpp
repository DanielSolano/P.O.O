#include "vector.h"
#include <sstream>
#include <math.h>

Vector::Vector(double x, double y, double z)
{
    // Todo objeto tiene un apuntador a si mismo llamado this
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Vector::Sumar(Vector v2)
{
    Vector r;
    r.x = this->x + v2.x;
    r.y = this->y + v2.y;
    r.z = this->z + v2.z;
    return r;
}

Vector Vector::Multiplicar(Vector v2)
{
    Vector r;
    r.x = this->y * v2.z - this->z * v2.y;
    r.y = this->z * v2.x - this->x * v2.z;
    r.z = this->x * v2.y - this->y * v2.x;
    return r;
}

Vector Vector::Multiplicar(double s)
{
    Vector r;
    r.x = this->x * s;
    r.y = this->y * s;
    r.z = this->z * s;
    return r;
}

Vector Vector::operator*(Vector v2)
{
    Vector r;
    r.x = this->y * v2.z - this->z * v2.y;
    r.y = this->z * v2.x - this->x * v2.z;
    r.z = this->x * v2.y - this->y * v2.x;
    return r;
}

Vector Vector::operator*(double s)
{
    Vector r;
    r.x = this->x * s;
    r.y = this->y * s;
    r.z = this->z * s;
    return r;
}

Vector Vector::operator+(Vector v2)
{
    Vector r;
    r.x = this->x + v2.x;
    r.y = this->y + v2.y;
    r.z = this->z + v2.z;
    return r;
}

string Vector::ToString()
{
    std::ostringstream out;
    out << "(" << x << "," << y << "," << z << ")";
    return out.str();
}

double Vector::GetMagnitud()
{
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::GetUnitVector()
{
    double m = GetMagnitud();
    Vector r;
    r.x = x / m;
    r.y = y / m;
    r.z = z / m;
    return r;
}

Vector operator*(double s, Vector v)
{
    return v * s;
}
