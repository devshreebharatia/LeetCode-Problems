/*
Given two non-negative integers num1 and num2 represented as string, return the 
sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

 */

#include<string>
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=num1.length()-1;
        int j=num2.length()-1;
        int sum;
        int carry = 0;
        string result = "";
        while(i>=0 || j>=0) {
            
            sum = carry;
            
            if(i>=0) {
                sum = sum + (num1[i]-'0');
            }
            
            if(j>=0) {
                sum = sum + (num2[j]-'0');
            }
            
            if(sum>=10) {
                sum = sum-10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            result = result + to_string(sum);
            
            i--;
            j--;
            
        }
        
        if(carry == 1) {
            result = result + to_string(carry);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};