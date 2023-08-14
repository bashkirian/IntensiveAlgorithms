#pragma once

using namespace std;

#include <vector>

// https://leetcode.com/problems/maximum-subarray/
class Solution
{
    public:
int maxSubArray(vector<int>& nums) {
        //Kaden's algorithm
        
        int n=nums.size();
        int sum=0;
        int max_sum=INT_MIN; //if all the numbers are negative it works 
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];        
            max_sum=max(sum,max_sum); //taking max at each index
            if(sum<0) 
            {               //if the sum till the present index is less than 0,
                            //we will skip all the numers till then
                sum=0;
            }
            
        }
        return max_sum;
		}
};
