#ifndef YKL_STACK_CC_
#define YKL_STACK_CC_

#define DEFAULT_STACK_ALLOC_SIZE 20  //Default size to initialize the underlying array
#define STACK_INCREMENT 5 

#include <stdexcept>  // for std::out_of_bounds exception
#include "stack.h"

namespace ds = yikliu::data_structure;

//
// Stack
//
template <typename T>
ds::Stack<T>::Stack (void)
	:array_(0),
	top_(-1)
{
	this->array_ = new Array<T>(DEFAULT_STACK_ALLOC_SIZE);
}

//
// Stack
//
template <typename T>
ds::Stack<T>::Stack (const ds::Stack<T> & stack)
	:array_(0),
	top_(-1)
{
	this->array_ = new Array<T>(*stack.array_);
	this->top_ = stack.top_;
}

//
// ~Stack
//
template <typename T>
ds::Stack<T>::~Stack (void)
{	
	if (NULL != array_)
	{
		delete array_;
        array_ = NULL;
	}
}

//
// push
//
template <typename T>
void ds::Stack<T>::push (T element)
{
	//if the stack is full, resize the underlying array to a larger size.
	if (this->top_ >= ((int)(array_->max_size() - 1)))
	{
		size_t new_size = array_->max_size() + STACK_INCREMENT;
		this->array_->resize(new_size);
	}	
	this->top_++;	
	try
	{
		this->array_->set(top_, element);
	}	
	catch (std::out_of_range  e)
	{
	}	
}

//
// pop
//
template <typename T>
void ds::Stack<T>::pop (void)
{
	if (this->is_empty())
	{
		throw new exception::my_exception("Stack is empty");
	}	
	this->top_--;	
}

//
// operator =
//
template <typename T>
const ds::Stack<T> & ds::Stack<T>::operator = (const Stack<T> & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	
	*this->array_ = *rhs.array_;
	this->top_ = rhs.top_;
	return *this;
}

//
// clear
//
template <typename T>
void ds::Stack<T>::clear (void)
{
	this->top_ = -1;
}

#endif
