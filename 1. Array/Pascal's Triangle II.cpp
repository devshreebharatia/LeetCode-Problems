/*

Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.

     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:
Could you optimize your algorithm to use only O(k) extra space?

*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
	//Solution 1: Brute Force without O(K) Extra-Space
        vector<vector<int>> matrix(rowIndex+1,vector<int>(0));
        
        for(int i=0;i<=rowIndex;i++) {
            matrix[i] = vector<int>(i+1,1);
        }
        
        if(rowIndex == 0 || rowIndex ==1) {
            return matrix[rowIndex];
        }
        
        for(int i=2;i<=rowIndex;i++) {
            
            for(int j=1;j<i;j++){
                matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
            }
        }
        return matrix[rowIndex];
        
        
        //Solution 2: With only O(k) extra space
        vector<int> output(1,1);
        vector<int> temp(1,1);
        
        if(rowIndex == 0) {
            return output;
        }
        for(int i=1;i<=rowIndex;i++) {
            
            output.push_back(1);
            for(int j=1;j<i;j++) {
                output[j] = temp[j-1] + temp[j];
            }
            temp = output;
        }
        
        return output;
    }
};
