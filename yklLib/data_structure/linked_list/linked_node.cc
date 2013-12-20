//
//  linked_node.cc
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//
#ifndef __yklLib__linked_node_CC_
#define __yklLib__linked_node_CC_

#include "linked_node.h"

template<typename T>
LinkedNode<T>::LinkedNode(void)
:data(0),prev(0), next(0)
{
    data = new T();
}

template<typename T>
LinkedNode<T>::LinkedNode(const T & p_val)
:data(0), prev(0), next(0)
{
    data = new T(p_val);
}

template<typename T>
LinkedNode<T>::~LinkedNode(void)
{
    if (data)
    {
        delete data;
        data = NULL;
    }
}


#endif