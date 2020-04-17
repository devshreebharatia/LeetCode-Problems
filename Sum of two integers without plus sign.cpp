/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1

 */


 class Solution {
public:
    int getSum(int a, int b) {
        
        //XOR operation helps to calculate the sum, where one of the bits is high. When both are high, carry has to be calculated. This carry can be obtained by AND operation. Now left shift by one position is necessary to add the carry to the sum.
        
        if(b == 0) return a;
        if(a == 0) return b;
        
        return getSum(a^b , (unsigned int)(a&b)<<1) ;
        
    }
};