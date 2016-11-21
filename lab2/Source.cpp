#include "TQueue.h"
#include "rhombus.h"
#include <iostream>

using namespace std;

int main()
{
	Rhombus *r = new Rhombus(5, 90);
	cin >> *r;
	cout << *r;
	TQueue q;
	q.push(Rhombus(5, 90));
	q.push(Rhombus(4, 40));
	cout << q << std::endl;
	delete r;
	//system("pause");
	return 0;
}
