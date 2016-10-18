#include "obj/Mpoint.h"
#include "include/allocator.h"
#include "algorithm/insertion.h"

using namespace maybe;

int main(int argc, char** argv)
{
	maybe::Allocator<int> alloc;

	int x = 10;
	int *ptr = (int*)alloc.allocate(10);
	*ptr = 10;
	cout << "ptr = " << *ptr << endl;
	alloc.deallocate(ptr);
	vector<int> ls;
	for (int i=0; i<100; i++)
	{
		ls.push_back(100-i);
	}
	
	Insertion<int> sert(ls);
	sert.ascend(ls);

	for (int i=0; i < ls.size(); ++i)
	{
		cout << "i = " << i << " " << ls[i] << endl;
	}

	system(0);
	return 0;
}