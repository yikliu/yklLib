//
//  LIS_test.c
//  yklLib
//
//  Created by Yikun Liu on 1/1/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST
#include "../../src/dp/LIS.h"
#include <gtest/gtest.h>

namespace yikliu{
    namespace test
    {
        TEST(LISTEST, FindLIS) {
            yikliu::dp::LIS lis_;
            int arr[] = { 10, 22, 9, 13, 21, 50, 41, 60 };
            int n = sizeof(arr)/sizeof(arr[0]);
            int max_i;
            int max_j;
            
            EXPECT_EQ(4, lis_.FindLIS(arr, n, max_i, max_j));
            EXPECT_EQ(2, max_i);
            EXPECT_EQ(5, max_j); //{9, 13, 21, 50}
        }
        
        TEST(LISTEST, FindSubLIS) {
            yikliu::dp::LIS lis_;
            int arr[] = { 10, 22, 9, 13, 21, 50, 41, 60 };
            int n = sizeof(arr)/sizeof(arr[0]);
            EXPECT_EQ(5, lis_.FindSubLIS(arr, n));
        }
    }
}

#endif
