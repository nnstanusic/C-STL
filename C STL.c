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

void print_float(float* data)
{
	printf("My simple float %f\n", *data);
}

make_variant(Variant,
(Data_t, Data),
(float_t, float));


make_visitor(visitor, Variant, visitor_return_t(void),
(Data_t, print),
(float_t, print_float));

bool equal_float(float* f) 
{
	return *f == 100.0f;
}

bool equal_data(Data* data) 
{
	return data->a == 1;
}

make_visitor(condition_visitor, Variant, visitor_return_t(bool),
(float_t, equal_float),
(Data_t, equal_data))

inline static fill_variants_(Variant* variant) 
{
	Data* data = &variant->From_Data_t;
	data->a = 1;
	data->f = 2.3f;
	data->text = "Hello World";

	variant->current_type = Data_t;
}

make_for_each(fill_variants, Variant, fill_variants_);
make_for_each(print_variant, Variant, visitor);

make_all_of(check_all_of, Variant, condition_visitor);

int main()
{
	Variant variant[5];
	
	fill_variants(variant, variant + 5);
	bool test = check_all_of(variant, variant + 5);
	variant[3].From_float_t = 5.7f;
	variant[3].current_type = float_t;
	bool test2 = check_all_of(variant, variant + 5);
	print_variant(variant, variant + 5);

	return 0;
}

