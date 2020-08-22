/*
Given a string which consists of lowercase or uppercase letters, find the length
of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input: "abccccdd"

Output: 7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int> m;
        
        for(int i=0;i<s.length();i++) {
            m[s[i]]++;
        }
        
        int length = 0;
        bool oddPresent = false;
        for(auto each : m) {
            if(each.second %2 == 0) {
                length = length + each.second;
            }
            else {
                length = length + each.second -1;
                oddPresent = true;
            }
        }
        
        if(oddPresent) {
            length++;
        }
        
        return length;
        
    }
};