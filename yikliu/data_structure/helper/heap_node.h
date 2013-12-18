//
//  node.h
//  Huffman
//
//  Created by Liu, Arthur on 3/11/13.
//  Copyright (c) 2013 liuarthur. All rights reserved.
//

#ifndef YKL_HEAP_HELPER_HEAP_NODE_H_
#define YKL_HEAP_HELPER_HEAP_NODE_H_

#include <string>

struct HeapNode
{
    // The largest value an unsigned long can be;
    const static unsigned long NEGATIVE_INFINITY = 4294967294;
    
    //The smallest vaue an long can be
	const static long POSTIVE_INFINITY = -2147483648;
    
    unsigned long key;
    
    HeapNode()
    :key(0)
    {
       
    }
    
    HeapNode(unsigned long k)
    :key(k)
    {
    }
    
    //Overriden assign operator for key assignment
    HeapNode& operator=(const unsigned long k){
        this->key = k;
        return *this;
    }
    
    //Comparsions are all reversed, since Heap class is implemented following Max Heap logic
    bool operator<(const HeapNode & rhs) const{
        return this->key > rhs.key;
    }
    
    bool operator<=(const HeapNode & rhs) const{
        return this->key >= rhs.key;
    }
    
    bool operator>(const HeapNode & rhs) const{
        return !this->operator<(rhs);
    }
    
    bool operator>=(const HeapNode & rhs) const{
        return !this->operator<=(rhs);
    }
    
    //if keys are equal, nodes are equal
    bool operator==(const HeapNode & rhs) const{
        return this->key == rhs.key;
    }    
    
    bool operator<(unsigned long key) const{
        return this->key > key;
    }
    
    bool operator<=(unsigned long key) const{
        return this->key >= key;
    }
    
    bool operator>(unsigned long key) const{
        return !this->operator<(key);
    }
    
    bool operator>=(unsigned long key) const{
        return !this->operator<=(key);
    }
    
    bool operator==(unsigned long key) const{
        return this->key == key;
    }
    
    friend std::ostream& operator<< (std::ostream& stream, const HeapNode & nd) {
        return stream << nd.key;
    }

};


#endif
