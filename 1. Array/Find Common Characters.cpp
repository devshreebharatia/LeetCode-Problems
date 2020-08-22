/*
Given an array A of strings made only from lowercase letters, return a list of 
all characters that show up in all strings within the list (including duplicates).
For example, if a character occurs 3 times in all strings but not 4 times, you 
need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]


*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        string curr = A[0];
        int count[26] = {0};
        int temp[26] = {0};
        
        //Counting the letter count for the first string
        for(int i=0;i<curr.length();i++) {
            count[curr[i] - 'a']++;
        }
        
        //Couting the letter count for every other string in the vector.
        //Storing the minimum count in the final count array
        for(int i=1;i<A.size();i++) {
            
            for(int j=0;j<A[i].size();j++) {
                temp[A[i][j]-'a']++;
            }  
            
            for(int j=0;j<26;j++) {
                count[j] = min(count[j],temp[j]);
                temp[j] = 0;
            }
        }
        
        vector<string> result;
        for(int i=0;i<26;i++) {
            if(count[i] > 0) {
                while(count[i] > 0) {
                    count[i]--;
                    string temp = "";
                    temp += i+'a';
                    
                    result.push_back(temp);
                }    
            }
        }
        return result;
        
    }
};