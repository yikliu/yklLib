//
//  OrderStat.h
//  CodeDrill
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_Order_Stat_H_
#define YKL_Order_Stat_H_

#include "../sorting/quick_sort/quick_sort.h"
template<typename T>
class QuickSort;

template<typename T>
class OrderStatistics {
public:
    OrderStatistics(void);
    virtual ~OrderStatistics(void);
    
    //Get he ith element from array
    T& RandomSelect(T* data, size_t left, size_t right, size_t target);
    
private:
    QuickSort<T> * q_sorter;
};

#include "order_stat.cc"

#endif /* defined(YKL_Order_Stat_H_) */
