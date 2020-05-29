/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        //With Extra Memory
        if(nums.size() ==1){
            return nums[0];
        } 
        if(nums.size()%2!=0) {
            int arr[nums.size()] = {0};
            for(int i=0;i<nums.size();i++) {
                arr[nums[i]]++;
            }
            for(int i=0;i<nums.size();i++) {
                if(arr[nums[i]] == 1) {
                    return nums[i];
                }
            }
        }
        return -1;

        //Without Extra Memory

        //Always try to use XOR for a problem where you have to eliminate
        //numbers that occur twice. This is because XORing the same numbers
        //results in 0.
        int sum = 0;
        if(nums.size() ==1){
            return nums[0];
        } 
        if(nums.size()%2!=0){
            for(int i=0;i<nums.size();i++) {
                sum = sum ^ nums[i];
            }
        }
        return sum;
    }
};