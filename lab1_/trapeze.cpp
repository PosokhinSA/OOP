#include "trapeze.h"
using namespace std;

Trapeze::Trapeze() {
}

Trapeze::Trapeze(int i, int j, int k) {
    a = i;
    b = j;
    h = k;
    cout << "Trapeze with bases " << a << ", " << b << " and height " << h << endl;
}

Trapeze::Trapeze(istream &is) {
    cout << "Input base a:" << endl;
    is >> a;
    cout << "Input base b:" << endl;
    is >> b;
    cout << "Input height h:" << endl;
    is >> h;
}



double Trapeze::Square() {
    double res = (1.0 * a + b) / h;
    return res;
}


void Trapeze::Print() {
    cout << "Figure: Trapeze \nbase a = " << a << " base b = " << b << " height = " << h << endl;    
}
