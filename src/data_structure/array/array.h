//==============================================================================
/**
 * @file       rray.h
 *
 * $class: Array, an Array implementation
 */
//==============================================================================

#ifndef YKL_ARRAY_H_
#define YKL_ARRAY_H_

#include <cstring>          // for size_t definition
/**
 * @class Array
 *
 * Basic implementation of a standard array class.
 * All indice range from [0, size - 1]
 */
namespace yikliu{
    namespace data_structure{
        template <typename T>
        class Array
        {
        public:
            /// Type definition of the element type.
            typedef T type;
            
            /// Default constructor.
            Array (void);
            
            /**
             * Initializing constructor.
             *
             * @param[in]      length        Initial size
             */
            Array (size_t length);
            
            /**
             * Initializing constructor.
             *
             * @param[in]      length        Initial size
             * @param[in]      fill          Initial value for each element
             */
            Array (size_t length, T fill);
            
            /**
             * Copy constructor
             *
             * @param[in]     arr         The source Array.
             */
            Array (const Array & arr);
            
            
            /**
             * Init with native Array
             *
             * @param[in]    arr   The source array.
             * @param[in]   size   The size of source array.
             */
            Array (const T* arr, size_t size);
            
            
            /// Destructor.
            ~Array (void);
            
            /**
             * Assignment operation
             *
             * @param[in]       rhs      Right-hand side of equal sign
             * @return          Reference to self
             */
            const Array & operator = (const Array & rhs);
            
            /**
             * Retrieve the current size of the Array.
             *
             * @return          The current size
             */
            size_t size (void) const;
            
            /**
             * Retrieve the maximum size of the Array.
             *
             * @return          The maximum size
             */
            size_t max_size (void) const;
            
            /**
             * Get the character at the specified index. If the index is not
             * within the range of the Array, then std::out_of_range exception
             * is thrown.
             *
             * @param[in]       index               Zero-based location
             * @exception       std::out_of_range   Invalid \a index value
             */
            T & operator [] (size_t index);
            
            T & at (size_t index);
            
            /**
             * @overload
             *
             * The returned character is not modifiable.
             */
            const T & operator [] (size_t index) const;
            
            /**
             * Get the character at the specified index. If the \a index is not within
             * the range of the Array, then std::out_of_range exception is thrown.
             *
             * @param[in]       index                 Zero-based location
             * @return          Character at \index
             * @exception       std::out_of_range     Invalid index value
             */
            T get (size_t index) const;
            
            /**
             * Set the character at the specified \a index. If the \a index is not
             * within range of the Array, then std::out_of_range exception is
             * thrown.
             *
             * @param[in]       index                 Zero-based location
             * @param[in]       value                 New value for character
             * @exception       std::out_of_range     Invalid \a index value
             */
            void set (size_t index, T value);
            
            /**
             * Set a new size for the Array. If \a new_size is less than the current
             * size, then the Array is truncated. If \a new_size if greater then the
             * current size, then the Array is made larger and the new elements are
             * not initialized to anything. If \a new_size is the same as the current
             * size, then nothing happens.
             *
             * The Array's original contents are preserved regardless of whether the
             * Array's size is either increased or decreased.
             *
             * @param[in]       new_size              New size of the Array
             */
            void resize (size_t new_size);
            
            /**
             * Locate the specified character in the Array. The index of the first
             * occurrence of the character is returned. If the character is not
             * found in the Array, then -1 is returned.
             *
             * @param[in]        ch        Character to search for
             * @return           Index value of the character
             * @retval           -1        Character not found
             */
            int find (T element) const;
            
            /**
             * @overload
             *
             * This version allows you to specify the start index of the search. If
             * the start index is not within the range of the Array, then the
             * std::out_of_range exception is thrown.
             *
             * @param[in]       ch                   Character to search for
             * @param[in]       start                Index to begin search
             * @return          Index value of first occurrence
             * @retval          -1                   Character not found
             * @exception       std::out_of_range    Invalid index
             */
            int find (T element, size_t start) const;
            
            /**
             * Test the Array for equality.
             *
             * @param[in]       rhs                  Right hand side of equal to sign
             * @retval          true                 Left side is equal to right side
             * @retval          false                Left side is not equal to right side
             */
            bool operator == (const Array & rhs) const;
            
            /**
             * Test the Array for inequality.
             *
             * @param[in]       rhs                  Right-hand size of not equal to sign
             * @retval          true                 Left side is not equal to right side
             * @retval          false                Left size is equal to right side
             */
            bool operator != (const Array & rhs) const;
            
            /**
             * Fill the contents of the Array.
             *
             * @param[in]       ch                   Fill character
             */
            void fill (T element);
            
            
            /**
             * Print the elements in the Array
             *
             */
            void print ( void );
            
            /**
             * Produce an native Array of T
             */
            T * generateNativeArray(void);
            
            /**
             * Exchange value between index i and j;
             *
             */
            void exchange(size_t i, size_t j);
            
            //private:
        protected:
            /// Pointer to the actual data.
            T * data_;
            
            /// Current size of the Array.
            size_t cur_size_;
            
            /// Maximum size of the Array.
            size_t max_size_;
        };
    }
}

#include "array.inl"
#include "array.cc"

#endif   // !defined _Array_H_
