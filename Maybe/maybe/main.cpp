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

	/*********************************1**************************************/
	/* name: all_of                                                              
	/* function: Returns true if pred returns true for all the elements 
	/* in the range [first,last) or if the range is empty, and false otherwise. 
	/************************************************************************/
	/*alg<list<int>, int> ag;
	list<int> _list;
	for (int i=0; i < 100; ++i)
	{
	_list.push_back(i*2 + 1);
	}
	ag.function_show("all_of", &_list, _list.size());*/

	
	/*********************************2**************************************/
	/*	name: adjacent_find
	/*	function: Searches the range [first,last) for the first occurrence 
	/*	of two consecutive elements that match, and returns an iterator to 
	/*	the first of these two elements, or last if no such pair is found.
	/************************************************************************/
	/*alg<list<int>, int> ag;
	list<int> _list(100);
	generate(_list.begin(), _list.end(), rand);
	ag.function_show("adjacent_find", &_list, _list.size());*/

	
	/*********************************3**************************************/
	/*	Test the copy constructor                                                                      
	/************************************************************************/
	/*alg<list<int>, int> ag2(ag);
	ag2.function_show("", &_list, _list.size());*/

	/*********************************4**************************************/
	/*	name: adjacent_find
	/*	function: Searches the range [first,last) for the first occurrence 
	/*	of two consecutive elements that match, and returns an iterator to 
	/*	the first of these two elements, or last if no such pair is found.
	/************************************************************************/
	alg<vector<int>, int> ag;
	vector<int> _list(100);
	generate(_list.begin(), _list.end(), rand);
	_list.push_back(-1); // This is used to be found by any_of
	ag.function_show("any_of", &_list, _list.size());


	return 0;
}