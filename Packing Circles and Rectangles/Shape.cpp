//Name: Tom Abraham
//Student ID: 917096660
#include "Shape.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

//Destructor for Rectangle
Rectangle::~Rectangle(void){

}

//Overlaps function for Rectangle and Shape object
bool Rectangle::overlaps(const Shape& r) const{
    string rect = "Rectangle";
    return r.overlaps(*this);
    
}

//Overlaps function for Rectangle and Circle object
bool Rectangle::overlaps(const Circle& r) const{
    int xClose, yClose, dist;
    xClose = min(max(r.center.x, this->position.x), (this->position.x + this->width));
    yClose = min(max(r.center.y, this->position.y), (this->position.y + this->height));

    dist = pow(r.center.y - yClose, 2) + pow(r.center.x - xClose, 2);

    if(dist < pow(r.radius, 2)){
        return true;
    }
    else{
        return false;
    }
    

}

//Overlaps function for Rectangle and Rectangle object
bool Rectangle::overlaps(const Rectangle& r) const{
    if((this->position.x) >= ((r.position.x)+r.width))
    {
        return false;
    }
    else if(((this->position.x)+this->width) <= (r.position.x))
    {
        return false ;
    }
    else if(((this->position.y)+this->height) <= (r.position.y))
    {
        return false ;
    }
    else if((this->position.y) >= (r.position.y+r.height))
    {
        return false;
    }
    else 
    {
        return true;
    }
}

//Checks if one rectangle fits in another one
bool Rectangle::fits_in(const Rectangle& r) const{
    if((this->position.x >= r.position.x) && (this->position.x + this->width <= r.width + r.position.x) && (this->position.y >= r.position.y) && (this->height <= r.height) ){
        return true;
    }
    else{
        return false;
    }
}

//Creates SVG output for drawing a rectangle
void Rectangle::draw(void) const{
    string rect = "<rect x=\"" + to_string(this->position.x) + "\" y=\"" + to_string(this->position.y) + "\" width=\"" + to_string(this->width) + "\" height=\"" + to_string(this->height) + "\"/>";
    cout << rect << endl;
}

//Destructor for circle
Circle::~Circle(void){

}

//Overlaps function for Circle and Shape object
bool Circle::overlaps(const Shape& s) const{
    return s.overlaps(*this);
}

//Overlaps function for Circle and Circle object
bool Circle::overlaps(const Circle& r) const{
    int distSquared = pow(this->center.x - r.center.x, 2) + pow(this->center.y - r.center.y, 2);
    int radSquared = pow(this->radius + r.radius, 2);

    if(distSquared >= radSquared){
        return false;
    }
    else{
        return true;
    }
}

//Overlaps function for Circle and Rectangle object
bool Circle::overlaps(const Rectangle& r) const{
    return r.overlaps(*this);
}

//Checks if a circle fits inside a rectangle
bool Circle::fits_in(const Rectangle& r) const{
    if((this->center.x + radius) > (r.position.x + r.width)){
        return false;
    }
    else if((this->center.x - this->radius) < (r.position.x)){
        return false;
    }
    if((this->center.y + this->radius) > (r.position.y+ r.height)){
        return false;
    }
    else if((this->center.y - this->radius) < (r.position.y)){
        return false;
    }
    return true;

}

//Generates svg output for drawing a circle
void Circle::draw(void) const{
    string circle = "<circle cx=\"" + to_string(this->center.x) + "\" cy=\"" + to_string(this->center.y) + "\" r=\"" + to_string(this->radius) + "\"/>";
    cout << circle << endl;
}