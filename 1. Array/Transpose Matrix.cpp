/*
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, 
switching the row and column indices of the matrix.

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        //Solution 1: Resize the matrix and then copy the elements into the new matrix
        vector<vector<int>> result;
        result.resize(A[0].size());
        
        for(int i=0;i<result.size();i++) {
            result[i].resize(A.size());
        }
        for(int i=0;i<A.size();i++) {
            for(int j=0;j<A[0].size();j++) {
                
                result[j][i] = A[i][j];
            }
        }
        return result;

        //Solution 2: For a n*n square matrix
        for(int i=1;i<A.size();i++) {
            for(int j=0;j<i;j++) {
                
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }
        return A;
        
    }
};