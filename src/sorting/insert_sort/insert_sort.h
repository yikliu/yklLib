//
//  InsertSort.h
//  yklLib
//
//  Created by Yikun Liu on 12/16/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_INSERTSORT_H_
#define YKL_INSERTSORT_H_
namespace yikliu{
    namespace sorting{
        template<typename T>
        class InsertSort{
        public:
            InsertSort(void);
            virtual ~InsertSort(void);
            
            void Sort(T* data, size_t size);
        };
    }
}


#include "insert_sort.cc"

#endif /* defined(__yklLib__InsertSort__) */
