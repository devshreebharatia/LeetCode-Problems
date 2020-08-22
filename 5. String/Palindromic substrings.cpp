/*
Given a string, your task is to count how many palindromic substrings in this 
string.

The substrings with different start indexes or end indexes are counted as 
different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/

class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        if(s.length() == 0) {
            return 0;
        }
        for(int i=0;i<s.length();i++) {
            
            //For ODD length palindromes
            count = count + expandPalindrome(s,i,i,s.length());
            //For EVEN length palindromes
            count = count + expandPalindrome(s,i,i+1,s.length());
        }
        return  count;
    }
    
    int expandPalindrome(string s, int left, int right, int n) {
        int count = 0;
        while(left>=0 && right<n && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
        return count;
    }
};