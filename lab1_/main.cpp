#include "figure.h"
#include "trapeze.h"
#include "rhombus.h"
#include "pentagon.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    Figure *ptr = new Pentagon(5);
    ptr->Print();
    cout << "Square = " << ptr->Square() << endl;
  //  Figure *ptr = new Rhombus(2, 90);
  //  ptr->Print();
 //   cout << "Square = " << ptr->Square() << endl;
 //   ptr = new Trapeze(std::cin);
 //   ptr->Print();
    return 0;
}
