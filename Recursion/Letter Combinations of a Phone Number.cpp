/*


*/

//CODE FLOW:
/*
Start with the first letter associated with the first digit. Recursively call the
letters associated with the second digit. Once the termination condition is reached
i.e. if we have 2 digits: "23", every combination will be of length 2. So once this
termination condition is reached, we return the recursion. Then we continue with the
second letter and this process continues....

For permutation combination problems: Recursion helps!!

*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        if(digits.length() == 0) {
            return result;
        }
        vector<string> mapping{
            "0",
            "1",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
            
        generateCombinations(result,digits,mapping,0,"");
        return result;
    }
    
    void generateCombinations(vector<string>& result, string digits, 
       vector<string> mapping, int index, string current) {
        
        //Always in a recursion, start with the terminating condition condition
        if(index == digits.length()) {
            result.push_back(current);
            cout<<"\ncurrent: "<<current;
            return;
        }
        
        string letters = mapping[digits[index]-'0'];
        for(int i=0;i<letters.length();i++) {
            generateCombinations(result,digits,mapping,index+1,current + letters[i]);
        }
        
    }
};