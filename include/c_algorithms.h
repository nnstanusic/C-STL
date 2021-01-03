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
make_find_if_not(impl_all_of_ ## name, type, unaryPredicate )\
inline static bool name(type* first, type* last)\
     {\
        return impl_all_of_ ## name(first, last) == last;\
     }

#define make_any_of(name, type, unaryPredicate) \
make_find_if(impl_any_of_ ## name, type, unaryPredicate )\
inline static bool name(type* first, type* last)\
     {\
        return impl_any_of_ ## name(first, last) != last;\
     }

#define make_none_of(name, type, unaryPredicate) \
make_find_if(impl_none_of_ ## name, type, unaryPredicate )\
inline static bool name(type* first, type* last)\
     {\
        return impl_none_of_ ## name(first, last) == last;\
     }