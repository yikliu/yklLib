//
//  reverse_words_test.cpp
//  GoogleTestExample
//
//  Created by yikliu on 8/21/16.
//  Copyright © 2016 Alloysoft. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../../src/leetcode/151_reverse_words.h"

namespace yikliu{
    namespace test{
        TEST(LeetcodeTests, reverseWords)
        {
            std::string str("the sky is blue");
            leetcode::ReverseWords rw;
            rw.reverseWords(str);
            std::cout<<str<<std::endl;
            ASSERT_STREQ("blue is sky the", str.c_str());
        }
    }
}