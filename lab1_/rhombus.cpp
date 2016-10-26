#include "rhombus.h"
#include <cmath>
using namespace std;

#define PI 3.14159265

Rhombus::Rhombus() {
}

Rhombus::Rhombus(int i, double j) {
    a = i;
    angle = j;
    if (angle > 90) {
        angle = 180.0 - angle;        
    }
    cout << "Rhombus with side " << a << " and angle " << angle << " created" << endl;
}


Rhombus::Rhombus(istream &is) {
    cout << "Input side a:" << endl;
    is >> a;
    cout << "Input angle b(<=90°):" << endl;
    is >> angle;
    if (angle > 90) {
        angle = 180.0 - angle;        
    }
}

double Rhombus::Square() {
    double res = a * a * sin(angle * PI / 180.0);
    return res; 
}

void Rhombus::Print() {
    cout << "Figure: Rhombus \nside = " << a << " angle = " << angle << endl;    
}
