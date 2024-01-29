#pragma once
#define _USE_MATH_DEFINES

#include "../common/point3d.h"
#include <vector>
#include <math.h>

class Circle
{
public:
    Circle(float radius_)
    : radius{radius_}
    {
        
    }
    // coords values at T
    virtual float getXFromT(float t)
    {
        return radius * cos(t);
    }
    virtual float getYFromT(float t)
    {
        return radius * sin(t);
    }
    virtual float getZFromT(float t)
    {
        return 0.f;
    }
    
    // derivetives of coords at T
    virtual float getDerivXFromT(float t)
    {
        return -radius * sin(t);
    }

    virtual float getDerivYFromT(float t)
    {
        return radius * cos(t);
    }
    virtual float getDerivZFromT(float t)
    {
        return 0.f;
    }
    
    point3D getDerivAtT(float t)
    {
        return point3D(getDerivXFromT(t), getDerivYFromT(t), getDerivZFromT(t));
    }

    point3D getPoint3DAt(float t)
    {
        return point3D(getXFromT(t), getYFromT(t), getZFromT(t));
    };

    float getRadius(){return radius;}

protected:
    float radius;
    
};
