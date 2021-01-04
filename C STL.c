// C STL.c : Defines the entry point for the application.
//


#include "C STL.h"
#include <stdio.h>

inline static void print(MessageEvent const* data)
{
	printf("Message '%s' send with priority: %d. Money gained: %f\n", data->text, data->priority, data->money);
}

inline static void print_float(float* data)
{
	printf("A simple cash transaction %f\n", *data);
}


make_visitor(PrintEvent, Event_v, visitor_return_t(void),
	(messageEvent_t, print),
	(cash_t, print_float));


static inline float ShowMoney(MessageEvent const* data) { return data->money; }

static inline float deref_f(float const* f) { return *f; }

make_visitor(CashValue, Event_v, float,
	(messageEvent_t, ShowMoney),
	(cash_t, deref_f));
