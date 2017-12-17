//
// Created by M17-612 on 12.12.2017.
//

#ifndef POINT_POINT_H
#define POINT_POINT_H

#include <ostream>

class Point {
private:
    double x;
    double y;
    double z;
double len;
public:

    double getX() const {
        return x;
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y << " z: " << point.z << " len: " << point.len;
        return os;
    }

    void setX(double x) {
        Point::x = x;
    }

    double getY() const {
        return y;
    }

    void setY(double y) {
        Point::y = y;
    }

    double getZ() const {
        return z;
    }

    void setZ(double z) {
        Point::z = z;
    }

    Point(double x, double y, double z) : x(x), y(y), z(z) {
        len = sqrt(x*x+y*y+z*z);

    }

    Point() {}

    bool operator<(const Point &T)const{
        return (pow(pow(x,2)+pow(y,2)+pow(z,2),1/2.))<pow(pow(T.getX(),2)+pow(T.getY(),2)+pow(T.getZ(),2),1/2.);
    }
};
#endif //POINT_POINT_H
