#include "circle.h"
#include <cmath>

TDCurves::Circle::Circle(): Curve()
{

}

TDCurves::Circle::~Circle()
{

}

TDCurves::Point TDCurves::Circle::value(const double t)
{
    Point r;
    r.x = radius() * cos(t);
    r.y = radius() * sin(t);
    r.z = 0;
    return r;
}

TDCurves::Vector TDCurves::Circle::derivative(const double t)
{
    Vector r;
    r.x = radius() * sin(t) * -1.f;
    r.y = radius() * cos(t);
    r.z = 0;
    return r;
}

bool TDCurves::Circle::setRadius(const double radius)
{
    if (radius <= 0) {
        return false;
    }
    m_radius = radius;
    return true;
}

double TDCurves::Circle::radius() const
{
    return m_radius;
}

