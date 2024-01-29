#include "circle/circle.h"
#include "circle/ellipse.h"
#include "circle/helix.h"

#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

using namespace std;

class Container
{
public:
    enum Type
    {
        CIRCLE,
        ELLIPSE,
        HELIX
    };

    vector<Circle*> data;
    vector<pair<Type, Circle*>> typeList;

    Container()
    {
        
    }

    void operator=(Container& c)
    {
        data = c.data;
        typeList = c.typeList;
    }

    
    void setData(const vector<Circle*> &data_, const vector<Type> &types_)
    {
        data.clear();
        typeList.clear();

        for(int i = 0; i < data_.size(); i++)
        {
            data.push_back(data_[i]);
            typeList.push_back(std::make_pair(types_[i], data_[i]));
        }
    } 

    void RandomFill(int listSize_, float minR_, float maxR_)
    {
        for(int i{0}; i < listSize_; i++)
        {
            //Unsatysfing way of determaning radii
            float radius = (rand() % ((int)(maxR_ - minR_) * 1000)) / 1000.0;
            float Radius = (rand() % ((int)(2 * maxR_) * 1000)) / 1000.0;
            float step = (rand() % (314 * 10)) / 1000.0;

            int type = rand() % 3;
            
            Circle* c;
            Type t;
            switch (type)
            {
            case 0:
                c = new Circle(radius);
                t = CIRCLE;
                break;
            
            case 1:
                c = new Ellepse(radius, Radius);
                t = ELLIPSE;
                break;
            
            case 2:
                c = new Helix(radius, step);
                t = HELIX;
                break;
            }

            data.push_back(c);
            typeList.push_back(std::make_pair(t,c));
        }
    }

    Container* getListOfType(Type t)
    {
        Container* result = new Container();
                
        vector<Circle*> data_;
        vector<Type> types_;

        for(auto &val : typeList)
            if(val.first == t)
            {
                data_.push_back(val.second);
                types_.push_back(t);
            }

        result->setData(data_, types_);
        return result;
    }

    void sort()
    {   
         std::sort(data.begin(), data.end(), [this] (Circle *c1 ,Circle *c2) {
             return c1->getRadius() < c2->getRadius();
        });
        //std::sort(data.begin(),data.end());
    }
    
    vector<float> getRadiiList()
    {
        vector<float> list;
        for(auto& val : data)
        {
            cout << val->getRadius() << " : ";
            list.push_back(val->getRadius());
        }
        return list;
    }

    const float getRadiiSum()
    {
        float sum{0.f};
        for(auto val = data.begin() ; val != data.end(); val++)
        {
            sum += (*val)->getRadius();
        }


        sum = std::accumulate(data.begin(), data.end(), 0.f, [](const float a, Circle* c)
        {
            auto v = c;
            return a + c->getRadius();
        });
        return sum;
    }


};
