#pragma once

#include <iostream>
#include <ostream>

using namespace std;

struct point3D
{
    float x,y,z;

    point3D(float x_, float y_, float z_) 
    : x(x_)
    , y(y_)
    , z(z_)
    {
    }

    void move(float x_, float y_, float z_)
    {
        x += x_;
        y += y_;
        z += z_;
    }
    
};

ostream& operator<<(ostream &out, const point3D& p)
{
    return out << "X: " << p.x << " Y: " << p.y << " Z:  " << p.z << endl;
}