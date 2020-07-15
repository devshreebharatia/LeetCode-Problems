/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
 */

 class Solution {
public:
    int trailingZeroes(int n) {
        
        //Solution 1: Calculate the factorial of the number and then keep checking 
        //whether fact is divisible by 10 and accordingly incrementing the count. 
        //But in most cases the factorial value might go out of bound. So instead 
        //of calculating the factorial, we can decide whether it will contain 
        //trailing zeros or not without calculating the factorial
        
        // For a number to contain zeros, it should be a multiple of 10 i.e 2 
        // and 5. But the number of 2s will always be equal to or greater than 5. 
        // Hence we calculate the number of 5s present in that number.
        
        long long a = 5, count = 0;
        while(n/a) {
            
            count = count + (n/a);
            a = a*5;
            
        }
        
        return count;
        
    }
};