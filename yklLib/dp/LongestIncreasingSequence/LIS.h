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
                
            int FindLIS(int * a, size_t size)
            {
                int curMax = 1;
                int globalMax = 1;
                int M[size];
                M[0] = 1;
                int i = 1;
                for(; i < size; i++)
                {
                    if(a[i] >= a[i-1])
                    {
                        curMax++;
                        
                        if(curMax > globalMax){
                            globalMax = curMax;
                            
                        }
                        
                        M[i] = curMax;
                    }else{
                        M[i] = 1;
                        curMax = 1;
                    }
                }
                
                return globalMax;
            }
        };
    }
}

#endif
