//
//  InsertSort.cpp
//  yklLib
//
//  Created by Yikun Liu on 12/16/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//


#include "insert_sort.h"

template<typename T>
InsertSort<T>::InsertSort(void){}

template<typename T>
InsertSort<T>::~InsertSort(void){}

template<typename T>
void InsertSort<T>::Sort(T* data, size_t size){
    size_t i, j;
    T cur_value;
    for(i = 1; i < size; i++){
        cur_value = data[i];
        for(j = i; j > 0 && cur_value < data[j-1]; j--){
            data[j] = data[j-1];
        }
        data[j] = cur_value;
    }
}