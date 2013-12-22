//
//  linked_list.h
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef __yklLib__linked_list__
#define __yklLib__linked_list__

#include <iostream>
#include "linked_node.h"

namespace yikliu{
    namespace data_structure{

        template<typename T>
        class LinkedList{
        public:
            LinkedList(void);
            
            virtual ~LinkedList(void);
            
            inline size_t Size(void){return this->length;}
            
            data_structure::LinkedNode<T> * GetNodeAt(size_t pos);
            
            //methods
            void Insert(LinkedNode<T> * node, size_t pos);
            
            void Delete(size_t pos);
            
            void AppendAtTail(LinkedNode<T> * node);
            
            void Print(void);
            
            LinkedNode<T> * head;

        private:
            size_t length;
        };
    }
}

#include "linked_list.cc"

#endif /* defined(__yklLib__linked_list__) */
