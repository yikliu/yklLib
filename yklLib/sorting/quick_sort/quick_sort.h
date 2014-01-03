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

namespace yikliu {
    //forward declaration
    namespace order_stat{
        template<class U>
        class OrderStatistics;
    }
    
    namespace sorting{
        template <typename T>
        class QuickSort{
        public:
            QuickSort(void);
            virtual ~QuickSort();
            void Sort(T* data, int left, int right);
            
            //allow OrderStatistics class to use the partition method
            template <typename U>
            friend class order_stat::OrderStatistics;
            
        private:
            //partition around the rightest element
            int Partition(T* data, int left, int right);
            int RandomPartition(T* data, int left, int right);
            
            
            void ExchangeByValue(T* data, int pos1, int pos2);
        };
    }
}



#include "quick_sort.cc"

#endif 
