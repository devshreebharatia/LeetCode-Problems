/*

Given two strings A and B, find the minimum number of times A has to be repeated 
such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 2, because by repeating A three times (“abcdabcdabcd”), B is a substring 
of it; 

*/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        int Acount[26] = {0};
        int Bcount[26] = {0};
        int max_count = -1;
        
        for(int i=0;i<A.length();i++) {
            Acount[A[i]-'a']++;
        }
        
        for(int j=0;j<B.length();j++) {
            Bcount[B[j]-'a']++;
        }
        
        for(int i=0;i<26;i++) {
            
            if(Bcount[i]>Acount[i]) {
                max_count = max(Bcount[i],max_count);
            }
            
        }
        
        return max_count;
    }
};