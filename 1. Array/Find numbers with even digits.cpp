/*
Given an array nums of integers, return how many of them contain an even number 
of digits.
 
Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.


Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.

*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        //Solution 1: O(n^2). Brute force approach to count the number of digits
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            
            if(digitCountEven(nums[i])) {
                count++;
            }
        }
        return count;
        
        //Solution 2: Use log10 to find the number of digits. If even, then
        //increment the count
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            int digitCount = (int)log10(nums[i]) + 1;
            if(digitCount % 2 == 0) {
                count++;
            }
        }
        return count;
        
        //Solution 3: Use log10 and also use AND operator to test the number of
        //digits is ODD or EVEN
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            count += (int)log10(nums[i])&1;
        }
        return count;
    }
    
    bool digitCountEven(int element) {
        
        int count = 0;
        while(element>0) {
            
            element = element/10;
            count++;
        }
        
        if(count%2 == 0) {
            return true;
        }
        return false;
    }
};