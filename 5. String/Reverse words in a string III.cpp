/*

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/

class Solution {
public:
    string reverseWords(string s) {
    
        string temp = "";
        string output = "";
        int i = 0;
        
        while(i<s.length()) {
            
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
            i++;
        }
         if(temp != "") {
            reverse(temp.begin(),temp.end());
            output += temp;
         }
        return output;
        
    }
};
