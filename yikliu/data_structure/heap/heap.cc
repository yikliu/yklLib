//
//  Heap.cpp
//  HeapSort
//
//  Created by yikliu on 2/7/13.
//  Copyright (c) 2013 yikliu. All rights reserved.
//
#ifndef YKL_HEAP_CC_
#define YKL_HEAP_CC_

#include "heap.h"

Heap::Heap (void)
: _array(0),
_heap_size(0)
{
    _array = new Array<HeapNode>();
}

Heap::Heap(Array<HeapNode> & array)
:_array(0),
_heap_size(0)
{
    _array = new Array<HeapNode>(array);
}

void Heap::set_array(Array<HeapNode> & array)
{
    if(_array)
        delete _array;
    _array = new Array<HeapNode>(array);
}

Heap::~Heap (void)
{
    _heap_size = 0;
    if(_array)
    {
        delete _array;
    }
}

void Heap::heapify(size_t i)
{
    if(i >= _heap_size)
        return;
    
    size_t left = this->left(i);
    size_t right = this->right(i);
    size_t largest;
    
    if(left <= _heap_size - 1 &&  _array->at(left)> _array->at(i))
    {
         largest = left;
    }
    else
    {
         largest = i;
    }
        
    if(right <= _heap_size - 1 && _array->at(right) > _array->at(largest))
    {
        largest  = right;
    }
    
    if (largest != i){
        this->exchange(largest,i);
        this->heapify(largest);
    }
}

void Heap::build_heap(void)
{
    _heap_size = _array->size();
    for(int i = (int)(_array->size() / 2 - 1); i >= 0; i--)
    {
        this->heapify(i);
    }
}

void Heap::heap_sort(void)
{
    this->build_heap();
    size_t n = _array->size();
    for (size_t i = n - 1; i > 0; i--){
        this->exchange(0,i);
        _heap_size--;
        this->heapify(0);
    }
    
}

HeapNode& Heap::pop(void)
{
    if(_heap_size < 1)
        throw new myException("Heap Underflow");
    this->exchange(0,_heap_size - 1);
    HeapNode & nd = (*_array)[_heap_size - 1];
    _heap_size--;
    this->heapify(0);
    return nd;
}

void Heap::insert(HeapNode nd, unsigned long key)
{
    _heap_size++;
    if(_array->size() < _heap_size){
        _array->resize(_heap_size);
    }
    
    nd = HeapNode::NEGATIVE_INFINITY;
    
    (*_array)[_heap_size - 1] = nd;
    this->increase_key(_heap_size - 1, key);
}

void Heap::increase_key(size_t i, unsigned long k)
{    
    if(_array->at(i) > k)
        throw new myException("current key is greater than new key");
    
    _array->at(i) = k;
    
    while (i > 0 && _array->at(this->parent(i)) < _array->at(i))
    {
        this->exchange(i, this->parent(i));
        i = parent(i);
    }
}

//move down the left path
void Heap::decrease_key(size_t i, unsigned long k)
{
    if(_array->at(i) < k)
        throw new myException("new Key is > current key");
    (*_array)[i].key = k; 
    while (i > 0 && _array->at(this->left(i)) > _array->at(i))
    {
        this->exchange(i, this->left(i));
        i = left(i);
    }
}

void Heap::exchange(size_t i, size_t j)
{
    if(i >= _array->size() || j >= _array->size())
    {
        throw std::out_of_range("Out of range!");
    }
    
    if(i == j) return;
     
    std::swap((*_array)[i], (*_array)[j]);
}

HeapNode * Heap::get_native_array(void)
{
    return _array->generateNativeArray();
}


#endif