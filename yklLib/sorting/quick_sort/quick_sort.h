//
//  QuickSort.h
//  QuickSort
//
//  Created by Yikun Liu on 11/13/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_QUICKSORT_H_
#define YKL_QUICKSORT_H_

#include <iostream>
#include "../../order_stat/order_stat.h"

template<class U>
class OrderStatistics;

template <typename T>
class QuickSort{
public:
    QuickSort(void);
    virtual ~QuickSort();
    void Sort(T* data, size_t left, size_t right);
    
    template <typename U>
    friend class OrderStatistics;
    
private:
    size_t Partition(T* data, size_t left, size_t right);
    size_t RandomPartition(T* data, size_t left, size_t right);
    

    void ExchangeByValue(T* data, size_t pos1, size_t pos2);
};

#include "quick_sort.cc"

#endif 
