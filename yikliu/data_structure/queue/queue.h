#ifndef YKL_QUEUE_H_
#define YKL_QUEUE_H_

#include "../array/array.h"
#include "../../exception/my_exception.h"
/**
 * @class Queue
 *
 * Basic queue for arbitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;
  
  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & q);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Put an element into the tail of the queue
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Get the element in the head of the queue. If the queue is empty, throw an empty exception
   *
   * @return         The element from the head.
   * @exception      empty_exception    The queue is empty.
   */
  T dequeue (void);
   

  /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the queue.
   *
   * @return         Size of the queue.
   */
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void); 
    
private:
  // add member variable here
  /// the underlying array for representing the queue
  Array<T> * array_;

  /// index to indicate head of the queue
  int head_;

  ///index to indicate the tail of the queue
  int tail_;
  
};

// include the inline files
#include "queue.inl"

// include the source file since template class
#include "queue.cc"

#endif  // !defined _CS507_QUEUE_H_
