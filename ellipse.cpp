#include "ellipse.h"
#include <cmath>

double TDCurves::Ellipse::Ellipse::a() {
    return m_radius2 > radius() ? m_radius2 : radius();
}

double TDCurves::Ellipse::Ellipse::b() {
    return m_radius2 > radius() ? radius() : m_radius2;
}


TDCurves::Ellipse::Ellipse(): Curve()
{

}

TDCurves::Ellipse::~Ellipse()
{

}

bool TDCurves::Ellipse::setRadius2(const double radius)
{
    if (radius <= 0) {
        return false;
    }
    m_radius2 = radius;
    return true;
}

TDCurves::Point TDCurves::Ellipse::value(const double t)
{
    Point r;
    r.x = a() * cos(t);
    r.y = b() * sin(t);
    r.z = 0;
    return r;
}

TDCurves::Point TDCurves::Ellipse::derivative(const double t)
{
    Point r;
    r.x = a() * sin(t) * -1.f;
    r.y = b() * cos(t);
    r.z = 0;
    return r;
}

