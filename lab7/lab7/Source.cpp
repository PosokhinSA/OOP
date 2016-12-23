#include "TQueue.h"
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"

#include "ntree.h"


#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    TQueue<TNTree<Figure>, Figure> queue;

    queue.InsertSubItem(new Pentagon(1));
    queue.InsertSubItem(new Pentagon(3));
    queue.InsertSubItem(new Pentagon(3));
    queue.InsertSubItem(new Pentagon(3));
    queue.InsertSubItem(new Pentagon(3));
    queue.InsertSubItem(new Pentagon(3));
    queue.InsertSubItem(new Pentagon(1));

    queue.RemoveSubItemByValue(10);
    

	system("pause");
	return 0;
}
