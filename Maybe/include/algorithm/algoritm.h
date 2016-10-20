//*********************************************************************************/
// MIT License
//
// Copyright (c) 2016 RedFree
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//*********************************************************************************/

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "sys_def.h"
#include "allocator.h"

namespace maybe
{
	using maybe::Allocator;
	template<typename _Ty>
	class Insertion
	{
	public:
		///The default constructor
		Insertion(){}
		///The constructor of copy
		Insertion(const Insertion& _insert){
			this->list_ = _insert.list_;
		}
		Insertion(const vector<_Ty> _list) : list_(_list){}
		~Insertion(){}

		void ascend(vector<_Ty>& _sortVec);
		void ascend_sort(vector<_Ty>& _sortVec);
		//************************************
		// Method:    insertion_sort
		// FullName:  maybe::Insertion<_Ty>::insertion_sort
		// Access:    public 
		// Returns:   void
		// Qualifier: standard insertion-sort
		// Parameter: const vector<_Ty> & _sort_vec
		//************************************
		void insertion_sort( vector<_Ty>& _sort_vec);

		//************************************
		// Method:    bubble_sort
		// FullName:  maybe::Insertion<_Ty>::bubble_sort
		// Access:    public 
		// Returns:   void
		// Qualifier: standard bubble-sort
		// Parameter: vector<_Ty> & _sort_vec
		//************************************
		void bubble_sort(vector<_Ty>& _sort_vec);
	protected:
	private:
		vector<_Ty> list_;
	};

	template<typename _Ty>
	void maybe::Insertion<_Ty>::bubble_sort( vector<_Ty>& _sort_vec )
	{
		for (size_t first = 0; first < _sort_vec.size(); ++first)
		{
			for (size_t scnd = _sort_vec.size() - 1; scnd > first; --scnd)
			{
				if (_sort_vec[scnd] < _sort_vec[scnd-1])
				{
					_Ty tmp = _sort_vec[scnd];
					_sort_vec[scnd] = _sort_vec[scnd-1];
					_sort_vec[scnd-1] = tmp;
				}
			}

		}
	}

	template<typename _Ty>
	void maybe::Insertion<_Ty>::insertion_sort( vector<_Ty>& _sort_vec )
	{
		for (size_t first = 1; first < _sort_vec.size(); ++first)
		{
			_Ty _key = _sort_vec[first];
			int _prev = first - 1;
			while (_prev >= 0 && _sort_vec[_prev] > _key)
			{
				_sort_vec[_prev+1] = _sort_vec[_prev];
				--_prev;
			}
			_sort_vec[_prev+1] = _key;

		}
	}

	template<typename _Ty>
	void Insertion<_Ty>::ascend(vector<_Ty>& _sortVec)
	{
		for (size_t i = 0; i < list_.size(); ++i)
		{
			size_t uRet = i;
			for (size_t dx = uRet; dx > 0; --dx)
			{
				if (list_[dx] < list_[dx-1])
				{
					_Ty tp = list_[dx];
					list_[dx] = list_[dx-1];
					list_[dx-1] = tp;
				}
				else
					break;
			}
		}
		_sortVec = list_;
	}
	template<typename _Ty>
	void Insertion<_Ty>::ascend_sort(vector<_Ty>& _sortVec)
	{
		vector<_Ty>::iterator _itor = ++_sortVec.begin();
		while (_itor != _sortVec.end())
		{
			vector<_Ty>::iterator _secItor = _itor;
			vector<_Ty>::iterator _thdItor;
			while (_secItor !=_sortVec.begin() && 
				  (*(_thdItor = _secItor) ) < *--_secItor )
			{
				_Ty _val = *_secItor;
				*_secItor = *_thdItor;
				*_thdItor = _val;
			}
			++_itor;
		}
	}
}


#endif