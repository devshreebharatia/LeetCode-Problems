/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

 */
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        if(s.length() == 0) {
            return true;
        }
        if(s.length()%2 != 0) {
            return false;
        }
        for(int i=0;i<s.length();i++) {
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);   
            }
            if(s[i] == '}' || s[i] == ']' || s[i] == ')' ) {
                if(st.empty()) {
                    return false;
                }
                char item = st.top();
                if((s[i] == '}' &&  item == '{') ||
                   (s[i] == ']' &&  item == '[') ||
                   (s[i] == ')' &&  item == '(')) {
                        st.pop();
                } else {
                    return false;
                }
            }
        }

       return st.empty();
        
    }
};