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
    //use post order walk to delete children before deleting the parent node
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
            this->PreOrderWalk(node->left, visit);
            this->PreOrderWalk(node->right, visit);
        }
    }
}

template<typename T>
void ds::BinarySearchTree<T>::Insert(BinaryTreeNode<T> * cur, BinaryTreeNode<T> * node)
{
    if(cur->key >= node->key)
    {
        if(cur->left)
        {
            this->Insert(cur->left, node);
        }
        else
        {
            node->parent = cur;
            node->type = leftChild;
            cur->left = node;
        }
    }
    else
    {
        if(cur->right)
        {
            this->Insert(cur->right, node);
    
        }
        else
        {
            node->parent = cur;
            node->type = rightChild;
            cur->right = node;
        }
    }
}

template<typename T>
ds::BinaryTreeNode<T> * ds::BinarySearchTree<T>::Search(BinaryTreeNode<T> * node, T key)
{
    if(node->key == key)
    {
        return node;
    }
    else if(key < node->key)
    {
        if(NULL == node->left)
        {
            return NULL;
        }
        return this->Search(node->left, key);
    }
    else
    {
        if(NULL == node->right)
        {
            return NULL;
        }
        return this->Search(node->right, key);
    }

}

template<typename T>
void ds::BinarySearchTree<T>::Delete(T key)
{
    BinaryTreeNode<T> * del = this->Search(this->root, key);
    if(del->IsLeaf()) //del is a leaf
    {
        if(del->type == leftChild)
        {
            del->parent->left = NULL;
        }
        else if(del->type == rightChild)
        {
            del->parent->right = NULL;
        }
    }
    else if (del->left == NULL) // del only has right child
    {
        if(del->type == leftChild)
        {
            del->parent->left = del->right;
        }
        else if(del->type == rightChild)
        {
            del->parent->right = del->right;
        }
        
    }
    else if (del->right == NULL) // del only has left child
    {
        if(del->type == leftChild)
        {
            del->parent->left = del->left;
        }
        else if(del->type == rightChild)
        {
            del->parent->right = del->left;
        }
    }
    else //del has two children
    {
        BinaryTreeNode<T> * minNode = this->FindMin(del->right); // find the min from right subtree
        
        minNode->parent->left = NULL;
        
        if(del->type == leftChild)
        {
            del->parent->left = minNode;
            minNode->type = leftChild;
        }
        else if(del->type == rightChild)
        {
            del->parent->right = minNode;
            minNode->type = rightChild;
        }
    }

    DeleteNode(del);
}

template<typename T>
void ds::BinarySearchTree<T>::DeleteNode(BinaryTreeNode<T> * node)
{
    if(node)
    {
        delete node;
        node = NULL;
    }
}

template<typename T>
ds::BinaryTreeNode<T> * ds::BinarySearchTree<T>::FindMin(BinaryTreeNode<T> *node)
{
    if(node->left == NULL)
        return node;
    else
        return this->FindMin(node->left);
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