/*

Given an array with n objects colored red, white or blue, sort them in-place so 
that objects of the same color are adjacent, with the colors in the order red, 
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1) {
            return;
        }
        
        int start = 0;
        int end = nums.size()-1;
        int index = 0;
        
        //If 0 is found, swap it with start, increment start and index
        //If 2 is found, swap it with end, decrement end but not index as the 
        //element swapped with end is still not checked yet
        //If 1 is found just increment the index
        while(index<=end) {
            
            if(nums[index] == 0) {
                nums[index] = nums[start];
                nums[start] = 0;
                index++;
                start++;
            }
            else if(nums[index] == 2) {
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            }
            else {
                index++;
            }
        }
        
    }
};