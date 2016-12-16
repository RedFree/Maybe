//
// algorithm.h
// Copyright (C), 2016-2017, MillionIdeas. Co., Ltd.
// Author:  3ds@home
// Date: 2016/12/14
// 
// version: 1.0 
// Desc: All the sample will be found on http://www.cplusplus.com/reference/algorithm/any_of/ 
//

#ifdef __cplusplus 
#include "util.h"

namespace mi_stl
{
	bool myfunction (int i, int j) {
		return (i==j);
	}

	template <typename _T>
	void format_print(_T format_name, list<string> param, _T return_val)
	{
		std::cout << "===========================call way===========================" << std::endl;
		std::cout << "@func_name: "<< format_name <<"               " << std::endl;
		int index = 1;
		for (auto elem : param)
		{
			std::cout << "@param" << index++ << ": " << elem <<"               " << std::endl;
		}
		std::cout << "@return: " << return_val << std::endl;
		std::cout << "=============================end==============================" << std::endl;
		//std::cout << std::endl;
	}

	/*
	*	This is a functional class of stl algorithm
	*	and it will show use of function that in algorithm of stl 
	*	note: these example would be come from www.cplusplus.com, please forgive me.
	*	
	*/
	template <typename _T, typename _Ty>
	class alg
	{
		/*
		*	Type define
		*/
		typedef typename _T type_val;
		typedef typename type_val* type_ptr;
		typedef typename type_val& type_ref;
		typedef typename _Ty type_ele;
	public:
		/*
		*	This class will be create as a nice class
		*/
		alg();
		~alg();

		alg(const type_ptr _data) : data_(_data)
		{
			/*Bring the param contractor*/
		}

		/*
		*	Overloading =
		*/
		alg& operator=(const alg& ref)
		{
			data_ = ref.data_;
			return *this;
		}

		alg(const alg& ref)
		{
			*this = ref;
		}

	public:
		/*
		*	This is a interface for custom and test all the functional
		*/
		template <typename _T>
		void function_show(const std::string& func_name, _T* data, size_t _size)
		{
			size = _size;
			data_ = data;
			detail_name(func_name);
		}

		bool comp(_Ty x_, _Ty y_)
		{
			return (x_>y_);
		}

	private:

		

		/*
		*	Showing all the name of function which in algorithm library on console.
		*/
		void show_all_name()
		{

		}

		/*
		*	Managing all the function that will be called
		*/
		void detail_name(const std::string& func_name)
		{
			if (!func_name.compare("all_of"))
				show_all_of();
			else if (!func_name.compare("adjacent_find"))
				show__adjacent_find();
			else if (!func_name.compare("any_of"))
				show_any_of();
			else if (!func_name.compare("binary_search"))
				show_binary_search();

		}

		/*
		*	Function adjacent_find of stl
		*	Searches the range [first,last) for the first occurrence of two consecutive elements that match, 
		*	and returns an iterator to the first of these two elements, or last if no such pair is found.
		*/
		void show__adjacent_find()
		{
			if (size <= 0)
				return;
			std::cout << "DATA SAMPLE:" << std::endl;
			util::PRINT_ELEMENTS(*data_);
			list<string> param;
			param.push_back("iterator");
			param.push_back("iterator");
			param.push_back("operation");
			format_print("adjacent_find", param, "find_iterator");

			_T::iterator first = data_->begin();
			_T::iterator last = data_->end();

			// using default comparison:
			_T::iterator it = std::adjacent_find (first, last);

			if (it!=data_->end())
				std::cout << "the first pair of repeated elements are: " << *it << '\n';
			else
			{
				std::cout << "No match...!" << std::endl;
			}

			//using predicate comparison:
			if (it!= data_->end())
				it = std::adjacent_find (++it, data_->end(), myfunction);

			if (it!= data_->end())
				std::cout << "the second pair of repeated elements are: " << *it << '\n';

		}

		/*
		* name: all_of                                                              
		* function: Returns true if pred returns true for all the elements 
		* in the range [first,last) or if the range is empty, and false otherwise. 
		*/
		void show_all_of()
		{
			util::PRINT_ELEMENTS(*data_);
			type_val::iterator first = data_->begin();
			type_val::iterator last = data_->end();
			if ( std::all_of(first, last, [](type_ele i){return i%2;}) )
				std::cout << "All the elements are odd numbers.\n";
			util::PRINT_ELEMENTS(*data_);
		}

		/*
		 *	Returns true if pred returns true for any of the elements 
		 *	in the range [first,last), and false otherwise
		 */
		void show_any_of()
		{
			if (size <= 0)
				return;
			list<string> param;
			param.push_back("iterator");
			param.push_back("iterator");
			param.push_back("operation");
			format_print("any_of", param, "bool");
			std::cout << "DATA SAMPLE:" << std::endl;
			util::PRINT_ELEMENTS(*data_);
			type_val::iterator first = data_->begin();
			type_val::iterator last = data_->end();
			if ( std::any_of(first, last, [](int i){return i<0;}) )
				std::cout << "There are negative elements in the range.\n";
			else
				std::cout << "There are not negative elements in the range.\n";
		}

		/*
		 *	Binary_serach is used to search the specific element in contains.
		 *	Here use the sort function to sorting the elements in contains,
		 *	sort function is not be used to list, because list is not support
		 *	random access the element.
		 */
		void show_binary_search()
		{
			if (size <= 0)
				return;
			list<string> param;
			param.push_back("iterator");
			param.push_back("iterator");
			param.push_back("operation");
			format_print("any_of", param, "bool");
			std::cout << "DATA SAMPLE:" << std::endl;
			util::PRINT_ELEMENTS(*data_);
			_T::iterator first = data_->begin();
			_T::iterator last = data_->end();

			// using default comparison:
			// Not use to list
			std::sort(first, last);

			std::cout << "looking for a 3... ";
			if (std::binary_search (first, last, 3))
				std::cout << "found!\n"; else std::cout << "not found.\n";

			// using myfunction as comp:
			std::sort (first, last, [](type_ele x_, type_ele y_)->bool{return (x_ < y_);});

			std::cout << "looking for a 6... ";
			if (std::binary_search (first, last, 6, [](type_ele x_, type_ele y_)->bool{return (x_ < y_);}))
				std::cout << "found!\n"; else std::cout << "not found.\n";
		}

	private:
		/*
		*	Data member
		*/
		type_ptr data_;
		size_t size;
	};

	template <typename _T, typename _Ty>
	alg<_T, _Ty>::alg()
	{
	}

	template <typename _T, typename _Ty>
	alg<_T, _Ty>::~alg()
	{
	}
}

#endif