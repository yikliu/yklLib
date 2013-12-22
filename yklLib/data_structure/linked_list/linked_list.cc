//
//  linked_list.cc
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef __yklLib__linked_list_CC_
#define __yklLib__linked_list_CC_

#include <iostream>
#include "linked_node.h"
#include "linked_list.h"
#include "../../exception/my_exception.h"
namespace ds = yikliu::data_structure;

template<typename T>
ds::LinkedList<T>::LinkedList(void):head(0),length(0)
{    
}

template<typename T>
ds::LinkedList<T>::~LinkedList(void)
{
}

template<typename T>
void ds::LinkedList<T>::Insert(LinkedNode<T> * node, size_t pos)
{
    if(pos > length) //accept pos [0 length]
    {
       throw new exception::my_exception("Pos larger than length");
    }
    
    LinkedNode<T> * p;
    
    if(pos < length)
    {
        p = this->GetNodeAt(pos);
        
        if(p->prev) //insert at head
        {
            p->prev->next = node;
            node->prev = p->prev;
        }
        else
        {
            this->head = node;
        }
        
        node->next = p;
        p->prev = node;

    }
    else // pos == length insert at end;
    {
        if(0 == pos) //empty list
        {
            this->head = node;
        }
        else
        {
            p = this->GetNodeAt(pos - 1);
            p->next = node;
            node->prev = p;
        }
        
    }
    
    length++;
}

template<typename T>
void ds::LinkedList<T>::Delete(size_t pos)
{
    LinkedNode<T> * p = this->GetNodeAt(pos);
    
    if(!p)
        throw new exception::my_exception("deleting at wrong postion.");
    
    if(p->prev)
        p->prev->next = p->next;
    if(p->next)
        p->next->prev = p->prev;
    
    length--;
}


template<typename T>
void ds::LinkedList<T>::AppendAtTail(LinkedNode<T> * node)
{
    this->Insert(node, this->length);
}


template<typename T>
void ds::LinkedList<T>::Print(void)
{
    LinkedNode<int> * p = this->head;
    while(p)
    {
        std::cout<<p->GetData()<<",";
        p = p->next;
    }
    std::cout<<std::endl;
}

template<typename T>
ds::LinkedNode<T> * ds::LinkedList<T>::GetNodeAt(size_t pos)
{
    if(pos >= this->length)
    {
        throw new exception::my_exception("Pos larger than length");
    }
    
    LinkedNode<T> * p = this->head;
    
    int num = 0;
    while(num < pos)
    {
        p = p->next;
        num++;
    }
    
    return p;
}

#endif /* defined(__yklLib__linked_list__) */