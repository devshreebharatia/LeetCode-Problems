/*

Given a string which contains only lowercase letters, remove duplicate letters 
so that every letter appears once and only once. You must make sure your result 
is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"

Example 2:

Input: "cbacdcbc"
Output: "acdb"

***** Duplicate of another question: Smallest Subsequence of distinct characters

*/


class Solution {
public:
    string removeDuplicateLetters(string text) {
        
        int visited[26] = {0};
        int last[26] = {0};
        stack<char> st;
        string output = "";
        
        for(int i=0;i<text.length();i++) {
            last[text[i]-'a'] = i;
        }
        
        for(int i=0;i<text.length();i++) {
            
            if(visited[text[i]-'a'] == 1) {
                continue;
            }
            
            else {
                
                while(st.size()>0 && st.top()> text[i] && last[st.top()-'a']>i){
                    visited[st.top()-'a'] = 0;
                    st.pop();
                }   
                
                visited[text[i]-'a'] = 1;
                st.push(text[i]);
            }
        }
        
        while(st.size()>0) {
            output = output + st.top();
            st.pop();
        }
        
        reverse(output.begin(),output.end());
        return output;
        
        
        
    }
};