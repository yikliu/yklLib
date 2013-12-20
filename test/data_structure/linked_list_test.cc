//
//  linked_list_test.cc
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "../../yklLib/data_structure/linked_list/linked_list.h"
#include "../../yklLib/data_structure/linked_list/linked_node.h"

namespace{
    class LinkedListTest : public ::testing::Test{
    protected:
        LinkedListTest() {
            llist = new LinkedList<int>();
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
                LinkedNode<int> * nd = new LinkedNode<int>(i);
                llist->Insert(nd, pos);
            }
            
            empty = new LinkedList<int>();
            first = new LinkedNode<int>(0);
        }
        
        virtual void TearDown() {
            LinkedNode<int> * p = llist->head;
            LinkedNode<int> * next;
            
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
        
        LinkedList<int> * llist;
        LinkedList<int> * empty;
        LinkedNode<int> * first;
    };
    
    TEST_F(LinkedListTest, Init)
    {
        int num = 0;
        LinkedNode<int> * p = llist->head;
        while(p)
        {
            ++num;
            p = p->next;
        }
        ASSERT_EQ(10, num);
    }
    
    TEST_F(LinkedListTest, InsertAtHead)
    {
        LinkedNode<int> * node = new LinkedNode<int>(-1);
        int orig_head_val = llist->head->GetData();
        llist->Insert(node, 0);
        EXPECT_EQ(-1, llist->head->GetData());
        EXPECT_EQ(orig_head_val, llist->head->next->GetData());
    }
    
    TEST_F(LinkedListTest, AppendAtTail)
    {
        LinkedNode<int> * node = new LinkedNode<int>(-1);
        LinkedNode<int> * p = llist->head;
        LinkedNode<int> * end;
        
        while(p)
        {
            end = p;
            p = p->next;
        }
        
        int orig_end_val = end->GetData();
        
        llist->AppendAtTail(node);
        
        p = llist->head;
        end = p;
        LinkedNode<int> * second_end = end;
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
        LinkedNode<int> * p = llist->GetNodeAt(mid);
        LinkedNode<int> * pv, * nx;
        
        pv = p->prev;
        nx = p->next;
        
        //std::cout<<"["<<pv->GetData()<<","<<p->GetData()<<","<<nx->GetData()<<"]"<<std::endl;
        
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
        EXPECT_THROW({
            empty->Insert(first, 1);
        }, my_exception);
        
        
    }
}