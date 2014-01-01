//
//  binary_search_tree.h
//  yklLib
//
//  Created by Yikun Liu on 12/22/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef __yklLib__binary_search_tree__
#define __yklLib__binary_search_tree__

#include "binary_tree_node.h"

namespace yikliu{
    namespace data_structure{
        
        template <typename T>
        class BinarySearchTree{
            
            //node visiting function pointer
            typedef void (BinarySearchTree:: * visitor)(BinaryTreeNode<T> *);
            
        public:
            BinarySearchTree(void);
            virtual ~BinarySearchTree(void);
            
            //ops
            void InOrderWalk(BinaryTreeNode<T> * node, visitor visit);
            void PostOrderWalk(BinaryTreeNode<T> * node, visitor visit);
            void PreOrderWalk(BinaryTreeNode<T> * node, visitor visit);
            
            //delete a node and its children
            void DeleteNode(BinaryTreeNode<T> * node);
            
            //Insert
            BinaryTreeNode<T> * Insert(BinaryTreeNode<T> * cur, BinaryTreeNode<T> * newNode);
            
            //print
            void PrintNode(BinaryTreeNode<T> * node);
            
            void Print(void);
            
            BinaryTreeNode<T> * root;
        
        private:
            
        };
    }
}

#include "binary_search_tree.cc"

#endif /* defined(__yklLib__binary_search_tree__) */
