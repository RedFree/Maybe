#include "include/obj/gepoint.h"
#include "include/sys_def.h"
//#include "sys_def.h"
#include "include/util.h"

typedef struct student
{
	int id;
};


void test_stl_sort()
{
	std::vector<student> vec(100);
	int i = 0;
	for(std::vector<student>::iterator itor = vec.begin(); 
				itor != vec.end(); ++itor){
		itor->id = 100 - i++;
	}

	//The student will be sorted by id
	sort(vec.begin(), vec.end(), [](const student& fwd, const student& lwd){
		if(fwd.id < lwd.id)
			return true;
		else
			return false;
	});

	// Output the information of student
	for_each(vec.begin(), vec.end(), [](student elem){
		cout << " id = " << elem.id;
	});
	//util::PRINT_ELEMENTS(vec);

}

int main(int argc, char** argv)
{
	test_stl_sort();
	// maybe::gepoint point(1, 2);
	// maybe::gepoint pt2(point);
	// cout << "x = " << point.get_x();
	// cout << " y = " << point.get_y();

	// cout << "pt2.x = " << pt2.get_x();
	// cout << " pt2.y = " << pt2.get_y();
	// cout << endl;
	// pt2.x_ = 3;
	// cout << "point " << (point == pt2) << endl;
	return 0;
}