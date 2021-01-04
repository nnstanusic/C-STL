#include <functional.h>

typedef float cash;

typedef struct
{
	int priority;
	cash money;
	char* text;
} MessageEvent;


make_variant(Event_v,
	(messageEvent_t, MessageEvent),
	(cash_t, cash));

void PrintEvent(Event_v* event);

cash CashValue(Event_v* event);