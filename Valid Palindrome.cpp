/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and 
ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 */

 class Solution {
public:
    bool isPalindrome(string s) {
        
        //Compare the first and last characters and then accordingly increment and decrement.
        if(s.length() == 0) {
            return true;
        }
        
        int i=0,j=s.length()-1;
        while(i<j) {
            
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }  
            if(toupper(s[i]) != toupper(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};