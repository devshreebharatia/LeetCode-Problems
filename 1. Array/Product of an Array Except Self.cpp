/*
Given an array nums of n integers where n > 1,  return an array output such that 
output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or 
suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not 
count as extra space for the purpose of space complexity analysis.)
 */


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //Solution 1: Simplest solution with Time Complexity O(n^2)
        vector<int> output;
        if(nums.size() == 0 || nums.size() ==1){
            return output;
        }
        output(nums.size(),1);
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums.size();j++) {
                if(i!=j) {
                    output[i] = output[i] * nums[j];
                }
            }
        }

        //Solution 2: Simply Calculate the entire product and go on dividing 
        //the current element. Time Complexity: O(n) + O(n) = O(n)
        vector<int> output;
        int product = 1;
         if(nums.size() == 0 || nums.size() ==1){
            return output;
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                product = product * nums[i];
            }   
        }
        for(int i=0;i<nums.size();j++) {
            if(nums[i] != 0) {
                output[i] = product/nums[i];
            }
        }
        
        //Solution 3: Left and Right division: Time Complexity: O(n) + O(n) = O(n)
        vector<int> output;
        if(nums.size() == 0 || nums.size() ==1) {
            return output;
        }
        output[0] = 1;
        for(int i=1;i<nums.size();i++) {
            output[i] = output[i-1] * nums[i-1];
        }
        int right_product = 1;
        for(int i=nums.size()-1;i>=0;i--) {
            output[i] = output[i] * right_product;
            right_product = right_product * nums[i];
        }
        
        return output;    
    }
};