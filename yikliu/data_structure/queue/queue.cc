#ifndef YKL_QUEUE_CC_
#define YKL_QUEUE_CC_

#define DEFAULT_QUEUE_ALLOC_SIZE 20 //Default size to initialize the underlying array
#define QUEUE_INCREMENT 5

#include <stdexcept>  // for std::out_of_bounds exception
#include "queue.h"

//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
	:array_(0),
	head_(-1),
	tail_(-1)
{
	this->array_ = new Array<T>(DEFAULT_QUEUE_ALLOC_SIZE);
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue)
    :array_(0),
    head_(-1),
    tail_(-1)
{
    this->array_ = new Array<T>(*queue.array_);
    this->head_ = queue.head_;
    this->tail_ = queue.tail_;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
	if (array_ != 0)
	{
		delete array_;
	}
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	// Increment the allocation space if the the space is used up
	if (this->tail_ >= (int)array_->max_size())
	{
		size_t new_size = array_->max_size() + QUEUE_INCREMENT;
		array_->resize(new_size);
	}
	//If it's initial state, set head and tail to correct value for enqueue
	if (this->head_ == -1 && this->tail_ == -1)
	{
		this->head_ = 0;
		this->tail_ = 0;
	}
	try
	{
		this->array_->set(this->tail_++, element);
	}
	catch (std::out_of_range e)
	{
	}
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
	if (this->is_empty())
	{
		throw new my_exception("Queue is empty");
	}
	try
	{
		T element = array_->get(this->head_++);
		//if head meets tail, clear to initial state to reuse memory
		if (this->head_ == this->tail_)
		{
			this->clear();
		}
		return element;
	}
	catch (std::out_of_range e)
	{
	}
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	*this->array_ = *rhs.array_;
	this->head_ = rhs.head_;
	this->tail_ = rhs.tail_;
	return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	this->head_ = -1;
	this->tail_ = -1;
}

#endif
