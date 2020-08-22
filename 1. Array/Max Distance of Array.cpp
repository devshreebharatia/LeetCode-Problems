/*
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
Last Updated: 29-08-2019
Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

Examples :

  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)

  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
  Output: 8 ( j = 8, i = 0)

  Input:  {1, 2, 3, 4, 5, 6}
  Output: 5  (j = 5, i = 0)

  Input:  {6, 5, 4, 3, 2, 1}
  Output: -1

*/
class Solution {
public:
    int maxDistance(vector<int> nums) {
        
        //Solution 1: O(n^2). It is better than the normal two-loop solution
        //as we are starting with j as the last index and not as i+1. Hence max 
        //distance can be obtained in a much better way
        if(nums.size() == 0) {
            return -1;
        }
        int maxDist = -1;
        for(int i=0;i<nums.size()-1;i++) {

            int j = nums.size()-1;
            while(i<j) {
                if(nums[i] <= nums[j]) {
                    maxDist = max(maxDist,j-i);
                    break;
                }
                j--;
            }
        }
        return maxDist;

        //Solution 2: Sorting(O(nlogn))
        //Sort the array and also store the indices of the sorted array inside 
        //another array/vector
        //Now use this array of indices, and obtain the max distance
    }
};