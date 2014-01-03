//
//  MCS.h
//  yklLib
//
//  Created by Yikun Liu on 1/2/14.
//  Copyright (c) 2014 yikliu@me.com. All rights reserved.
//
//  Find the Max Subarray from an array
//  M[i] = the max sum of all windows ending at a[i]
//  then M[i+1] = Max{a[i+1], M[i]+a[i+1]}
//  The final answer is the maximum of all M[i]
//  This is bottom-up implementation. (O(n))


#ifndef YIKLIU_DP_MCS
#define YIKLIU_DP_MCS

#include <stdio.h>
namespace yikliu
{
    namespace dp
    {
        class MCS
        {
        public:
            MCS(void){};
            virtual ~MCS(void){};
            
            //return the max sum of subarray between gl_i and gl_j
            int FindMCS(int * a, size_t size, int& gl_i, int& gl_j)
            {
                int M[size];
                M[0] = a[0];
                int globalMax = M[0];
                int start_i = 0;
                int start_j = 0;
                for(int i = 1; i < size; i++)
                {
                    int num = M[i-1] + a[i];
                    if(num > a[i])
                    {
                        M[i] = num;
                        start_j = i;
                    }
                    else
                    {
                        M[i] = a[i];
                        start_i = i; //reset index
                        start_j = i; //reset index
                    }
                    
                    if(M[i] > globalMax)
                    {
                        globalMax = M[i];
                        gl_i = start_i;
                        gl_j = start_j;
                    }
                    
                }
                return globalMax;
            }
            
        };
    }
}

#endif
