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
#include "../../yklLib/data_structure/heap/heap_node.h"
#include <gtest/gtest.h>

namespace yikliu{
    namespace test{
        namespace ds = yikliu::data_structure;
        
        class HeapSortTest : public ::testing::Test{
        protected:
            HeapSortTest() {
                sorter = new ds::Heap();
            }
            
            virtual ~HeapSortTest() {
                if(sorter){
                    delete sorter;
                    sorter = NULL;
                }
            }
            
            virtual void SetUp() {
                ds::HeapNode n1(17);
                ds::HeapNode n2(23);
                ds::HeapNode n3(12);
                ds::HeapNode n4(55);
                ds::HeapNode list[4] = {n1,n2,n3,n4};
                ds::Array<ds::HeapNode> arr(list,4);
                //arr.print();
                sorter->set_array(arr);
            }
            
            virtual void TearDown() {
                
            }
            
            ds::Heap * sorter;
        };
        
        TEST_F(HeapSortTest, sort){
            sorter->heap_sort();
            EXPECT_EQ(55, sorter->top().key);
        }
 
    }
}



#endif