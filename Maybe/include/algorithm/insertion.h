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

#ifndef _INSERTION_H
#define _INSERTION_H

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
		void sort();
	protected:
	private:
		vector<_Ty> list_;
	};

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
	void Insertion<_Ty>::sort()
	{

	}

}


#endif