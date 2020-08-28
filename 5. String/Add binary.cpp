/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        int i= a.length()-1;
        int j= b.length()-1;
        int carry = 0;
        string result = "";
        
        while(i>=0 || j>=0 || carry) {
         
           if(i>=0 && a[i] == '1') {
               carry++;
           } 
           if(j>=0 && b[j] == '1') {
               carry++;
           }
           result.insert(0,1,carry%2 == 0? '0':'1');
           i--;
           j--; 
           carry = carry/2; 
        }
        
        return result;
        
    }
};
