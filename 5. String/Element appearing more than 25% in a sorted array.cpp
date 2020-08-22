
/*

Given an integer array sorted in non-decreasing order, there is exactly one 
integer in the array that occurs more than 25% of the time.

Return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

 */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        if(arr.size() == 0) {
            return -1;
        }
        if(arr.size() == 1) {
            return arr[0];
        }
        int max_count = arr.size()/4;
        int count = 1;
        
        for(int i=1;i<arr.size();i++) {
            
            if(arr[i] == arr[i-1]) {
                
                count++;
                if(count>max_count) {
                    return arr[i];
                }
            }
            else {
                count = 1;
            }
        }
        
        return -1;
        
    }
};