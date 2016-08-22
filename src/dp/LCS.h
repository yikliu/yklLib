//
//  LCS.h
//  yklLib
//
//  Created by Yikun Liu on 1/3/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//
// Longest common subsequence

#ifndef yklLib_LCS_h
#define yklLib_LCS_h

#include <string.h>

namespace yikliu {
    namespace dp {
        class LCS{
        public:
            LCS(void){};
            virtual ~LCS(void){};
            
            // return the LCS of str1 and str2
            // Let L[i][j] denote the LCS for str1 ending at i and str2 ending at j
            // if str1[i] == str[j]
            //    L[i][j] = L[i-1][j-1] + 1;
            // else
            //    L[i][j] = max(L[i-1][j],L[i][j-1]);
            int FindLCS(char * str1, char * str2)
            {
                size_t n = strlen(str1);
                size_t m = strlen(str2);
                
                int L[n+1][m+1];
                for (int i = 0; i <= n; i++)
                {
                    for (int j = 0; j <= m; j++) {
                        if (i == 0 || j == 0) {
                            L[i][j] = 0;
                            continue;
                        }
                        
                        if (str1[i] == str2[j])
                        {
                            L[i][j] = L[i-1][j-1] + 1;
                        }
                        else
                        {
                            L[i][j] = max(L[i-1][j], L[i][j-1]);
                        }
                    }
                }
                
                return L[n][m];
            }
            
        private:
            int max(int a, int b)
            {
                return a > b ? a : b;
            }
        };
    }
}


#endif
