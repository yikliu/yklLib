//
//  TestQuickSort.h
//  CodeDrill
//
//  Created by Yikun Liu on 12/15/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../yikliu/data_structure/my_string/my_string.h"
#include <gtest/gtest.h>

TEST(MyString, DefaultConstructor) {
    const MyString s;
    EXPECT_STREQ(NULL, s.c_string());
    EXPECT_EQ(0u, s.Length());
}

const char kHelloString[] = "Hello, world!";

// Tests the c'tor that accepts a C string.
TEST(MyString, ConstructorFromCString) {
    const MyString s(kHelloString);
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    EXPECT_EQ(sizeof(kHelloString)/sizeof(kHelloString[0]) - 1,
              s.Length());
}

// Tests the copy c'tor.
TEST(MyString, CopyConstructor) {
    const MyString s1(kHelloString);
    const MyString s2 = s1;
    EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));
}

// Tests the Set method.
TEST(MyString, Set) {
    MyString s;
    
    s.Set(kHelloString);
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    
    // Set should work when the input pointer is the same as the one
    // already in the MyString object.
    s.Set(s.c_string());
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    
    // Can we set the MyString to NULL?
    s.Set(NULL);
    EXPECT_STREQ(NULL, s.c_string());
}

#endif
