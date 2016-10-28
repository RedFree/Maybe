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
#pragma pack(push, _CRT_PACKING) //表示从此处开始结构体成员按照_CRT_PACKING所表示的字节数对齐
#pragma warning(push, 3)         //表示从此处开始将警告级别提升为3
#pragma warning(disable: 4244)   //表示不记录4244号警告 

// 由于下方使用了operator new函数，因此需要先取消new的宏定义  
#pragma push_macro("new")  
#undef new  

#pragma warning(disable: 4100)  

#ifndef _FARQ   /* specify standard memory model */  
#define _FARQ  
#define _PDFT  ptrdiff_t  
#define _SIZT  size_t  
#endif /* _FARQ */  

/// memory allocator
namespace maybe
{
	template<typename _Ty>
	class Allocator
	{
		typedef _Ty size_type;
	public:
		Allocator();
		~Allocator();

		/// allocate the memory
		/// allocate memory of _Ty type, size is _size.
		size_type* allocate(size_t _size){
			return static_cast<size_type*>(::operator new(_size*sizeof(size_type)));
		}
		
		/// deallocate memory
		void deallocate(size_type* _t)
		{
			::operator delete (_t);
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

#pragma pop_macro("new")  
#pragma warning(pop)  
#pragma pack(pop)  

#endif
