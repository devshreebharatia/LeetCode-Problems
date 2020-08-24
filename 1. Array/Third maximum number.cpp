/*

Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1
Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]

Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
       sort(nums.begin(),nums.end());
       int size = nums.size();
       if(size<3) {
           return nums[size-1];
       }
       int count = 0; 
       int i = size-1; 
       while(count<2 && i>0) {
           
           if(nums[i]>nums[i-1]) {
               count++;
           }
           i--;
       }
       if(count == 2) {
           return nums[i];
       }
       return nums[size-1];
    }
};


