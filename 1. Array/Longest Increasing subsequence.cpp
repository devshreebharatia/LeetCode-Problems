/*
Given an unsorted array of integers, find the length of longest continuous 
increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its 
length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous 
one where 5 and 7 are separated by 4.


Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 


*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return 1;
        }
        int max_count = 0;
        int count = 0;
        for(int i=0;i<nums.size()-1;i++) {
            
            if(nums[i] < nums[i+1]) {
                count++;
            }
            else {
                count = 0;
            }
            max_count = max(count,max_count);
        }
        
        return max_count+1;
    }
};