/*
Given an array of size n, find the majority element. The majority element is the 
element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist 
in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int max_element = nums[0];
        
        //If it is the same element, increment the count, and if a different 
        //element decrement the count.Once the count becomes zero, it is an 
        //indication that the majority element candidate has changed. At the end, 
        //we get the mojority element.
        for(int i=0;i<nums.size();i++) {
            if(max_element == nums[i]) {
                count++;
            }
            else{
                if(count ==0) {
                    max_element = nums[i];
                    count++;
                } else {
                    count--;
                }
            }
        }
        return max_element;
    }
};