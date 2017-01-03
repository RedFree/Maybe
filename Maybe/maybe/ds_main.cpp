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

#include "../include/ds.h"
using namespace mi_stl;
int main(int argc, char** argv)
{
	const int length = 100;
	int *p = new int[length];
	for (int i = 0; i <= length; ++i)
	{
		if (p != nullptr)
		{
			p[i] = i;
			//cout << "p = " << p << endl;
			
		}
		
	}
	
	base_ds<int, int>* object = new base_binary<int, int>(length);
	object->create();
	cout << "fill_tree" << endl;
	object->fill_tree(object->get_root(), p);
	cout << "pre_order" << endl;
	object->pre_order(object->get_root());


	object->release(object->get_root());

	return 0;
}