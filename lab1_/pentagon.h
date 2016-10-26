#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <cstdlib>
#include <iostream>

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(int i);
    Pentagon(std::istream &is);
    
    double Square() override;
    void Print() override;
    
    virtual ~Pentagon();
private:
    size_t a;
};
#endif
