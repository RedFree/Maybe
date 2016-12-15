#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include "STL/algorithm.h"

using namespace std;
using namespace mi_stl;

int main(int argc, char** argv)
{
	/*std::vector<int> vec(100);
	generate(vec.begin(), vec.end(), rand);

	std::vector<int>::iterator min_itor = find_if(vec.begin(), vec.end(), [](int key1)->bool{
		if (key1 % 2 == 0)
			return true;
		else
		{
			return false;
		}
	});

	std::vector<int>::iterator max_itor = find_if(vec.begin(), vec.end(), [](int key1)->bool{
		if (key1 % 3 == 0)
			return true;
		else
		{
			return false;
		}
	});

	cout << "min = " << *min_itor << endl;
	cout << "max = " << *max_itor << endl;*/

	alg<list<int>> ag;
	list<int> _list(100);

	generate(_list.begin(), _list.end(), rand);
	ag.function_show("", &_list, _list.size());
	alg<list<int>> ag2(ag);
	ag2.function_show("", &_list, _list.size());


	return 0;
}