//
//  LIS.cc
//  yklLib
//
//  Created by Yikun Liu on 1/1/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//

// This is the implmentation of Longest Increasing Sequence DP solution
// FindLIS returns the max length of increasing sequence in an given array

#ifndef YIKLIU_DP_LIS
#define YIKLIU_DP_LIS

#include <stdio.h>
namespace yikliu
{
    namespace dp
    {
        class LIS
        {
          public:
            LIS(void){};
            virtual ~LIS(void){};
                
            int FindLIS(int * a, size_t size, int& max_i, int& max_j)
            {
                int curMax = 1;
                int globalMax = 1;
                int M[size];
                M[0] = 1;
                int start_i = 0;
                int start_j = 0;
                for(int i = 1; i < size; i++)
                {
                    if(a[i] >= a[i-1])
                    {
                        curMax++;
                        start_j = i;
                        
                        if(curMax > globalMax){
                            globalMax = curMax;
                            max_i = start_i;
                            max_j = start_j;
                        }
                        
                        M[i] = curMax;
                    }else{
                        M[i] = 1;
                        curMax = 1;
                        start_i = i;
                        start_j = i;
                    }
                }
                
                return globalMax;
            }
        };
    }
}

#endif
