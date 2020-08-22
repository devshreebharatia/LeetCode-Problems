/*
Given an array nums with n integers, your task is to check if it could become 
non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every 
i (0-based) such that (0 <= i <= n - 2).

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        bool check = false;
        int index = 0;
        for(int i=0;i<nums.size()-1;i++) {
            
            if(nums[i]> nums[i+1]) {
                check  = true;
                index = i;
                break;
            }
        }
        if(check) {
            vector<int> v1(nums);
            vector<int> v2(nums);
            
            v1[index] = v1[index+1];
            v2[index+1] = v2[index];
            
            return std::is_sorted(v1.begin(),v1.end()) || std::is_sorted(v2.begin(),v2.end());
        }
        return true;
    }
};