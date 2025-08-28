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

TDCurves::Point TDCurves::Circle::derivative(const double t)
{
    Point r;
    r.x = radius() * sin(t) * -1.f;
    r.y = radius() * cos(t);
    r.z = 0;
    return r;
}
