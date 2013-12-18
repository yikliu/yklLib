#ifndef YKL_FIXED_ARRAY_CC_
#define YKL_FIXED_ARRAY_CC_

#include <stdexcept>         // for std::out_of_bounds exception
#include "fixed_array.h"

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	:Array<T>(N)
{	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	:Array<T>(arr)
{	
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
	:Array<T>(N)
{
	size_t smaller_size = M >= N ? N : M;
	try  
	{
		for (size_t i = 0; i < smaller_size; i++) 
		{
			Array<T>::set(i, arr.get(i));
		}
	}
	catch (std::out_of_range e)
	{		
	}	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	:Array<T>(N,fill)
{	
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{	
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (this != &rhs)
	{
		Array<T>::operator=(rhs);		
	}
	return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	// If N > M, then the values between [0, M-1] get to be assigned, 
	// the portion between [M, N-1] remain the same as before assignment; 
	// If M > N, then the portion between [N, M-1] in rhs is truncated.
	size_t smaller_size = M >= N ? N : M;
	try 
	{
		for (size_t i = 0; i < smaller_size; i++) 
		{
			Array<T>::set(i, rhs.get(i));					
		}
	}
	catch (std::out_of_range e)
	{		
	}	
	return *this;	
}
#endif