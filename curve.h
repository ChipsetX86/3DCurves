#ifndef CURVE_H
#define CURVE_H

#include "utils.h"

namespace TDCurves {

class Curve
{
public:
    Curve();
    virtual ~Curve();

    virtual Point value(const double t) = 0;
    virtual Vector derivative(const double t) = 0;
};

}
#endif // CURVE_H
