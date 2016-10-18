#include "obj/Mpoint.h"
#include "include/allocator.h"


using namespace maybe;

int main(int argc, char** argv)
{
	maybe::Allocator<int> alloc;

	int x = 10;
	int *ptr = &x;
	//*++ptr = 20;
	cout << *ptr << endl;
	//int *ptr = (int*)alloc.allocate(x, 10);
	//int *tmpPtr = ptr;
	//for (int i=0; i<11; i++)
	//{
	//	*ptr = 10+i;
	//	++ptr;
	//}

	///*for (int i=0; i<10; i++)
	//{
	//cout << "*tmpPtr = " << *tmpPtr++ << endl;
	//}*/
	//cout << "tmpPtr++" << *(tmpPtr+5) << endl;
	//alloc.deallocate(tmpPtr, 1);
	//cout << "ptr = " << *--ptr << endl;
	//delete tmpPtr;

	system(0);
	return 0;
}