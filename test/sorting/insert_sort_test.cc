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

#include "../../src/sorting/insert_sort/insert_sort.h"
#include "test_helper.h"
#include <gtest/gtest.h>

namespace yikliu{
    namespace test{
        class InsertSortTest : public ::testing::Test {
        protected:
            InsertSortTest() {
                insert_sort = new sorting::InsertSort<int>();
            }
            
            virtual ~InsertSortTest() {
                if(insert_sort){
                    delete insert_sort;
                    insert_sort = NULL;
                }
            }
            
            virtual void SetUp() {
                
            }
            
            virtual void TearDown() {
                
            }
            
            sorting::InsertSort<int> * insert_sort;
            
        };
        
        TEST_F(InsertSortTest, Sort){
            int expected_sorted_array[11] = {5,11,15,17,22,23,33,34,54,82,90};
            int original_array[11] = {17,33,82,5,23,15,11,54,34,22,90};
            insert_sort->Sort(original_array, sizeof(original_array)/sizeof(original_array[0]));
            EXPECT_TRUE(::yikliu::test::ArraysMatch(expected_sorted_array, original_array));
        }
    }
}
}
#endif