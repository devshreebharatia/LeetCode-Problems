/*
Given an array of integers A sorted in non-decreasing order, return an array of
the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        //Solution 1: Find squares and add them in the same order and then sort later
        //Time Complexity: O(n) + O(nlogn)

        vector<int> result;
        for(int i=0;i<A.size();i++) {
            
            result.push_back(A[i]*A[i]);
        }
        
        sort(result.begin(),result.end());
        return result;
        
        //Solution 2: Two pointers are used to check the greater square value
        //and accordingly inserted in the result
        //Time Complexity: O(n)

        vector<int>result(A.size());
        int start = 0;
        int end = A.size()-1;
        int index = result.size()-1;
        
        while(start <= end) {
            
            if(A[start]*A[start] < A[end]*A[end]) {
                
                result[index] = A[end]*A[end];
                index--;
                end--;
            }
            else {
                
                result[index] = A[start]*A[start];
                index--;
                start++;
            }
            
        }
        return result;
        
    }
};