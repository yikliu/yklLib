//
//  binary_tree_node.h
//  yklLib
//
//  Created by Yikun Liu on 12/22/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef __yklLib__binary_tree_node__
#define __yklLib__binary_tree_node__

#include <iostream>
namespace yikliu{
    namespace data_structure{
        
        enum NodeType {
            root,
            leftChild, //this node is its parent's left child
            rightChild // this node is its parent's right child
        };
        
        template<typename T>
        class BinaryTreeNode {
        public:
            BinaryTreeNode(int key, T * data)
                : left(0), right(0), parent(0), type(root),key(key), data(data){}
            
            BinaryTreeNode<T> * left;
            BinaryTreeNode<T> * right;
            BinaryTreeNode<T> * parent;
            
            NodeType type;
            
            int key;
            
            inline bool IsLeaf(void) {return NULL == left && NULL == right;}
        
        private:
            BinaryTreeNode(void)
                : data(0), left(0), right(0), parent(0), type(root),key(0) {}
        
        private:
            T * data; //point to satellite data
        };
    }
}

#endif /* defined(__yklLib__binary_tree_node__) */
