#ifndef _SYS_DEF_H
#define _SYS_DEF_H

#if !defined(__FILE__)
#   define __FILE__ ""
#endif
#if !defined(__LINE__)
#   define __LINE__ 0
#endif 

#if defined(__func__)
#   undef __func__
#endif
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#   define __func__ __FUNCSIG__
#endif



#endif
