#include "C STL.h"
#include "c_algorithms.h"


inline static construct_event(Event* variant)
{
	static int increment = 0;
	if (increment++ % 2)
	{
		MessageEvent* event = &variant->From_message_v;
		event->priority = increment;
		event->money = 2.3f * increment;
		event->text = "Hello World";
		variant->current_type = message_v;
	}
	else
	{
		variant->From_cash_v = increment * 5.0f;
		variant->current_type = cash_v;
	}
}


static inline void addition_visitor(cash_t* f, Event* var)
{
	cash_t tmp = CashValue(var);
	*f += tmp * tmp;
}

make_for_each(generate_messages, Event, construct_event);
make_for_each(print_events, Event, PrintEvent);
make_accumulate(sum_of_squares, Event, cash_t, addition_visitor);


algorithm_chain(complexAlgo, Event, cash_t,
	(generate_messages),
	(print_events),
	(return sum_of_squares, begin, end - 2, 0.0f)
)


int main()
{
	Event variant[5];
	cash_t sum = complexAlgo(variant, variant + 5);

	printf("I made this much money %f\n", 0.5f);
	return 0;
}
