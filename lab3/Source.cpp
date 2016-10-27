#include "TQueue.h"
#include "rhombus.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	TQueue queue;
    
    queue.push(std::shared_ptr<Rhombus>(new Rhombus(4, 20)));
    queue.push(std::shared_ptr<Rhombus>(new Rhombus(5, 30)));
    queue.push(std::shared_ptr<Rhombus>(new Rhombus(6, 18)));

    
    std::cout << queue;
    
    
    std::shared_ptr<Rhombus> t;
    
    t = queue.pop(); std::cout << *t << std::endl;
    t = queue.pop(); std::cout << *t << std::endl;
    t = queue.pop(); std::cout << *t << std::endl;
	//system("pause");
	return 0;
}
