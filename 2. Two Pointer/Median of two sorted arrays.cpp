class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        vector<int> merged;
        
        int i=0;
        int j=0;
        
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                merged.push_back(nums2[j]);
                j++;
            }
            else {
                merged.push_back(nums1[i]);
                merged.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        
        while(i<nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }
        
        while(j<nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }
        
        if(merged.size()%2 != 0) {
            return merged[merged.size()/2];
        } else {
            int m = merged.size()/2;
            float mid = merged[m] + merged[m-1];
            return mid/2;
        }
    }
};
