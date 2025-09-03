#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

namespace TDCurves {

class Circle: public Curve
{
public:
    Circle();
    ~Circle();

    bool setRadius(const double radius);
    double radius() const;

    Point value(const double t) override;
    Vector derivative(const double t) override;
private:
    double m_radius = 0;
};

}

#endif // CIRCLE_H
