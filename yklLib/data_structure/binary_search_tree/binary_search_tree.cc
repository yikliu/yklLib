//
//  binary_search_tree.cc
//  yklLib
//
//  Created by Yikun Liu on 12/22/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_BINARY_SEARCH_TREE_CC_
#define YKL_BINARY_SEARCH_TREE_CC_

#include "binary_search_tree.h"
namespace ds = yikliu::data_structure;

template<typename T>
ds::BinarySearchTree<T>::BinarySearchTree(void)
:root(0)
{
}

template<typename T>
ds::BinarySearchTree<T>::~BinarySearchTree(void)
{
    this->PostOrderWalk(root, &BinarySearchTree<T>::DeleteNode);
}

template<typename T>
void ds::BinarySearchTree<T>::InOrderWalk(BinaryTreeNode<T> * node, visitor visit)
{
    if(node)
    {
        InOrderWalk(node->left, visit);
        (this->*(visit))(node);
        if(node) //node might be null after visit
            InOrderWalk(node->right, visit);
    }
}

template<typename T>
void ds::BinarySearchTree<T>::PostOrderWalk(BinaryTreeNode<T> *node, visitor visit)
{
    if(node)
    {
        this->PostOrderWalk(node->left, visit);
        this->PostOrderWalk(node->right, visit);
        (this->*(visit))(node);
    }
}

template<typename T>
void ds::BinarySearchTree<T>::PreOrderWalk(BinaryTreeNode<T> *node, visitor visit)
{
    if(node)
    {
        (this->*(visit))(node);
        if(node)
        {
            this->PostOrderWalk(node->left, visit);
            this->PostOrderWalk(node->right, visit);
        }
    }
}

template<typename T>
ds::BinaryTreeNode<T> * ds::BinarySearchTree<T>::Insert(BinaryTreeNode<T> * cur, BinaryTreeNode<T> * node)
{
    if(NULL == cur){
        return node;
    }
    
    if(cur->key >= node->key)
    {
        cur->left = this->Insert(cur->left, node);
    }
    else
    {
        cur->right = this->Insert(cur->right, node);
    }
    
    return cur;
}

template<typename T>
void ds::BinarySearchTree<T>::DeleteNode(BinaryTreeNode<T> *node)
{
    if(node)
    {
        delete node;
        node = NULL;
    }
}

template<typename T>
void ds::BinarySearchTree<T>::PrintNode(BinaryTreeNode<T> * node)
{
    std::cout<<node->key<<" ";
}

template<typename T>
void ds::BinarySearchTree<T>::Print(void)
{
    std::cout<<"In Order Walk:";
    this->InOrderWalk(this->root, &BinarySearchTree<T>::PrintNode);
    std::cout<<std::endl;
    
    std::cout<<"Pre Order Walk:";
    this->PreOrderWalk(this->root, &BinarySearchTree<T>::PrintNode);
    std::cout<<std::endl;

    std::cout<<"Post Order Walk:";
    this->PostOrderWalk(this->root, &BinarySearchTree<T>::PrintNode);
    std::cout<<std::endl;
}


#endif