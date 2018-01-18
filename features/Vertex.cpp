#include <string>

#include "features/Vertex.h"

using namespace std;

std::string Vertex::toJSON()
{
    std::string ret;
    ret.append("[");
    ret.append(to_string(x()));
    ret.append(",");
    ret.append(to_string(y()));
    ret.append(",");
    ret.append(to_string(z()));
    ret.append(",");
    ret.append(to_string(this->index));
    ret.append("]");
    return ret;
}

Point_3 Vertex::getCGALPoint(){
    Vertex* v = this;
    return Point_3(v->x(),v->y(),v->z());
}

void Vertex::translate(double diff[]){
    for (int i = 0 ; i < 3 ; i++) coords[i] += diff[i];
}

void Vertex::translateTo(vector<double> diff){
    for (int i = 0 ; i < 3; i++) coords[i] = diff[i];
}

bool Vertex::compare(Vertex* a, Vertex* b){
    if (a->x() < b->x()){
        return true;
    }
    else if (a->x() > b->x()){
        return false;
    }
    else{
        if (a->y() < b->y())
        {
            return true;
        }
        else if (a->y() > b->y())
        {
            return false;
        }
        else{
            if (a->z() < b->z())
            {
                return true;
            }
            else
                return false;

        }
    }
}