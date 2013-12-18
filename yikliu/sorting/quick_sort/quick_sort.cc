//
//  QuickSort.cc
//  QuickSort
//
//  Created by Yikun Liu on 11/13/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//
#ifndef YKL_QUICKSORT_CC_
#define YKL_QUICKSORT_CC_

#include "quick_sort.h"

template<typename T>
QuickSort<T>::QuickSort(void){
}

template<typename T>
QuickSort<T>::~QuickSort(){
}

template<typename T>
void QuickSort<T>::Sort(T* data, size_t left, size_t right)
{
    if(left < right){
        size_t pivot = this->RandomPartition(data, left, right);
        this->Sort(data, left, pivot - 1);
        this->Sort(data, pivot + 1, right);
    }
}

template<typename T>
size_t QuickSort<T>::Partition(T * data, size_t left, size_t right){
    size_t i = left - 1;
    for (size_t j = left; j < right; j++){
        if(data[j] <= data[right]){
            i++;
            this->ExchangeByValue(data, i,j);
        }
    }
    this->ExchangeByValue(data, i+1, right);
    return i+1;
}

template<typename T>
size_t QuickSort<T>::RandomPartition(T * data, size_t left, size_t right){
    srand((unsigned)time(0));
    size_t rand_pos = left + rand() % (right - left + 1);
    this->ExchangeByValue(data, rand_pos,right);
    return Partition(data, left, right);
}

template<typename T>
void QuickSort<T>::ExchangeByValue(T* data, size_t pos1, size_t pos2){
    T temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
}

#endif