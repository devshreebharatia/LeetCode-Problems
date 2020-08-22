/*
Given a palindromic string palindrome, replace exactly one character by any 
lowercase English letter so that the string becomes the lexicographically 
smallest possible string that isn't a palindrome.

After doing so, return the final string.  If there is no way to do so, return 
the empty string.

Example 1:

Input: palindrome = "abccba"
Output: "aaccba"

Example 2:

Input: palindrome = "a"
Output: ""

*/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length() == 0) {
            return " ";
        }
        
        if(palindrome.length() == 1) {
            return "";
        }
        
        //Only traverse through half of the string because it is a palindrome
        for(int i=0;i<palindrome.length()/2;i++) {   
            if(palindrome[i] != 'a') { 
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        //If all 'a's then make one as 'b', to break the palindrome
        palindrome[palindrome.length()-1] = 'b';
        return palindrome;
        
    }
};