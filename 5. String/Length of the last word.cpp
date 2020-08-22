/*
Given a string s consists of upper/lower-case alphabets and empty space 
characters ' ', return the length of last word (last word means the last 
appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters 
only.

Example:

Input: "Hello World"
Output: 5


*/

class Solution {
public:
    int lengthOfLastWord(string s) {
     
        //Basic Null/zero case
        if(s.length() == 0) {
            return 0;
        }
        
        int length = 0;
        int i=0;
        while(i<s.length()) {
            
            //If there is a space, increment to a point when there is a character.
            //If the length has reached, then do not reset length. But if the end
            //has still not reached then reset length to 0.
            if(s[i] == ' ') {
                while(s[i] == ' ') {
                    i++;
                }
                if(i < s.length()) {
                    length = 0;
                }
            }
            //Simply increment the pointer and the length count when there is a
            //character.
            else {
                    i++;
                    length++;
            }
        }
        
        return length;
    }
};