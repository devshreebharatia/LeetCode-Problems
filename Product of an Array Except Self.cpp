/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */


 class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Simply Calculate the entire product and go on dividing the current element.
        vector<int> output;
        int product1 = 1;
        int product2 = 1;
        int count = 0;
        
        if(nums.size() == 0 || nums.size() ==1) {
            return output;
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                product1 = product1 * nums[i];
            } else {
                count++;
            }
            product2 = product2 * nums[i];
        }
        
        if(count>1) {
            product1 = 0;
        }
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                output.push_back(product1);
            } else {
                output.push_back(product2/nums[i]);
            }
        }*/
        
        
        //Left and Right division
        vector<int> output(nums.size());
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