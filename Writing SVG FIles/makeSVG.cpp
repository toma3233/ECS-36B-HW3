//Name: Tom Abraham
//Student ID: 917096660

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

//Shape class: Base class used to create link between Rectangle and Shape classes
class Shape{
    public:
        //Designates type of shape
        char type;
        //Virtual function print() that prints based on the type of shape
        virtual void print() = 0;

};

//Rectangle class used to create new rectangle
class Rectangle : public Shape{
    private:
        //Aspects of a Rectangle
        int rectCoordX;
        int rectCoordY;
        int rectWidth;
        int rectLength;
    
    public:
        //Constructs a new Rectangle
        Rectangle(int rcx, int rcy, int rwidth, int rlength){
            type = 'R';
            rectCoordX = rcx;
            rectCoordY = rcy;
            rectWidth = rwidth;
            rectLength = rlength;
        } 

        //Customized print for a Rectangle
        void print(){
            cout << "<rect x=\"" + to_string(rectCoordX) + "\" y=\"" + to_string(rectCoordY) + "\" width=\"" + to_string(rectWidth) + "\" height=\"" + to_string(rectLength) + "\"/>" << endl;

        }

};

//Circle class used to create a new Circle
class Circle : public Shape{
    private:
        //Aspects of a Circle
        int circCoordX;
        int circCoordY;
        int radius;
    
    public:
        //Used to construct a Circle
        Circle(int ccx, int ccy, int rad){
            type = 'C';
            circCoordX = ccx;
            circCoordY = ccy;
            radius = rad;
        }

        //Customized print for a Circle
        void print(){
           cout << "<circle cx=\"" + to_string(circCoordX) + "\" cy=\"" + to_string(circCoordY) + "\" r=\"" + to_string(radius) + "\"/>" << endl;
        }

};

//This is the main function that prints SVG file information to standard output 
int main(){
    //Header of SVG file
    string top = "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>\n<svg width=\"700\" height=\"600\"\nxmlns=\"http://www.w3.org/2000/svg\">\n<g transform=\"matrix(1,0,0,-1,50,550)\"\nfill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">\n<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>";
    //Footer of SVG file
    string bottom = "</g>\n</svg>";
    //Vector that holds pointers to Shapes
    vector<Shape*> v;
    
    char shape = ' ';
    int rectCoordX = 0, rectCoordY = 0, rectWidth = 0, rectLength = 0, circCoordX = 0, circCoordY = 0, radius = 0;
    cin >> shape;
    while(cin){
        if (shape == 'R'){
            cin >> rectCoordX >> rectCoordY >> rectWidth >> rectLength;
            Rectangle* r = new Rectangle(rectCoordX, rectCoordY, rectWidth, rectLength);
            //Adds rectangle to the vector
            v.push_back(r);
        }
        if (shape == 'C'){
            cin >> circCoordX >> circCoordY >> radius;
            Circle* c = new Circle(circCoordX, circCoordY, radius);
            //Adds circle to the vector
            v.push_back(c);
        }
        cin >> shape;
    } 

    //prints svg file info to standard output
    cout << top << endl;
    for(auto i : v){
        i->print();
    }
    cout << bottom << endl;

    
}