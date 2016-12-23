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
    
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(5)));
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(4)));
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(3)));
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(2)));
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(1)));

    
    std::cout << queue << std::endl;
    
   // queue.sort();
    queue.sort_parallel();
    std::cout << queue << std::endl;

	system("pause");
	return 0;
}
