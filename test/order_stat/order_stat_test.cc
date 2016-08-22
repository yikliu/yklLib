//
//  order_stat_test.cc
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../../src/order_stat/order_stat.h"

namespace yikliu{
    namespace test{
        TEST(OrderStatTest, RandomSelect)
        {
            int data[5] = {7,6,2,5,4};
            order_stat::OrderStatistics<int> os;
            int selected = os.RandomSelect(data,0,4,3);
            EXPECT_EQ(5, selected);
        }
    }
}

