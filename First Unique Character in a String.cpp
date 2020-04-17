/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.


 */
class Solution {
public:
    int firstUniqChar(string s) {
        
        //Solution with array
        /*int counts[26] = {0};
        for(int i=0;i<s.length();i++) {
            counts[s[i] - 'a']++;
        }
        
        for(int i=0;i<s.length();i++) {
            if(counts[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
        */
        
        //Solution with vector
        vector<int> counts(26,0);
        for(int i=0;i<s.length();i++) {
            counts[s[i] - 'a']++;
        }
        
        for(int i=0;i<s.length();i++) {
            if(counts[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};