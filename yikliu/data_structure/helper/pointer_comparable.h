//
//  Compare elements by dereferencing the pointers and compare the objects
//
//  Created by Liu, Arthur on 3/15/13.
//  Copyright (c) 2013 liuarthur. All rights reserved.
//

#ifndef YKL_HEAP_HELPER_POINTER_COMPARABLE_H_
#define YKL_HEAP_HELPER_POINTER_COMPARABLE_H_

#include "Comparable.h"

template<typename T>
class ComparableByDeRefPointer : public Comparable<T>
{
public:
    ComparableByDeRefPointer(void){}
    virtual ~ComparableByDeRefPointer(void){}
    
    // T vs. T
    virtual bool greater(T& left, T& right){ return (*left) > (*right); }
    virtual bool less (T& left, T& right){ return !this->greater(left, right); }
    virtual bool greater_or_equal(T& left, T& right){ return (*left) >= (*right); }
    virtual bool less_or_equal(T& left, T& right){ return !this->greater_or_equal(left, right); }
    virtual bool equal (T& left, T& right) { return (*left) == (*right);}
    virtual bool inequal(T& left, T& right) { return !this->equal(left, right); }
    
    // T vs. unsigned long key
    virtual bool greater(T& left, unsigned long key) {return (*left) > key; }
    virtual bool less(T& left, unsigned long key) { return !this->greater(left, key); }
    virtual bool greater_or_equal(T& left, unsigned long key) { return (*left) >= key; }
    virtual bool less_or_equal(T& left, unsigned long key) { return !this->greater_or_equal(left, key); }
    virtual bool equal (T& left, unsigned long key) { return (*left) == key; }
    virtual bool inequal(T& left, unsigned long key) {return !this->equal(left, key); }
};

#endif
