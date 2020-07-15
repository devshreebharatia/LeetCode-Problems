/*
Given an array of integers nums sorted in ascending order, find the starting and
ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

 */


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>output(2,-1);
        if(nums.size() == 0) {
            return output;
        }
        
        //Solution 1: Simple solution with Time Complexity: O(n)
        int i = 0;
        while(i<nums.size()) {
            if(nums[i] > target) {
                break;
            } else if(nums[i] == target){

                //Start Index
                if(output[0] > i) {
                    output[0] = i;
                } 
                //Last Index
                else if(output[1] < i) {
                    output[1] = i;
                }
            }
            i++;
        }

        //Solution 2: Optimized solution using Binary Search.
        // Here we are tring to use binary search even for finding the first and
        // te last occurrence and not just the target element.
        output[0] = binarySearch(nums,target,"First");
        output[1] = binarySearch(nums,target,"Last");
        
        return output;
    }
public:
    int binarySearch(vector<int> nums, int target,string occurrence) {
        int low = 0, high = nums.size()-1, mid;
        int index = -1;
        
        while(low<=high) {
            
            mid = (low+high)/2;
            
            if(nums[mid] == target) {
                
               index = mid;
               if(occurrence == "First") {
                   high = mid - 1;
               } else {
                   low = mid  + 1;
               }
                                           
            } 
            else if(nums[mid] > target) {
                
                high = mid-1;
            } 
            else {
                
                low = mid+1;
            }
            
        }
        
        return index;
    }
};