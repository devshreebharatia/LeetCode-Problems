/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

 */

#include <bits/stdc++.h> 
#include<algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //Solution: Simple Sliding Window Protocol
        set<char> st;
        int i=0;
        int j=0;
        int result = 0;
        

        while(j< s.length()) {
            
            //If character not present in the set, insert it
            if(st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                j++;
                
                //Maintains the maximum length of the substring
                result = max(j-i,result);
            }
            //If present remove it and add it in the next cycle
            else {
                
                st.erase(s[i]);
                i++;
            }
        }
        
        return result;
    }
};