#ifndef _MPOINT_H
#define _MPOINT_H

#include "sys_def.h"
#include "type_def.h"

namespace maybe
{
	using namespace gem;
	/// 平面几何中的点
	class gepoint
	{
	public:
		gepoint() : x_(0), y_(0){}
		gepoint(const ge_real32 _x, const ge_real32 _y) : 
			x_(_x), y_(_y){}

		/*
		 *	拷贝构造函数
		 */
		gepoint(const gepoint& _point){
			x_ = _point.get_x();
			y_ = _point.get_y();
		}

		/*
		 *	重载=， 用于赋值
		 */
		gepoint& operator=(const gepoint& _point){
			x_ = _point.get_x();
			y_ = _point.get_y();
			return *this;
		}

		/*
		 *	用于大于比较
		 */
		ge_bool operator>(const gepoint& _point){
			if (x_ > _point.get_x() && y_ > _point.get_y())
				return ge_true;
			else
				return ge_false;
		}

		/*
		 *	用于小于比较
		 */
		ge_bool operator<(const gepoint& _point){
			if (x_ < _point.get_x() && y_ < _point.get_y())
				return ge_true;
			else 
				return ge_false;
		}

		/*
		 *	用于等于比较
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
		 *	获取点的x坐标
		 */
		ge_real32 get_x()const{return x_;}

		/*
		 *	获取点的y轴坐标
		 */
		ge_real32 get_y()const {return y_;}
	public:
		ge_real32	x_;
		ge_real32	y_;
	};
}

#endif //_MPOINT_H

