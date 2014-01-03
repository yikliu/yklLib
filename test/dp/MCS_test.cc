//
//  MCS_test.cc
//  yklLib
//
//  Created by Yikun Liu on 1/2/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../yklLib/dp/MCS.h"
#include <gtest/gtest.h>

namespace yikliu{ 
    namespace test
    {
        TEST(MCSTEST, FindMCS) {
            yikliu::dp::MCS mcs_;
            int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
            int n = sizeof(arr)/sizeof(arr[0]);
            int max_i;
            int max_j;
            
            EXPECT_EQ(6, mcs_.FindMCS(arr,n,max_i,max_j));
            EXPECT_EQ(3, max_i);
            EXPECT_EQ(6, max_j);
        }
    }
}

#endif