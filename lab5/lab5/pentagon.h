#pragma once


#include <cstdlib>
#include <iostream>
#include "figure.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(size_t side);
	Pentagon(const Pentagon& orig);
	double Square() override;
	void Print() override;
	friend std::istream& operator >> (std::istream& is, Pentagon& obj);
	friend std::ostream& operator<<(std::ostream& os, const Pentagon& obj);
	virtual ~Pentagon();
private:
	size_t side;
	
};

