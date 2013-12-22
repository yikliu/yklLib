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

namespace sorter = yikliu::sorting;

template<typename T>
sorter::QuickSort<T>::QuickSort(void){
}

template<typename T>
sorter::QuickSort<T>::~QuickSort(){
}

template<typename T>
void sorter::QuickSort<T>::Sort(T* data, int left, int right)
{
    if(left < right){
        int pivot = this->RandomPartition(data, left, right);
        this->Sort(data, left, pivot - 1);
        this->Sort(data, pivot + 1, right);
    }
}

template<typename T>
int sorter::QuickSort<T>::Partition(T * data, int left, int right){
    int i = left - 1;
    for (int j = left; j < right; j++){
        if(data[j] <= data[right]){
            i++;
            this->ExchangeByValue(data, i,j);
        }
    }
    this->ExchangeByValue(data, i+1, right);
    return i+1;
}

template<typename T>
int sorter::QuickSort<T>::RandomPartition(T * data, int left, int right){
    srand((unsigned)time(0));
    
    int rand_pos = left + rand() % (right - left + 1) ;
    
    this->ExchangeByValue(data, rand_pos, right);
    return Partition(data, left, right);
}

template<typename T>
void sorter::QuickSort<T>::ExchangeByValue(T * data, int pos1, int pos2){
    T temp = data[pos1];
    data[pos1] = data[pos2];
    data[pos2] = temp;
}

#endif