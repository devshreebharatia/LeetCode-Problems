/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and 
return its index.

The array may contain multiple peaks, in that case return the index to any one 
of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index 
number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak 
element is or index number 5 where the peak element is 6.
Follow up: Your solution should be in logarithmic complexity.

 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        
        //No elements
        if(nums.size() == 0) {
            return -1;
        }
        //Single element
        if(nums.size() == 1) {
            return 0;
        }
        
        while(low<=high) {
            
            mid = (low+high)/2;
            
            //First Element
            if(mid == 0) {
                if(nums[mid] > nums[mid+1]) return mid;
                else return mid+1;
            }
            //Last Element
            else if(mid == nums.size()-1) {
                if(nums[mid] > nums[mid-1]) return mid;
                else return mid-1;
            }
            //When elements on either sides are smaller
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            //When elements on one of the sides is greater
            else if(nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]) {
                high = mid-1;
            } 
            else if(nums[mid] < nums[mid+1] && nums[mid] > nums[mid-1]) {
                low = mid+1;
            }
            //When elements on either sides are smaller
            else if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
                low = mid+1;
            }
        }
        return mid;
    }
};