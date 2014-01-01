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
                ds::BinaryTreeNode<int> * root = new ds::BinaryTreeNode<int>(-1,NULL);
                p_bst->root = root;
                for (int i = 0; i < 10; i++)
                {
                    ds::BinaryTreeNode<int> * n = new ds::BinaryTreeNode<int>(i, NULL);
                    p_bst->root = p_bst->Insert(p_bst->root, n);
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
    }
}
#endif
