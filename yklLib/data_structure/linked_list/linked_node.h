//
//  linked_node.h
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef __yklLib__linked_node_H_
#define __yklLib__linked_node_H_

template<typename T>
class LinkedNode{
public:
    LinkedNode(void);
    LinkedNode(const T & p_val);
    
    virtual ~LinkedNode(void);
    
    LinkedNode * next;
    LinkedNode * prev;
    
    inline T & GetData(void){return *this->data;}

private:
    T * data; //pointer to the satellite data
};

#include "linked_node.cc"

#endif
