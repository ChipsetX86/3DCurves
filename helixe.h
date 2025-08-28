#ifndef HELIXE_H
#define HELIXE_H

#include "curve.h"

namespace TDCurves {

class Helixe : public Curve
{
public:
    Helixe();
    virtual ~Helixe();

    bool setStep(const double step);

    virtual Point value(const double t);
    virtual Point derivative(const double t);
private:
    double m_step = 0;
};

}
#endif // HELIXE_H
