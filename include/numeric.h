#define make_accumulate(name, iterator_type, accumulation_t, binaryPredicate) \
inline static accumulation_t name(iterator_type* begin, iterator_type* end, accumulation_t initial_value)\
     {\
           for (; begin != end; ++begin) { \
                binaryPredicate(&initial_value, begin); \
           }\
           return initial_value; \
     }

#define make_iota(name, iterator_type)\
inline static void name(iterator_type* begin, iterator_type* end, iterator_type initial_value)\
{\
    while (begin != end) {\
        *begin++ = initial_value++;\
    }\
}