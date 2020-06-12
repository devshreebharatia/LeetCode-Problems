/*
Given a string s, find the longest palindromic substring in s. You may assume 
that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
 */

#include<algorithm>
class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length() == 0) {
            return "";
        } 
        if(s.length() == 1) {
            return s;
        }
        int start = 0;
        int end = 0;
        for(int i=0;i<s.length();i++) {
            
            //Choose the middle wisely. There are two cases:
            //1. "abcba" where we have odd number of characters, with one odd character "c" in the middle
            //2. "abba" where we have even characters, no odd character
            int len1 = expandFromMiddle(s,i,i);
            int len2 = expandFromMiddle(s,i,i+1);
            
            //Calculating start and end is tricky
            int len = max(len1,len2);
            if(len>end-start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        
        //substring from index start with end-start+1 characters
        return s.substr(start,end-start+1);
    }
    
    //Simple function from starting from middle and expanding till there is a palindrome
    int expandFromMiddle(string s, int left, int right) {
        
        if(s.length() == 0) {
            return 0;
        }
        while(left>=0 && right<s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right-left-1;
    }
};