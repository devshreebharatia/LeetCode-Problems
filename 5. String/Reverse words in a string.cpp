/*

Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain 
leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/


class Solution {
public:
    string reverseWords(string s) {
        
        string output = "";
        string temp = "";
        
        
        if(s.length() == 0) {
            return s;
        }
        
        for(int i=s.length()-1;i>=0;i--) {
            
            if(s[i] != ' ') {
                temp += s[i];
            }
            else {
                if(temp != "") {
                    reverse(temp.begin(),temp.end());
                    output += temp + " ";
                    temp = "";
                }
            }
        }
        if(temp != "") {
            cout<<"\n "<<temp;
            reverse(temp.begin(),temp.end());
            output += temp;
        }
        //For the ending space
        if(output!= "" && output[output.length()-1] == ' ') {
             output = output.substr(0,output.length()-1);
        }
        return output;
        
    }
};
