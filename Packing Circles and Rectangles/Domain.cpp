//Name: Tom Abraham
//Student ID: 917096660
#include "Domain.h"
#include "Shape.h"
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

Domain::Domain(void){
    //Define length and width of rectangle
    sizex = 600;
    sizey = 500;

}

Domain::~Domain(void){
    // Deletes every shape pointer in vector s
    for (auto i : s){
        delete i;
    }
}

void Domain::addShape(const Shape* p){
    //Adds shape to vector s of shape pointers
    s.push_back(p);
}

//Function used to generate entire svg output. Also determines diagnostic message.
void Domain::draw(void){
    string top = "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n<svg width=\"700\" height=\"600\"\nxmlns=\"http://www.w3.org/2000/svg\">\n<g transform=\"matrix(1,0,0,-1,50,550)\"\nfill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">\n<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>";
    Point p1(0,0);
    int flag = 0;
    string message = "ok";
    string bottom = "";
    
    //Created rectangular region of fixed size
    Rectangle rect(p1, sizex, sizey);
    vector<const Shape*>::iterator iter;
    vector<const Shape*>::iterator iter2;

    //Determines if any of the shapes overlap
    for(iter = s.begin(); iter != s.end()-1; iter++){
        for(iter2 = iter + 1; iter2 != s.end(); iter2++){
            if ((*iter)->overlaps(*(*iter2))){
                message = "overlap";
                flag = 1;
                break;
            }
        }
    }

    //Determines if any of the shapes does not fit within the rectangle
    for (iter = s.begin(); iter != s.end(); iter++){
        if((*iter)->fits_in(rect) == false){
            message = "does not fit";
            flag = 1;
            break;
        }
    }

    //Determines if it's a desirable svg file
    if(flag != 1){
        message = "ok";
    }
    
    flag = 0;
    bottom = "</g>\n<g transform=\"matrix(1,0,0,1,50,590)\"\n font-family=\"Arial\" font-size=\"32\">\n<text x=\"0\" y=\"0\">" + message + "</text>\n</g>\n</svg>";
    
    //Prints out entire svg output
    cout << top << endl;
    for (iter = s.begin(); iter != s.end(); iter++){
        (*iter)->draw();
    }
    cout << bottom << endl;    
}

