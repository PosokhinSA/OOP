#include "TQueue.h"
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"

#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
   /* 
	TQueue<Figure> queue;
    
    queue.push(std::shared_ptr<Rhombus>(new Rhombus(4, 20)));
    queue.push(std::shared_ptr<Trapeze>(new Trapeze(4, 5, 2, 2)));
    queue.push(std::shared_ptr<Pentagon>(new Pentagon(5)));
    queue.pop();
    */
   // queue.push(std::shared_ptr<Pentagon>(new Pentagon(4)));
    
    //std::cout << queue;
    
    /*
    std::shared_ptr<Figure> t;
    t = queue.top(); 
	t->Print();
	//std::cout << t << std::endl;
	*/
    
 /*   for (auto i : queue) {
        std::cout << "[ ";
        i->Print();
        std::cout << " ]" << std::endl;
    }
    /*
    for (TIterator<TQueueItem<Figure>, Figure> it = queue.begin(), end = queue.end(); it != end; it++) {
        std::cout << "[ ";
        it->Print();
        std::cout << " ]" << std::endl;
    }
    */

    TAllocator allocator(sizeof(int), 10);
    int *a1 = nullptr;
    int *a2 = nullptr;
    int *a3 = nullptr;
    int *a4 = nullptr;
    int *a5 = nullptr;
    a1 = (int*)allocator.allocate();
    *a1 = 1; std::cout << "a1 pointer value:" << *a1 << std::endl;
    a2 = (int*)allocator.allocate();
    *a2 = 2; std::cout << "a2 pointer value:" << *a2 << std::endl;
    a3 = (int*)allocator.allocate();
    *a3 = 3; std::cout << "a3 pointer value:" << *a3 << std::endl;
    allocator.deallocate(a1);
    allocator.deallocate(a3);
    a4 = (int*)allocator.allocate();
    *a4 = 4; std::cout << "a4 pointer value:" << *a4 << std::endl;
    a5 = (int*)allocator.allocate(); *a5 = 5;
    std::cout << "a5 pointer value:" << *a5 << std::endl;
    std::cout << "a1 pointervalue:" << *a1 << std::endl;
    std::cout << "a2 pointer value:" << *a2 << std::endl;
    std::cout << "a3 pointer value:" << *a3 << std::endl;
    allocator.deallocate(a2);
    allocator.deallocate(a4);
    allocator.deallocate(a5);


	system("pause");
	return 0;
}
