/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative 
integer.

Since the return type is an integer, the decimal digits are truncated and only 
the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

 */

class Solution {
public:
    int mySqrt(int x) {
    
        long long low = 0,high = x,mid,result;
        
        //Solution: Use Binary Search for Time Complexity: O(logn)
        while(low<=high) {
            
            mid = (low+high)/2;
            if(mid*mid == x) {
                return mid;
            } else if(mid*mid > x) {
                high = mid-1;
            } else {
                low = mid+1;
                //Very Important: We want only the integer and hence we always 
                //store this value so that when low>high, we can return the result
                result = mid;
            }
            
        }
        return result;
    
    }
    
};