/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int max_count = 0;
        int i=0;
        
        
        while(i<nums.size()) {
            
            if(nums[i] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            max_count = max(count,max_count);
            i++;
        }
        
        return max_count;
    }
};