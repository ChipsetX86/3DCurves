#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"
#include "point.h"

namespace TDCurves {

class Circle: public Curve
{
public:
    Circle();
    virtual ~Circle();

    virtual Point value(const double t);
    virtual Point derivative(const double t);
private:

};

}

#endif // CIRCLE_H
