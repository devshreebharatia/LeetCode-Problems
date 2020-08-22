/*

Given the array of integers nums, you will choose two different indices i and j 
of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will 
get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the
maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12

 */
 class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        //Solution 1: Brute Force Option
        //Time Complexity: O(n^2)
        
        int max=0;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                
                if((nums[i]-1)*(nums[j]-1) > max) {
                    max = (nums[i]-1)*(nums[j]-1);
                }
                
            }
        }
        
        return max;
        
        //Solution 2: Optimized Version
        //Time Complexity O(nlogn)

        sort(nums.begin(),nums.end());
        int num1 = nums[nums.size()-1];
        int num2 = nums[nums.size()-2];
        
        return ((num1-1)*(num2-1));
        
        
        //Solution 3: Find First max and then second max
        //Time Complexity: O(n)
        
        int max1 = 0;
        int max2 = 0;
        int index;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > max1) {
                max1 = nums[i];
                index = i;
            }
        }
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > max2 && i!=index) {
                max2 = nums[i];
            }
        }
        
        return ((max1-1)*(max2-1));        
        
    }
};



