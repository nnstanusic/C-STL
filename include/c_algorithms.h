#include "find.h"
#include "numeric.h"

#define make_for_each(name, type, unaryPredicate) \
inline static void name(type* first, type* last)\
     {\
        for (; first != last; ++first) { \
            unaryPredicate(first);\
        }\
     }

     