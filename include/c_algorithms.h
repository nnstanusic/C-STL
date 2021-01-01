#include "find.h"
#include "numeric.h"
#include <stdbool.h>

#define make_for_each(name, type, unaryPredicate) \
inline static void name(type* first, type* last)\
     {\
        for (; first != last; ++first) { \
            unaryPredicate(first);\
        }\
     }
#define make_all_of(name, type, unaryPredicate) \
make_find_if_not(find_if_not_ ## name, type, unaryPredicate )\
inline static bool name(type* first, type* last)\
     {\
        return find_if_not_ ## name(first, last) == last;\
     }