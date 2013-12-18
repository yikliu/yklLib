//
//  HeapSortTest.cc
//  yklLib
//
//  Created by Yikun Liu on 12/16/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//
#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../yklLib/data_structure/heap/heap.h"
#include "../../yklLib/data_structure/helper/heap_node.h"
#include <gtest/gtest.h>

namespace{
    class HeapSortTest : public ::testing::Test{
    protected:
        HeapSortTest() {
            sorter = new Heap();
        }
        
        virtual ~HeapSortTest() {
            if(sorter){
                delete sorter;
                sorter = NULL;
            }
        }
        
        virtual void SetUp() {
            HeapNode n1(17);
            HeapNode n2(23);
            HeapNode n3(12);
            HeapNode n4(55);
            HeapNode list[4] = {n1,n2,n3,n4};
            Array<HeapNode> arr(list,4);
            //arr.print();
            sorter->set_array(arr);
        }
        
        virtual void TearDown() {
            
        }
        
        Heap * sorter;
    };
    
    TEST_F(HeapSortTest, sort){
        sorter->heap_sort();
        EXPECT_EQ(55, sorter->top().key);
    }
}


#endif