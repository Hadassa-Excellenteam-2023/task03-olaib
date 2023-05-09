#include "MyException.h"
#include "constants.h"

char const* EmptyQueue::what() const
{
	return EMPTY_QUEUE_MSG;
}
