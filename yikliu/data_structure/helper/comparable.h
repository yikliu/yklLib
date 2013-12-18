//
//  comparable.h
//  Huffman
//
//  Created by Liu, Arthur on 3/15/13.
//  Copyright (c) 2013 liuarthur. All rights reserved.
//

#ifndef YKL_HEAP_HELPER_COMPARABLE_H_
#define YKL_HEAP_HELPER_COMPARABLE_H_

template<typename T>
class Comparable{
public:
    virtual ~Comparable(void){};
    
    //T vs. T
    virtual bool greater(T& left, T& right) { return left > right; }
    virtual bool less(T& left, T& right) { return left < right }
    virtual bool greater_or_equal(T& left, T& right) {return left >= right;}
    virtual bool less_or_equal(T& left, T& right) {return left <= right; }
    virtual bool equal (T& left, T& right) { return left == right; }
    virtual bool inequal(T& left, T& right) { return left != right; }
    
    // T vs. unsigned long key
    virtual bool greater(T& left, unsigned long key) = 0;
    virtual bool less(T& left, unsigned long key) = 0;
    virtual bool greater_or_equal(T& left, unsigned long key) = 0;
    virtual bool less_or_equal(T& left, unsigned long key) = 0;
    virtual bool equal (T& left, unsigned long key) = 0;
    virtual bool inequal(T& left, unsigned long key) = 0;
};

#endif
