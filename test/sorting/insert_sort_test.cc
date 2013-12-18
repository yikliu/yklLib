//
//  InsertSortTest.cc
//  yklLib
//
//  Created by Yikun Liu on 12/16/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include <iostream>

#include "../../yklLib/sorting/insert_sort/insert_sort.h"
#include "test_helper.h"
#include <gtest/gtest.h>

namespace{
    
    class InsertSortTest : public ::testing::Test {
    protected:
        InsertSortTest() {
            sorter = new InsertSort<int>();
        }
        
        virtual ~InsertSortTest() {
            if(sorter){
                delete sorter;
                sorter = NULL;
            }
        }
        
        virtual void SetUp() {
            
        }
        
        virtual void TearDown() {
            
        }
        
        InsertSort<int> * sorter;
        
    };
    
    TEST_F(InsertSortTest, Sort){
        int expected_sorted_array[11] = {5,11,15,17,22,23,33,34,54,82,90};
        int original_array[11] = {17,33,82,5,23,15,11,54,34,22,90};
        sorter->Sort(original_array, sizeof(original_array)/sizeof(original_array[0]));
        EXPECT_TRUE(ArraysMatch(expected_sorted_array, original_array));
    }
    
}
#endif