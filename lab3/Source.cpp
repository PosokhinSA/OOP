#include "TQueue.h"
#include "rhombus.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	TQueue queue;
    
    queue.push(std::shared_ptr<Rhombus>(new Rhombus(4, 20)), nullptr, nullptr);
    queue.push(nullptr,std::shared_ptr<Trapeze>(new Trapeze(4, 5, 2, 2)), nullptr);
    queue.push(nullptr, nullptr, std::shared_ptr<Pentagon>(new Pentagon(5)));

    
    std::cout << queue;
    
    
    std::shared_ptr<Rhombus> t;
    
    t = queue.top_rhomb(); 
    std::cout << *t << std::endl;
	//system("pause");
	return 0;
}
