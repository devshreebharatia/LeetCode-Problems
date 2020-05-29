/*Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?


*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        //Solution 1: With Loop, Time Complexity: O(n)
        while(n>1) {
            if(n%3!=0) {
                return false;
            }
            n = n/3;
        }
        return (n==1);
        
        
        //Solution 2: Without Loop (1162261467 is the largest integer 
        //that is a power of 3 i.e. 3^19)
        if(n>0 && 1162261467%n == 0) {
            return true;
        }
        return false;
    }
};

