/*
We have a string S of lowercase letters, and an integer array shifts.

Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.

Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.

Return the final string after all such shifts to S are applied.

Example 1:

Input: S = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: 
We start with "abc".
After shifting the first 1 letters of S by 3, we have "dbc".
After shifting the first 2 letters of S by 5, we have "igc".
After shifting the first 3 letters of S by 9, we have "rpl", the answer.

*/

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        
        if(S.length() == 0) {
            return S;
        }
        
        if(shifts.size() == 0) {
            return S;
        }
        //Brute Force Approach:
        //Outer For loop for traversing through the shifts vector, and Inner For lopp for traversing
        //through each character of the string till the index of shift, and change the characters
        //Time Complexity: O(n^2)
        
        
        //Optimized solution:
        //One loop will prepare the shift vector for the right number of shiifting counts
        //Another loop will apply the specified shifts on each character of the string
        //Time Complexity: O(n) + O(n) = O(n)
        
        int n = shifts.size()-1;
        shifts[n] = shifts[n]% 26; 
        for(int i=n-1;i>=0;i--) {
            
            shifts[i] = (shifts[i] + shifts[i+1])%26;
        }
        string result = "";
        for(int i=0;i<shifts.size();i++) {
            
            int each = (S[i] -'a' + shifts[i])%26;
            char every = 'a' + each;
            result = result + every;
        }
        return result;
    }
};

