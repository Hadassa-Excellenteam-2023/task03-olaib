#pragma once
#include <exception>

/***
 *custom exception class for empty queue
 */
class EmptyQueue : public std::exception
{
public:
	EmptyQueue() = default;
	char const* what() const override;
};