#pragma once
#include "circle.h"

class Helix : public Circle
{
public:
    Helix(float radius_, float step_ = 0.f) 
    : Circle(radius_)
    , step{step_}
    {

    }
    float getZFromT(float t) override
    {
        return t * (step / M_2_PI);
    }

    float getDerivZFromT(float t) override
    {
        return step / M_2_PI;
    }

private:
    float step;
};