//
//  linked_list_test.cc
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../../src/data_structure/linked_list/linked_list.h"
#include "../../src/data_structure/linked_list/linked_node.h"
#include "../../src/exception/my_exception.h"

namespace yikliu{
    namespace test{
        
        namespace ds = data_structure;
        
        class LinkedListTest : public ::testing::Test{
        protected:
            LinkedListTest() {
                llist = new ds::LinkedList<int>();
            }
            
            virtual ~LinkedListTest() {
                if(llist)
                    delete llist;
            }
            
            virtual void SetUp() {
                for(int i = 0; i < 10; ++i)
                {
                    size_t curLength = llist->Size();
                    int pos = (0 == curLength) ? 0 : rand() % curLength;
                    ds::LinkedNode<int> * nd = new ds::LinkedNode<int>(i);
                    llist->Insert(nd, pos);
                }
                
                empty = new ds::LinkedList<int>();
                first = new ds::LinkedNode<int>(0);
            }
            
            virtual void TearDown() {
                ds::LinkedNode<int> * p = llist->head;
                ds::LinkedNode<int> * next;
                
                while(p)
                {
                    next = p->next ? p->next : NULL; //save next first
                    delete p;
                    p = next;
                }
                
                if(empty)
                    delete empty;
                
                if(first)
                    delete first;
            }
            
            ds::LinkedList<int> * llist;
            ds::LinkedList<int> * empty;
            ds::LinkedNode<int> * first;
        };
        
        TEST_F(LinkedListTest, Init)
        {
            int num = 0;
            ds::LinkedNode<int> * p = llist->head;
            while(p)
            {
                ++num;
                p = p->next;
            }
            ASSERT_EQ(10, num);
        }
        
        TEST_F(LinkedListTest, InsertAtHead)
        {
            ds::LinkedNode<int> * node = new ds::LinkedNode<int>(-1);
            int orig_head_val = llist->head->GetData();
            llist->Insert(node, 0);
            EXPECT_EQ(-1, llist->head->GetData());
            EXPECT_EQ(orig_head_val, llist->head->next->GetData());
        }
        
        
        TEST_F(LinkedListTest, AppendAtTail)
        {
            ds::LinkedNode<int> * node = new ds::LinkedNode<int>(-1);
            ds::LinkedNode<int> * p = llist->head;
            ds::LinkedNode<int> * end = NULL;
            
            while(p)
            {
                end = p;
                p = p->next;
            }
            
            int orig_end_val = end->GetData();
            
            llist->AppendAtTail(node);
            
            p = llist->head;
            end = p;
            ds::LinkedNode<int> * second_end = end;
            while(p)
            {
                end = p;
                second_end = end->prev;
                p = p->next;
            }
            
            EXPECT_EQ(-1, end->GetData());
            EXPECT_EQ(orig_end_val, second_end->GetData());//second last contains the original last value
        }
        
        
        TEST_F(LinkedListTest, Delete)
        {
            size_t mid = 5;
            ds::LinkedNode<int> * p = llist->GetNodeAt(mid);
            ds::LinkedNode<int> * pv, * nx;
            
            pv = p->prev;
            nx = p->next;
            
            int exp_prv_val = -1;
            int exp_nx_val = -1;
            
            if(pv)
                exp_prv_val = pv->GetData();
            
            if(nx)
                exp_nx_val = nx->GetData();
            
            llist->Delete(mid);
            
            EXPECT_EQ(9, llist->Size());
            
            int act_prev_val = llist->GetNodeAt(4)->GetData();
            int act_next_val = llist->GetNodeAt(5)->GetData();
            
            EXPECT_EQ(exp_prv_val, act_prev_val);
            EXPECT_EQ(exp_nx_val, act_next_val);
        }
        
        
        TEST_F(LinkedListTest, InsertEmpty)
        {
            empty->Insert(first, 0);
            EXPECT_EQ(1, empty->Size());
            EXPECT_EQ(0, empty->head->GetData());
        }
        
        
        TEST_F(LinkedListTest, IllegalInsert)
        {
            EXPECT_ANY_THROW({
                empty->Insert(first, 1);
            });
        }

    }
    
}