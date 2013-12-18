//
//  merge_sort.h
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_Merge_Sort_H_
#define YKL_Merge_Sort_H_

template<typename T>
class MergeSort{
public:
    MergeSort(void);
    virtual ~MergeSort(void);
    
    void Sort(T * data, size_t size);
    
    void Debug(T * data, size_t size);

private:
    void MSort(T * data, T * temp, size_t begin, size_t end);
    void Merge(T * data, T * temp, size_t begin, size_t mid, size_t end);
};

#include "merge_sort.cc"

#endif /* defined(YKL_Merge_Sort_H_) */
