#ifndef CONCURRENCYSTACK_HPP_
#define CONCURRENCYSTACK_HPP_

#include <deque>

#include "ConcurrencyStackDecl.hpp"

#include "MutexLock.h"
/*
template<typename ElementType, 
			template<typename ElemType, typename ALLOC = std::allocator<ElemType> > 
				class CONT = std::deque>
class ConcurrencyStack
{
public:

	void push(const ElementType&);

	void pop();

	size_t size();

	ElementType top();

private:

	CONT<ElementType> container;

};
*/

template<typename ElementType, template<typename, typename> class CONT>
void ConcurrencyStack<ElementType, CONT>::push(const ElementType& element)
{
	MutexLockGuard(lock);

	container.push_back(element);
}

template<typename ElementType, template<typename, typename> class CONT>
void ConcurrencyStack<ElementType, CONT>::pop()
{
	MutexLockGuard(lock);

	container.pop_back();
}

template<typename ElementType, template<typename, typename> class CONT>
size_t ConcurrencyStack<ElementType, CONT>::size()
{
	MutexLockGuard(lock);

	return container.size();
}

template<typename ElementType, template<typename, typename> class CONT>
bool ConcurrencyStack<ElementType, CONT>::empty()
{
	MutexLockGuard(lock);

	return container.empty();
}

template<typename ElementType, template<typename, typename> class CONT>
ElementType ConcurrencyStack<ElementType, CONT>::top()
{
	MutexLockGuard(lock);

	return container.top();
}

#endif