/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size()-1;
        
        while(start<end && nums[start] <= nums[start+1]) {
            start++;
        }
        if(start == nums.size()-1) {
            return 0;
        }
        
        while(end>0 && nums[end] >= nums[end-1]) {
            end--;
        }
        
        int min_value = nums[start];
        int max_value = nums[end];
        
        for(int i=start;i<=end;i++) {
            if(nums[i] < min_value) {
                min_value = nums[i];
            }
            if(nums[i] > max_value) {
                max_value = nums[i];
            }
        }
        
        for(int i=0;i<=start;i++) {
            if(nums[i] > min_value) {
                start = i;
            }
        }
        
        for(int i=end;i<nums.size();i++) {
            if(nums[i] < max_value) {
                end = i;
            }
        }
        
        return(end-start+1);
    }
};