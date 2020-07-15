/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

 */

class Solution {
public:
    int maxArea(vector<int>& nums) {
        

        //Solution 1: Simple two FOR loops, and try every possible of length 
        //and height for obtaining the maximum area.

        //Solution 2: Sliding Window Protocol
        //Here define two separate conditions:
        //To shrink the window either from left/right
        int i=0,j=nums.size()-1;
        int max_area = 0;
        int l=0,h=0;
        
        while(i<j) {
            
            l = j-i;
            //Because no slant is allowed
            h = min(nums[i],nums[j]);
            max_area = max(max_area,l*h);
            
            if(nums[i]<nums[j]) {
                i++;
            } else {
                j--;
            }
    
        }
        return max_area;
    }
};