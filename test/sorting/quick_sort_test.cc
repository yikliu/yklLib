//
//  QuickSort_Test.cpp
//  yklLib
//
//  Created by Yikun Liu on 12/15/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include <iostream>
#include <gtest/gtest.h>

#include "../../yklLib/sorting/quick_sort/quick_sort.h"
#include "test_helper.h"

namespace{
    
    class QSortTest : public ::testing::Test {
    protected:
        QSortTest() {
            qsort = new QuickSort<int>();
        }
        
        virtual ~QSortTest() {
            if(qsort){
                delete qsort;
                qsort = NULL;
            }
        }
        
        virtual void SetUp() {
            
        }
        
        virtual void TearDown() {
            
        }
        
        QuickSort<int> * qsort;
        
    };
    
    TEST_F(QSortTest, Sort){
        int original_array[11] = {17,33,82,5,23,15,11,54,34,22,90};
        qsort->Sort(original_array, 0, 10);
        EXPECT_TRUE(AscendingSorted(original_array));
    }
    
}
#endif
