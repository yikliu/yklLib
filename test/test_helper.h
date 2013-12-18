//
//  ArrayMatch.h
//  yklLib
//
//  Created by Yikun Liu on 12/16/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST_HELPER
#define YIKUN_TEST_HELPER

#include <gtest/gtest.h>

template<typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T (&expected)[size],
                                       const T (&actual)[size]){
    for (size_t i(0); i < size; ++i){
        if (expected[i] != actual[i]){
            return ::testing::AssertionFailure() << "array[" << i
            << "] (" << actual[i] << ") != expected[" << i
            << "] (" << expected[i] << ")";
        }
    }
    
    return ::testing::AssertionSuccess();
}

template<typename T, size_t size>
::testing::AssertionResult AscendingSorted(const T (&actual)[size]){
    for(size_t i(1); i < size; ++i){
        if(actual[i] < actual[i-1]){
            return ::testing::AssertionFailure() <<"array[" << i
            << "] ("<< actual[i] <<") is less than array[" << i - 1 << "] (" << actual[i-1] << ")";
        }
    }
    
    return ::testing::AssertionSuccess();
}
#endif
