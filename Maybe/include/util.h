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

#ifndef _UTIL_H
#define _UTIL_H
#include "sys_def.h"

namespace util
{
	template <typename _Ty>
	inline void INSERT_ELEMENTS(_Ty& coll, int first, int last)
	{
		for (int i=first; i <= last; ++i)
		{
			coll.insert(coll.end(), i);
		}
	}

	template <typename _Ty>
	inline void PRINT_ELEMENTS(const _Ty& coll, const std::string& optcstr="")
	{
		std::cout << optcstr;
		for (auto elem : coll)
		{
			std::cout << elem << ' ';
		}

		std::cout << std::endl;
	}
}



#endif