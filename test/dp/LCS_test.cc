//
//  LCS_test.cc
//  yklLib
//
//  Created by Yikun Liu on 1/3/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//
#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../yklLib/dp/LCS.h"
#include <gtest/gtest.h>

namespace yikliu {
    namespace test {
        TEST(LCSTEST, FindLCS) {
            yikliu::dp::LCS lcs_;
            
            char X[] = "AGGTAB";
            char Y[] = "GXTXAYB";
            
            EXPECT_EQ(4, lcs_.FindLCS(X,Y));
        }
    }
}

#endif