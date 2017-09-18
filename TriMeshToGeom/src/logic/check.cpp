//
//  check.cpp
//  TriMeshToGeom
//
//  Created by Dong's MacBook Pro on 2017. 6. 9..
//  Copyright © 2017년 Dong's MacBook Pro. All rights reserved.
//

#include "logic/check.hpp"
#include <algorithm>
#include <cmath>


using namespace std;


bool Checker::isExistDuplication(vector<Vertex*> vertex){
//    sort(vertex.begin(), vertex.end(), this->compare_vertex);
//    for (int i = 0 ; i < vertex.size() - 1 ; i++)
//    {
//        int j = i + 1;
//        if (isSameVertex(vertex[i],vertex[j]))
//        {
//            cout << i << ", " << j << endl;
//            Printer::printVertex(vertex[i]);
//            Printer::printVertex(vertex[j]);
//            return true;
//        }
//    }
    return false;
}

bool Checker::isSameVertex(Vertex* v1, Vertex* v2){
    double thres = this->threshold_vertex;
    if (fabs(v1->z() - v2->z()) <= thres && fabs(v1->x() - v2->x()) <= thres && fabs(v1->y() - v2->y()) <=thres){
        return true;
    }
    else
        return false;
}

bool Checker::isSameVertex(Vertex& v1, Vertex& v2){
    double thres = this->threshold_vertex;
    if (fabs(v1.z() - v2.z()) <= thres && fabs(v1.x() - v2.x()) <= thres && fabs(v1.y() - v2.y()) <=thres){
        return true;
    }
    else
        return false;
}

bool Checker::isSameOrientation(Vector_3& nv1, Vector_3& nv2){
    double thres = this->ori_degree;
    double angle = CGALCalculation::getAngle(nv1, nv2);
    return (angle <= thres) ;
}


bool Checker::isSameOrientation(Vertex* origin, Vertex* v1, Vertex* v2){
    Point_3 p3a(origin->x(),origin->y(),origin->z());
    Point_3 p3b(v1->x(),v1->y(),v1->z());
    Point_3 p3c(v2->x(),v2->y(),v2->z());

    Vector_3 vec1(p3a,p3b);
    Vector_3 vec2(p3a,p3c);

    return this->isSameOrientation(vec1, vec2);
}


bool Checker::isSamePlanar(Vector_3& big, Vector_3& small, double degree){
    double thres = this->ori_degree;
    double angle = CGALCalculation::getAngle(big, small);
    Vector_3 added = big + small;
    if (angle <= degree){
        return (CGALCalculation::getAngle(added, big) <= thres);
    }
    return false;
}

bool Checker::isSamePlanar(Vertex* origin, Vertex* v1, Vertex* v2){
    Point_3 p3a(origin->x(),origin->y(),origin->z());
    Point_3 p3b(v1->x(),v1->y(),v1->z());
    Point_3 p3c(v2->x(),v2->y(),v2->z());

    Vector_3 vec1(p3a,p3b);
    Vector_3 vec2(p3a,p3c);

    return isSamePlanar(vec1, vec2, 30.0);
}

bool Checker::isSimilarOrientation(Vector_3& nv1, Vector_3& nv2){
    double thres = this->ori_degree;
    double angle = CGALCalculation::getAngle(nv1, nv2);
    return (angle <= thres * 2) ;
}


int Checker::compare_vertex(Vertex* a, Vertex* b)
{
    double x = a->x() - b->x();
    if (fabs(x) > threshold_vertex)
    {
        return x > 0.0 ? 1 : -1;
    }
    else
    {
        double y = a->y() - b->y();
        if (fabs(y) > threshold_vertex)
        {
            return y > 0.0 ? 1 : -1;
        }
        else
        {
            double z = a->z() - b->z();
            if (fabs(z) > threshold_vertex)
            {
                return z > 0.0 ? 1 : -1;
            }
            else
                return 0;
        }
    }
}


bool Checker::isSameX(Vertex* v1, Vertex* v2){
    double thres = this->threshold_vertex;
    if (fabs(v1->x() - v2->x()) <= thres){
        return true;
    }
    else
        return false;
}

bool Checker::isSameY(Vertex* v1, Vertex* v2){
    double thres = this->threshold_vertex;
    if (fabs(v1->y() - v2->y()) <=thres){
        return true;
    }
    else
        return false;
}

bool Checker::isSameZ(Vertex* v1, Vertex* v2){
    double thres = this->threshold_vertex;
    if (fabs(v1->z() - v2->z()) <= thres){
        return true;
    }
    else
        return false;
}

bool Checker::isCollinear(Vertex* origin, Vertex* v1, Vertex* v2){
    double thres = this->collinear_degree;
    Point_3 p3a(origin->x(),origin->y(),origin->z());
    Point_3 p3b(v1->x(),v1->y(),v1->z());
    Point_3 p3c(v2->x(),v2->y(),v2->z());

    Vector_3 vec1(p3a,p3b);
    Vector_3 vec2(p3a,p3c);
    double angle = CGALCalculation::getAngle(vec1, vec2);
    return (angle <= thres);
}

