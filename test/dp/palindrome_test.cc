//
//  palindrome_test.cc
//  yklLib
//
//  Created by Yikun Liu on 1/3/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../src/dp/palindrome.h"
#include <gtest/gtest.h>

namespace yikliu{
    namespace test
    {
        TEST(PALINEDROMTEST, FindLPS) {
            yikliu::dp::Palindrome pal;
            char seq[] = "GEEKS FOR GEEKS";
            
            EXPECT_EQ(7, pal.FindLongestPalindrome(seq));
            
        }
    }
}

#endif