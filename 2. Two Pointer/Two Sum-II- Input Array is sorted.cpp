/*



*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        /*
        //Brute Force Approach
        vector<int> output;
        for(int i=0;i<numbers.size()-1;i++) {
            
            for(int j=i+1;j<numbers.size();j++) {
                
                if((numbers[i] + numbers[j]) == target) {
                    output.push_back(i+1);
                    output.push_back(j+1);
                    
                    return output;
                }
            }
        }
        return output;
        */
        
        /*
        //Optimized Approach with O(n^2) but using the sorted array to our advantage
        vector<int> output;
        for(int i=0;i<numbers.size()-1;i++) {
            
            for(int j=i+1;j<numbers.size();j++) {
                
                if((numbers[i] + numbers[j]) == target) {
                    output.push_back(i+1);
                    output.push_back(j+1);
                    return output;
                }
                if(numbers[j] > target-numbers[i]) {
                    break;
                }
                
            }
            
        }
        return output;
        */
        
        //Further Optimized Approach with Time Complexity O(n)
        vector<int> output;
        int i=0;
        int j=numbers.size()-1;
        
        while(i<j) {
            
            if(numbers[i]+numbers[j] == target) {
                output.push_back(i+1);
                output.push_back(j+1);
                return output;
            } else if(numbers[i]+numbers[j] > target) {
                j--;
            } else {
                i++;
            }
            
        }
        return output;
        
    }
};
