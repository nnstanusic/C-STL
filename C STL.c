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


inline static void print2(Data const* data)
{
	printf("My complicated struct: %d, %f, %s\n", data->a, data->f, data->text);
}

inline static void fill(Data* const data)
{
	static int a = 0;
	data->a = a++;
	data->f = 2.3f;
	data->text = "Hello World";
}

inline static int findHelloWorld2(Data const* data)
{
	return data->a == 1;
}

inline static void Addition(int* accum, int const* next)
{
	*accum += *next;
}

make_for_each(print_data, Data, print2);
make_for_each(fill_data, Data, fill);
make_find_if(find_second_world, Data, findHelloWorld2);
make_accumulate(sum, int, int, Addition);
make_iota(enumeration, int);

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
(float_t, float),
(int_t, int),
(char_t, char));


make_visitor(visitor, Variant,
(Data_t, print),
(float_t, print_float));

inline static fill_variant_(Variant* variant) 
{
	static int a = 0;
	Data* data = &variant->From_Data_t;
	data->a = a++;
	data->f = 2.3f;
	data->text = "Hello World";

	variant->current_type = Data_t;
}

make_for_each(fill_variants, Variant, fill_variant_);
make_for_each(print_variant, Variant, visitor);

int main()
{
	Variant variant[5];
	
	fill_variants(variant, variant + 5);
	variant[3].From_float_t = 5.7f;
	variant[3].current_type = float_t;

	print_variant(variant, variant + 5);

	return 0;
}

