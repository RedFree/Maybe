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

	/*
	 *	合并两个已经排好序的数组
	 *	_coll: 容器
	 *	_first: left数组第一个元素索引
	 *	_mid: 两个数组中间元素索引，属于left数组最后一个元素索引
	 *	_last: right数组中最后一个元素索引，
	 *	_size: _coll 数组长度
	 */
	template <typename _Ty>
	void merge(_Ty& _coll, const size_t& _first, const size_t& _mid, const size_t& _last, const size_t& _size)
	{
		//此方法可以任意进行发挥，使用各种算法
		///定义两个数组分别保存left和right数组元素，用于合并两个数组
		_Ty left;
		_Ty right;
		
 		for (size_t idx=0; idx<=_mid-_first ; ++idx)
		{
			//	将_coll数组中左边已经排好序的数组复制到left
			//	数组中
			left.push_back(_coll[_first+idx]);
		}

 		for (size_t idx=0; idx <= _last-_mid - 1; ++idx)
		{
			//	将__coll数组中右边已经排好序的数组复制到right
			//	数组中
  			right.push_back(_coll[_mid+idx+1]);
		}

		for (size_t i=0, j=0, k=_first; k<=_last; k++)  
		{  
			//	合并两个数组
			if (i <= _mid)
			{
				//	如果第一个数组和第二个数组都没有合并完成
				if (j < _last - _mid)
				{
					if (left[i]<=right[j] && i <= _mid)  
					{  
						_coll[k] = left[i];  
						i++;  
					}else{  
						_coll[k] = right[j];  
						j++;   
					}  
				}
				else
				{
					//	right数组合并完成，
					//	将left数组剩余元素复制到
					//	_coll数组中
					_coll[k] = left[i];  
					i++; 
				}
				
			}
			else
			{
				//	如果left数组合并完成，
				//	则将right数组复制到_coll数组中
				if (j < _last - _mid)
				{
					_coll[k] = right[j];  
					j++;   
				}
			}
		}  
	}

	//  [10/28/2016 wd]
	/*
	 *	归并排序算法简单实现
	 *  _Ty为STL容器
	 *	_first: 数组第一个索引
	 *	_last: 数组最后一个索引
	 */
	template<typename _Ty>
	void merge_sort1(_Ty& _coll, const size_t& _first, const size_t& _last)
	{
		if (_first < _last)
		{
			/*如果数组中大于等于两个元素，则继续分*/
			///此种分法必然导致left数组size大于等于right数组size
			size_t _mid = (_first + _last)/2;
			//	继续分left数组
			merge_sort1(_coll, _first, _mid);  
			//	继续分right数组
			merge_sort1(_coll, _mid+1, _last);
			//	对两个已经排好序的数组进行合并

			size_t _size = _coll.size();
			//_size暂时没有使用
			merge(_coll, _first, _mid, _last, _size);  
		}
	}

	//  [10/28/2016 wd]
	/*
	 *	明天必须实现
	 *	今天就算了
	 */
	template<typename _Ty>
	void quick_sort(_Ty& _coll, const size_t& _left, const size_t& _right)
	{

	}

}


#endif