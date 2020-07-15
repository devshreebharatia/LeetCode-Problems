/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to 
you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, 
otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //Solution: First find the pivot: The only index where the next element 
        //will be smaller than the previous  element and then perform binarySearch 
        //for the right/left section of the array.
        int pivot = findPivot(0,nums.size()-1,nums);
        if(pivot == -1) {
            return binarySearch(0,nums.size()-1,target,nums);
        }
        if(nums[pivot] == target){
            return pivot;
        } else if(nums[0] > target) {
            return binarySearch(pivot+1,nums.size()-1,target,nums);
        } else {
            return binarySearch(0,pivot,target,nums);
        }
        
        return -1;
    }
    
public:   
    int binarySearch(int low,int high,int target, vector<int> nums) {

        int mid;
        if(low<=high) {
            mid = (low+high)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                return binarySearch(low,mid-1,target,nums);
            } else {
               return binarySearch(mid+1,high,target,nums);
            }
        }        
        return -1;
    }
    
public: 
    int findPivot(int low, int high,vector<int> nums) {
        
        //Use Binary search even for finding the pivot, as the complexity
        //required is o(logn).
        int mid;
        if(low<=high) {
            mid = (low+high)/2;
            if(mid<high && nums[mid] > nums[mid+1]) {
                return mid;
            } else if(mid>low && nums[mid-1] > nums[mid]) {
                return mid-1;
            } else if(nums[low] > nums[mid] ) {
                return findPivot(low,mid-1,nums);
            } else {
                return findPivot(mid+1,high,nums);
            }
        }  
        return -1;
    }
};