/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.


 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //Simplest Solution is sorting. But is time inefficient
        /*if(s.length() == t.length()) {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());

            if(s == t){
                return true;
            }
        }
        return false;
        */
        
        
        
        //Second solution using hash map: add the element in the hash map if in string s. Delete it if in t. If the map is empty, i.e if it empty(all values 0), it is an anagram.
        
        /*if(s.length() == t.length()) {
            
              unordered_map<char,int> counts;
              for(int i=0;i<s.length();i++) {
                  counts[s[i]]++;
                  counts[t[i]]--;
              }
            
              for(auto count: counts) {
                  if(count.second){
                      return false;
                  }
              }
            
              return true;
        }
        return false;
        */
        
        //Third solution uses an array
        if(s.length() == t.length()) {
            
              int count[26] = {0};
              for(int i=0;i<s.length();i++) {
                  count[s[i] -'a']++;
                  count[t[i] -'a']--;
              }
            
              for(int i=0;i<26;i++) {
                  if(count[i]!= 0) {
                      return false;
                  }
              }
              return true;
        }
        return false;
        
        
    }
};