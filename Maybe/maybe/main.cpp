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
	/*	name: any_of
	/*	Returns true if pred returns true for any of the elements in the 
	/*	range [first,last), and false otherwise. 
	/*	
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//_list.push_back(-1); // This is used to be found by any_of
	//ag.function_show("any_of", &_list, _list.size());

	/*********************************5**************************************/
	/*	name: binary_search
	/*	Returns true if any element in the range [first,last) is equivalent 
	/*	to val, and false otherwise.
	/*	
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//_list.push_back(-1); // This is used to be found by any_of
	//ag.function_show("binary_search", &_list, _list.size());

	/*********************************5**************************************/
	/*	name: copy
	/*	Returns true if any element in the range [first,last) is equivalent 
	/*	to val, and false otherwise.
	/*	
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//ag.function_show("copy", &_list, _list.size());

	/*********************************6**************************************/
	/*	name: copy_backward
	/*	Copies the elements in the range [first,last) starting from the end 
	/*	into the range terminating at result.
	/*	
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//ag.function_show("copy_backward", &_list, _list.size());

	/*********************************7**************************************/
	/*	name: copy_if
	/*	Copies the elements in the range [first,last) starting from the end 
	/*	into the range terminating at result.
	/*	
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//for_each(_list.begin(), _list.end(), [](int& x){if (x%2 == 0)x = -x;});
	//ag.function_show("copy_if", &_list, _list.size());

	/*********************************8**************************************/
	/*	name: copy_if
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//ag.function_show("copy_n", &_list, _list.size());

	/*********************************9**************************************/
	/*	name: count
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//_list.push_back(10);
	//_list.push_back(10);
	//ag.function_show("count", &_list, _list.size());

	/*********************************10**************************************/
	/*	name: count_if
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//_list.push_back(10);
	//_list.push_back(10);
	//ag.function_show("count_if", &_list, _list.size());

	/*********************************11**************************************/
	/*	name: equal
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//ag.function_show("equal", &_list, _list.size());

	/*********************************12**************************************/
	/*	name: equal_range
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//generate(_list.begin(), _list.end(), rand);
	//ag.function_show("equal_range", &_list, _list.size());

	/*********************************12**************************************/
	/*	name: find_end
	/************************************************************************/
	//alg<vector<int>, int> ag;
	//vector<int> _list(100);
	//for (size_t i=0; i < _list.size(); ++i)
	//{
	//	_list[i] = i;
	//}
	////generate(_list.begin(), _list.end(), rand);
	//ag.function_show("find_end", &_list, _list.size());

	/*********************************13**************************************/
	/*	name: find_first_of
	/************************************************************************/
	alg<vector<int>, int> ag;
	vector<int> _list(100);
	for (size_t i=0; i < _list.size(); ++i)
	{
		_list[i] = i+1;
	}
	//generate(_list.begin(), _list.end(), rand);
	ag.function_show("find_if", &_list, _list.size());

	return 0;
}