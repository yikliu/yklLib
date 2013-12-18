#ifndef YKL_FixedArray_H_
#define YKL_FixedArray_H_

#include "../array/array.h"

/**
 * @class FixedArray
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T, size_t N>
class FixedArray : public Array <T>
{
public:
  /// Default constructor.
  FixedArray (void);

	/**
	 * Copy constructor.
	 *
	 * @param[in]      arr        Source array
	 */
  FixedArray (const FixedArray <T, N> & arr);
	
  /**
   * Initializing constructor. The source array can be of any size
   * as long as they are of the same type.
   *
   * @param[in]      arr        Source array
   */
  template <size_t M>
  FixedArray (const FixedArray <T, M> & arr);

  /**
   * Initializing constructor. Fills the contents of the 
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  FixedArray (T fill);

  /// Destructor.
  ~FixedArray (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  const FixedArray & operator = (const FixedArray <T, N> & rhs);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  template <size_t M>
  const FixedArray & operator = (const FixedArray <T, M> & rhs);		
};

// include the inline files
#include "fixed_array.inl"

// include the source file since template class
#include "fixed_array.cc"

#endif
