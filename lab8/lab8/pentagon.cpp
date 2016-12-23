#include "pentagon.h"
#include <cmath>
#define PI 3.14159265


Pentagon::Pentagon() {
}
Pentagon::Pentagon(size_t side_) {
	side = side_;
	
	std::cout << "Pentagon created: " << side << std::endl;
}
Pentagon::Pentagon(std::istream &is) {
	is >> side;
}

Pentagon::Pentagon(const Pentagon& orig) {
	std::cout << "Pentagon copy created" << std::endl;
	side = orig.side;
	
}
double Pentagon::Square() {
	return (double)(5 * side * side /(4 * (double)tan(36 * (PI / 180))));
}
void Pentagon::Print() {
	std::cout << "Pentagon: side = " << side;
}


std::ostream& operator<<(std::ostream& os, const Pentagon& obj) {
	os << "Pentagon: side = " << obj.side;
	return os;
}

std::istream& operator >> (std::istream& is, Pentagon& obj) {
	std::cout << "Enter <side> <smaller_angle>\n";
	is >> obj.side;
	return is;
}


bool Pentagon::operator<(const Pentagon& other)
{
    return (double)(*this) < (double)(other);
}
bool Pentagon::operator>(const Pentagon& other)
{
    return double(*this) > double(other);
}
bool Pentagon::operator<=(const Pentagon& other)
{
    return double(*this) <= double(other);
}
bool Pentagon::operator>=(const Pentagon& other)
{
    return double(*this) >= double(other);
}
Pentagon::operator double() const
{
    return (double)(5 * side * side / (4 * (double)tan(36 * (PI / 180))));
}
bool Pentagon::operator == (const Pentagon &right)
{
    if (this->Square() == double(right)) {
        return true;
    }
    else return false;
}




Pentagon::~Pentagon() {
	std::cout << "Pentagon deleted" << std::endl;
}
