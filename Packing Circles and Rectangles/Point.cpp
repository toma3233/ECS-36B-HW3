//Name: Tom Abraham
//Student ID: 917096660

#include "Point.h"
#include<iostream>
using namespace std;

//Temporary point variable used to hold middle calculations
Point tempPoint(0,0);

//Adds two coordinates
Point Point::operator+(const Point& rhs) const{
    tempPoint.x = this->x + rhs.x;
    tempPoint.y = this->y + rhs.y;

    return(tempPoint);
}

//Subtracts two coordinates
Point Point::operator-(const Point& rhs) const{
    tempPoint.x = this->x - rhs.x;
    tempPoint.y = this->y - rhs.y;

    return(tempPoint);
}

//Prints coordinates to standard output in proper form
std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.x << "," << p.y << ")";
    
    return(os);
}

//Accepts x and y coordinates from standard input
std::istream& operator>>(std::istream& is, Point& p){
    int x,y;
    cin >> x >> y;
    p.x = x;
    p.y = y;

    return(is);
}