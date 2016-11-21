#include "TQueue.h"
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
	TQueue<Figure> queue;
    
    queue.push(std::shared_ptr<Rhombus>(new Rhombus(4, 20)));
    queue.push(std::shared_ptr<Trapeze>(new Trapeze(4, 5, 2, 2)));
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(5)));

    
    std::cout << queue;
    
    
    std::shared_ptr<Figure> t;
    t = queue.top(); 
	t->Print();
	//std::cout << t << std::endl;
	
	system("pause");
	return 0;
}
