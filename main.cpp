#include <iostream>
#include "container.h"

using namespace std;
int main()
{
    Container* c1 = new Container();
    c1->RandomFill(10, 1.f, 5.f);

    float t = M_PI_4;
    cout << "Points for C1 at T = " << t << endl;
    for(auto &val : c1->data)
    {
        cout << "Coord: " << val->getPoint3DAt(t) << endl;
        cout << "Deriv: " << val->getDerivAtT(t) << endl;
    }

    Container* c2 = new Container();
    c2 = c1->getListOfType(Container::Type::CIRCLE);
    c2->sort();
        auto rList = c2->getRadiiList();

    cout << "Radii for C2: ";
    for(float r : rList)
        cout << r << " : ";
    cout << endl;

    cout << "Sum of C2 radii = " << c2->getRadiiSum() << endl;

    return 0;
}