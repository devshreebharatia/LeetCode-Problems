/*
Given an arbitrary ransom note string and another string containing letters from
all the magazines, write a function that will return true if the ransom note can 
be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:
You may assume that both strings contain only lowercase letters.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        //If the note itself is empty, then return true
        if(ransomNote.size() == 0){
            return true;
        }
        //If the magazine does not have any characters, but note has, then return false
        if(magazine.size() == 0){
            return false;
        }

        /* Use of arrays can be done here, as we know that there are only lowercase
           letters, we can declare the size of the array as 26 before hand.
           If in case, we didnt know, then we can use maps and store letters and
           their respective counts as a key value pair.
        */
        int letterCount[26] = {0};
        for(int i=0;i<magazine.size();i++) {
            letterCount[magazine[i] - 'a']++;   
        }
        
        for(int j=0;j<ransomNote.size();j++) {
            if(letterCount[ransomNote[j] - 'a'] != 0){
                letterCount[ransomNote[j] - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
};