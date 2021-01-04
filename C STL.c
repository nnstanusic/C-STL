// C STL.c : Defines the entry point for the application.
//

#include <stdlib.h>
#include <stdio.h>
#include "c_algorithms.h"
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "functional.h"

typedef struct
{
	int a;
	float f;
	char* text;
} Data;


inline static void print(Data const* data)
{
	printf("My complicated struct: %d, %f, %s\n", data->a, data->f, data->text);
}

inline static void print_float(float* data)
{
	printf("My simple float %f\n", *data);
}

make_variant(Variant,
(Data_t, Data),
(float_t, float));


make_visitor(visitor, Variant, visitor_return_t(void),
(Data_t, print),
(float_t, print_float));

inline static void Square_data(Data* data)
{
	data->a *= data->a;
	data->f *= data->f;
}

inline static void Square_float(float* data)
{
	*data *= *data;
}

make_visitor(square_visitor, Variant, void,
(Data_t, Square_data),
(float_t, Square_float)
)

inline static fill_variants_(Variant* variant) 
{	
	static int increment = 0;
	Data* data = &variant->From_Data_t;
	data->a = increment;
	data->f = 2.3f * increment++;
	data->text = "Hello World";

	variant->current_type = Data_t;
}

make_for_each(fill_variants, Variant, fill_variants_);
make_for_each(print_variants, Variant, visitor);
make_for_each(square_variants, Variant, square_visitor);

static inline float extract_datafloat(Data const* data) { return data->f; }

static inline float identity(float const* f) { return *f; }

make_visitor(extract_float, Variant, float,
	(Data_t, extract_datafloat),
	(float_t, identity));

static inline void addition_visitor(float* f, Variant* var)
{
	*f += extract_float(var);
}

make_accumulate(sum, Variant, float, addition_visitor);

void newLine(Variant* a, Variant* b)
{
	putc('\n', stdout);
}

algorithm_chain(complexAlgo, Variant, float,
	(fill_variants),
	(print_variants),
	(newLine),
	(square_variants, begin, begin + 3),
	(print_variants),
	(return sum, begin, end, 0.0f)
	)


int main()
{
	Variant variant[5];

	float sum = complexAlgo(variant, variant + 5);
	
	printf("Sum of floats %f\n", sum);
	return 0;
}

