/*
Given an array nums containing n + 1 integers where each integer is between 1 
and n (inclusive), prove that at least one duplicate number must exist. Assume 
that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more 
than once.

 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //Solution 1: A little inefficient. Sort the array and then check the
        //adjacent elements. Time Complexity: O(nlogn) + O(n)
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return -1;


        //Solution 2: Optimized solution
        //As we know there are only 1 to n numbers, we can make the element
        //at position nums[i] as negative. If nums[i] reeat we will find that
        //position already negative.
        int index = 0;
        for(int i=0;i<nums.size();i++) {
            
            index = abs(nums[i]);
            if(nums[index-1]<0) {
                return abs(nums[i]);
            }
            nums[index-1] = nums[index-1] * -1;
        }
        return -1;
    }
};