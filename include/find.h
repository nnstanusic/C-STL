#define make_find_if(name, type, unaryPredicate) \
     inline static type* name(type* first, type* last)\
     {\
        for (; first != last; ++first) {\
            if (unaryPredicate(first)) {\
                return first;\
            }\
		}\
        return last;\
     }

#define make_find_if_not(name, type, unaryPredicate) \
     inline static type* name(type* first, type* last)\
     {\
        for (; first != last; ++first) {\
            if (!unaryPredicate(first)) {\
                return first;\
            }\
		}\
        return last;\
     }
