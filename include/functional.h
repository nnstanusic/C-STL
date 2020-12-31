#define EXPAND( x ) x

#define GET_MACRO(_0,_1,_2,_3,_4,_5,_6, _7, _8,NAME,...) NAME 
#define FE_1(WHAT, a) EXPAND(WHAT EXPAND(a))
#define FE_2(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_1(WHAT, __VA_ARGS__))
#define FE_3(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_2(WHAT, __VA_ARGS__))
#define FE_4(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_3(WHAT, __VA_ARGS__))
#define FE_5(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_4(WHAT, __VA_ARGS__))
#define FE_6(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_5(WHAT, __VA_ARGS__))
#define FE_7(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_6(WHAT, __VA_ARGS__))
#define FE_8(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_7(WHAT, __VA_ARGS__))
#define FE_9(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_8(WHAT, __VA_ARGS__))
#define FE_10(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_9(WHAT, __VA_ARGS__))
#define FE_11(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_10(WHAT, __VA_ARGS__))
#define FE_12(WHAT, a, ...) EXPAND(WHAT EXPAND(a)) EXPAND(FE_11(WHAT, __VA_ARGS__))


#define VISIT_CASE(ENUM, FUNCTION) case ENUM: FUNCTION(&variant->EXPAND(VISITOR_DATA_PREFIX) ## ENUM); break;

#define ERR(args) 1

#define VISIT_(args) args
#define VISIT(...)  EXPAND(EXPAND(GET_MACRO(_0, __VA_ARGS__,FE_8,FE_7,FE_6,FE_5,FE_4,FE_3,FE_2,FE_1,ERR))(VISIT_CASE, __VA_ARGS__))


/**
Generates a visitor function for a C STL Variant
@param name The name of the visitor
@param variant_t The type of the variant
@param ... A list of overload pairs the visitor may use. The pairs written as (ENUM_VALUE, FUNCTION).
*/
#define make_visitor(name, variant_t, ...) \
void name(variant_t* variant)\
{\
	switch (variant->current_type)\
	{\
	VISIT(__VA_ARGS__)\
	default:\
		break;\
	}\
}

#define EXPAND( x ) x

#define SET_ENUM(a, b) a,

#define VISITOR_DATA_PREFIX From_
#define VISITOR_TAG_SUFIX current_type

#define SET_UNION(A, B) B EXPAND(VISITOR_DATA_PREFIX) ##A;


/**
*Generates a C STL Variant
*/
#define make_variant(name, ...)enum name ##_type { \
EXPAND(EXPAND(GET_MACRO(_0, __VA_ARGS__, FE_8, FE_7, FE_6, FE_5, FE_4, FE_3, FE_2, FE_1, ERR))(SET_ENUM, __VA_ARGS__))\
}; \
typedef struct\
{\
union\
{\
EXPAND(EXPAND(GET_MACRO(_0, __VA_ARGS__, FE_8, FE_7, FE_6, FE_5, FE_4, FE_3, FE_2, FE_1, ERR))(SET_UNION, __VA_ARGS__))  \
};\
enum name ## _type current_type;\
} name;
