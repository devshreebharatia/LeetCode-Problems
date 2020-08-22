/*

Given a sentence text (A sentence is a string of space-separated words) in the 
following format:

First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged 
in an increasing order of their lengths. If two words have the same length, 
arrange them in their original order.

Return the new text following the format shown above.


Example 1:

Input: text = "Leetcode is cool"
Output: "Is cool leetcode"
Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and 
"cool" of length 4.
Output is ordered by length and the new first word starts with capital letter.

Example 2:

Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.

Example 3:

Input: text = "To be or not to be"
Output: "To be or to be not"

*/


class Solution {
public:
    string arrangeWords(string text) {
        
        if(text.length() == 0) {
            return " ";
        }
        string output = "";
        map<int,vector<string>>m;
        int length = 0;
        string str = "";
        
        //At the start convert the first letter into lowercase
        text[0] = tolower(text[0]);
        
        int i=0;
        for(char c: text) {
            
            if(c != ' ') 
            {
                length++;
                str = str + c;
                
            } else {
                m[length].push_back(str);
                cout<<"\n"<<length;
                cout<<str;
                length = 0;
                str = "";
            }
        }
        m[length].push_back(str);
        for(auto each: m) {
            for(string s: each.second) {
                output = output + s + " ";
            }
        }
        output.pop_back();
        
        //At the end convert first letter into uppercase
        output[0] = toupper(output[0]);
        
        return output;
    }
};