#include "Rs232.h"

using namespace std;

#if defined(__linux__) || defined(__FreeBSD__)   /*------------- Linux & FreeBSD ------------------*/
    #include "Rs232.cpp.linux"
#else /*----------------- Windows --------------------*/
    #include "Rs232.cpp.windows"
#endif  /*------------ on a choisit linux ou windows ----------------*/

