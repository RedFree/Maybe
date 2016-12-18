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

		void describe_func(const string& name, const string& param1, const string& param2, const string& operation, const string& _return)
		{
			list<string> param;
			param.push_back(param1);
			param.push_back(param2);
			param.push_back(operation);
			format_print(name, param, _return);
			std::cout << "DATA SAMPLE:" << std::endl;
			util::PRINT_ELEMENTS(*data_);
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
			else if (!func_name.compare("copy"))
				show_copy();
			else if (!func_name.compare("copy_backward"))
				show_copy_backward();
			else if (!func_name.compare("copy_if"))
				show_copy_if();	
			else if (!func_name.compare("copy_n"))
				show_copy_n();
			else if (!func_name.compare("count"))
				show_count();
			else if (!func_name.compare("count_if"))
				show_count_if();
			else if (!func_name.compare("equal"))
				show_equal();

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
			format_print("binary_search", param, "bool");
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

		/*
		*	@function: Copies the elements in the range [first,last) into the range beginning at result.
		*			   The function returns an iterator to the end of the destination range 
		*			   (which points to the element following the last element copied).
		*	@return: The function returns an iterator to the end of the destination range 
		*			 (which points to the element following the last element copied).
		*	@Complexity: linear
		*/
		void show_copy()
		{
			if (size <= 0)
				return;

			list<string> param;
			param.push_back("iterator");
			param.push_back("iterator");
			param.push_back("operation");
			format_print("copy", param, "iterator");
			std::cout << "DATA SAMPLE:" << std::endl;
			util::PRINT_ELEMENTS(*data_);
			_T::iterator first = data_->begin();
			_T::iterator last = data_->end();

			type_val out_data(size);

			// This will return the end iterator of out_data.
			copy(first, last, out_data.begin());

			cout << "copy array is : " << endl;
			util::PRINT_ELEMENTS(out_data);
		}

		/*
		*	@function:	Copies the elements in the range [first,last) starting from 
		*				the end into the range terminating at result.
		*	@return:	The function returns an iterator to the first element in the destination range.
		*	@complexity: linear
		*/
		void show_copy_backward()
		{
			describe_func("copy_backward", "start_iterator", "end_iterator", "out_array_end", "first_iterator_out");

			type_val::iterator first = data_->begin();
			type_val::iterator end   = data_->end();
			
			// output array, initialize array by size.
			type_val out_data(size);
			std::copy_backward ( first, end,  out_data.end());

			std::cout << "out_data contains:";
			for (type_val::iterator it=out_data.begin(); it!=out_data.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

		}

		/**
		 * @function: Copies the elements in the range [first,last) for which 
		 *			  pred returns true to the range beginning at result.	
		 * @return:		
		 * @complexity:	Linear 
		 *
		 */
		void show_copy_if()
		{
			describe_func("copy_if", "start_iterator", "end_iterator", "out_array_begin", "end_iterator_out");
			type_val::iterator first = data_->begin();
			type_val::iterator end   = data_->end();

			// output array, initialize array by size.
			type_val out_data(size);
			// copy only positive numbers:
			type_val::iterator it = std::copy_if (first, end, out_data.begin(), [](_Ty i){return !(i<0);} );
			out_data.resize(std::distance(out_data.begin(),it));  // shrink container to new size

			std::cout << "out_data contains:";
			for (_Ty& x: out_data) std::cout << ' ' << x;
			std::cout << '\n';
		}

		/**
		 * @function:Copies the first n elements from the range beginning at first into the range beginning at result.
		 * @return:	The function returns an iterator to the end of the destination range 
		 *		    (which points to one past the last element copied).	
		 * @complexity:	Linear 
		 *
		 */
		void show_copy_n()
		{
			describe_func("copy_n", "out_data_array", "n", "in_array_begin", "end_iterator_out");
			type_val::iterator first = data_->begin();
			type_val::iterator end   = data_->end();

			// output array, initialize array by size.
			type_val out_data(size);

			//Copy the the first seven elements to out_data.
			std::copy_n ( first, 7, out_data.begin() );

			std::cout << "out_data contains:";
			for (type_val::iterator it = out_data.begin(); it!=out_data.end(); ++it)
				std::cout << ' ' << *it;

			std::cout << '\n';

		}

		/**
		 * @function:Returns the number of elements in the range [first,last) that compare equal to val.	
		 * @return:		
		 * @complexity:	Linear
		 *
		 */
		void show_count()
		{
			describe_func("count", "indata_container_beg_iterator", "n", "indata_container_end_iterator", "key_num");
			type_val::iterator first = data_->begin();
			type_val::iterator end   = data_->end();

			// output array, initialize array by size.
			type_val out_data(size);

			int mycount = std::count (first, end, 10);
			std::cout << "10 appears " << mycount << " times.\n";
		}

		/**
		 * @function:Returns the number of elements in the range [first,last) for which pred is true.	
		 * @return:		
		 * @complexity:	Linear 
		 *
		 */
		void show_count_if()
		{
			describe_func("count_if", "indata_container_beg_iterator", "indata_container_end_iterator", "operation", "key_num");
			type_val::iterator first = data_->begin();
			type_val::iterator end   = data_->end();

			// output array, initialize array by size.
			//type_val out_data(size);

			// count the number of Odd 
			int mycount = count_if (first, end, [](_Ty i){return ((i%2)==1);});
			std::cout << "out_data contains " << mycount  << " odd values.\n";

		}

		/**
		 * @function: Compares the elements in the range [first1,last1) with those in the range beginning at first2, 
		 *			  and returns true if all of the elements in both ranges match.	
		 * @return:		
		 * @complexity:	linear 
		 *
		 */
		void show_equal()
		{
			describe_func("equal", "indata_container_beg_iterator", "indata_container_end_iterator", "out_data_container", "bool");
			type_val::iterator first = data_->begin();
			type_val::iterator end   = data_->end();

			int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
			type_val myvector (first, end);     // myvector: 20 40 60 80 100

			// using default comparison:
			if ( std::equal (myvector.begin(), myvector.end(), first) )
				std::cout << "The contents of both sequences are equal.\n";
			else
				std::cout << "The contents of both sequences differ.\n";

			// make not equal
			myvector[3]=81;                                 // myvector: 20 40 60 81 100

			// using predicate comparison:
			if ( std::equal (myvector.begin(), myvector.end(), first, [](_Ty i, _Ty j){return (i==j);}) )
				std::cout << "The contents of both sequences are equal.\n";
			else
				std::cout << "The contents of both sequences differ.\n";

		}

		/**
		 * @function:	
		 * @return:		
		 * @complexity:	 2*log2(N)+1
		 *
		 */
		void show_equal_range()
		{
			int myints[] = {10,20,30,30,20,10,10,20};
			std::vector<int> v(myints,myints+8);                         // 10 20 30 30 20 10 10 20
			std::pair<std::vector<int>::iterator,std::vector<int>::iterator> bounds;

			// using default comparison:
			std::sort (v.begin(), v.end());                              // 10 10 10 20 20 20 30 30
			bounds=std::equal_range (v.begin(), v.end(), 20);            //          ^        ^

			// using "mygreater" as comp:
			std::sort (v.begin(), v.end(), [](int i,int j) { return (i>j); });                   // 30 30 20 20 20 10 10 10
			bounds=std::equal_range (v.begin(), v.end(), 20, [](int i,int j) { return (i>j); }); //       ^        ^

			std::cout << "bounds at positions " << (bounds.first - v.begin());
			std::cout << " and " << (bounds.second - v.begin()) << '\n';
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