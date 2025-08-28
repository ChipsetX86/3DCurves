#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"
#include "point.h"

namespace TDCurves {

class Ellipse : public Curve
{
public:
    Ellipse();
    virtual ~Ellipse();

    bool setRadius2(const double radius);

    virtual Point value(const double t);
    virtual Point derivative(const double t);
private:
    double m_radius2 = 0;
    double a();
    double b();
};

}
#endif // ELLIPSE_H
