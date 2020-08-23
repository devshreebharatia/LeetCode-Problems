/* PROBLEM STATEMENT:
Given an array nums and a value val, remove all instances of that value in-place and return
the new length.
Do not allocate extra space for another array, you must do this by modifying the input 
array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

EXAMPLE:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) { 

        //Solution: Whenever the problem says that the elements beyond the length do 
        // not matter, it is an opportunity to always replace the valid value
        // with the invalid values, so that at the start you get the correct
        // elements and at the end it does not matter. Never use swapping as it is
        // extremely expensive and inefficient.
        int k=0;
        for(int i=0;i<nums.size();i++) {
          if(nums[i] != val) {
              nums[k] = nums[i];
              k++;
          }
        }
        return (k);
    }
};
