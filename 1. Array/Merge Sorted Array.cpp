/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one 
sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        //Solution: Smart merging method where we consider three separate 
        // indices: i,j and end
        int i = m-1, j= n-1;
        int end = m+n -1;
        
        //If the second array is non-zero and the first array is empty then simply
        //copy the second into the first, as the first array should have the
        //final array. If in case the second array is empty, do nothing as the
        //answer will be the first array itself.
        if(m == 0 && n!=0) {
            nums1 = nums2;
        }
        if(m!=0 && n!=0){
            while(j>=0 && i>=0) {
                if(nums1[i] < nums2[j]) {
                    nums1[end] = nums2[j];
                    j--;
                } else if(nums1[i] >= nums2[j]) {
                    nums1[end] = nums1[i];
                    i--;
                }
                 end--;
            }
            while(j>=0) {
                nums1[end] = nums2[j];
                j--;
                end--;
            }
        }
        
    }
};