/*

Given two strings S and T, return if they are equal when both are typed into empty 
text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

 */
class Solution 
{
 public:
    bool backspaceCompare(string S, string T) {
        
        if(S.length() == 0 && T.length() == 0) {
            return true;
        }
        string s = compute(S);
        string t = compute(T);
        cout<<s;
        if(s==t) {
            return true;
        }
        return false;
    }
    
    
public:
    string compute(string str) {
        
        int i = 0;
        while(i<str.length()) {
            
            if(str[i] == '#') {
                
                if(i==0) {
                    str.erase(0,1);
                    i = 0;
                } else {
                    str.erase(i-1,2);
                    i = i-1;
                }
                
            }
            else {
                i++;
            }
            
        }
        
        return str;
        
    }
};