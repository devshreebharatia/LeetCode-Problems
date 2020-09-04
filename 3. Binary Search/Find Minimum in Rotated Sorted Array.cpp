/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1


Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return -1;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        
        //Solution 1: Brute Force
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] > nums[i+1] ) {
                return nums[i+1];
            }
        }
        return nums[0];
        
        
	//Solution 2: Binary Search
        int low = 0;
        int high = nums.size()-1;
        int mid;
        
        while(low<=high) {
            
            mid = low + (high-low)/2;
            if(low == high) {
                return nums[mid];
            }
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        return -1;
    }
};
