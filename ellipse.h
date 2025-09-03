#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

namespace TDCurves {

class Ellipse : public Curve
{
public:
    Ellipse();
    ~Ellipse();

    bool setRadiusOX(const double radius);
    bool setRadiusOY(const double radius);

    Point value(const double t) override;
    Vector derivative(const double t) override;
private:
    double m_radiusOX = 0;
    double m_radiusOY = 0;
};

}
#endif // ELLIPSE_H
