
#ifndef _SYS_DEF_H
#define _SYS_DEF_H

#if !defined(__FILE__)
#   define __FILE__ ""
#endif
#if !defined(__LINE__)
#   define __LINE__ 0
#endif 
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#   define __func__ __funcbe__
#endif
#endif

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <stack>

using namespace std;

namespace maybe
{

}