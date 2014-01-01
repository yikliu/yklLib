//
//  LIS_test.c
//  yklLib
//
//  Created by Yikun Liu on 1/1/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../yklLib/dp/LongestIncreasingSequence/LIS.h"
#include <gtest/gtest.h>

namespace yikliu{
    namespace test
    {
        TEST(LISTEST, Find) {
            yikliu::dp::LIS lis_;
            int arr[] = { 10, 22, 9, 13, 21, 50, 41, 60 };
            int n = sizeof(arr)/sizeof(arr[0]);
            EXPECT_EQ(4, lis_.FindLIS(arr,n));
        }
    }
}

#endif
