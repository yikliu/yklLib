//
//  merge_sort_test.cc
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//
#ifndef YIKUN_TEST
#define YIKUN_TEST

#include <gtest/gtest.h>
#include "../../yklLib/sorting/merge_sort/merge_sort.h"
#include "../test_helper.h"

namespace yikliu {
    namespace test{
        
        TEST(MergeSortTest, Sort)
        {
            sorting::MergeSort<int> merge_sorter;
            int even_data[10] = {17,25,3,14,9,11,23,34,6,20};
            int odd_data[11] = {17,25,3,14,9,11,23,34,6,20,12};
            int two_data[2] = {25,17};
            merge_sorter.Sort(even_data, 10);
            merge_sorter.Sort(odd_data, 11);
            merge_sorter.Sort(two_data, 2);
            EXPECT_TRUE(::yikliu::test::AscendingSorted(even_data));
            EXPECT_TRUE(::yikliu::test::AscendingSorted(odd_data));
            EXPECT_TRUE(::yikliu::test::AscendingSorted(two_data));
        }
    }
}
}

#endif