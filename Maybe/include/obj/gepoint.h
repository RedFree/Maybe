#ifndef _MPOINT_H
#define _MPOINT_H

#include "../sys_def.h"
#include "../type_def.h"

namespace maybe
{
	using namespace gem;
	/// ƽ�漸���еĵ�
	class gepoint
	{
	public:
		gepoint() : x_(0), y_(0){}
		gepoint(const ge_real32 _x, const ge_real32 _y) : 
			x_(_x), y_(_y){}

		/*
		 *	�������캯��
		 */
		gepoint(const gepoint& _point){
			x_ = _point.get_x();
			y_ = _point.get_y();
		}

		/*
		 *	����=�� ���ڸ�ֵ
		 */
		gepoint& operator=(const gepoint& _point){
			x_ = _point.get_x();
			y_ = _point.get_y();
			return *this;
		}

		/*
		 *	���ڴ��ڱȽ�
		 */
		ge_bool operator>(const gepoint& _point){
			if (x_ > _point.get_x() && y_ > _point.get_y())
				return ge_true;
			else
				return ge_false;
		}

		/*
		 *	����С�ڱȽ�
		 */
		ge_bool operator<(const gepoint& _point){
			if (x_ < _point.get_x() && y_ < _point.get_y())
				return ge_true;
			else 
				return ge_false;
		}

		/*
		 *	���ڵ��ڱȽ�
		 */
		ge_bool operator==(const gepoint& _point){
			if (x_ == _point.get_x() && y_ == _point.get_y())
				return ge_true;
			else 
				return ge_false;
		}

		~gepoint(){};

	public:
		/*
		 *	��ȡ����x����
		 */
		ge_real32 get_x()const{return x_;}

		/*
		 *	��ȡ����y������
		 */
		ge_real32 get_y()const {return y_;}
	public:
		ge_real32	x_;
		ge_real32	y_;
	};
}

#endif //_MPOINT_H

