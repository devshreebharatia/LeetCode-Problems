/*
Return the lexicographically smallest subsequence of text that contains all the 
distinct characters of text exactly once.

Example 1:

Input: "cdadabcc"
Output: "adbc"

Example 2:

Input: "abcd"
Output: "abcd"

Example 3:

Input: "ecbacba"
Output: "eacb"

Example 4:

Input: "leetcode"
Output: "letcod"


*/

class Solution {
public:
    string smallestSubsequence(string text) {
        
        int visited[26] = {0};
        int last[26] = {0};
        stack<char> st;
        string output = "";
        
        //Maintaining the last index for each unique element
        for(int i=0;i<text.length();i++) {
            last[text[i]-'a'] = i;
        }
        
        for(int i=0;i<text.length();i++) {
            
            //If already visited, continue the loop
            if(visited[text[i]-'a'] == 1) {
                continue;
            }
            //If not visited, then 
            //1. Mark it visited and push into the stack
            //2. But before 1st, you need to apply LOGIC for lexicographical order:
            //If the current element is smaller than the topmost element of the stack
            //and if the topmost element of the stack occurs at some latter stage again,then
            //pop the topmost stack element and also mark it as unvisisted.
            else {

                //2
                while(st.size()>0 && st.top()> text[i] && last[st.top()-'a']>i){
                    visited[st.top()-'a'] = 0;
                    st.pop();
                }   
                //1
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

