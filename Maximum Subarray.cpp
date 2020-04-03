/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include<bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum =0;
        for(int i=0;i<nums.size();i++) {
            sum = sum + nums[i];
            if(sum<nums[i]) {
                sum = nums[i];
            }
            if(sum>max) {
                max = sum;
            }
        }
        return max;
    }
};