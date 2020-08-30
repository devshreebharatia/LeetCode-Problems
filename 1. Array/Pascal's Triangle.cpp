/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> nums(numRows, vector<int>(0));
        if(numRows == 0) {
            return nums;
        }
        else if(numRows == 1) {
            nums[0] = vector<int>(1,1);
            return nums;
        }
        else if(numRows == 2) {
            nums[0] = vector<int>(1,1);
            nums[1] = vector<int>(2,1);
            return nums;
        }
        
        //Initalization of a vector
        for(int i=0;i<numRows;i++) {
            nums[i] = vector<int>(i+1,1);
        }
        
        //Formation of the pascal triangle
        int i=2;
        int j=1;
        while(i<numRows) {
            nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
            j++;
            if(j==nums[i].size()-1) {
                i++;
                j=1;
            }
        }
        return nums;
    }
};
