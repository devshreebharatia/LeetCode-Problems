/*
Implement function ToLowerCase() that has a string parameter str, and returns 
the same string in lowercase.

Example 1:
Input: "Hello"
Output: "hello"

Example 2:
Input: "here"
Output: "here"

Example 3:
Input: "LOVELY"
Output: "lovely"

*/

class Solution {
public:
    string toLowerCase(string str) {
        
        for(int i=0;i<str.length();i++) {
            
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }
        }
        return str;
    }
};