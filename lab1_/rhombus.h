#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <cstdlib>
#include <iostream>

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(int i, double j);
    Rhombus(std::istream &is);
    
    double Square() override;
    void Print() override;
    virtual ~Rhombus();
private:
    size_t a;
    double angle;
};
#endif
