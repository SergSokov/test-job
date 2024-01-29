#pragma once
#include "circle.h"

class Ellepse : public Circle
{
public:
    Ellepse(float xRadius_, float yRadius_) 
    : Circle(xRadius_)
    , yRadius{yRadius_}
    {
    }

    float getYFromT(float t) override
    {
        return yRadius * sin(t);
    }

    float getDerivYFromT(float t) override
    {
        return yRadius * cos(t);
    }
    
    
private:
    float yRadius;
};
