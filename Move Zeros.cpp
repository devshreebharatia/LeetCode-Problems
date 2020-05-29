/*
Given an array nums, write a function to move all 0's to the end of it while 
maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        //Solution 1: Shift all the non-zero elements to the start
        //and then add zeros at the end till the size of the array
        int j = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        while(j < nums.size()) {
            nums[j] = 0;
            j++;
        }


        //Solution 2: Keep shifting to the back by swapping. Although
        //swapping is an expensive operation, but for retension of zeros, it
        //has to be done.

        int i=0,j=1;
        while(j<nums.size() && i<nums.size()) {
            if(nums[i] == 0) {
                
                if(nums[j] != 0) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    i++;
                } 
            } 
            else {
                i++;
            }
            j++;
        }
    }
};