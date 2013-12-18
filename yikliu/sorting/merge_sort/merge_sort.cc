//
//  merge_sort.cpp
//  CodeDrill
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//
#ifndef YKL_Merge_Sort_CC_
#define YKL_Merge_Sort_CC_

#include "merge_sort.h"

template<typename T>
MergeSort<T>::MergeSort(void){}

template<typename T>
MergeSort<T>::~MergeSort(void){}

template<typename T>
void MergeSort<T>::Sort(T * data, size_t size)
{
    T temp[size];
    this->MSort(data, temp, 0, size - 1);
}

template<typename T>
void MergeSort<T>::MSort(T * data, T * temp, size_t begin, size_t end)
{
    if((end - begin) < 1)
    {
        return;
    }
    
    size_t mid = (end + begin) / 2; //NOT (end-begin)/2 !!!
    
    this->MSort(data, temp, begin, mid);
    this->MSort(data, temp, mid + 1, end);
    this->Merge(data, temp, begin, end, mid);
}

template<typename T>
void MergeSort<T>::Merge(T * data, T * temp, size_t begin, size_t end, size_t mid)
{
    size_t i = begin;
    size_t j = mid + 1;
    size_t k = begin;
    size_t h = begin;
    
    //copy the lower half to temp
    while(h <= mid)
    {
        temp[h] = data[h];
        h++;
    }
    
    //look at higher and lower half one by one, put the smaller one in the right pos
    while(i <= mid && j <= end)
    {
        data[k++] = temp[i] < data[j] ? temp[i++] : data[j++];
    }
    
    //copy the remaining (must be on lower half, lower half is always longer)
    while(i <= mid)
    {
        data[k++] = temp[i++];
    }
}

template<typename T>
void MergeSort<T>::Debug(T * data, size_t size)
{
    T * iter = data;
    std::cout<<"[";
    for(size_t i = 0; i < size; i++)
    {
        std::cout<<*iter++<<",";
    }
    std::cout<<"]"<<std::endl;
}

#endif