#include <QCoreApplication>

#include <random>
#include <iostream>
#include <iomanip>
#include <omp.h>

#include "circle.h"
#include "ellipse.h"
#include "helixe.h"

const size_t countCurve = 10;

using namespace std;
using namespace TDCurves;

int main(int argc, char *argv[])
{
    vector<shared_ptr<Curve>> v;
    v.resize(countCurve);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distr(0.01f, 3.f);

    for (auto it = v.begin(); it != v.end(); ++it) {
        auto randValue = distr(gen);
        if (randValue >=0 && randValue < 1) {
            (*it).reset(new Circle());
            (*it)->setRadius(distr(gen));
        } else if (randValue >=1 && randValue < 2) {
            auto e = new Ellipse();
            e->setRadius(distr(gen));
            e->setRadius2(distr(gen));
            (*it).reset(e);
        } else {
            auto h = new Helixe();
            h->setRadius(distr(gen));
            h->setStep(distr(gen));
            (*it).reset(h);
        }
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        Point t = (*it)->value(acos(-1.0f) / 4.f);
        cout << std::fixed << std::setprecision(2)
             << "Value: " << t.x << " " << t.y << " " << t.z << std::endl;
        t = (*it)->derivative(acos(-1.0f) / 4.f);
        cout << std::fixed << std::setprecision(2)
             << "Derivative: " << t.x << " " << t.y << " " << t.z << std::endl;

    }

    vector<shared_ptr<Curve>> vCircle;
    for (auto it = v.begin(); it != v.end(); ++it) {
        Circle* circle = dynamic_cast<Circle*>((*it).get());
        if (circle) {
            shared_ptr<Curve> s((*it));
            vCircle.push_back(s);
        }
    }

    sort(vCircle.begin(), vCircle.end(), [](const shared_ptr<Curve>& a, const shared_ptr<Curve>& b) {
        return a->radius() < b->radius();
    });

    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < vCircle.size(); ++i) {
        sum += vCircle[i]->radius();
    }

    cout << std::fixed << std::setprecision(2)
         << "Sum: " << sum << std::endl;

    return 0;
}
