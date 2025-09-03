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
            auto c = new Circle();
            c->setRadius(distr(gen));
            (*it).reset(c);
        } else if (randValue >=1 && randValue < 2) {
            auto e = new Ellipse();
            e->setRadiusOX(distr(gen));
            e->setRadiusOY(distr(gen));
            (*it).reset(e);
        } else {
            auto h = new Helixe();
            h->setRadius(distr(gen));
            h->setStep(distr(gen));
            (*it).reset(h);
        }
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        Point t = (*it)->value(acos(-1.0f) / 4);
        cout << std::fixed << std::setprecision(2)
             << "Value: " << t.x << " " << t.y << " " << t.z << std::endl;
        Vector v = (*it)->derivative(acos(-1.0f) / 4);
        cout << std::fixed << std::setprecision(2)
             << "Derivative: " << v.x << " " << v.y << " " << v.z << std::endl;

    }

    vector<Circle*> vCircle;
    for (auto it = v.begin(); it != v.end(); ++it) {
        Circle* circle = dynamic_cast<Circle*>((*it).get());
        if (circle) {
            vCircle.push_back(circle);
        }
    }

    sort(vCircle.begin(), vCircle.end(), [](const Circle* a, const Circle* b) {
        if (a && b) {
            return a->radius() < b->radius();
        } else return false;
    });

    double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < vCircle.size(); ++i) {
        auto pCircle = vCircle[i];
        if (pCircle) {
            sum += pCircle->radius();
        }
    }

    cout << std::fixed << std::setprecision(2)
         << "Sum: " << sum << std::endl;

    return 0;
}
