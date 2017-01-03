#include "include/obj/gepoint.h"
#include "include/allocator.h"
#include "include/algorithm/algoritm.h"
#include "include/util.h"


using namespace maybe;
using namespace util;

typedef struct line
{
	double st;
	double ed;

	bool operator==(line l1)
	{
		if (st == l1.st && ed == l1.ed)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}T_LINE;

int main(int argc, char** argv)
{
	T_LINE line1, line2;
	line1.st = 2;
	line1.ed = 2;
	line2.st = 1;
	line2.ed = 2;

	if (line1 == line2)
	{
		cout << "line1 == line2" << endl;
	}
	else
	{
		cout << "line1 != line2" << endl;
	}

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
	//sert.bubble_sort(ls);
	int first = 0;
	int last = ls.size() - 1;
	//merge_sort1(ls, first, last);
	quick_sort(ls, 0, ls.size()-1);
	PRINT_ELEMENTS(ls);
	/*for (size_t i=0; i < ls.size(); ++i)
	{
		cout << "i = " << i << " " << ls[i] << endl;
	}*/

	system(0);
	return 0;
}