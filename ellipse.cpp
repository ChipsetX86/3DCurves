#include "ellipse.h"
#include <cmath>


TDCurves::Ellipse::Ellipse(): Curve()
{

}

TDCurves::Ellipse::~Ellipse()
{

}

TDCurves::Point TDCurves::Ellipse::value(const double t)
{
    Point r;
    r.x = m_radiusOX * cos(t);
    r.y = m_radiusOY * sin(t);
    r.z = 0;
    return r;
}

TDCurves::Vector TDCurves::Ellipse::derivative(const double t)
{
    Vector r;
    r.x = m_radiusOX * sin(t) * -1.f;
    r.y = m_radiusOY * cos(t);
    r.z = 0;
    return r;
}

bool TDCurves::Ellipse::setRadiusOX(const double radius)
{
    if (radius <= 0) {
        return false;
    }
    m_radiusOX = radius;
    return true;
}

bool TDCurves::Ellipse::setRadiusOY(const double radius)
{
    if (radius <= 0) {
        return false;
    }
    m_radiusOY = radius;
    return true;
}

