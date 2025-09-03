#ifndef HELIXE_H
#define HELIXE_H

#include "curve.h"

namespace TDCurves {

class Helixe : public Curve
{
public:
    Helixe();
    ~Helixe();

    bool setRadius(const double radius);
    double radius() const;
    bool setStep(const double step);

    Point value(const double t) override;
    Vector derivative(const double t) override;
private:
    double m_radius = 0;
    double m_step = 0;
};

}
#endif // HELIXE_H
