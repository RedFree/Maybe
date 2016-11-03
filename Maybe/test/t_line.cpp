#include "obj/gepoint.h"
#include "sys_def.h"

int main(int argc, char** argv)
{
	maybe::gepoint point(1, 2);
	maybe::gepoint pt2(point);
	cout << "x = " << point.get_x();
	cout << " y = " << point.get_y();

	cout << "pt2.x = " << pt2.get_x();
	cout << " pt2.y = " << pt2.get_y();
	cout << endl;
	pt2.x_ = 3;
	cout << "±È½Ï£º " << (point == pt2) << endl;
	return 0;
}