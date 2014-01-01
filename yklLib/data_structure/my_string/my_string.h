//
//  MyString.h
//  yklLib
//
//  Created by Yikun Liu on 12/15/13.
//  Copyright (c) 2013 yikliu@me.com. All rights reserved.
//

#ifndef YKL_MY_STRING_H_
#define YKL_MY_STRING_H_

#include <iostream>
#include <string.h>

namespace yikliu {
    namespace data_structure{
        
        class MyString {
        private:
            const char* c_string_;
            
            const MyString& operator=(const MyString& rhs);
            
        public:
            // Clones a 0-terminated C string, allocating memory using new.
            static const char* CloneCString(const char* a_c_string) {
                if (a_c_string == NULL) return NULL;
                
                const size_t len = strlen(a_c_string);
                char* const clone = new char[ len + 1 ];
                memcpy(clone, a_c_string, len + 1);
                
                return clone;
            }
            
            ////////////////////////////////////////////////////////////
            //
            // C'tors
            
            // The default c'tor constructs a NULL string.
            MyString() : c_string_(NULL) {}
            
            // Constructs a MyString by cloning a 0-terminated C string.
            explicit MyString(const char* a_c_string) : c_string_(NULL) {
                Set(a_c_string);
            }
            
            // Copy c'tor
            MyString(const MyString& string) : c_string_(NULL) {
                Set(string.c_string_);
            }
            
            ////////////////////////////////////////////////////////////
            //
            // D'tor.  MyString is intended to be a final class, so the d'tor
            // doesn't need to be virtual.
            ~MyString() { delete[] c_string_; }
            
            // Gets the 0-terminated C string this MyString object represents.
            const char* c_string() const { return c_string_; }
            
            size_t Length() const {
                return c_string_ == NULL ? 0 : strlen(c_string_);
            }
            
            // Sets the 0-terminated C string this MyString object
            // represents.
            void Set(const char* a_c_string) {
                // Makes sure this works when c_string == c_string_
                const char* const temp = MyString::CloneCString(a_c_string);
                delete[] c_string_;
                c_string_ = temp;
            }
        };

    }
}

#endif
