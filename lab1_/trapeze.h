#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "figure.h"
#include <cstdlib>
#include <iostream>

class Trapeze : public Figure {
public:
    Trapeze();
    Trapeze(int i, int j, int k);
    Trapeze(std::istream &is);
    
    double Square() override;
    void Print() override;
    virtual ~Trapeze();
private:
    size_t a;
    size_t b;
    size_t h;
};
#endif
