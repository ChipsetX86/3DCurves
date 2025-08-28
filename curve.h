#ifndef CURVE_H
#define CURVE_H

#include "point.h"

namespace TDCurves {

class Curve
{
public:
    Curve();
    virtual ~Curve();

    bool setRadius(const double radius);
    double radius() const;

    virtual Point value(const double t) = 0;
    virtual Point derivative(const double t) = 0;

private:
    double m_radius = 0;
    Point m_x, m_y;
};

}
#endif // CURVE_H
