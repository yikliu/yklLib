//
//  Heap.h
//  HeapSort
//
//  Created by Arthur Liu on 2/7/13.
//  Copyright (c) 2013 Arthur Liu. All rights reserved.
//

#ifndef YKL_HEAP_H_
#define YKL_HEAP_H_

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../array/array.h"
#include "../../exception/my_exception.h"
#include "heap_node.h"

namespace yikliu {
    namespace data_structure{
        /**
         * @class Heap
         *
         * Basic implementation of a Heap structure (Max Heap)
         */
        class Heap{
            
        public:
            
            //Default c'tor
            Heap(void);
            
            //c'tor with array
            Heap(Array<HeapNode> & array);
            
            // d'ctor
            virtual ~Heap(void);
            
            
            //maintain heap property. Using max_heapify logic, leaving node operator overloading in node to change the comparison direction.
            //interpret lhs > rhs as lhs should be precede rhs and lhs < rhs as lhs should be behind rhs.
            void heapify(size_t i);
            
            // Precedures to build a heap out of an array (based on max_heapify)
            void build_heap();
            
            // HeapSort based on heap, for debug only
            void heap_sort();
            
            //insert a new node to heap with key = key
            void insert(HeapNode nd, unsigned long key);
            
            //remove the element at root, re-heapify the rest elements
            HeapNode & pop(void);
            
            // copy the top element (element at root), does not remove it
            inline HeapNode top(void) { return _array->get(0); }
            
            //increase one element's key, doesn't neccessariy increase key value, instead, move the element up to root.
            void increase_key(size_t i, unsigned long k);
            
            //decrease key, move the element down
            void decrease_key(size_t i, unsigned long k);
            
            //Binary Tree traverse opeartions
            inline size_t parent(size_t i){ return (i + 1) / 2 - 1; }
            inline size_t left(size_t i) { return 2 * (i + 1) - 1; }
            inline size_t right(size_t i) { return 2 * (i + 1) ; }
            
            //heap size
            inline size_t size(void) {return _heap_size;}
            
            //util funcs
            void set_array(Array<HeapNode> & array);
            HeapNode * get_native_array(void);
            
        private:
            void exchange (size_t i, size_t j); //Exchange element at i and j
            
        private:
            Array<HeapNode> * _array;
            size_t _heap_size;
        };
    }

}

#include "heap.cc"
#endif
