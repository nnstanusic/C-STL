#include "C STL.h"
#include "c_algorithms.h"


inline static fill_variants_(Event_v* variant)
{
	static int increment = 0;
	if (increment++ % 2)
	{
		MessageEvent* data = &variant->From_messageEvent_t;
		data->priority = increment;
		data->money = 2.3f * increment;
		data->text = "Hello World";
		variant->current_type = messageEvent_t;
	}
	else
	{
		variant->From_cash_t = increment * 5.0f;
		variant->current_type = cash_t;
	}
}

make_for_each(generate_messages, Event_v, fill_variants_);
make_for_each(print_events, Event_v, PrintEvent);

static inline void addition_visitor(cash* f, Event_v* var)
{
	cash tmp = CashValue(var);
	*f += tmp * tmp;
}

make_accumulate(sum_of_squares, Event_v, cash, addition_visitor);


algorithm_chain(complexAlgo, Event_v, cash,
	(generate_messages),
	(print_events),
	(return sum_of_squares, begin, end, 0.0f)
)



int main()
{
	Event_v variant[5];
	cash sum = complexAlgo(variant, variant + 5);

	printf("I made this much money %f\n", 0.5f);
	return 0;
}