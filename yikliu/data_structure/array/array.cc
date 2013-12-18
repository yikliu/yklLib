#ifndef YKL_ARRAY_CC_
#define YKL_ARRAY_CC_

#define DEFAULT_MAXSIZE 20

#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>
#include "array.h"

//
// Array
//
template <typename T>
Array <T>::Array (void)
:data_(0),
cur_size_(0),
max_size_(DEFAULT_MAXSIZE)
{
	data_ = new T[max_size_];
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:data_(0),
cur_size_(0),
max_size_(0)
{
	this->data_ = new T[length];
	this->cur_size_ = this->max_size_ = length;
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:data_(0),
cur_size_(0),
max_size_(0)
{
	this->data_ = new T[length];
	this->cur_size_ = this->max_size_ = length;
	this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & Array)
:data_(0),
cur_size_(0),
max_size_(0)
{
    this->cur_size_ = Array.cur_size_;
    this->max_size_ = Array.max_size_;
    this->data_ = new T[max_size_];
    T * iter = this->data_;
    T * src = Array.data_;
    for (size_t i = 0; i < this->max_size_; i++)
    {
        *iter++ = *src++;
    }
}

//
// Array (T[] Array)
//
template <typename T>
Array <T>::Array (const T * arr, size_t size)
:data_(0),
cur_size_(0),
max_size_(0)
{
    this->cur_size_ = size;
    this->max_size_ = this->cur_size_;
    this->data_ = new T[max_size_];
    T * iter = this->data_;
    const T * src = arr;
    for (size_t i = 0; i < this->max_size_; i++)
    {
        *iter++ = *src++;
    }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	delete[] data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (this->max_size_ < rhs.cur_size_)
	{
		this->resize(rhs.cur_size_);
	}
	this->cur_size_ = rhs.cur_size_;
	T * iter = this->data_;
	T * src = rhs.data_;
	for (size_t i = 0; i < rhs.cur_size_; i++)
	{
		*iter++ = *src++;
	}
	return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if (index < this->cur_size_)
	{
		return this->data_[index];
	}
	throw std::out_of_range("Out of Bounds");
}

//
// at
//
template <typename T>
T & Array<T>::at(size_t index){
    return this->operator[](index);
}

//
// operator []
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if (index < this->cur_size_)
	{
		return this->data_[index];
	}
	throw std::out_of_range("Out of Bounds");
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if (index < this->cur_size_)
	{
		return this->data_[index];
	}
	throw std::out_of_range("Out of Bounds");
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if (index < this->cur_size_)
	{
		this->data_[index] = value;
		return;
	}
	throw std::out_of_range("Out of Bounds");
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if (new_size == this->cur_size_)  //new_size == cur_size
	{
		return;
	}
	else if (new_size < this->cur_size_)  // new_size is between [0, cur_size_)
	{
        
		// The portion between the new_size and cur_size_ need to be set to null, otherwise, when the size is
		// enlarged again from previously shrunk size,the previous value in this range will re-emerge and
		// then it will produce wrong values for find(), get() and [] functions.
		for (size_t i = new_size; i < this->cur_size_; i++)
		{
			this->data_[i] = NULL;
		}
		this->cur_size_ = new_size;
	}
	else if (new_size <= this->max_size_)  // new_size is between (cur_size_ max_size]
	{
		this->cur_size_ = new_size;
	}
	else  // new_size > max_size_, reallocate
	{
		this->max_size_ = new_size;
		T * temp = new T[this->max_size_];
		T * iter = temp;
		T * src = this->data_;
		for (size_t i = 0; i < this->cur_size_; i++)
		{
			*iter++ = *src++;
		}
		delete [] data_;
		this->data_ = temp;
		this->cur_size_ = new_size;
	}
	return;
}

//
// find (T)
//
template  <typename T>
int Array <T>::find (T value) const
{
	try
	{
		return this->find(value,0);
	}
	catch (std::exception e)
	{
	}
	return -1;
}

//
// find (T, size_t)
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if (start >= this->cur_size_)
	{
		throw std::out_of_range("Out of Bounds");
	}
	for (size_t i = start; i < this->cur_size_; i++)
	{
		if (val == this->data_[i])
		{
			return i;
		}
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if (this == &rhs)
	{
		return true;
	}
	return !(*this != rhs);
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	if (this->cur_size_ != rhs.cur_size_)
	{
		return true;
	}
	T * iter = this->data_;
	T * rhs_iter = rhs.data_;
	for (size_t i = 0; i < this->cur_size_; i++)
	{
		if (*iter++ != *rhs_iter++)
		{
			return true;
		}
	}
	return false;
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	T * iter = this->data_;
	for (size_t i = 0; i < this->cur_size_; i++)
	{
		*iter++ = value;
	}
}


//
// print
//
template <typename T>
void Array<T>::print()
{
    T * iter = this->data_;
    std::cout<<"[";
    for (size_t i = 0; i < this->cur_size_; i++)
    {
        std::cout<<*iter++<<" ";
    }
    std::cout<<"]"<<std::endl;
}

template <typename T>
T * Array<T>::generateNativeArray(void)
{
    size_t s = this->cur_size_;
    T * ret = new T[s];
    T * iter = this->data_;
    for (size_t i = 0; i < s; i++){
        *ret++ = *iter++;
    }
    return ret;
}

//
// Exchange
//
template <typename T>
void Array<T>::exchange(size_t i, size_t j)
{
    T temp = this->get(i);
    this->set(i,this->get(j));
    this->set(j,temp);
}

#endif
