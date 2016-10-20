#include "obj/Mpoint.h"
#include "include/allocator.h"
#include "algorithm/algoritm.h"
#include "util.h"


using namespace maybe;
using namespace util;

int main(int argc, char** argv)
{
	maybe::Allocator<int> alloc;

	int x = 10;
	int *ptr = (int*)alloc.allocate(10);
	*ptr = 10;
	//cout << "ptr = " << *ptr << endl;
	alloc.deallocate(ptr);
	vector<int> ls;
	for (size_t i=0; i<100; i++)
	{
		ls.push_back(100-i);
	}
	
	Insertion<int> sert(ls);
	//sert.ascend(ls);
	//sert.ascend_sort(ls);

	//sert.insertion_sort(ls);
	sert.bubble_sort(ls);
	PRINT_ELEMENTS(ls);
	/*for (size_t i=0; i < ls.size(); ++i)
	{
		cout << "i = " << i << " " << ls[i] << endl;
	}*/

	system(0);
	return 0;
}