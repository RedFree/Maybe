//
// algorithm.h
// Copyright (C), 2016-2017, MillionIdeas. Co., Ltd.
// Author:  3ds@home
// Date: 2016/12/14
// 
// version: 1.0 
// Desc: 
//

#ifdef __cplusplus 
#include "sys_def.h"

namespace mi_stl
{
	bool myfunction (int i, int j) {
		return (i==j);
	}

	template <typename _T>
	void format_print(_T format_name, list<string> param, _T return_val)
	{
		std::cout << "===========================call way===========================" << std::endl;
		std::cout << "                 "<< format_name <<"               " << std::endl;
		int index = 1;
		for (auto elem : param)
		{
			std::cout << " param" << index++ << elem <<"               " << std::endl;
		}
		std::cout << "=============================end==============================" << std::endl;
		std::cout << std::endl;
	}

	/*
	 *	This is a functional class of stl algorithm
	 *	and it will show use of function that in algorithm of stl 
	 *	note: these example would be come from www.cplusplus.com, please forgive me.
	 *	
	 */
	template <typename _T>
	class alg
	{
		/*
		 *	Type define
		 */
		typedef typename _T type_val;
		typedef typename type_val* type_ptr;
		typedef typename type_val& type_ref;
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
			if (func_name.compare(""))
				show_all_name();
			else
			{
				detail_name(func_name);
			}
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
			show__adjacent_find();
		}

		void show__adjacent_find()
		{
			if (size <= 0)
				return;
			_T::iterator first = data_->begin();
			_T::iterator last = data_->begin();

			// using default comparison:
			_T::iterator it = std::adjacent_find (first, last);

			if (it!=data_->end())
				std::cout << "the first pair of repeated elements are: " << *it << '\n';

			//using predicate comparison:
			it = std::adjacent_find (++it, data_->end(), myfunction);

			if (it!= data_->end())
				std::cout << "the second pair of repeated elements are: " << *it << '\n';

		}

	private:
		/*
		 *	Data member
		 */
		type_ptr data_;
		size_t size;
	};

	template <typename _T>
	alg<_T>::alg()
	{
	}
	
	template <typename _T>
	alg<_T>::~alg()
	{
	}
}

#endif