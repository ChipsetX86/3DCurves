#include "curve.h"

TDCurves::Curve::Curve() {}

TDCurves::Curve::~Curve()
{

}

bool TDCurves::Curve::setRadius(const double radius)
{
    if (radius <= 0) {
        return false;
    }
    m_radius = radius;
    return true;
}

double TDCurves::Curve::radius() const
{
    return m_radius;
}
