#include "pentagon.h"
#include <cmath>
using namespace std;

#define PI 3.14159265

Pentagon::Pentagon() {
}

Pentagon::Pentagon(int i) {
    a = i;
    cout << "Pentagon with side " << a << " created" << endl;
}


Pentagon::Pentagon(istream &is) {
    cout << "Input side a:" << endl;
    is >> a;
}

double Pentagon::Square() {
    double res = (5.0 * a * a) / (4.0 * tan(36.0 * PI / 180.0));
    return res; 
}

void Pentagon::Print() {
    cout << "Figure: Pentagon \nside = " << a << endl;    
}
