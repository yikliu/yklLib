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
                
            //returns the contiguous increasing sequence in a from i to j
            //Let M[i] = the LIS ending at i, then
            // M[i+1] = M[i] + 1 if a[i+1] > a[i]
            //        = 1 a[i+1] < a[i]
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
            
            //return the LIS subsequence (don't have to be contiguous)
            // M[i] = SubLIS ending at i, then
            // M[i+1] = 1 + Max{M[j]} for all j < i, if a[i+1] > a[i]
            //        = 1
            // return the Max(M[i]) is the solution
            int FindSubLIS(int * arr, int size)
            {
                int maxSofar = 0;
                int M[size];
                M[0] = 1;
                for (int i = 1; i < size; i++)
                {
                    if(arr[i] > arr[i-1])
                    {
                        M[i] = ++maxSofar;
                    }
                    else
                    {
                        M[i] = 1;
                    }
                }
                return maxSofar;
            }
        };
    }
}

#endif
