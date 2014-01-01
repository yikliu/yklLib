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
        template<typename T>
        class BinaryTreeNode {
        public:
            BinaryTreeNode(int key, T * data)
                : left(0), right(0), key(key), data(data){}
            
            BinaryTreeNode<T> * left;
            BinaryTreeNode<T> * right;
            
            int key;
        
        private:
            BinaryTreeNode(void)
                : data(0), left(0), right(0),key(0) {}
        
        private:
            T * data; //point to satellite data
        };
    }
}

#endif /* defined(__yklLib__binary_tree_node__) */
