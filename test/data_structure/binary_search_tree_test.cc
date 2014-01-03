//
//  binary_search_tree_test.cc
//  yklLib
//
//  Created by Yikun Liu on 12/22/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YIKUN_TEST
#define YIKUN_TEST

#include "../../yklLib/data_structure/binary_search_tree/binary_search_tree.h"
#include "../../yklLib/data_structure/binary_search_tree/binary_tree_node.h"

#include <gtest/gtest.h>

namespace yikliu{
    namespace test
    {
        namespace ds = data_structure;
        
        class BSTTEST : public ::testing::Test{
        protected:
            BSTTEST(void){
                p_bst = new ds::BinarySearchTree<int>();
            }
            
            virtual ~BSTTEST(void) {
                if(NULL != p_bst)
                    delete p_bst;
            }
            
            virtual void SetUp(void){
                int a[] = {5, 2, 12, -4, 3, 9, 21, 25, 19};
                size_t sz = sizeof(a) / sizeof(a[0]);
                
                ds::BinaryTreeNode<int> * root = new ds::BinaryTreeNode<int>(a[0],NULL);
                p_bst->root = root;
                
                
                for (int i = 1; i < sz; i++)
                {
                    ds::BinaryTreeNode<int> * n = new ds::BinaryTreeNode<int>(a[i], NULL);
                    p_bst->Insert(p_bst->root, n);
                }
            }
                   
            virtual void TearDown(void){
            }
            
            ds::BinarySearchTree<int> * p_bst;
            
        };
        
        TEST_F(BSTTEST, DefaultConstructor) {
            const data_structure::BinarySearchTree<int> bst;
            EXPECT_EQ(NULL, bst.root);
        }
        
        TEST_F(BSTTEST, AfterSetUp)
        {
            p_bst->Print();
            SUCCEED();
        }
        
        TEST_F(BSTTEST, SearchSuccess)
        {
            ds::BinaryTreeNode<int> * res = p_bst->Search(p_bst->root,9);
            EXPECT_EQ(9, res->key);
        }
        
        TEST_F(BSTTEST, SearchNotFound)
        {
            ds::BinaryTreeNode<int> * res = p_bst->Search(p_bst->root,11);
            EXPECT_EQ(NULL, res);
        }
        
        TEST_F(BSTTEST, Delete)
        {
            p_bst->Delete(9);
            p_bst->Print();
        }
    }
}
#endif
