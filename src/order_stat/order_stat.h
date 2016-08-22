//
//  OrderStat.h
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_Order_Stat_H_
#define YKL_Order_Stat_H_
#include "../sorting/quick_sort/quick_sort.h"

namespace yikliu {
    
    //forward declaration
    namespace sorting{
        template<typename T>
        class QuickSort;
    }
    
    namespace order_stat{
        
        template<typename T>
        class OrderStatistics {
        public:
            OrderStatistics(void);
            virtual ~OrderStatistics(void);
            
            //Get he ith element from array
            T& RandomSelect(T* data, int left, int right, int target);
            
        private:
            sorting::QuickSort<T> * q_sorter;
        };
    }
}

#include "order_stat.cc"

#endif /* defined(YKL_Order_Stat_H_) */
