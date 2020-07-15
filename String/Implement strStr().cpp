/*
Return the index of the first occurrence of needle in haystack, or -1 if 
needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question 
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. 

 */


 class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle == "") {
            return 0;
        }
        int i=0,j=0,start = -1;
        
        while(i<haystack.length()) {
            
            if(haystack[i] == needle[j]) {
                
                if(j == 0) {
                     start = i;
                }
                i++;
                j++;
                
                if(j == needle.length()) {
                    return i-j;
                }
            } 
            else {
                
                if(j == 0) {
                    i++;
                }
                else {
                    j = 0;
                    i = start + 1;
                }
            }
        }
        return -1;
    }
};