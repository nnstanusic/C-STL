#include <functional.h>

typedef float cash_t;

typedef struct
{
	int priority;
	cash_t money;
	char* text;
} MessageEvent;

make_variant(Event,
	(message_v, MessageEvent),
	(cash_v, cash_t));

void PrintEvent(Event* event);

cash_t CashValue(Event* event);