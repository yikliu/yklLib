//
//  palindromes.cc
//  yklLib
//
//  Created by Yikun Liu on 1/2/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//
// Using DP to solve some problems related to palindrome. Palindromes are string that
// are same when reversed. e.g "bob"
#ifndef YKL_DP_PALINDROME
#define YKL_DP_PALINDROME

#include <stdio.h>
#include <string.h>
namespace yikliu{
    namespace dp{
        class Palindrome{
        public:
            Palindrome(void){};
            virtual ~Palindrome(void){};
            
            // Find the longest palindrome string (LPS)
            // table M[i,j] indicate the LPS from index i to index j
            // then M[i,j] = :
            //  if str[i] == str [j],
            //     if j = i + 1,
            //          M[i, j] = 2 //init
            //     else
            //          M[i,j] = M[i+1,j-1] + 2 //extend
            //  else
            //     M[i,j] = Max(M[i+1,j],M[i,j-1])
            //  Use memorization
            int FindLongestPalindrome(char * str)
            {
                size_t length = strlen(str);
                int M[length][length];
                
                for (int i = 0; i < length; i++) {
                    M[i][i] = 1;
                }
                
                int j = 0;
                for (int cl = 2; cl <= length; cl++)//cl is the distance between i and j
                {
                    for (int i = 0; i < length - cl + 1; i++)
                    {
                        j = i + cl - 1;
                        if(str[i] == str[j])
                        {
                            if(	cl == 2)
                            {
                                M[i][j] = 2;
                            }
                            else
                            {
                                M[i][j] = M[i+1][j-1] + 2;
                            }
                        }
                        else
                        {
                            M[i][j] = M[i+1][j] > M[i][j-1] ? M[i+1][j] : M[i][j-1];
                        }
                    }
                }
                
                return M[0][length-1];
                
            }
        };
    }
}

#endif