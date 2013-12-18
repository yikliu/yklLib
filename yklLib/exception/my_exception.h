//
//  my_exception.h
//  yklLib
//
//  Created by Yikun Liu on 12/17/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_MY_EXCEPTION_H_
#define YKL_MY_EXCEPTION_H_

#include <iostream>
#include <exception>
/**
 * @class empty_exception
 *
 * runtime error Exception thrown to output whatever the cause
 */
class my_exception : public std::runtime_error
{
public:
    
    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    my_exception (const char *  msg)
    : std::runtime_error (msg) { }
};

#endif
