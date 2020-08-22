/*
Given an integer array, count element x such that x+1 is also in the array
If there are duplicates in the array count them separately.

I/P: [1,3,2,3,5,0]
o/p: 3

As 0+1, 1+1 and 2+1 are present in the array.

*/
class Solution
{
    public: 
        int Elements(vector<int> nums) {

            //Solution: Time Complexity: O(n) + O(n) = O(n)
            if(nums.size() == 0 || nums.size() == 1) {
                return 0;
            }
            //Only unique elements will be added i.e. each x+1 will be added only once
            set<int> st;
            for(int i=0;i<nums.size();i++) {
                st.insert(nums[i]+1);
            }
            int count = 0;
            for(int i=0;i<nums.size();i++) {
                if(st.find(nums[i]) != st.end()) {
                    count++;
                }
            }
            return count;
        }
};



