/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that 
is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //In this case, the SUM method is easier but sometimes the sum might
        //exceed the integer limit. In that case either use long or if not
        //then use the XOR method
      
       //SUM METHOD
        int expected_sum = (nums.size()*(nums.size()+1)/2);
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum = sum + nums[i];
        }
        
        //XOR METHOD
        /*int expected_xor = 0;
        int xor1 = 0;
        for(int i=1;i<=nums.size();i++) {
            expected_xor = expected_xor ^ i;
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                xor1 = xor1 ^ nums[i];
            }
        }
        
        return xor1^expected_xor;
        */
        
        return (expected_sum-sum);
    }
};