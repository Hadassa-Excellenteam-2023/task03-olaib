#pragma once

#include <iostream>
#include <list>
#include "MyException.h"

//======================================================================
/***
 * This is a comparator struct for comaring between two objects of same type
*/
template<typename T>
struct MyComparator {
	// compare 2 objects of type T and return true if the first is bigger than the second
	T operator()(T a, T b) const {
		return a - b;
	}
};
//======================================================================
/***
 * This is a template priority queue class
 * The class is a max heap priority queue
 * The class is using a comparator struct to compare between two objects of type T
 * The class is using the stl list to hold the objects in the queue of type T
*/
template<typename  T>
class PriorityQueue {
public:
	// =========================== C-TOR ===============================
	PriorityQueue() = default;
	// ========================== METHODS ==============================
	void push(const T& t);
	T poll();
	decltype(auto) isEmpty()const { return m_queue.empty(); }

private:
	// ========================= MEMBERS ===============================
	std::list<T> m_queue;
	// comparator struct
	struct MyComparator<T> m_comparator;
};

template <typename T>
void PriorityQueue<T>::push(const T& t)
{
	if (isEmpty())
	{
		m_queue.emplace_front(t);
		return;
	}

	auto it = m_queue.cbegin();
	while (it != m_queue.cend() && m_comparator(*it, t) < 0)
		++it;
	// insert new object in the correct place
	m_queue.insert(it, t);
}

template <typename T>
T PriorityQueue<T>::poll()
{
	if (isEmpty())
		throw EmptyQueue();

	auto backObject = m_queue.front();
	m_queue.pop_front();
	return backObject;
}
