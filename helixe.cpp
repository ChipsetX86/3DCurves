#include "helixe.h"
#include <cmath>

TDCurves::Helixe::Helixe(): Curve() {}

TDCurves::Helixe::~Helixe()
{

}

bool TDCurves::Helixe::setStep(const double step)
{
    if (step <= 0) {
        return false;
    }
    m_step = step;
    return true;
}

TDCurves::Point TDCurves::Helixe::value(const double t)
{
    Point r;
    r.x = radius() * cos(t);
    r.y = radius() * sin(t);
    r.z = m_step * t / (2.0f * acos(-1.0f));
    return r;
}

TDCurves::Vector TDCurves::Helixe::derivative(const double t)
{
    Vector r;
    r.x = radius() * sin(t) * -1.f;
    r.y = radius() * cos(t);
    r.z = m_step / (2.0f * acos(-1.0f));
    return r;
}

bool TDCurves::Helixe::setRadius(const double radius)
{
    if (radius <= 0) {
        return false;
    }
    m_radius = radius;
    return true;
}

double TDCurves::Helixe::radius() const
{
    return m_radius;
}


