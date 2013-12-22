//
//  OrderStat.cpp
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//
#ifndef YKL_Order_Stat_CC_
#define YKL_Order_Stat_CC_

#include "order_stat.h"

namespace OS = yikliu::order_stat;
template<typename T>
OS::OrderStatistics<T>::OrderStatistics(void)
{
    q_sorter = new sorting::QuickSort<T>();
}

template<typename T>
OS::OrderStatistics<T>::~OrderStatistics(void)
{
    if(q_sorter)
    {
        delete q_sorter;
    }
}

template<typename T>
T& OS::OrderStatistics<T>::RandomSelect(T * data, int left, int right, int target)
{
   if(right == left)
       return data[left];
    
    int q = q_sorter->RandomPartition(data, left, right);
    
    int k = q - left + 1;
    
    if (target == k)
    {
        return data[q];
    }
    else if (target < k)
    {
        return this->RandomSelect(data, left, q - 1, target);
    }
    else
    {
        return this->RandomSelect(data, q + 1, right, target - k);
    }
}

#endif