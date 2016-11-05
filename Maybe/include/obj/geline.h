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

#ifndef _GELINE_H
#define _GELINE_H
#include "include/obj/gepoint.h"

/// ֱ����
/// ��ʼ������ȷ��һ��ֱ��
namespace maybe
{
	class geline
	{
	public:
		/*
		 *	Ĭ�Ϲ��캯��
		 */
		geline() : vector_(0, 0){}

		/*
		 *	���ι��캯��
		 */
		geline(const gepoint& _st, const gepoint& _ed) : 
			start_(_st), end_(_ed)
		{
			vector_.x_ = end_.x_ - start_.x_;
			vector_.y_ = end_.y_ - start_.y_;
		}

		~geline();

	private:
		gepoint start_;
		gepoint end_;

		/*
		 *	����Ϊֱ�ߵ�бʽ����
		 */
		ge_real32 afcator;//б��
		ge_real32 bfactor;//�ؾ�

	public:
		/*
		 *	ֱ������
		 */
		gepoint vector_;



		ge_real32 get_afactor(void)
		{
			return ge_real32();
		}

		ge_real32 get_bfactor(void)
		{
			return ge_real32();
		}
	};

}

#endif