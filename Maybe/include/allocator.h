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

#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H

/// memory allocator
namespace maybe
{
	template<typename _Ty>
	class Allocator
	{
	public:
		Allocator();
		~Allocator();

		void* allocate(const _Ty& _t, size_t _size)
		{
			return ::operator new(_size*sizeof(_Ty));
		}

		void deallocate(_Ty* _t, size_t _size)
		{
			//for (size_t idx=0; idx<_size; ++idx)
			{
				::operator delete (_t);
				//++_t;
			}
		}
	private:

	};

	template<typename _Ty>
	Allocator<_Ty>::Allocator()
	{
	}

	template<typename _Ty>
	Allocator<_Ty>::~Allocator()
	{
	}

}
#endif
