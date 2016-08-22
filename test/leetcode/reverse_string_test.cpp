//
//  reverse_string_test.cpp
//  GoogleTestExample
//
//  Created by yikliu on 8/21/16.
//  Copyright © 2016 Alloysoft. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../../src/leetcode/344_reverse_string.h"

namespace yikliu{
    namespace test{
        TEST(LeetcodeTests, reverseString)
        {
            std::string str("hello");
            leetcode::ReverseString rs;
            rs.reverseString(str);
            std::cout<<str<<std::endl;
            ASSERT_STREQ("olleh", str.c_str());
        }
    }
}
