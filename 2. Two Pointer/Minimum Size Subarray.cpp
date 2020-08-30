/*

Given an array of n positive integers and a positive integer s, find the minimal length of a 
contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.


*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            if(nums[0] >=s) {
                return 1;
            } else {
                return 0;
            }
        }
        int minDist = INT_MAX;
        int dist = 0;
        int sum = 0;
        int start = 0;
        
        for(int i=0;i<nums.size();i++) {
            
            sum += nums[i];
            while(sum >=s) {
                
                dist = i-start+1;
                minDist = min(dist,minDist);
                
                sum -= nums[start];
                start++;
            } 
        }
        if(minDist == INT_MAX) {
            return 0;
        }
        return minDist;
    }
};
